// Win32Project5.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Pushbox.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

#define MAX_LOADSTRING 100
#define FRAMENUMBER 15
#define PICTURE 20
// ȫ�ֱ���:
HINSTANCE hInst;								// ��ǰʵ��
TCHAR szTitle[MAX_LOADSTRING];					// �������ı�
TCHAR szWindowClass[MAX_LOADSTRING];			// ����������
int map[18][12] = { { 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,1,1,1,0,0,0,0 },{ 0,0,0,0,0,1,4,1,0,0,0,0 },
{ 0,0,1,1,1,1,5,1,0,0,0,0 },{ 0,0,1,4,5,3,3,1,1,1,0,0 },{ 0,0,1,1,1,5,2,3,4,1,0,0 },{ 0,0,0,0,1,3,1,1,1,1,0,0 },
{ 0,0,0,0,1,4,1,0,0,0,0,0 },{ 0,0,0,0,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 } };
int px = 9, py = 6, power = 4;
int map2[18][12] = { { 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,1,1,1,1,1,5,5,5,5,5,5 },{ 0,1,2,5,5,1,1,1,1,1,0,0 },{ 0,1,5,3,3,1,1,5,5,1,0,0 },
{ 0,1,5,3,5,5,5,5,5,1,0,0 },{ 0,1,1,1,1,1,5,5,5,1,0,0 },{ 0,0,0,0,0,1,5,1,1,1,0,0 },{ 0,0,0,1,1,1,5,5,1,0,0,0 },
{ 0,0,0,1,4,4,4,5,1,0,0,0 },{ 0,0,0,1,1,1,1,1,1,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 } };
int px2 = 5, py2 = 2, power2 = 3;
int map3[18][12] = { { 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0, },{ 0,0,0,0,1,1,1,1,0,0,0,0 },{ 0,0,1,1,1,5,5,1,1,0,0,0 },{ 0,0,1,5,3,2,4,4,1,0,0,0 },
{ 0,0,1,5,1,5,4,4,1,0,0,0 },{ 0,0,1,5,1,3,1,1,1,0,0,0 },{ 0,0,1,5,1,5,5,5,1,0,0,0 },{ 0,0,1,5,5,5,3,5,1,0,0,0 },
{ 0,0,1,1,5,3,5,5,1,0,0,0 },{ 0,0,0,1,5,5,1,1,1,0,0,0 },{ 0,0,0,1,1,1,1,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0,0,0,0,0 } };
int px3 = 6, py3 = 5, power3 = 4;//��ͼ
int i = 1;//��ǰ��ͼ���
int pwr = 0;//��ǰ����������

			// �˴���ģ���а����ĺ�����ǰ������:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
void pwall(HDC, HDC, int, int);
void phuba(HDC, HDC, int, int);
void pheart(HDC, HDC, int, int);
void pmxmfloor(HDC, HDC, int, int);
void pfloor(HDC, HDC, int, int);
void pblankground(HDC, HDC, int, int);
void pgamecover(HDC, HDC, int, int);
void pgameend(HDC, HDC, int, int);
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: �ڴ˷��ô��롣


	MSG msg;
	HACCEL hAccelTable;
	


																								 // ��ʼ��ȫ���ַ���
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PUSHBOX, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// ִ��Ӧ�ó����ʼ��:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PUSHBOX));

	// ����Ϣѭ��:
	while (GetMessage(&msg, NULL, 0, 0))
	{

		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}



//
//  ����: MyRegisterClass()
//
//  Ŀ��: ע�ᴰ���ࡣ
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDC_PUSHBOX));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_PUSHBOX);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   ����: InitInstance(HINSTANCE, int)
//
//   Ŀ��: ����ʵ�����������������
//
//   ע��:
//
//        �ڴ˺����У�������ȫ�ֱ����б���ʵ�������
//        ��������ʾ�����򴰿ڡ�
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // ��ʵ������洢��ȫ�ֱ�����

	RECT acrect;
	SetRect(&acrect, 0, 0, 900, 600);
	AdjustWindowRectEx(&acrect, WS_OVERLAPPEDWINDOW, false, NULL);

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		0, 0, acrect.right - acrect.left, acrect.bottom - acrect.top, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  ����: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  Ŀ��: ���������ڵ���Ϣ��
//
//  WM_COMMAND	- ����Ӧ�ó���˵�
//  WM_PAINT	- ����������
//  WM_DESTROY	- �����˳���Ϣ������
//
//


