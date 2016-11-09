#include "StdAfx.h"
#include "NewFile_datatype_h.h"

void NewFile_datatype_h()
{
	CStdioFile stFile;
	stFile.Open("datatype.h",CFile::modeCreate|CFile::modeReadWrite);
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("* 模块名称: datatype.h\n");
	stFile.WriteString("* 摘    要: \n");
	stFile.WriteString("* 当前版本: 1.0\n");
	stFile.WriteString("* 作    者: \n");
	stFile.WriteString("* 完成日期: \n");
	stFile.WriteString("* 内    容:\n");
	stFile.WriteString("* 注    意: none                                                                  \n");
	stFile.WriteString("**********************************************************************************************************\n");
	stFile.WriteString("* 取代版本: \n");
	stFile.WriteString("* 作    者:\n");
	stFile.WriteString("* 完成日期: \n");
	stFile.WriteString("* 修改内容:\n");
	stFile.WriteString("* 修改文件: \n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("#ifndef __DATATYPE_H\n");
	stFile.WriteString("#define __DATATYPE_H\n");
	stFile.WriteString("\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              宏定义\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("typedef	signed char			i8;\n");
	stFile.WriteString("typedef	signed short		i16;\n");
	stFile.WriteString("typedef	signed int			i32;\n");
	stFile.WriteString("typedef	unsigned char		u8;\n");
	stFile.WriteString("typedef	unsigned short		u16;\n");
	stFile.WriteString("typedef	unsigned int		u32;\n");
	stFile.WriteString("\n");
	stFile.WriteString("typedef	int            		BOOL;\n");
	stFile.WriteString("typedef	unsigned char  		BYTE;\n");
	stFile.WriteString("typedef	unsigned short		WORD;			//两个Byte组成一个Word\n");
	stFile.WriteString("typedef	unsigned int   		DWORD;			//四个Byte组成一个Double Word\n");
	stFile.WriteString("typedef	long	        	LONG;\n");
	stFile.WriteString("\n");
	stFile.WriteString("\n");
	stFile.WriteString("#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))	//两个Byte组成一个Word\n");
	stFile.WriteString("#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))\n");
	stFile.WriteString("\n");
	stFile.WriteString("#define LOWORD(l)           ((WORD)(l))								\n");
	stFile.WriteString("#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))\n");
	stFile.WriteString("\n");
	stFile.WriteString("#define LOBYTE(w)           ((BYTE)(w))							//低字节\n");
	stFile.WriteString("#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))	//高字节\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              宏定义\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("// #define		TRUE	1\n");
	stFile.WriteString("// #define		FALSE	0\n");
	stFile.WriteString("//#define		NULL	0\n");
	stFile.WriteString("#define  INVALID_DATA  			-100\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              结构体定义\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              API函数声明\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("\n");
	stFile.WriteString("#endif\n");
	stFile.Close();
}