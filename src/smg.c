/*
 * smg.c
 *
 *  Created on: 2023年6月29日
 *      Author: a8456
 */

#include "smg.h"
#include "hal_data.h"


void smg_num(int num)
{
    switch(num)
    {
        case 0:
        {
            SMG_A_OPEN;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_OPEN;
            SMG_E_OPEN;
            SMG_F_OPEN;
            SMG_G_CLOSE;
            SMG_DP_CLOSE;
            break;
        }
        case 1:
        {
            SMG_A_CLOSE;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_CLOSE;
            SMG_E_CLOSE;
            SMG_F_CLOSE;
            SMG_G_CLOSE;
            SMG_DP_CLOSE;
            break;
        }
        case 2:
        {
            SMG_A_OPEN;
            SMG_B_OPEN;
            SMG_C_CLOSE;
            SMG_D_OPEN;
            SMG_E_OPEN;
            SMG_F_CLOSE;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }
        case 3:
        {
            SMG_A_OPEN;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_OPEN;
            SMG_E_CLOSE;
            SMG_F_CLOSE;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }
        case 4:
        {
            SMG_A_CLOSE;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_CLOSE;
            SMG_E_CLOSE;
            SMG_F_OPEN;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }
        case 5:
        {
            SMG_A_OPEN;
            SMG_B_CLOSE;
            SMG_C_OPEN;
            SMG_D_OPEN;
            SMG_E_CLOSE;
            SMG_F_OPEN;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }
        case 6:
        {
            SMG_A_OPEN;
            SMG_B_CLOSE;
            SMG_C_OPEN;
            SMG_D_OPEN;
            SMG_E_OPEN;
            SMG_F_OPEN;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }
        case 7:
        {
            SMG_A_OPEN;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_CLOSE;
            SMG_E_CLOSE;
            SMG_F_CLOSE;
            SMG_G_CLOSE;
            SMG_DP_CLOSE;
            break;
        }
        case 8:
        {
            SMG_A_OPEN;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_OPEN;
            SMG_E_OPEN;
            SMG_F_OPEN;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }
        case 9:
        {
            SMG_A_OPEN;
            SMG_B_OPEN;
            SMG_C_OPEN;
            SMG_D_OPEN;
            SMG_E_CLOSE;
            SMG_F_OPEN;
            SMG_G_OPEN;
            SMG_DP_CLOSE;
            break;
        }




    }



}

void smg_1(int num)
{
    SMG_1_OPEN;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_CLOSE;

    smg_num(num);

}


void smg_2(int num)
{
    SMG_1_CLOSE;
    SMG_2_OPEN;
    SMG_3_CLOSE;
    SMG_4_CLOSE;
    smg_num(num);

}



void smg_3(int num)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_OPEN;
    SMG_4_CLOSE;
    smg_num(num);

}



void smg_4(int num)
{

    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_OPEN;
    smg_num(num);

}


void smg_1_p(void)
{
    SMG_1_OPEN;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_CLOSE;

    SMG_A_OPEN;
    SMG_B_OPEN;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_OPEN;
    SMG_F_OPEN;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}


void smg_1_d(void)
{
    SMG_1_OPEN;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_CLOSE;

    SMG_A_CLOSE;
    SMG_B_OPEN;
    SMG_C_OPEN;
    SMG_D_OPEN;
    SMG_E_OPEN;
    SMG_F_CLOSE;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}




void smg_1_close(void)
{
    SMG_1_OPEN;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_CLOSE;

    SMG_A_CLOSE;
    SMG_B_CLOSE;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_CLOSE;
    SMG_F_CLOSE;
    SMG_G_CLOSE;
    SMG_DP_CLOSE;

}


void smg_2_close(void)
{
    SMG_1_CLOSE;
    SMG_2_OPEN;
    SMG_3_CLOSE;
    SMG_4_CLOSE;

    SMG_A_CLOSE;
    SMG_B_CLOSE;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_CLOSE;
    SMG_F_CLOSE;
    SMG_G_CLOSE;
    SMG_DP_CLOSE;
}

void smg_2_a(void)
{
    SMG_1_CLOSE;
    SMG_2_OPEN;
    SMG_3_CLOSE;
    SMG_4_CLOSE;

    SMG_A_OPEN;
    SMG_B_OPEN;
    SMG_C_OPEN;
    SMG_D_CLOSE;
    SMG_E_OPEN;
    SMG_F_OPEN;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}