// �����ڡ������Ϣ�������
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	HDC bmphdc;
	int x = 0, y = 0;
	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// �����˵�ѡ��:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		bmphdc = CreateCompatibleDC(hdc);
		pgamecover(hdc, bmphdc, 0, 0);


		ReleaseDC(hWnd, bmphdc);
		EndPaint(hWnd, &ps);
		PlaySound(_T("����ҵ����\\gamecover.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
		//��Ӧ�����Ϣģ��
	case WM_LBUTTONDOWN:
		PlaySound(_T("����ҵ����\\mapbegin.wav"), NULL, SND_FILENAME | SND_ASYNC);
		hdc = GetDC(hWnd);
		bmphdc = CreateCompatibleDC(hdc);
		pblankground(hdc, bmphdc, 0, 0);
		for (x = 0; x <= 17; x++)
			for (y = 0; y <= 11; y++)
			{
				if (map[x][y] == 0)
				{
				}
				else if (map[x][y] == 1)
				{
					pwall(hdc, bmphdc, x * 50, y * 50);
				}
				else if (map[x][y] == 2)
				{
					pfloor(hdc, bmphdc, x * 50, y * 50);
					phuba(hdc, bmphdc, x * 50, y * 50);
				}
				else if (map[x][y] == 3)
				{
					pfloor(hdc, bmphdc, x * 50, y * 50);
					pheart(hdc, bmphdc, x * 50, y * 50);
				}
				else if (map[x][y] == 4)
				{
					pmxmfloor(hdc, bmphdc, x * 50, y * 50);
				}
				else if (map[x][y] == 5)
				{
					pfloor(hdc, bmphdc, x * 50, y * 50);
				}
				else if (map[x][y] == 24)
				{
					pmxmfloor(hdc, bmphdc, x * 50, y * 50);
					phuba(hdc, bmphdc, x * 50, y * 50);

				}
				else
				{
					pmxmfloor(hdc, bmphdc, x * 50, y * 50);
					pheart(hdc, bmphdc, x * 50, y * 50);
				}
			}
		ReleaseDC(hWnd, bmphdc);
		ReleaseDC(hWnd, hdc);
		break;
		//��Ӧ�����Ϣģ��
		//��Ӧ������Ϣģ��
	case WM_KEYDOWN:


		switch (wParam)
		{
			//�����Ϸ����ģ��
		case VK_UP:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px][py - 1])
			{
				//��һ��heartmxm
			case 34:
				switch (map[px][py - 2])
				{

					//�϶���wall
				case 1:
					break;
					//�϶���heart
				case 3:
					break;
					//�϶���mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px][py - 1] = 24;
						map[px][py - 2] = 34;
						py--;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px][py - 1] = 24;
						map[px][py - 2] = 34;
						py--;
						break;
					default:
						break;
					}

					break;
					//�϶���heartmxm
				case 34:

					break;
					//�϶���floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 5;
						map[px][py - 1] = 24;
						map[px][py - 2] = 3;
						py--;
						pwr--;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 4;
						map[px][py - 1] = 24;
						map[px][py - 2] = 3;
						py--;
						pwr--;
						break;
					default:
						break;
					}

					break;

				default:
					break;
				}
				break;
				//��һ��wall
			case 1:
				break;
				//��һ��heart
			case 3:
				switch (map[px][py - 2])
				{
					//�϶���wall
				case 1:
					break;
					//�϶���heart
				case 3:
					break;
					//�϶���mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{

							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py - 2] = 34;
						map[px][py - 1] = 2;
						map[px][py] = 5;
						py--;
						pwr++;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py - 2] = 34;
						map[px][py - 1] = 2;
						map[px][py] = 4;
						py--;
						pwr++;
						break;
					default:
						break;
					}
					break;
					//�϶���heartmxm
				case 34:
					break;
					//�϶���floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py - 2] = 3;
						map[px][py - 1] = 2;
						map[px][py] = 5;
						py--;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py - 2] = 3;
						map[px][py - 1] = 2;
						map[px][py] = 4;
						py--;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;
				//��һ��mxm
			case 4:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
					phuba(hdc, bmphdc, px * 50, py * 50 - 50);
					map[px][py - 1] = 24;
					map[px][py] = 5;
					py--;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
					phuba(hdc, bmphdc, px * 50, py * 50 - 50);
					map[px][py - 1] = 24;
					map[px][py] = 4;
					py--;
					break;
				default:
					break;
				}
				break;
				//��һ��floor
			case 5:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
					phuba(hdc, bmphdc, px * 50, py * 50 - 50);
					map[px][py - 1] = 2;
					map[px][py] = 5;
					py--;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
					phuba(hdc, bmphdc, px * 50, py * 50 - 50);
					map[px][py - 1] = 2;
					map[px][py] = 4;
					py--;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			ReleaseDC(hWnd, bmphdc);
			ReleaseDC(hWnd, hdc);
			break;
			//�����Ϸ����ģ�����
			//�����·����ģ��
		case VK_DOWN:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px][py + 1])
			{
				//��һ��heartmxm
			case 34:
				switch (map[px][py + 2])
				{

					//�¶���wall
				case 1:
					break;
					//�¶���heart
				case 3:
					break;
					//�¶���mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px][py + 1] = 24;
						map[px][py + 2] = 34;
						py++;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px][py + 1] = 24;
						map[px][py + 2] = 34;
						py++;
						break;
					default:
						break;
					}

					break;
					//�¶���floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 5;
						map[px][py + 1] = 24;
						map[px][py + 2] = 3;
						py++;
						pwr--;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 4;
						map[px][py + 1] = 24;
						map[px][py + 2] = 3;
						py++;
						pwr--;
						break;
					default:
						break;
					}

					break;

				default:
					break;
				}
				break;
				//��һ��wall
			case 1:
				break;
				//��һ��heart
			case 3:
				switch (map[px][py + 2])
				{
					//�¶���wall
				case 1:
					break;
					//�¶���heart
				case 3:
					break;
					//�¶���mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py + 2] = 34;
						map[px][py + 1] = 2;
						map[px][py] = 5;
						py++;
						pwr++;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py + 2] = 34;
						map[px][py + 1] = 2;
						map[px][py] = 4;
						py++;
						pwr++;
						break;
					default:
						break;
					}
					break;
					//�¶���heartmxm
				case 34:
					break;
					//�¶���floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py + 2] = 3;
						map[px][py + 1] = 2;
						map[px][py] = 5;
						py++;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py + 2] = 3;
						map[px][py + 1] = 2;
						map[px][py] = 4;
						py++;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;
				//��һ��mxm
			case 4:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
					phuba(hdc, bmphdc, px * 50, py * 50 + 50);
					map[px][py + 1] = 24;
					map[px][py] = 5;
					py++;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
					phuba(hdc, bmphdc, px * 50, py * 50 + 50);
					map[px][py + 1] = 24;
					map[px][py] = 4;
					py++;
					break;
				default:
					break;
				}
				break;

				//��һ��floor
			case 5:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
					phuba(hdc, bmphdc, px * 50, py * 50 + 50);
					map[px][py + 1] = 2;
					map[px][py] = 5;
					py++;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
					phuba(hdc, bmphdc, px * 50, py * 50 + 50);
					map[px][py + 1] = 2;
					map[px][py] = 4;
					py++;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			ReleaseDC(hWnd, bmphdc);
			ReleaseDC(hWnd, hdc);
			break;
			//�����·����ģ�����
			//���������ģ��
		case VK_LEFT:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px - 1][py])
			{
				//��һ��heartmxm
			case 34:
				switch (map[px - 2][py])
				{

					//�����wall
				case 1:
					break;
					//�����heart
				case 3:
					break;
					//�����mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px - 1][py] = 24;
						map[px - 2][py] = 34;
						px--;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px - 1][py] = 24;
						map[px - 2][py] = 34;
						px--;
						break;
					default:
						break;
					}

					break;
					//�����floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 5;
						map[px - 1][py] = 24;
						map[px - 2][py] = 3;
						px--;
						pwr--;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 4;
						map[px - 1][py] = 24;
						map[px - 2][py] = 3;
						px--;
						pwr--;
						break;
					default:
						break;
					}

					break;

				default:
					break;
				}
				break;
				//��һ��wall
			case 1:
				break;
				//��һ��heart
			case 3:
				switch (map[px - 2][py])
				{
					//�����wall
				case 1:
					break;
					//�����heart
				case 3:
					break;
					//�����mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px - 2][py] = 34;
						map[px - 1][py] = 2;
						map[px][py] = 5;
						px--;
						pwr++;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px - 2][py] = 34;
						map[px - 1][py] = 2;
						map[px][py] = 4;
						px--;
						pwr++;
						break;
					default:
						break;
					}
					break;
					//�����heartmxm
				case 34:
					break;
					//�����floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px - 2][py] = 3;
						map[px - 1][py] = 2;
						map[px][py] = 5;
						px--;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px - 2][py] = 3;
						map[px - 1][py] = 2;
						map[px][py] = 4;
						px--;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;
				//��һ��mxm
			case 4:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
					phuba(hdc, bmphdc, px * 50 - 50, py * 50);
					map[px - 1][py] = 24;
					map[px][py] = 5;
					px--;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
					phuba(hdc, bmphdc, px * 50 - 50, py * 50);
					map[px - 1][py] = 24;
					map[px][py] = 4;
					px--;
					break;
				default:
					break;
				}
				break;
				//��һ��floor
			case 5:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
					phuba(hdc, bmphdc, px * 50 - 50, py * 50);
					map[px - 1][py] = 2;
					map[px][py] = 5;
					px--;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
					phuba(hdc, bmphdc, px * 50 - 50, py * 50);
					map[px - 1][py] = 2;
					map[px][py] = 4;
					px--;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			ReleaseDC(hWnd, bmphdc);
			ReleaseDC(hWnd, hdc);
			break;
			//���������ģ�����
			//�����ҷ����ģ��
		case VK_RIGHT:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px + 1][py])
			{
				//��һ��heartmxm
			case 34:
				switch (map[px + 2][py])
				{

					//�Ҷ���wall
				case 1:
					break;
					//�Ҷ���heart
				case 3:
					break;
					//�Ҷ���mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}

						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px + 1][py] = 24;
						map[px + 2][py] = 34;
						px++;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px + 1][py] = 24;
						map[px + 2][py] = 34;
						px++;
						break;
					default:
						break;
					}

					break;
					//�Ҷ���floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 5;
						map[px + 1][py] = 24;
						map[px + 2][py] = 3;
						px++;
						pwr--;
						break;
						//����hubamxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px][py] = 4;
						map[px + 1][py] = 24;
						map[px + 2][py] = 3;
						px++;
						pwr--;
						break;
					default:
						break;
					}

					break;

				default:
					break;
				}
				break;
				//��һ��wall
			case 1:
				break;
				//��һ��heart
			case 3:
				switch (map[px + 2][py])
				{
					//�Ҷ���wall
				case 1:
					break;
					//�Ҷ���heart
				case 3:
					break;
					//�Ҷ���mxm
				case 4:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px + 2][py] = 34;
						map[px + 1][py] = 2;
						map[px][py] = 5;
						px++;
						pwr++;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("����ҵ����\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px + 2][py] = 34;
						map[px + 1][py] = 2;
						map[px][py] = 4;
						px++;
						pwr++;
						break;
					default:
						break;
					}
					break;
					//�Ҷ���heartmxm
				case 34:
					break;
					//�Ҷ���floor
				case 5:
					switch (map[px][py])
					{
						//����huba
					case 2:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);////////////////////////////////////
						}
						map[px + 2][py] = 3;
						map[px + 1][py] = 2;
						map[px][py] = 5;
						px++;
						break;
						//����huba&mxm
					case 24:
						PlaySound(_T("����ҵ����\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						map[px + 2][py] = 3;
						map[px + 1][py] = 2;
						map[px][py] = 4;
						px++;
						break;
					default:
						break;
					}
					break;
				default:
					break;
				}
				break;
				//��һ��mxm
			case 4:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
					phuba(hdc, bmphdc, px * 50 + 50, py * 50);
					map[px + 1][py] = 24;
					map[px][py] = 5;
					px++;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
					phuba(hdc, bmphdc, px * 50 + 50, py * 50);
					map[px + 1][py] = 24;
					map[px][py] = 4;
					px++;
					break;
				default:
					break;
				}
				break;
				//��һ��floor
			case 5:
				switch (map[px][py])
				{
					//����huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
					phuba(hdc, bmphdc, px * 50 + 50, py * 50);
					map[px + 1][py] = 2;
					map[px][py] = 5;
					px++;
					break;
					//����huba&mxm
				case 24:
					pmxmfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
					phuba(hdc, bmphdc, px * 50 + 50, py * 50);
					map[px + 1][py] = 2;
					map[px][py] = 4;
					px++;
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			ReleaseDC(hWnd, bmphdc);
			ReleaseDC(hWnd, hdc);
			break;
			//�����ҷ����ģ�����
		default:
			break;
		}
		//����ͼ
		if (pwr == power)
		{
			i++;
			pwr = 0;
			switch (i)
			{
			case 2:
				PlaySound(_T("����ҵ����\\pass.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(3000);
				PlaySound(_T("����ҵ����\\mapbegin.wav"), NULL, SND_FILENAME | SND_ASYNC);
				for (x = 0; x <= 17; x++)
					for (y = 0; y <= 11; y++)
					{
						map[x][y] = map2[x][y];
					}
				px = px2;
				py = py2;
				power = power2;
				hdc = GetDC(hWnd);
				bmphdc = CreateCompatibleDC(hdc);
				pblankground(hdc, bmphdc, 0, 0);
				for (x = 0; x <= 17; x++)
					for (y = 0; y <= 11; y++)
					{
						if (map[x][y] == 0)
						{
						}
						else if (map[x][y] == 1)
						{
							pwall(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 2)
						{
							pfloor(hdc, bmphdc, x * 50, y * 50);
							phuba(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 3)
						{
							pfloor(hdc, bmphdc, x * 50, y * 50);
							pheart(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 4)
						{
							pmxmfloor(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 5)
						{
							pfloor(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 24)
						{
							pmxmfloor(hdc, bmphdc, x * 50, y * 50);
							phuba(hdc, bmphdc, x * 50, y * 50);

						}
						else
						{
							pmxmfloor(hdc, bmphdc, x * 50, y * 50);
							pheart(hdc, bmphdc, x * 50, y * 50);
						}
					}
				ReleaseDC(hWnd, bmphdc);
				ReleaseDC(hWnd, hdc);
				break;
			case 3:
				PlaySound(_T("����ҵ����\\pass.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(3000);
				PlaySound(_T("����ҵ����\\mapbegin.wav"), NULL, SND_FILENAME | SND_ASYNC);
				for (x = 0; x <= 17; x++)
					for (y = 0; y <= 11; y++)
					{
						map[x][y] = map3[x][y];
					}
				px = px3;
				py = py3;
				power = power3;
				hdc = GetDC(hWnd);
				bmphdc = CreateCompatibleDC(hdc);
				pblankground(hdc, bmphdc, 0, 0);
				for (x = 0; x <= 17; x++)
					for (y = 0; y <= 11; y++)
					{
						if (map[x][y] == 0)
						{
						}
						else if (map[x][y] == 1)
						{
							pwall(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 2)
						{
							pfloor(hdc, bmphdc, x * 50, y * 50);
							phuba(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 3)
						{
							pfloor(hdc, bmphdc, x * 50, y * 50);
							pheart(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 4)
						{
							pmxmfloor(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 5)
						{
							pfloor(hdc, bmphdc, x * 50, y * 50);
						}
						else if (map[x][y] == 24)
						{
							pmxmfloor(hdc, bmphdc, x * 50, y * 50);
							phuba(hdc, bmphdc, x * 50, y * 50);

						}
						else
						{
							pmxmfloor(hdc, bmphdc, x * 50, y * 50);
							pheart(hdc, bmphdc, x * 50, y * 50);
						}
					}
				ReleaseDC(hWnd, bmphdc);
				ReleaseDC(hWnd, hdc);
				break;
			case 4:
				PlaySound(_T("����ҵ����\\gameend.wav"), NULL, SND_FILENAME | SND_ASYNC);
				hdc = GetDC(hWnd);
				bmphdc = CreateCompatibleDC(hdc);
				pgameend(hdc, bmphdc, 0, 0);
				ReleaseDC(hWnd, bmphdc);
				ReleaseDC(hWnd, hdc);
				break;
			default:
				break;
			}
		}
		break;
		//��Ӧ������Ϣģ��
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}