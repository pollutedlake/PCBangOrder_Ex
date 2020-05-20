#include "framework.h"
#include "CInputDlg.h"
#include "GlobalValue.h"
#include "resource.h"
#include <CommCtrl.h>

CInputDlg::CInputDlg()
{
}

CInputDlg::~CInputDlg()
{
}

void CInputDlg::On_Initdialog(HWND hDlg)
{
	//ShowWindow(GetDlgItem(hDlg, IDC_INFOSTR), SW_HIDE);		// �ݾ��� ���ڶ��ϴ�. �ϴ� ���� ����
}

void CInputDlg::On_IDOK(HWND hDlg)
{
}

void CInputDlg::On_ShowWindow(HWND hDlg, WPARAM wParam)
{
	if (wParam == TRUE) {
		//------ �θ� ������ �������� ������ ��ġ�� ���� �ٵ��� �����ϴ� ���
		static RECT a_wRT;
		GetWindowRect(g_hWnd, &a_wRT);
		
		//------ �θ� ������ �������� ������ ��ġ�� ���� �ٵ��� �����ϴ� ���
	}
}

void CInputDlg::On_Command(HWND hDlg, WPARAM wParam)
{
}

void CInputDlg::On_Notify(HWND hDlg, WPARAM wParam)
{
}

void CInputDlg::On_Paint(HWND hDlg)
{
}

void CInputDlg::On_Destroy()
{
}

void CInputDlg::On_MessageHook(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message) {
	case WM_INITDIALOG:
		On_Initdialog(hDlg);
		break;
	}	// switch (message)
}

bool CInputDlg::CheckCtrlState(WPARAM wParam)
{
	return false;
}

void CInputDlg::ReCalculateCost(HWND hDlg)
{
}

void CInputDlg::ReCalcChange(HWND hDlg, int a_Total)
{
}

void CInputDlg::ClearCtrl(HWND hDlg)
{
}

INT_PTR CInputDlg::InputDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	g_InputDlg.On_MessageHook(hDlg, message, wParam, lParam);

	UNREFERENCED_PARAMETER(lParam);
	switch (message) {
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK) {
			return (INT_PTR)TRUE;
		}
		else if (LOWORD(wParam) == IDCANCEL) {
			ShowWindow(hDlg, SW_HIDE);		// <--- �𵨸��� ���̾˷α� �ڽ����� ���̾˷α� �ڽ� ����� ��
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

CInputDlg g_InputDlg;