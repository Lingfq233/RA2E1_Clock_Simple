/*
 * beep.h
 *
 *  Created on: 2023年7月26日
 *      Author: MyPC
 */

#ifndef BEEP_H_
#define BEEP_H_

#define BEEP_OPEN  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_02, BSP_IO_LEVEL_HIGH)

#define BEEP_CLOSE  R_IOPORT_PinWrite(&g_ioport_ctrl, BSP_IO_PORT_03_PIN_02, BSP_IO_LEVEL_LOW)

void beep(int num);
void testbeep(void);


#endif /* BEEP_H_ */
