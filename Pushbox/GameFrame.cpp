// Win32Project5.cpp : 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Pushbox.h"
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

#define MAX_LOADSTRING 100
#define FRAMENUMBER 15
#define PICTURE 20
// 全局变量:
HINSTANCE hInst;								// 当前实例
TCHAR szTitle[MAX_LOADSTRING];					// 标题栏文本
TCHAR szWindowClass[MAX_LOADSTRING];			// 主窗口类名
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
int px3 = 6, py3 = 5, power3 = 4;//地图
int i = 1;//当前地图序号
int pwr = 0;//当前法阵启动数

			// 此代码模块中包含的函数的前向声明:
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

	// TODO: 在此放置代码。


	MSG msg;
	HACCEL hAccelTable;
	


																								 // 初始化全局字符串
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_PUSHBOX, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 执行应用程序初始化:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PUSHBOX));

	// 主消息循环:
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
//  函数: MyRegisterClass()
//
//  目的: 注册窗口类。
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
//   函数: InitInstance(HINSTANCE, int)
//
//   目的: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // 将实例句柄存储在全局变量中

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
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目的: 处理主窗口的消息。
//
//  WM_COMMAND	- 处理应用程序菜单
//  WM_PAINT	- 绘制主窗口
//  WM_DESTROY	- 发送退出消息并返回
//
//


