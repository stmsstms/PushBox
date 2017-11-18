#include "stdafx.h"
#include "Pushbox.h"
#pragma comment(lib, "msimg32.lib")
//函数：pblankground(HDC hdc)
void pblankground(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP blankground = (HBITMAP)LoadImage(NULL, _T("大作业图片\\blankground.bmp"), IMAGE_BITMAP, 900, 600, LR_LOADFROMFILE);
	SelectObject(bmphdc, blankground);
	BitBlt(hdc, x, y, 1000, 1000, bmphdc, 0, 0, SRCCOPY);
}
//函数：pwall(HDC hdc,HDC bmphdc,int x,int y)
void pwall(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP wall = (HBITMAP)LoadImage(NULL, _T("大作业图片\\wall.bmp"), IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	SelectObject(bmphdc, wall);
	BitBlt(hdc, x, y, 1000, 1000, bmphdc, 0, 0, SRCCOPY);
}
//函数：huba(HDC hdc,HDC bmphdc,int x,int y)
void phuba(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP huba = (HBITMAP)LoadImage(NULL, _T("大作业图片\\huba.bmp"), IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	SelectObject(bmphdc, huba);
	TransparentBlt(hdc, x, y, 50, 50, bmphdc, 0, 0, 50, 50, RGB(128, 128, 128));
}
//函数：pheart(HDC hdc,HDC bmphdc,int x,int y)
void pheart(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP heart = (HBITMAP)LoadImage(NULL, _T("大作业图片\\heart.bmp"), IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	SelectObject(bmphdc, heart);
	TransparentBlt(hdc, x, y, 50, 50, bmphdc, 0, 0, 50, 50, RGB(128, 128, 128));
}
//函数：pmxmfloor(HDC hdc,HDC bmphdc,int x,int y)
void pmxmfloor(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP mxmfloor = (HBITMAP)LoadImage(NULL, _T("大作业图片\\mxmfloor.bmp"), IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	SelectObject(bmphdc, mxmfloor);
	BitBlt(hdc, x, y, 1000, 1000, bmphdc, 0, 0, SRCCOPY);
}
//函数：pfloor(HDC hdc,HDC bmphdc,int x,int y)
void pfloor(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP floor = (HBITMAP)LoadImage(NULL, _T("大作业图片\\floor.bmp"), IMAGE_BITMAP, 50, 50, LR_LOADFROMFILE);
	SelectObject(bmphdc, floor);
	BitBlt(hdc, x, y, 1000, 1000, bmphdc, 0, 0, SRCCOPY);
}
//函数：pgamecover(HDC hdc,HDC bmphdc,int x,int y)
void pgamecover(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP gamecover = (HBITMAP)LoadImage(NULL, _T("大作业图片\\gamecover.bmp"), IMAGE_BITMAP, 900, 600, LR_LOADFROMFILE);
	SelectObject(bmphdc, gamecover);
	BitBlt(hdc, x, y, 1000, 1000, bmphdc, 0, 0, SRCCOPY);
}
//函数：pgameend(HDC hdc,HDC bmphdc,int x,int y)
void pgameend(HDC hdc, HDC bmphdc, int x, int y)
{
	HBITMAP gameend = (HBITMAP)LoadImage(NULL, _T("大作业图片\\gameend.bmp"), IMAGE_BITMAP, 900, 600, LR_LOADFROMFILE);
	SelectObject(bmphdc, gameend);
	BitBlt(hdc, x, y, 1000, 1000, bmphdc, 0, 0, SRCCOPY);
}