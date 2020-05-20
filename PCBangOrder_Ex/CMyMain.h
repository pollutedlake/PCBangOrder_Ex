#pragma once

#define IDC_INPUTSHOWBTN 1100		// 버튼 컨트롤 ID 1000번대이면 아무번호나 상관없다.

class CMyMain
{
	HWND m_hDlg;		// 모델리스 다이알로그 박스 핸들
	HWND m_hShowBtn;

public:
	CMyMain();
	~CMyMain();

public:
	void MainInit(HINSTANCE hInst, HWND a_hWnd);		// 초기화 함수
	void MainUpdate();									// 게임의 연산 담당부분
	void MainRender(HDC a_MainDC);						// 게임의 그리기 부분
	void MainDestroy();

	void On_Move(HWND hWnd);
	void On_Size(HWND hWnd);
	void On_MessageHook(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

extern CMyMain g_MyMain;