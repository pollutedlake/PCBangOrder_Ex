#pragma once

//------ �޴� ���� ����
enum FoodType {
	NOODLE = 0,		// ����
	DRINK = 1,		// �����
	ETC = 2,		// ��Ÿ
	SNACK = 3		// ����
};

enum ETCKind {
	Mandu = 0,		// ����
	Sausage = 1,	// �Ҽ���
	HotBar = 2		// �ֹ�
};

enum ETCCombo {
	EC_Unselect = 0,			// ���þ���
	Add_Ketchup = 1,			// ����
	Add_Mustard = 2,			// �ӽ��͵�
	Add_GanJang = 3,			// ����
	Add_Ketchup_Mustard = 4		// ���� + �ӽ��͵�
};
//------ �޴� ���� ����

extern HWND g_hWnd;