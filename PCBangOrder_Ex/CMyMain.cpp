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
	m_hShowBtn = CreateWindow(_T("button"), _T("입력"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 10, 10, 100, 30, g_hWnd, (HMENU)IDC_INPUTSHOWBTN, hInst, NULL);

	//------ 모델리스 다이알로그 박스 생성
	m_hDlg = CreateDialogParam(hInst, (LPCTSTR)IDD_DIALOG1, g_hWnd, (DLGPROC)CInputDlg::InputDlgProc, (LPARAM)NULL);
	//------ 모델리스 다이알로그 박스 생성
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
	// 윈도우의 이동이 완료되었을 때 발생되는 메시지
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
		// 메뉴 선택을 구문 분석합니다.
		switch (wmID) {
		case IDC_INPUTSHOWBTN:		// 입력 다이알로그 박스 활성화 버튼
			//------ 모델리스 다이알로그 박스 활성화
			ShowWindow(m_hDlg, SW_SHOW);
			//------ 모델리스 다이알로그 박스 활성화
			break;
		}	// switch (wmID)
	}	// case WM_COMMAND:
	break;

	//------ 모델리스 다이알로그 박스가 부모 윈도우를 따라다니게 하는 부분의 변수 초기화
	case WM_MOVE:
		g_MyMain.On_Move(hWnd);
		break;

	case WM_SIZE:
		g_MyMain.On_Size(hWnd);
		break;
	//------ 모델리스 다이알로그 박스가 부모 윈도우를 따라다니게 하는 부분의 변수 초기화
	}	// switch (message)
}

CMyMain g_MyMain;