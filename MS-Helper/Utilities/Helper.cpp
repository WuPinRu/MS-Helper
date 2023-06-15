#define PrintColorMode 0
#include "Helper.h"

void Helper::PrintColor(HDC hContext, int nPixelX, int nPixelY, float fDuration, int nTimes)
{
	float sleepTime = fDuration * 1000.0f / nTimes;
	for (int i = 0; i < nTimes; i++) {
		cout << GetPixel(hContext, nPixelX, nPixelY) << endl;
		Sleep(sleepTime);
	}
}

void Helper::Processing(HWND hWindow, HDC hContext)
{
	// 緩衝預備
	system("pause");
	int nBuffer = 3;
	for (int b = nBuffer; b > 0; --b)
	{
		system("cls");
		cout << "Process will be started in " << b << " seconds." << endl;
		Sleep(1000);
	}
	system("cls");
	cout << "Process start!" << endl;
#if PrintColorMode
	// 抓取指定位置的顏色 (用來提供狀態判斷)
	PrintColor(hContext, 1010, 480, 5, 50);
#else
	// 初始設定
	int nCurrentTimes = 0;
	int nMaxTimes = 4000;
	cout << "Current Times: ";
	cin >> nCurrentTimes;
	// 調整到最前頁
	SetForegroundWindow(hWindow);
	// 正式任務
	while (nCurrentTimes < nMaxTimes)
	{
		Key(CTRL);
		if (GetPixel(hContext, 1010, 480) < 16000000)
		{
			nCurrentTimes++;
			cout << "Get Suger! " << nCurrentTimes << "/" << nMaxTimes << endl;
		}
		else
		{
			Key(DOWN);
			Key(DOWN);
			Key(CTRL);
			Key(CTRL);
			Key(DOWN);
			Key(CTRL);
			Key(CTRL);
		}
	}
#endif
}

void Helper::Key(int nKeyCode)			// 按下 & 彈起
{
	//cout << "Key press: " << nKeyCode << endl;
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | 0, 0);
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(KeyDelayMs);
}

void Helper::KeyHold(int nKeyCode)		// 按住不放
{
	//cout << "Key hold: " << nKeyCode << endl;
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | 0, 0);
	Sleep(KeyDelayMs);
}

void Helper::KeyRelease(int nKeyCode)	// 釋放按鍵
{
	//cout << "Key release: " << nKeyCode << endl;
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(KeyDelayMs);
}
