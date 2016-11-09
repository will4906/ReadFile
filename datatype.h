/*********************************************************************************************************
* 模块名称: datatype.h
* 摘    要: 
* 当前版本: 1.0
* 作    者: 
* 完成日期: 
* 内    容:
* 注    意: none                                                                  
**********************************************************************************************************
* 取代版本: 
* 作    者:
* 完成日期: 
* 修改内容:
* 修改文件: 
*********************************************************************************************************/
#ifndef __DATATYPE_H
#define __DATATYPE_H

/*********************************************************************************************************
*                                              宏定义
*********************************************************************************************************/
typedef	signed char			i8;
typedef	signed short		i16;
typedef	signed int			i32;
typedef	unsigned char		u8;
typedef	unsigned short		u16;
typedef	unsigned int		u32;

typedef	int            		BOOL;
typedef	unsigned char  		BYTE;
typedef	unsigned short		WORD;			//两个Byte组成一个Word
typedef	unsigned int   		DWORD;			//四个Byte组成一个Double Word
typedef	long	        	LONG;


#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))	//两个Byte组成一个Word
#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))

#define LOWORD(l)           ((WORD)(l))								
#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))

#define LOBYTE(w)           ((BYTE)(w))							//低字节
#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))	//高字节
/*********************************************************************************************************
*                                              宏定义
*********************************************************************************************************/
// #define		TRUE	1
// #define		FALSE	0
//#define		NULL	0
#define  INVALID_DATA  			-100
/*********************************************************************************************************
*                                              结构体定义
*********************************************************************************************************/

/*********************************************************************************************************
*                                              API函数声明
*********************************************************************************************************/

#endif