void smg_3_y(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_OPEN;
    SMG_4_CLOSE;

    SMG_A_CLOSE;
    SMG_B_OPEN;
    SMG_C_OPEN;
    SMG_D_OPEN;
    SMG_E_CLOSE;
    SMG_F_OPEN;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}

void smg_3_r(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_OPEN;
    SMG_4_CLOSE;

    SMG_A_CLOSE;
    SMG_B_OPEN;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_OPEN;
    SMG_F_OPEN;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}

void smg_3_o(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_OPEN;
    SMG_4_CLOSE;

    SMG_A_OPEN;
    SMG_B_OPEN;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_CLOSE;
    SMG_F_OPEN;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}

void smg_3_close(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_OPEN;
    SMG_4_CLOSE;

    SMG_A_CLOSE;
    SMG_B_CLOSE;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_CLOSE;
    SMG_F_CLOSE;
    SMG_G_CLOSE;
    SMG_DP_CLOSE;
}

void smg_4_C(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_OPEN;

    SMG_A_OPEN;
    SMG_B_CLOSE;
    SMG_C_CLOSE;
    SMG_D_OPEN;
    SMG_E_OPEN;
    SMG_F_OPEN;
    SMG_G_CLOSE;
    SMG_DP_CLOSE;

}

void smg_4_H(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_OPEN;

    SMG_A_CLOSE;
    SMG_B_OPEN;
    SMG_C_OPEN;
    SMG_D_CLOSE;
    SMG_E_OPEN;
    SMG_F_OPEN;
    SMG_G_OPEN;
    SMG_DP_CLOSE;

}

void smg_4_close(void)
{
    SMG_1_CLOSE;
    SMG_2_CLOSE;
    SMG_3_CLOSE;
    SMG_4_OPEN;

    SMG_A_CLOSE;
    SMG_B_CLOSE;
    SMG_C_CLOSE;
    SMG_D_CLOSE;
    SMG_E_CLOSE;
    SMG_F_CLOSE;
    SMG_G_CLOSE;
    SMG_DP_CLOSE;
}







//立创数码管
void smg_maohao_open(int num)
{

    SMG_1_CLOSE;
    SMG_2_CLOSE;

    if(num)//开启冒号
    {
        SMG_3_OPEN;
        SMG_4_OPEN;
        SMG_A_CLOSE;
        SMG_B_CLOSE;
        SMG_C_CLOSE;
        SMG_D_CLOSE;
        SMG_E_CLOSE;
        SMG_F_CLOSE;
        SMG_G_CLOSE;
        SMG_DP_OPEN;
    }
    else
    {
        SMG_3_CLOSE;
        SMG_4_CLOSE;

        SMG_A_CLOSE;
        SMG_B_CLOSE;
        SMG_C_CLOSE;
        SMG_D_CLOSE;
        SMG_E_CLOSE;
        SMG_F_CLOSE;
        SMG_G_CLOSE;
        SMG_DP_CLOSE;

    }
}
//优信数码管
//void smg_maohao_open(int num)
//{
//
//    SMG_1_CLOSE;
//    SMG_3_CLOSE;
//    SMG_4_CLOSE;
//
//    if(num)//开启冒号
//    {
//        SMG_2_OPEN;
//        SMG_A_CLOSE;
//        SMG_B_CLOSE;
//        SMG_C_CLOSE;
//        SMG_D_CLOSE;
//        SMG_E_CLOSE;
//        SMG_F_CLOSE;
//        SMG_G_CLOSE;
//        SMG_DP_OPEN;
//    }
//    else
//    {
//        SMG_2_CLOSE;
//
//        SMG_A_CLOSE;
//        SMG_B_CLOSE;
//        SMG_C_CLOSE;
//        SMG_D_CLOSE;
//        SMG_E_CLOSE;
//        SMG_F_CLOSE;
//        SMG_G_CLOSE;
//        SMG_DP_CLOSE;
//
//    }
//}
void ceshi_smg(void)
{
    for(int i=0;i<40;i++)
    {
        if(i<10)
        {   smg_1(i);}

        else if(i>=10&&i<20)
        {    smg_2(i-10);}

        else if(i>=20&&i<30)
        {    smg_3(i-20);}

        else if(i>=30&&i<40)
        {   smg_4(i-30);}


        R_BSP_SoftwareDelay(100U, BSP_DELAY_UNITS_MILLISECONDS);
    }
     smg_maohao_open(1);





}