// “关于”框的消息处理程序。
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
		// 分析菜单选择:
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
		PlaySound(_T("大作业声音\\gamecover.wav"), NULL, SND_FILENAME | SND_ASYNC);
		break;
		//响应鼠标消息模块
	case WM_LBUTTONDOWN:
		PlaySound(_T("大作业声音\\mapbegin.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
		//响应鼠标消息模块
		//响应键盘消息模块
	case WM_KEYDOWN:


		switch (wParam)
		{
			//按下上方向键模块
		case VK_UP:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px][py - 1])
			{
				//上一格heartmxm
			case 34:
				switch (map[px][py - 2])
				{

					//上二格wall
				case 1:
					break;
					//上二格heart
				case 3:
					break;
					//上二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px][py - 1] = 24;
						map[px][py - 2] = 34;
						py--;
						break;
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px][py - 1] = 24;
						map[px][py - 2] = 34;
						py--;
						break;
					default:
						break;
					}

					break;
					//上二格heartmxm
				case 34:

					break;
					//上二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//上一格wall
			case 1:
				break;
				//上一格heart
			case 3:
				switch (map[px][py - 2])
				{
					//上二格wall
				case 1:
					break;
					//上二格heart
				case 3:
					break;
					//上二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{

							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py - 2] = 34;
						map[px][py - 1] = 2;
						map[px][py] = 5;
						py--;
						pwr++;
						break;
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y >= py * 50 - 50; y = y - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y - 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
					//上二格heartmxm
				case 34:
					break;
					//上二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//上一格mxm
			case 4:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50, py * 50 - 50);
					phuba(hdc, bmphdc, px * 50, py * 50 - 50);
					map[px][py - 1] = 24;
					map[px][py] = 5;
					py--;
					break;
					//本格huba&mxm
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
				//上一格floor
			case 5:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50, py * 50 - 50);
					phuba(hdc, bmphdc, px * 50, py * 50 - 50);
					map[px][py - 1] = 2;
					map[px][py] = 5;
					py--;
					break;
					//本格huba&mxm
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
			//按下上方向键模块结束
			//按下下方向键模块
		case VK_DOWN:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px][py + 1])
			{
				//下一格heartmxm
			case 34:
				switch (map[px][py + 2])
				{

					//下二格wall
				case 1:
					break;
					//下二格heart
				case 3:
					break;
					//下二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px][py + 1] = 24;
						map[px][py + 2] = 34;
						py++;
						break;
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px][py + 1] = 24;
						map[px][py + 2] = 34;
						py++;
						break;
					default:
						break;
					}

					break;
					//下二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//下一格wall
			case 1:
				break;
				//下一格heart
			case 3:
				switch (map[px][py + 2])
				{
					//下二格wall
				case 1:
					break;
					//下二格heart
				case 3:
					break;
					//下二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py + 2] = 34;
						map[px][py + 1] = 2;
						map[px][py] = 5;
						py++;
						pwr++;
						break;
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; y <= py * 50 + 50; y = y + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
							pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 100);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x, y + 50);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
					//下二格heartmxm
				case 34:
					break;
					//下二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//下一格mxm
			case 4:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50, py * 50 + 50);
					phuba(hdc, bmphdc, px * 50, py * 50 + 50);
					map[px][py + 1] = 24;
					map[px][py] = 5;
					py++;
					break;
					//本格huba&mxm
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

				//下一格floor
			case 5:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50, py * 50 + 50);
					phuba(hdc, bmphdc, px * 50, py * 50 + 50);
					map[px][py + 1] = 2;
					map[px][py] = 5;
					py++;
					break;
					//本格huba&mxm
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
			//按下下方向键模块结束
			//按下左方向键模块
		case VK_LEFT:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px - 1][py])
			{
				//左一格heartmxm
			case 34:
				switch (map[px - 2][py])
				{

					//左二格wall
				case 1:
					break;
					//左二格heart
				case 3:
					break;
					//左二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px - 1][py] = 24;
						map[px - 2][py] = 34;
						px--;
						break;
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px - 1][py] = 24;
						map[px - 2][py] = 34;
						px--;
						break;
					default:
						break;
					}

					break;
					//左二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//左一格wall
			case 1:
				break;
				//左一格heart
			case 3:
				switch (map[px - 2][py])
				{
					//左二格wall
				case 1:
					break;
					//左二格heart
				case 3:
					break;
					//左二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px - 2][py] = 34;
						map[px - 1][py] = 2;
						map[px][py] = 5;
						px--;
						pwr++;
						break;
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x >= px * 50 - 50; x = x - 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 - 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x - 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
					//左二格heartmxm
				case 34:
					break;
					//左二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//左一格mxm
			case 4:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50 - 50, py * 50);
					phuba(hdc, bmphdc, px * 50 - 50, py * 50);
					map[px - 1][py] = 24;
					map[px][py] = 5;
					px--;
					break;
					//本格huba&mxm
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
				//左一格floor
			case 5:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50 - 50, py * 50);
					phuba(hdc, bmphdc, px * 50 - 50, py * 50);
					map[px - 1][py] = 2;
					map[px][py] = 5;
					px--;
					break;
					//本格huba&mxm
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
			//按下左方向键模块结束
			//按下右方向键模块
		case VK_RIGHT:
			hdc = GetDC(hWnd);
			bmphdc = CreateCompatibleDC(hdc);
			switch (map[px + 1][py])
			{
				//右一格heartmxm
			case 34:
				switch (map[px + 2][py])
				{

					//右二格wall
				case 1:
					break;
					//右二格heart
				case 3:
					break;
					//右二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}

						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 5;
						map[px + 1][py] = 24;
						map[px + 2][py] = 34;
						px++;
						break;
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px][py] = 4;
						map[px + 1][py] = 24;
						map[px + 2][py] = 34;
						px++;
						break;
					default:
						break;
					}

					break;
					//右二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格hubamxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//右一格wall
			case 1:
				break;
				//右一格heart
			case 3:
				switch (map[px + 2][py])
				{
					//右二格wall
				case 1:
					break;
					//右二格heart
				case 3:
					break;
					//右二格mxm
				case 4:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						map[px + 2][py] = 34;
						map[px + 1][py] = 2;
						map[px][py] = 5;
						px++;
						pwr++;
						break;
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
						for (x = px * 50, y = py * 50; x <= px * 50 + 50; x = x + 1.0 * 50 / PICTURE)
						{
							pmxmfloor(hdc, bmphdc, px * 50, py * 50);
							pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
							pmxmfloor(hdc, bmphdc, px * 50 + 100, py * 50);
							phuba(hdc, bmphdc, x, y);
							pheart(hdc, bmphdc, x + 50, y);
							Sleep(1.0 * 1000 / FRAMENUMBER);
						}
						PlaySound(_T("大作业声音\\mxmstart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
					//右二格heartmxm
				case 34:
					break;
					//右二格floor
				case 5:
					switch (map[px][py])
					{
						//本格huba
					case 2:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
						//本格huba&mxm
					case 24:
						PlaySound(_T("大作业声音\\moveheart.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				//右一格mxm
			case 4:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pmxmfloor(hdc, bmphdc, px * 50 + 50, py * 50);
					phuba(hdc, bmphdc, px * 50 + 50, py * 50);
					map[px + 1][py] = 24;
					map[px][py] = 5;
					px++;
					break;
					//本格huba&mxm
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
				//右一格floor
			case 5:
				switch (map[px][py])
				{
					//本格huba
				case 2:
					pfloor(hdc, bmphdc, px * 50, py * 50);
					pfloor(hdc, bmphdc, px * 50 + 50, py * 50);
					phuba(hdc, bmphdc, px * 50 + 50, py * 50);
					map[px + 1][py] = 2;
					map[px][py] = 5;
					px++;
					break;
					//本格huba&mxm
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
			//按下右方向键模块结束
		default:
			break;
		}
		//换地图
		if (pwr == power)
		{
			i++;
			pwr = 0;
			switch (i)
			{
			case 2:
				PlaySound(_T("大作业声音\\pass.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(3000);
				PlaySound(_T("大作业声音\\mapbegin.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				PlaySound(_T("大作业声音\\pass.wav"), NULL, SND_FILENAME | SND_ASYNC);
				Sleep(3000);
				PlaySound(_T("大作业声音\\mapbegin.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
				PlaySound(_T("大作业声音\\gameend.wav"), NULL, SND_FILENAME | SND_ASYNC);
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
		//响应键盘消息模块
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}