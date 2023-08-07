/*
 * timer_smg.c
 *
 *  Created on: 2023年7月3日
 *      Author: a8456
 */
#include "beep.h"
#include "timer_smg.h"
//数码管变量
extern uint8_t num1,num2,num3,num4;//4个数码管显示的数值
extern uint16_t year,month,day,week,t_year,t_month,t_day,t_week;
extern uint8_t num_flag;//4个数码管和冒号轮流显示，一轮刷新五次

//按键变量
extern  bsp_io_level_t sw1;//按键SW1状态
extern  bsp_io_level_t sw2;//按键SW2状态
extern  bsp_io_level_t sw3;//按键SW3状态
extern  bsp_io_level_t sw4;//按键SW4状态
extern  bsp_io_level_t qe_sw;//触摸电容状态

extern int sw1_num1;//按键SW1计数值，去抖和长按短按判断
extern int sw2_num1;//按键SW2计数值，去抖和长按短按判断
extern int sw3_num1;//按键SW3计数值，去抖和长按短按判断
extern int sw4_num1;//按键SW4计数值，去抖和长按短按判断
extern int qe_sw_num1;//触摸按键计数值，去抖和长按短按判断


extern int smg_mode;//数码管显示状态，0正常显示，1修改小时，2修改分钟，3保存修改数据，4温度，5湿度
extern int sec,min,hour;//保存时间数据
extern uint16_t time_mode_num;//定时器刷新时间，实现闪烁效果
uint16_t maohao=0,calendar=0,count=0,beepcount=1;//冒号和日期显示的刷新计数


extern rtc_time_t set_time;//RTC时间定义
extern rtc_alarm_time_t set_alarm_time;//RTC闹铃定义
extern int alarm_hour,alarm_min;
extern volatile bool rtc_alarm_flag;//RTC闹钟
extern int alarm_count;
int set_alarm_flag=0;//闹钟开启关闭铃声标志位

extern uint8_t flash_flag;//保存时间数据，一半在每过一分钟或者按键修改时间

//温湿度变量定义
extern uint8_t humdity_integer;//湿度整数
extern uint8_t humdity_decimal;//湿度小数
extern uint8_t temp_integer ;//温度整数
extern uint8_t temp_decimal ;//温度小数
extern uint8_t dht11_check ;//校验值

int count1=0,count2=0,count3=0,count4=0;//倒计时
int countflag=0;//倒计时开始标志

