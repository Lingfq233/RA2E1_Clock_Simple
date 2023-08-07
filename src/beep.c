/*
 * beep.c
 *
 *  Created on: 2023年7月26日
 *      Author: MyPC
 */
#include "beep.h"
#include "hal_data.h"

void beep(int num){

    BEEP_OPEN;
    R_BSP_SoftwareDelay(num, BSP_DELAY_UNITS_MILLISECONDS);//2*num ms
    BEEP_CLOSE;

}

void testbeep(){
    uint32_t i;
    for(i=0;i<500;i++){
        BEEP_OPEN;
//        R_BSP_SoftwareDelay(1000, BSP_DELAY_UNITS_MICROSECONDS);
        BEEP_CLOSE;
    }
}

void BeepInitial(){
    fsp_err_t err = FSP_SUCCESS;
    /* Initializes the module. */
    err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
    /* Handle any errors. This function should be defined by the user. */
    assert(FSP_SUCCESS == err);
}

void BeepOpen(){

    /* Start the timer. */
    (void) R_GPT_Start(&g_timer1_ctrl);
}

void BeepStop(){
    R_GPT_Stop(&g_timer1_ctrl);
}

void PwmBeep(){
    fsp_err_t err = FSP_SUCCESS;
    /* Initializes the module. */
    err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
    /* Handle any errors. This function should be defined by the user. */
    assert(FSP_SUCCESS == err);
    /* Start the timer. */
    (void) R_GPT_Start(&g_timer1_ctrl);
    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
    R_GPT_Stop(&g_timer1_ctrl);
}

void PwmBeepDo(){
    fsp_err_t err = FSP_SUCCESS;
    /* Initializes the module. */
    err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
    /* Handle any errors. This function should be defined by the user. */
    assert(FSP_SUCCESS == err);
    /* Start the timer. */
    (void) R_GPT_Start(&g_timer1_ctrl);
    err = R_GPT_PeriodSet(&g_timer1_ctrl, 45800);//频率
    assert(FSP_SUCCESS == err);
    R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
    err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 22900, GPT_IO_PIN_GTIOCA);//占空比
    assert(FSP_SUCCESS == err);
    R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

//    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
    R_GPT_Stop(&g_timer1_ctrl);
}

void PwmBeepRe(){
    fsp_err_t err = FSP_SUCCESS;
    /* Initializes the module. */
    err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
    /* Handle any errors. This function should be defined by the user. */
    assert(FSP_SUCCESS == err);
    /* Start the timer. */
    (void) R_GPT_Start(&g_timer1_ctrl);
    err = R_GPT_PeriodSet(&g_timer1_ctrl, 41100);//频率
    assert(FSP_SUCCESS == err);
    R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
    err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 20550, GPT_IO_PIN_GTIOCA);//占空比
    assert(FSP_SUCCESS == err);
    R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

//    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
    R_GPT_Stop(&g_timer1_ctrl);
}

    void PwmBeepMi(){
        fsp_err_t err = FSP_SUCCESS;
        /* Initializes the module. */
        err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
        /* Handle any errors. This function should be defined by the user. */
        assert(FSP_SUCCESS == err);
        /* Start the timer. */
        (void) R_GPT_Start(&g_timer1_ctrl);
        err = R_GPT_PeriodSet(&g_timer1_ctrl, 36400);//频率
        assert(FSP_SUCCESS == err);
        R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
        err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 18200, GPT_IO_PIN_GTIOCA);//占空比
        assert(FSP_SUCCESS == err);
        R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

    //    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
        R_GPT_Stop(&g_timer1_ctrl);
    }
    void PwmBeepFa(){
            fsp_err_t err = FSP_SUCCESS;
            /* Initializes the module. */
            err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
            /* Handle any errors. This function should be defined by the user. */
            assert(FSP_SUCCESS == err);
            /* Start the timer. */
            (void) R_GPT_Start(&g_timer1_ctrl);
            err = R_GPT_PeriodSet(&g_timer1_ctrl, 34400);//频率
            assert(FSP_SUCCESS == err);
            R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
            err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 17200, GPT_IO_PIN_GTIOCA);//占空比
            assert(FSP_SUCCESS == err);
            R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

        //    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
            R_GPT_Stop(&g_timer1_ctrl);
        }
    void PwmBeepSo(){
            fsp_err_t err = FSP_SUCCESS;
            /* Initializes the module. */
            err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
            /* Handle any errors. This function should be defined by the user. */
            assert(FSP_SUCCESS == err);
            /* Start the timer. */
            (void) R_GPT_Start(&g_timer1_ctrl);
            err = R_GPT_PeriodSet(&g_timer1_ctrl, 30400);//频率
            assert(FSP_SUCCESS == err);
            R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
            err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 15200, GPT_IO_PIN_GTIOCA);//占空比
            assert(FSP_SUCCESS == err);
            R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

        //    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
            R_GPT_Stop(&g_timer1_ctrl);
        }
    void PwmBeepLa(){
                fsp_err_t err = FSP_SUCCESS;
                /* Initializes the module. */
                err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
                /* Handle any errors. This function should be defined by the user. */
                assert(FSP_SUCCESS == err);
                /* Start the timer. */
                (void) R_GPT_Start(&g_timer1_ctrl);
                err = R_GPT_PeriodSet(&g_timer1_ctrl, 27200);//频率
                assert(FSP_SUCCESS == err);
                R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
                err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 13600, GPT_IO_PIN_GTIOCA);//占空比
                assert(FSP_SUCCESS == err);
                R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

            //    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
                R_GPT_Stop(&g_timer1_ctrl);
            }
    void PwmBeepXi(){
                    fsp_err_t err = FSP_SUCCESS;
                    /* Initializes the module. */
                    err = R_GPT_Open(&g_timer1_ctrl, &g_timer1_cfg);
                    /* Handle any errors. This function should be defined by the user. */
                    assert(FSP_SUCCESS == err);
                    /* Start the timer. */
                    (void) R_GPT_Start(&g_timer1_ctrl);
                    err = R_GPT_PeriodSet(&g_timer1_ctrl, 24300);//频率
                    assert(FSP_SUCCESS == err);
                    R_BSP_SoftwareDelay (20, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功
                    err = R_GPT_DutyCycleSet(&g_timer1_ctrl, 12150, GPT_IO_PIN_GTIOCA);//占空比
                    assert(FSP_SUCCESS == err);
                    R_BSP_SoftwareDelay (100, BSP_DELAY_UNITS_MILLISECONDS);//不加延时可能会设置不成功

                //    R_BSP_SoftwareDelay(100, BSP_DELAY_UNITS_MILLISECONDS);
                    R_GPT_Stop(&g_timer1_ctrl);
                }
