#pragma once

//------ 메뉴 관련 변수
enum FoodType {
	NOODLE = 0,		// 국수
	DRINK = 1,		// 음료수
	ETC = 2,		// 기타
	SNACK = 3		// 스택
};

enum ETCKind {
	Mandu = 0,		// 만두
	Sausage = 1,	// 소세지
	HotBar = 2		// 핫바
};

enum ETCCombo {
	EC_Unselect = 0,			// 선택안함
	Add_Ketchup = 1,			// 케찹
	Add_Mustard = 2,			// 머스터드
	Add_GanJang = 3,			// 간장
	Add_Ketchup_Mustard = 4		// 케찹 + 머스터드
};
//------ 메뉴 관련 변수

extern HWND g_hWnd;