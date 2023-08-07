/*
 * smg.h
 *
 *  Created on: 2023年6月29日
 *      Author: a8456
 */

#ifndef SMG_H_
#define SMG_H_
#define SMG_A_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_03, BSP_IO_LEVEL_HIGH)
#define SMG_B_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_00, BSP_IO_LEVEL_HIGH)
#define SMG_C_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_13, BSP_IO_LEVEL_HIGH)
#define SMG_D_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_08, BSP_IO_LEVEL_HIGH)
#define SMG_E_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_07, BSP_IO_LEVEL_HIGH)
#define SMG_F_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_02, BSP_IO_LEVEL_HIGH)
//旧版PCB
//#define SMG_G_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_00, BSP_IO_LEVEL_HIGH)
//新版PCB
#define SMG_G_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_00, BSP_IO_LEVEL_HIGH)
#define SMG_DP_OPEN R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_12, BSP_IO_LEVEL_HIGH)


#define SMG_A_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_03, BSP_IO_LEVEL_LOW)
#define SMG_B_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_05_PIN_00, BSP_IO_LEVEL_LOW)
#define SMG_C_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_13, BSP_IO_LEVEL_LOW)
#define SMG_D_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_08, BSP_IO_LEVEL_LOW)
#define SMG_E_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_07, BSP_IO_LEVEL_LOW)
#define SMG_F_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_02, BSP_IO_LEVEL_LOW)
//旧版PCB
//#define SMG_G_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_00, BSP_IO_LEVEL_LOW)
//新版PCB
#define SMG_G_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_00, BSP_IO_LEVEL_LOW)
#define SMG_DP_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_02_PIN_12, BSP_IO_LEVEL_LOW)

#define SMG_1_OPEN R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_04, BSP_IO_LEVEL_LOW)
#define SMG_2_OPEN R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_01, BSP_IO_LEVEL_LOW)
#define SMG_3_OPEN R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_00, BSP_IO_LEVEL_LOW)
//旧版PCB
//#define SMG_4_OPEN R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_00, BSP_IO_LEVEL_LOW)
//新版PCB
#define SMG_4_OPEN R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_00, BSP_IO_LEVEL_LOW)


#define SMG_1_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_04, BSP_IO_LEVEL_HIGH)
#define SMG_2_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_01, BSP_IO_LEVEL_HIGH)
#define SMG_3_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_01_PIN_00, BSP_IO_LEVEL_HIGH)
//旧版PCB
//#define SMG_4_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_00_PIN_00, BSP_IO_LEVEL_HIGH)
//新版PCB
#define SMG_4_CLOSE R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_04_PIN_00, BSP_IO_LEVEL_HIGH)


void smg_num(int num);

void smg_1(int num);
void smg_2(int num);
void smg_3(int num);
void smg_4(int num);

void smg_1_p(void);


void smg_1_close(void);
void smg_2_close(void);
void smg_3_close(void);
void smg_4_close(void);
void smg_maohao_open(int num);

void ceshi_smg(void);
#endif /* SMG_H_ */
