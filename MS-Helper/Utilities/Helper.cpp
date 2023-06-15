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
	// Buffer for preparation.
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
	// Print the color value of the specified pixel. (as a state checkpoint)
	PrintColor(hContext, 465, 465, 3, 30);
#else
	// Input the current collect times to initial data.
	int nCurrentTimes = 0;
	int nMaxTimes = 4000;
	cout << "Current Times: ";
	cin >> nCurrentTimes;
	// Set the window to the top of the stack.
	SetForegroundWindow(hWindow);
	// Start button wizard!
	while (nCurrentTimes < nMaxTimes)
	{
		Key(CTRL);
		Sleep(1000);	// Wait for gamania window popup delay.
		if (GetPixel(hContext, 465, 465) == 56746 && GetPixel(hContext, 555, 345) == 255)
		{
			Key(DOWN);
			Key(DOWN);
			Key(CTRL);
			Key(CTRL);
			Key(DOWN);
			Key(CTRL);
			Key(CTRL);
		}
		else
		{
			nCurrentTimes++;
			cout << "Get Suger! " << nCurrentTimes << "/" << nMaxTimes << endl;
		}
	}
#endif
}

void Helper::Key(int nKeyCode)			// Press & Release.
{
	//cout << "Key press: " << nKeyCode << endl;
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | 0, 0);
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(KeyDelayMs);
}

void Helper::KeyHold(int nKeyCode)		// Hold the key.
{
	//cout << "Key hold: " << nKeyCode << endl;
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | 0, 0);
	Sleep(KeyDelayMs);
}

void Helper::KeyRelease(int nKeyCode)	// Release the key.
{
	//cout << "Key release: " << nKeyCode << endl;
	keybd_event(nKeyCode, MapVirtualKey(nKeyCode, 0), KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(KeyDelayMs);
}
