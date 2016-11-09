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

public:														//�������Ƽ����

	BOOL CheckVarName(CString strVar);						//ƥ���ַ����Ƿ���ϱ�������������
	BOOL CheckFileAsciiName(CString strFile);				//ƥ���ַ����Ƿ�����ļ�ASCII����

public:														//ʮ�����Ƽ����

	BOOL CheckNegativeHex(CString strHex);					//ƥ���ַ����Ƿ����ʮ�����Ƹ���
	BOOL CheckPositiveHex(CString strHex);					//ƥ���ַ����Ƿ����ʮ����������
	BOOL CheckHexWithOx(CString strHex);					//ƥ���ַ�����"0x"�Ƿ�Ϊʮ��������
	BOOL CheckNegativeHexWithoutOx(CString strHex);			//ƥ���ַ�������"0x"�Ƿ����ʮ�����Ƹ���
	BOOL CheckPositiveHexWithoutOx(CString strHex);			//ƥ���ַ�������"0x"�Ƿ����ʮ����������
	BOOL CheckHexWithoutOx(CString strHex);					//ƥ���ַ�������"0x"�Ƿ�Ϊʮ��������
	BOOL CheckNegativeHexWithOx(CString strHex);			//ƥ���ַ�����"0x"�Ƿ����ʮ����������
	BOOL CheckPositiveHexWithOx(CString strHex);			//ƥ���ַ�����"0x"�Ƿ����ʮ�����Ƹ���
	BOOL CheckHexNum(CString strHex);						//ƥ���ַ����Ƿ����ʮ��������
	BOOL CheckByteHexNum(CString strHex);					//ƥ���ַ����Ƿ�Ϊһ�ֽڵ�ʮ��������

public:														//ʮ���Ƽ����
	
	BOOL CheckNegativeDec(CString strDec);					//ƥ���ַ����Ƿ�Ϊʮ���Ƹ���
	BOOL CheckPositiveDec(CString strDec);					//ƥ���ַ����Ƿ�Ϊʮ��������
	BOOL CheckDecNum(CString strDec);						//ƥ���ַ����Ƿ�Ϊʮ������
};

#endif // !defined(AFX_STRINGCHECK_H__B3752D25_FBB7_4692_A260_CCDC5BB3DA0E__INCLUDED_)
