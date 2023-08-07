/*
 * flash_smg.c
 *
 *  Created on: 2023年7月5日
 *      Author: a8456
 */
#include "flash_smg.h"

volatile bool               interrupt_called;
volatile flash_event_t      flash_event;


void flash_callback (flash_callback_args_t * p_args)
{
    interrupt_called = true;
    flash_event      = p_args->event;
}


extern fsp_err_t err ;
/*FLASH写入程序*/
void WriteFlashTest(uint32_t L,uint8_t Data[],uint32_t addr)
{


    interrupt_called = false;
    /* Erase 1 block of data flash starting at block 0. */
    err = R_FLASH_LP_Erase(&g_flash0_ctrl, FLASH_DF_BLOCK_0, 1);
    assert(FSP_SUCCESS == err);
    while (!interrupt_called)
    {
    ;
    }
    assert(FLASH_EVENT_ERASE_COMPLETE == flash_event);
    interrupt_called = false;
    flash_status_t status;
    /* Write 32 bytes to the first block of data flash. */
    err = R_FLASH_LP_Write(&g_flash0_ctrl, (uint32_t) Data, addr, L);
    assert(FSP_SUCCESS == err);

    /* Wait until the current flash operation completes. */
    do
    {
        err = R_FLASH_LP_StatusGet(&g_flash0_ctrl, &status);
    } while ((FSP_SUCCESS == err) && (FLASH_STATUS_BUSY == status));


    /* If the interrupt wasn't called process the error. */
    assert(interrupt_called);
    /* If the event wasn't a write complete process the error. */
    assert(FLASH_EVENT_WRITE_COMPLETE == flash_event);
    /* Verify the data was written correctly. */
    assert(0 == memcmp(Data, (uint8_t *) FLASH_DF_BLOCK_0, L));


}

extern int sec,min,hour;//保存时间数据
extern uint16_t year,month,day,week,t_year,t_month,t_day,t_week;
/*FLASH读取打印程序*/
void PrintFlashTest(uint32_t addr)
{
    hour=*(__IO uint8_t*)(addr);
    min=*(__IO uint8_t*)(addr+1);
    year=*(__IO uint8_t*)(addr+2)+1900;
    month=*(__IO uint8_t*)(addr+3);
    day=*(__IO uint8_t*)(addr+4);
    week=*(__IO uint8_t*)(addr+5);

    if(hour>=24)
        hour=0;
    if(min>=60)
        min=0;
    if(year>2099||year<1900)
            year=2023;
    if(month>12)
            month=1;
    if(day>31)
            day=1;
    if(week>7)
            week=1;
}



