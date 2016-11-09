#include "StdAfx.h"
#include "NewFile_datatype_h.h"

void NewFile_datatype_h()
{
	CStdioFile stFile;
	stFile.Open("datatype.h",CFile::modeCreate|CFile::modeReadWrite);
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("* ģ������: datatype.h\n");
	stFile.WriteString("* ժ    Ҫ: \n");
	stFile.WriteString("* ��ǰ�汾: 1.0\n");
	stFile.WriteString("* ��    ��: \n");
	stFile.WriteString("* �������: \n");
	stFile.WriteString("* ��    ��:\n");
	stFile.WriteString("* ע    ��: none                                                                  \n");
	stFile.WriteString("**********************************************************************************************************\n");
	stFile.WriteString("* ȡ���汾: \n");
	stFile.WriteString("* ��    ��:\n");
	stFile.WriteString("* �������: \n");
	stFile.WriteString("* �޸�����:\n");
	stFile.WriteString("* �޸��ļ�: \n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("#ifndef __DATATYPE_H\n");
	stFile.WriteString("#define __DATATYPE_H\n");
	stFile.WriteString("\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              �궨��\n");
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
	stFile.WriteString("typedef	unsigned short		WORD;			//����Byte���һ��Word\n");
	stFile.WriteString("typedef	unsigned int   		DWORD;			//�ĸ�Byte���һ��Double Word\n");
	stFile.WriteString("typedef	long	        	LONG;\n");
	stFile.WriteString("\n");
	stFile.WriteString("\n");
	stFile.WriteString("#define MAKEWORD(a, b)      ((WORD)(((BYTE)(a)) | ((WORD)((BYTE)(b))) << 8))	//����Byte���һ��Word\n");
	stFile.WriteString("#define MAKELONG(a, b)      ((LONG)(((WORD)(a)) | ((DWORD)((WORD)(b))) << 16))\n");
	stFile.WriteString("\n");
	stFile.WriteString("#define LOWORD(l)           ((WORD)(l))								\n");
	stFile.WriteString("#define HIWORD(l)           ((WORD)(((DWORD)(l) >> 16) & 0xFFFF))\n");
	stFile.WriteString("\n");
	stFile.WriteString("#define LOBYTE(w)           ((BYTE)(w))							//���ֽ�\n");
	stFile.WriteString("#define HIBYTE(w)           ((BYTE)(((WORD)(w) >> 8) & 0xFF))	//���ֽ�\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              �궨��\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("// #define		TRUE	1\n");
	stFile.WriteString("// #define		FALSE	0\n");
	stFile.WriteString("//#define		NULL	0\n");
	stFile.WriteString("#define  INVALID_DATA  			-100\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              �ṹ�嶨��\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("\n");
	stFile.WriteString("/*********************************************************************************************************\n");
	stFile.WriteString("*                                              API��������\n");
	stFile.WriteString("*********************************************************************************************************/\n");
	stFile.WriteString("\n");
	stFile.WriteString("#endif\n");
	stFile.Close();
}