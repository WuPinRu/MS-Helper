#include "Utilities/Helper.h"
#include "Utilities/BmpDrawer.h" 

int main()
{
	// 設定視窗標題
	system("title 楓之谷小幫手");
	// 抓取視窗
	HWND hWindow = FindWindow(0, L"MapleStory");
	if (hWindow == NULL)
	{
		cout << "Window not found." << endl;
		return 0;
	}
	// 取得視窗繪圖內容
	HDC hContext = GetDC(hWindow);
	if (hContext == NULL)
	{
		cout << "Context not found." << endl;
		return 0;
	}
	// 產生圖片
	//BmpDrawer::Hdc2Bmp("data.bmp", hContext, 1920, 1080);
	// 執行任務
	Helper::Processing(hWindow, hContext);
	return 0;
}
