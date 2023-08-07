/*
 * flash_smg.h
 *
 *  Created on: 2023年7月5日
 *      Author: a8456
 */

#ifndef FLASH_SMG_H_
#define FLASH_SMG_H_
#include "hal_data.h"

#define FLASH_DF_BLOCK_0                0x40100000U/*   1 KB: 0x40100000 - 0x401003FF */

/*FLASH写入程序*/
void WriteFlashTest(uint32_t L,uint8_t Data[],uint32_t addr);
/*FLASH读取打印程序*/
void PrintFlashTest(uint32_t addr);


#endif /* FLASH_SMG_H_ */
