/*******************************************************************************************
	File Name:		StringCheck.h
	Author:			will4906
	Date:			2016.8.5
	Version:		v1.00.00
	File Describe:	interface for the CStringCheck class
  ******************************************************************************************/
#if !defined(AFX_STRINGCHECK_H__B3752D25_FBB7_4692_A260_CCDC5BB3DA0E__INCLUDED_)
#define AFX_STRINGCHECK_H__B3752D25_FBB7_4692_A260_CCDC5BB3DA0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class AFX_EXT_CLASS CStringCheck  
{
public:
	CStringCheck();
	virtual ~CStringCheck();

public:														//变量名称检查组

	BOOL CheckVarName(CString strVar);						//匹配字符串是否符合变量名命名规则
	BOOL CheckFileAsciiName(CString strFile);				//匹配字符串是否符合文件ASCII命名

public:														//十六进制检查组

	BOOL CheckNegativeHex(CString strHex);					//匹配字符串是否符合十六进制负数
	BOOL CheckPositiveHex(CString strHex);					//匹配字符串是否符合十六进制正数
	BOOL CheckHexWithOx(CString strHex);					//匹配字符串带"0x"是否为十六进制数
	BOOL CheckNegativeHexWithoutOx(CString strHex);			//匹配字符串不带"0x"是否符合十六进制负数
	BOOL CheckPositiveHexWithoutOx(CString strHex);			//匹配字符串不带"0x"是否符合十六进制正数
	BOOL CheckHexWithoutOx(CString strHex);					//匹配字符串不带"0x"是否为十六进制数
	BOOL CheckNegativeHexWithOx(CString strHex);			//匹配字符串带"0x"是否符合十六进制正数
	BOOL CheckPositiveHexWithOx(CString strHex);			//匹配字符串带"0x"是否符合十六进制负数
	BOOL CheckHexNum(CString strHex);						//匹配字符串是否符合十六进制数
	BOOL CheckByteHexNum(CString strHex);					//匹配字符串是否为一字节的十六进制数

public:														//十进制检查组
	
	BOOL CheckNegativeDec(CString strDec);					//匹配字符串是否为十进制负数
	BOOL CheckPositiveDec(CString strDec);					//匹配字符串是否为十进制正数
	BOOL CheckDecNum(CString strDec);						//匹配字符串是否为十进制数
};

#endif // !defined(AFX_STRINGCHECK_H__B3752D25_FBB7_4692_A260_CCDC5BB3DA0E__INCLUDED_)