void timer0_callback(timer_callback_args_t *p_args)
{
    /* TODO: add your own code here */
    if (TIMER_EVENT_CYCLE_END == p_args->event)
    {
        time_mode_num++;
        maohao++;

        if(time_mode_num>200)
            time_mode_num=0;
        if(maohao>500)
            maohao=0;

        if(smg_mode==0)//显示时间
        {
            if(num_flag==0)
            smg_1(num1);
            else if(num_flag==1)
            smg_2(num2);
            else if(num_flag==2)
            smg_3(num3);
            else if(num_flag==3)
            smg_4(num4);
            else if(num_flag==4)
            {
                if(maohao<200)
                    smg_maohao_open(1);   //冒号
                else
                    smg_maohao_open(0);   //冒号
            }
        }
        else if(smg_mode==1)//修改时间小时
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(hour/10);
                else if(num_flag==1)
                    smg_2(hour%10);
                else if(num_flag==2)
                    smg_3(min/10);
                else if(num_flag==3)
                    smg_4(min%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
            else
            {
                if(num_flag==0)
                    smg_1_close();
                else if(num_flag==1)
                    smg_2_close();
                else if(num_flag==2)
                    smg_3(min/10);
                else if(num_flag==3)
                    smg_4(min%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
        }
        else if(smg_mode==2)//修改时间分钟
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(hour/10);
                else if(num_flag==1)
                    smg_2(hour%10);
                else if(num_flag==2)
                    smg_3(min/10);
                else if(num_flag==3)
                    smg_4(min%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
            else
            {
                if(num_flag==0)
                    smg_1(hour/10);
                else if(num_flag==1)
                    smg_2(hour%10);
                else if(num_flag==2)
                    smg_3_close();
                else if(num_flag==3)
                    smg_4_close();
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
        }
        else if(smg_mode==3)//保存数据
        {
            set_time.tm_sec=sec;
            set_time.tm_min =min;
            set_time.tm_hour  =hour ;
            R_RTC_CalendarTimeSet(&g_rtc0_ctrl, &set_time);
            smg_mode=0;
            flash_flag=1;//保存数据
        }
        else if(smg_mode==4)//显示温度
        {

//                if(num_flag==0)
//                    smg_1_p();
//                else if(num_flag==1)
//                    smg_2(1);
//                else if(num_flag==2)
//                    smg_3(temp_integer/10);
//                else if(num_flag==3)
//                    smg_4(temp_integer%10);
//                else if(num_flag==4)
//                    smg_maohao_open(1);   //冒号
            if(num_flag==0)
                smg_1(temp_integer/10);
            else if(num_flag==1)
                smg_2(temp_integer%10);
            else if(num_flag==2)
                smg_3_o();
            else if(num_flag==3)
                smg_4_C();
            else if(num_flag==4)
                smg_maohao_open(0);   //冒号
        }
        else if(smg_mode==5)//显示湿度
        {

                if(num_flag==0)
                    smg_1(humdity_integer/10);
                else if(num_flag==1)
                    smg_2(humdity_integer%10);
                else if(num_flag==2)
                    smg_3_r();
                else if(num_flag==3)
                    smg_4_H();
                else if(num_flag==4)
                    smg_maohao_open(0);   //冒号
        }
        else if(smg_mode==6)//显示年月日周
        {
            if(calendar<2000)
            {
                if(num_flag==0)
                    smg_1(year/1000);
                else if(num_flag==1)
                    smg_2(year/100%10);
                else if(num_flag==2)
                    smg_3(year/10%10);
                else if(num_flag==3)
                    smg_4(year%10);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            else if(calendar>=2000&&calendar<4000)
            {
                if(num_flag==0)
                    smg_1(month/10);
                else if(num_flag==1)
                    smg_2(month%10);
                else if(num_flag==2)
                    smg_3(day/10);
                else if(num_flag==3)
                    smg_4(day%10);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            else
            {
                if(num_flag==0)
                    smg_1_d();
                else if(num_flag==1)
                    smg_2_a();
                else if(num_flag==2)
                    smg_3_y();
                else if(num_flag==3)
                    smg_4(week);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            if(calendar<=6000)
                calendar++;
            else
                calendar=0;
        }
        else if(smg_mode==7)//修改年
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(year/1000);
                else if(num_flag==1)
                    smg_2(year/100%10);
                else if(num_flag==2)
                    smg_3(year/10%10);
                else if(num_flag==3)
                    smg_4(year%10);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            else
            {
                if(num_flag==0)
                    smg_1_close();
                else if(num_flag==1)
                    smg_2_close();
                else if(num_flag==2)
                    smg_3_close();
                else if(num_flag==3)
                    smg_4_close();
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
        }
        else if(smg_mode==8)//修改月
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(month/10);
                else if(num_flag==1)
                    smg_2(month%10);
                else if(num_flag==2)
                    smg_3(day/10);
                else if(num_flag==3)
                    smg_4(day%10);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            else
            {
                if(num_flag==0)
                    smg_1_close();
                else if(num_flag==1)
                    smg_2_close();
                else if(num_flag==2)
                    smg_3(day/10);
                else if(num_flag==3)
                    smg_4(day%10);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
        }
        else if(smg_mode==9)//修改日
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(month/10);
                else if(num_flag==1)
                    smg_2(month%10);
                else if(num_flag==2)
                    smg_3(day/10);
                else if(num_flag==3)
                    smg_4(day%10);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            else
            {
                if(num_flag==0)
                    smg_1(month/10);
                else if(num_flag==1)
                    smg_2(month%10);
                else if(num_flag==2)
                    smg_3_close();
                else if(num_flag==3)
                    smg_4_close();
                else if(num_flag==4)
                    smg_maohao_open(0);   //冒号
            }
        }
        else if(smg_mode==10)//修改周
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1_d();
                else if(num_flag==1)
                    smg_2_a();
                else if(num_flag==2)
                    smg_3_y();
                else if(num_flag==3)
                    smg_4(week);
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
            else
            {
                if(num_flag==0)
                    smg_1_d();
                else if(num_flag==1)
                    smg_2_a();
                else if(num_flag==2)
                    smg_3_y();
                else if(num_flag==3)
                    smg_4_close();
                else if(num_flag==4)
                    smg_maohao_open(0);
            }
        }
        else if(smg_mode==11)//保存数据
        {
            set_time.tm_year=year-1900;
            set_time.tm_mon=month;
            set_time.tm_mday=day ;
            set_time.tm_wday=week ;
            R_RTC_CalendarTimeSet(&g_rtc0_ctrl, &set_time);
            calendar=0;
            smg_mode=6;
            flash_flag=1;//保存数据
        }
        else if(smg_mode==12)//倒计时
        {
            if(num_flag==0)
                smg_1(count1/10);
            else if(num_flag==1)
                smg_2(count1%10);
            else if(num_flag==2)
                smg_3(count2/10);
            else if(num_flag==3)
                smg_4(count2%10);
            else if(num_flag==4){
                if(countflag==0)
                    smg_maohao_open(1);
                else{
                    if(maohao<250)
                        smg_maohao_open(1);   //冒号
                    else
                        smg_maohao_open(0);   //冒号
                    maohao++;
                }
            }
            if(countflag==1)
            {
                if(count<500)
                    count++;
                else
                {
                    count=0;
                    if(count2>0)
                        count2--;
                    else
                    {
                        if(count1>0)
                        {
                            count1--;
                            count2=59;
                        }
                        else
                            countflag=2;
                    }
                }
            }
            if(countflag==2){
                if(maohao<250)
                {
                    if(maohao==1)
                        BeepInitial();
                    else
                        BeepOpen();
                }
                else
                    BeepStop();
                maohao++;
            }
         }
        else if(smg_mode==13)//修改倒计时分钟
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(count1/10);
                else if(num_flag==1)
                    smg_2(count1%10);
                else if(num_flag==2)
                    smg_3(count2/10);
                else if(num_flag==3)
                    smg_4(count2%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
            else
            {
                if(num_flag==0)
                    smg_1_close();
                else if(num_flag==1)
                    smg_2_close();
                else if(num_flag==2)
                    smg_3(count2/10);
                else if(num_flag==3)
                    smg_4(count2%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
        }
        else if(smg_mode==14)//修改倒计时秒
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(count1/10);
                else if(num_flag==1)
                    smg_2(count1%10);
                else if(num_flag==2)
                    smg_3(count2/10);
                else if(num_flag==3)
                    smg_4(count2%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
            else
            {
                if(num_flag==0)
                    smg_1(count1/10);
                else if(num_flag==1)
                    smg_2(count1%10);
                else if(num_flag==2)
                    smg_3_close();
                else if(num_flag==3)
                    smg_4_close();
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
        }
        else if(smg_mode==15)//显示闹铃时间
        {
            if(num_flag==0)
                smg_1(set_alarm_time.time.tm_hour/10);
            else if(num_flag==1)
                smg_2(set_alarm_time.time.tm_hour%10);
            else if(num_flag==2)
                smg_3(set_alarm_time.time.tm_min/10);
            else if(num_flag==3)
                smg_4(set_alarm_time.time.tm_min%10);
            else if(num_flag==4)
                smg_maohao_open(1);   //冒号
            if(set_alarm_flag==1)//关闭闹铃提示音铃声
            {
                if(beepcount<100)
                {
                    if(beepcount==1)
                        BeepInitial();
                    else
                        BeepOpen();
                }
                else if(beepcount>100&&beepcount<200)
                    BeepStop();
                else if(beepcount>200&&beepcount<300)
                {
                    if(beepcount==201)
                        BeepInitial();
                    else
                        BeepOpen();
                }
                else if(beepcount>300&&beepcount<400)
                    BeepStop();
                else if(beepcount>400)
                {
                    set_alarm_flag=0;
                    beepcount=0;
                }
                beepcount++;
            }
            if(set_alarm_flag==2)//打开闹铃提示音铃声
            {
                if(beepcount<100)
                {
                    if(beepcount==1)
                        BeepInitial();
                    else
                        BeepOpen();
                }
                else if(beepcount>100&&beepcount<200)
                    BeepStop();
                else if(beepcount>200&&beepcount<300)
                {
                    if(beepcount==201)
                        BeepInitial();
                    else
                        BeepOpen();
                }
                else if(beepcount>300&&beepcount<400)
                    BeepStop();
                else if(beepcount>400&&beepcount<500)
                {
                    if(beepcount==401)
                        BeepInitial();
                    else
                        BeepOpen();
                }
                else if(beepcount>500&&beepcount<600)
                    BeepStop();
                else if(beepcount>600)
                {
                    set_alarm_flag=0;
                    beepcount=0;
                }
                beepcount++;
            }
        }
        else if(smg_mode==16)//修改闹铃小时
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(alarm_hour/10);
                else if(num_flag==1)
                    smg_2(alarm_hour%10);
                else if(num_flag==2)
                    smg_3(alarm_min/10);
                else if(num_flag==3)
                    smg_4(alarm_min%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
            else
            {
                if(num_flag==0)
                    smg_1_close();
                else if(num_flag==1)
                    smg_2_close();
                else if(num_flag==2)
                    smg_3(alarm_min/10);
                else if(num_flag==3)
                    smg_4(alarm_min%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
        }
        else if(smg_mode==17)//修改闹铃分钟
        {
            if(time_mode_num<100)
            {
                if(num_flag==0)
                    smg_1(alarm_hour/10);
                else if(num_flag==1)
                    smg_2(alarm_hour%10);
                else if(num_flag==2)
                    smg_3(alarm_min/10);
                else if(num_flag==3)
                    smg_4(alarm_min%10);
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
            else
            {
                if(num_flag==0)
                    smg_1(alarm_hour/10);
                else if(num_flag==1)
                    smg_2(alarm_hour%10);
                else if(num_flag==2)
                    smg_3_close();
                else if(num_flag==3)
                    smg_4_close();
                else if(num_flag==4)
                    smg_maohao_open(1);   //冒号
            }
        }
        else if(smg_mode==18)//同步闹铃
        {
            set_alarm_time.time.tm_hour=alarm_hour;
            set_alarm_time.time.tm_min=alarm_min;
            R_RTC_CalendarAlarmSet(&g_rtc0_ctrl, &set_alarm_time);
            smg_mode=15;
        }
        num_flag++;
        if(num_flag==5)
            num_flag=0;

    }
}

void set_smg_button(void)
{

     R_IOPORT_PinRead(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_07, &sw1);
     R_IOPORT_PinRead(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_08, &sw2);
     R_IOPORT_PinRead(&g_ioport_ctrl, BSP_IO_PORT_09_PIN_13, &sw3);
     R_IOPORT_PinRead(&g_ioport_ctrl, BSP_IO_PORT_09_PIN_14, &sw4);
     if(sw1+sw2+sw3+sw4==4&&qe_sw==0)//按键都没按下,清除按键按下计数值
     {
         sw1_num1=0;
         sw2_num1=0;
         sw3_num1=0;
         sw4_num1=0;
         qe_sw_num1=0;
     }
     else if(sw1==0&&sw2&&sw3&&sw4&&qe_sw==0)//只有SW1按下
     {
         if(sw1_num1<800)//按下小于10s,1001是防止变量在1000时候一直切换模式
         sw1_num1++;
         if(sw1_num1%200==0)//模式切换,按下
         {
             //buzzer_num=20;//蜂鸣器叫200ms
             if(smg_mode<4)
             {
                 if(smg_mode>2)
                     smg_mode=0;
                 else
                     smg_mode++;
             }
             else if(smg_mode>5&&smg_mode<12)
             {
                 if(smg_mode>10)
                     smg_mode=6;
                 else
                     smg_mode++;
             }
             else if(smg_mode>11&smg_mode<15){
                 if(smg_mode>13)
                     smg_mode=12;
                 else
                     smg_mode++;
             }
             else if(smg_mode>14&smg_mode<19){
                 if(smg_mode>18)
                     smg_mode=15;
                 else
                     smg_mode++;
             }
         }
         if(smg_mode==19)
             smg_mode=0;

     }
     else if(sw2==0&&sw1&&sw3&&sw4&&qe_sw==0)//只有SW2按下
     {
         if(sw2_num1<30)//300ms 减一次
             sw2_num1++;
         else
         {
             sw2_num1=0;
             if(smg_mode==1)
             {
                 if(hour>0)
                      hour--;
                 else
                     hour=23;

             }
             else if(smg_mode==2)
             {
                 if(min>0)
                     min--;
                 else
                     min=59;
             }
             else if(smg_mode==7)
             {
                 if(year>1900)
                     year--;
                 else
                     year=2099;
             }
             else if(smg_mode==8)
             {
                 if(month>1)
                     month--;
                 else
                     month=12;
             }
             else if(smg_mode==9)
             {
                 if(day>1)
                     day--;
                 else
                 {
                     if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                         day=31;
                     else if(month==2)
                         day=27;
                     else
                         day=30;
                 }
             }
             else if(smg_mode==10)
             {
                 if(week>1)
                     week--;
                 else
                     week=7;
             }
             else if(smg_mode==13)
             {
                 if(count1>0)
                     count1--;
                 else
                     count1=60;
             }
             else if(smg_mode==14)
             {
                 if(count2>0)
                     count2--;
                 else
                     count2=59;
             }
             else if(smg_mode==16)
             {
                 if(alarm_hour>0)
                     alarm_hour--;
                 else
                     alarm_hour=23;
             }
             else if(smg_mode==17)
             {
                 if(alarm_min>0)
                     alarm_min--;
                 else
                     alarm_min=59;
             }

         }
     }
     else if(sw3==0&&sw1&&sw2&&sw4&&qe_sw==0)//只有SW3按下
     {
         if(sw3_num1<30)//300ms 减一次
             sw3_num1++;
         else
         {
             sw3_num1=0;
             if(smg_mode==1)
             {
                 if(hour<23)
                     hour++;
                 else
                     hour=0;

             }
             else if(smg_mode==2)
             {
                 if(min<59)
                     min++;
                 else
                     min=0;
             }
             else if(smg_mode==7)
             {
                 if(year<2099)
                     year++;
                 else
                     year=1900;
             }
             else if(smg_mode==8)
             {
                 if(month<12)
                     month++;
                 else
                     month=1;
             }
             else if(smg_mode==9)
             {
                 if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
                     {
                         if(day<31)
                             day++;
                         else
                             day=1;
                     }
                 else if(month==2)
                 {
                     if(day<27)
                         day++;
                     else
                         day=1;
                 }
                 else
                 {
                     if(day<30)
                         day++;
                     else
                         day=1;
                 }

             }
             else if(smg_mode==10)
             {
                 if(week<7)
                     week++;
                 else
                     week=1;
             }
             else if(smg_mode==13)
             {
                 if(count1<60)
                     count1++;
                 else
                     count1=0;
             }
             else if(smg_mode==14)
             {
                 if(count2<59)
                     count2++;
                 else
                     count2=0;
             }
             else if(smg_mode==16)
             {
                 if(alarm_hour<23)
                     alarm_hour++;
                 else
                     alarm_hour=0;
             }
             else if(smg_mode==17)
             {
                 if(alarm_min<59)
                     alarm_min++;
                 else
                     alarm_min=0;
             }
         }
     }
     else if(sw4==0&&sw2&&sw3&&sw1&&qe_sw==0)//只有SW4按下
          {
              if(sw4_num1<20)
                  sw4_num1++;
              else
              {
                  PwmBeep();
                  sw4_num1=0;
                  if(smg_mode==0)
                  {
                      smg_mode=6;
                  }
                  else if(smg_mode==6)
                  {
                      calendar=0;
                      smg_mode=12;
                  }
                  else if(smg_mode==12)
                  {
                      smg_mode=15;
                  }
                  else if(smg_mode==15)
                  {
                      smg_mode=0;
                  }
                  else if(smg_mode==5)
                  {
                      smg_mode=6;
                  }
                  else if(smg_mode==4)
                  {
                      smg_mode=6;
                  }
                  else if(smg_mode==1||smg_mode==2)
                  {
                      smg_mode=3;
                  }

              }

          }
     else if(sw1&&sw2&&sw3&&sw4&&qe_sw)//只有触摸电容按下
     {
         if(qe_sw_num1<20)//1000ms 切换一次
             qe_sw_num1++;
         else
         {
             qe_sw_num1=0;
             if(rtc_alarm_flag==1){
                 rtc_alarm_flag=0;
                 BeepStop();
                 alarm_count=0;
             }
             else
             {
                 if(smg_mode==0)//切换到显示温度
                 {
                     PwmBeep();
                     smg_mode=4;
                 }
                 else if(smg_mode==4)//切换到显示湿度
                 {
                     PwmBeep();
                     smg_mode=5;
                 }
                 else if(smg_mode==6)//切换到显示温度
                 {
                     PwmBeep();
                     smg_mode=4;
                 }
                 //切换为数据保存
                 else if(smg_mode==1||smg_mode==2)
                 {
                     PwmBeep();
                     smg_mode=3;
                 }
                 else if(smg_mode==5)//正常显示
                 {
                     PwmBeep();
                     smg_mode=0;
                 }
                 else if(smg_mode==12)//倒计时
                 {
                     if(countflag==0&&(count1!=0||count2!=0))
                     {
                         PwmBeep();
                         countflag=1;
                     }
                     else if(countflag==1)
                     {
                         PwmBeep();
                         countflag=0;
                     }
                     else if(countflag==2)
                     {
                         PwmBeep();
                         countflag=0;
                     }
                 }
                 else if(smg_mode==15&&rtc_alarm_flag==0)
                 {
                     if(set_alarm_time.hour_match&&set_alarm_time.min_match)
                     {
                         set_alarm_time.hour_match=0;
                         set_alarm_time.min_match=0;
                         set_alarm_flag=1;
                     }
                     else
                     {
                         set_alarm_time.hour_match=1;
                         set_alarm_time.min_match=1;
                         set_alarm_flag=2;
                     }
                 }
             }
         }

     }

}



















