#pragma once

#define IDC_INPUTSHOWBTN 1100		// ��ư ��Ʈ�� ID 1000�����̸� �ƹ���ȣ�� �������.

class CMyMain
{
	HWND m_hDlg;		// �𵨸��� ���̾˷α� �ڽ� �ڵ�
	HWND m_hShowBtn;

public:
	CMyMain();
	~CMyMain();

public:
	void MainInit(HINSTANCE hInst, HWND a_hWnd);		// �ʱ�ȭ �Լ�
	void MainUpdate();									// ������ ���� ���κ�
	void MainRender(HDC a_MainDC);						// ������ �׸��� �κ�
	void MainDestroy();

	void On_Move(HWND hWnd);
	void On_Size(HWND hWnd);
	void On_MessageHook(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

extern CMyMain g_MyMain;