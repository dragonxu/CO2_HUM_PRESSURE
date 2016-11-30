#ifndef __STMFLASH_H__
#define __STMFLASH_H__

#include "bitmap.h"  

//********************************************************************************
//V1.1修改说明
//修正了STMFLASH_Write函数地址偏移的一个bug.
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////
//用户根据自己的需要设置
#define STM32_FLASH_SIZE 	512 	 		//所选STM32的FLASH容量大小(单位为K)
#define STM32_FLASH_WREN 	1              	//使能FLASH写入(0，不是能;1，使能)
//////////////////////////////////////////////////////////////////////////////////////////////////////

//FLASH起始地址
#define	STM32_FLASH_BASE 			0x08000000 	//STM32 FLASH的起始地址

#define FLASH_APP1_ADDR				0x08008000  	//第一个应用程序起始地址(存放在FLASH)
//FLASH解锁键值
#define FLASH_KEY1					0X45670123
#define FLASH_KEY2					0XCDEF89AB
void STMFLASH_Unlock(void);					  //FLASH解锁
void STMFLASH_Lock(void);					  //FLASH上锁
u8 STMFLASH_GetStatus(void);				  //获得状态
u8 STMFLASH_WaitDone(u16 time);				  //等待操作结束
u8 STMFLASH_ErasePage(u32 paddr);			  //擦除页
u8 STMFLASH_WriteHalfWord(u32 faddr, u16 dat);//写入半字
u16 STMFLASH_ReadHalfWord(u32 faddr);		  //读出半字  
void STMFLASH_WriteLenByte(u32 WriteAddr, u32 DataToWrite, u16 Len);	//指定地址开始写入指定长度的数据
u32 STMFLASH_ReadLenByte(u32 ReadAddr, u16 Len);						//指定地址开始读取指定长度数据
//void STMFLASH_Write(u32 WriteAddr, u16 *pBuffer, u16 NumToWrite);		//从指定地址开始写入指定长度的数据
void STMFLASH_Read(u32 ReadAddr, u16 *pBuffer, u16 NumToRead);   		//从指定地址开始读出指定长度的数据

//测试写入
void Test_Write(u32 WriteAddr, u16 WriteData);	

void iap_write_appbin(u32 appxaddr,u8 *appbuf,u32 appsize) ;
void STMFLASH_MUL_Read(u32 ReadAddr, u8 *pBuffer, u16 NumToRead) ;  	
void STMFLASH_Write_NoCheck(u32 WriteAddr, u16 *pBuffer, u16 NumToWrite);

void iap_load_app(u32 appxaddr);			//执行flash里面的app程序  
typedef  void (*iapfun)(void);				//定义一个函数类型的参数.
#endif

















