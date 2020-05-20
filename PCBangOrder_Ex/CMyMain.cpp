#include "framework.h"
#include "CMyMain.h"

#include "Resource.h"
#include "GlobalValue.h"
#include "CInputDlg.h"

CMyMain::CMyMain()
{
}

CMyMain::~CMyMain()
{
}

void CMyMain::MainInit(HINSTANCE hInst, HWND a_hWnd)
{
	m_hShowBtn = CreateWindow(_T("button"), _T("�Է�"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 10, 100, 30, g_hWnd, (HMENU)IDC_INPUTSHOWBTN, hInst, NULL);

	//------ �𵨸��� ���̾˷α� �ڽ� ����
	m_hDlg = CreateDialogParam(hInst, (LPCTSTR)IDD_DIALOG1, g_hWnd, (DLGPROC)CInputDlg::InputDlgProc, (LPARAM)NULL);
	//------ �𵨸��� ���̾˷α� �ڽ� ����
}

void CMyMain::MainUpdate()
{
}

void CMyMain::MainRender(HDC a_MainDC)
{
}

void CMyMain::MainDestroy()
{
	if (IsWindow(m_hShowBtn)) {
		DestroyWindow(m_hShowBtn);
		m_hShowBtn = NULL;
	}

	if (IsWindow(m_hDlg)) {
		DestroyWindow(m_hDlg);
		m_hDlg = NULL;
	}
}

void CMyMain::On_Move(HWND hWnd)
{
	static RECT a_wRT;
	// �������� �̵��� �Ϸ�Ǿ��� �� �߻��Ǵ� �޽���
	GetWindowRect(hWnd, &a_wRT);

	SetWindowPos(m_hDlg, NULL, g_InputDlg.m_ChildWPos.x + (a_wRT.left - g_InputDlg.m_MainWPos.x), g_InputDlg.m_ChildWPos.y + (a_wRT.top - g_InputDlg.m_MainWPos.y), 0, 0, SWP_NOSIZE);

	g_InputDlg.m_ChildWPos.x = g_InputDlg.m_ChildWPos.x + (a_wRT.left - g_InputDlg.m_MainWPos.x);
	g_InputDlg.m_ChildWPos.y = g_InputDlg.m_ChildWPos.y + (a_wRT.top - g_InputDlg.m_MainWPos.y);

	g_InputDlg.m_MainWPos.x = a_wRT.left;
	g_InputDlg.m_MainWPos.y = a_wRT.top;
}

void CMyMain::On_Size(HWND hWnd)
{
}

void CMyMain::On_MessageHook(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_COMMAND:
	{
		int wmID = LOWORD(wParam);
		// �޴� ������ ���� �м��մϴ�.
		switch (wmID) {
		case IDC_INPUTSHOWBTN:		// �Է� ���̾˷α� �ڽ� Ȱ��ȭ ��ư
			//------ �𵨸��� ���̾˷α� �ڽ� Ȱ��ȭ
			ShowWindow(m_hDlg, SW_SHOW);
			//------ �𵨸��� ���̾˷α� �ڽ� Ȱ��ȭ
			break;
		}	// switch (wmID)
	}	// case WM_COMMAND:
	break;

	//------ �𵨸��� ���̾˷α� �ڽ��� �θ� �����츦 ����ٴϰ� �ϴ� �κ��� ���� �ʱ�ȭ
	case WM_MOVE:
		g_MyMain.On_Move(hWnd);
		break;

	case WM_SIZE:
		g_MyMain.On_Size(hWnd);
		break;
	//------ �𵨸��� ���̾˷α� �ڽ��� �θ� �����츦 ����ٴϰ� �ϴ� �κ��� ���� �ʱ�ȭ
	}	// switch (message)
}

CMyMain g_MyMain;