#pragma once
class CInputDlg
{
	bool m_isCtrlChange = false;		// ���� ���ڰ� ��Ʈ���� �ǵ���� ���� �����ϱ� ���� ����
	int m_Total = 0;					// ���� �ݾ�
	int m_SubKind = -1;					// ������ư ���� ���� (����, �Ҽ���, �ֹ�...)
	int m_SubCombo = -1;				// �ɼ� (����, �ӽ�Ÿ��, ����...)
	int m_Su = 0;						// ����
	int m_Point = 0;					// ����Ʈ ��� �ݾ� ����

public:
	//------ �𵨸��� ���̾˷α� �ڽ��� �θ� �����츦 ����ٴϰ� �ϴ� �κ��� ����
	POINT m_MainWPos;
	POINT m_ChildWPos;
	POINT m_DlgSize;
	POINT m_MWTopLeft;
	//------ �𵨸��� ���̾˷α� �ڽ��� �θ� �����츦 ����ٴϰ� �ϴ� �κ��� ����

public:
	CInputDlg();
	~CInputDlg();

public:
	void On_Initdialog(HWND hDlg);
	void On_IDOK(HWND hDlg);
	void On_ShowWindow(HWND hDlg, WPARAM wParam);
	void On_Command(HWND hDlg, WPARAM wParam);
	void On_Notify(HWND hDlg, WPARAM wParam);
	void On_Paint(HWND hDlg);
	void On_Destroy();

	void On_MessageHook(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);

	bool CheckCtrlState(WPARAM wParam);		// ��Ʈ�ѵ��� ��ȭ�� �����ϴ� �Լ�
	void ReCalculateCost(HWND hDlg);		// ��Ʈ�ѵ��� ��ȭ�� �߻��ϸ� ����� �ٽ� ����� �ִ� �Լ�
	void ReCalcChange(HWND hDlg, int a_Total);		// �Ž����� ��� �Լ�
	void ClearCtrl(HWND hDlg);		// ��Ʈ�� ���� ������ ��� �ʱ�ȭ �� �ִ� �Լ�

public:
	static INT_PTR CALLBACK InputDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

extern CInputDlg g_InputDlg;

