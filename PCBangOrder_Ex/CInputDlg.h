#pragma once
class CInputDlg
{
	bool m_isCtrlChange = false;		// 뭔가 유자가 컨트롤을 건드렸을 때를 감지하기 위한 변수
	int m_Total = 0;					// 계산된 금액
	int m_SubKind = -1;					// 라디오버튼 선택 사항 (만두, 소세지, 핫바...)
	int m_SubCombo = -1;				// 옵션 (케찹, 머스타드, 간장...)
	int m_Su = 0;						// 수량
	int m_Point = 0;					// 포인트 사용 금액 변수

public:
	//------ 모델리스 다이알로그 박스가 부모 윈도우를 따라다니게 하는 부분의 변수
	POINT m_MainWPos;
	POINT m_ChildWPos;
	POINT m_DlgSize;
	POINT m_MWTopLeft;
	//------ 모델리스 다이알로그 박스가 부모 윈도우를 따라다니게 하는 부분의 변수

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

	bool CheckCtrlState(WPARAM wParam);		// 컨트롤들의 변화를 감지하는 함수
	void ReCalculateCost(HWND hDlg);		// 컨트롤들의 변화가 발생하면 비용을 다시 계산해 주는 함수
	void ReCalcChange(HWND hDlg, int a_Total);		// 거스름돈 계산 함수
	void ClearCtrl(HWND hDlg);		// 컨트롤 선택 사항을 모두 초기화 해 주는 함수

public:
	static INT_PTR CALLBACK InputDlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

extern CInputDlg g_InputDlg;

