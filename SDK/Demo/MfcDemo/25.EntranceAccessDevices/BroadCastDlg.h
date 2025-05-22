#if !defined(_BROADCASTDLG_)
#define _BROADCASTDLG_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "afxwin.h"
#include "LatticeScreenDlg2.h"

// BroadCastDlg �Ի���

class BroadCastDlg : public CDialog
{
	DECLARE_DYNAMIC(BroadCastDlg)

public:
	BroadCastDlg(CWnd* pParent = NULL,
		LATTICE_SCREEN_ACT_TYPE LatticeScreenActTmp = ACT_UNKNOWN,
		int SeletedRowtmp = -1);   // ��׼���캯��

	virtual ~BroadCastDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_BROADCAST_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CWnd* m_pParent;
	LATTICE_SCREEN_ACT_TYPE m_emBroadCastAct;
	int m_nSeletedRow;

	CComboBox m_cmbTextType;
	CEdit m_edText;

	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
};

#endif //_BROADCASTDLG_
