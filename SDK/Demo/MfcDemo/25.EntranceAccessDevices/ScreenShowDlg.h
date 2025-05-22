#if !defined(_SCREENSHOWDLG_)
#define _SCREENSHOWDLG_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afxwin.h"
#include "LatticeScreenDlg2.h"

// ScreenShowDlg �Ի���

class ScreenShowDlg : public CDialog
{
	DECLARE_DYNAMIC(ScreenShowDlg)

public:
	ScreenShowDlg(CWnd* pParent = NULL, 
		LATTICE_SCREEN_ACT_TYPE LatticeScreenActTmp = ACT_UNKNOWN,
		int SeletedRowtmp = -1);   // ��׼���캯��
	virtual ~ScreenShowDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_SCREENSHOW_DETAIL };

protected:
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

private:
	CWnd* m_pParent;
	LATTICE_SCREEN_ACT_TYPE m_emScreenShowAct;
	int m_nSeletedRow;

	CEdit m_edScreenNo;
	CComboBox m_cmbTextType;
	CComboBox m_cmbTextColor;
	CComboBox m_cmbTextRollMode;
	CComboBox m_cmbRollSpeed;
	CEdit m_edText;

	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();

};



#endif //_SCREENSHOWDLG_
