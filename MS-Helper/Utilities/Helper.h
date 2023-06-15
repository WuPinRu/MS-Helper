#include "KeyCode.h"
#include <iostream>
#include <windows.h>
#include <wingdi.h>
#include <string>

using namespace std;

static class Helper
{
public:
	static void PrintColor(HDC hContext, int nPixelX, int nPixelY, float fDuration, int nTimes);
	static void Processing(HWND hWindow, HDC hContext);

private:
	static const int KeyDelayMs = 300;
	static void Key(int nKeyCode);
	static void KeyHold(int nKeyCode);
	static void KeyRelease(int nKeyCode);
};
