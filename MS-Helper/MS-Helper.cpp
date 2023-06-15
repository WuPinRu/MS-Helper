#include "Utilities/Helper.h"
#include "Utilities/BmpDrawer.h" 

int main()
{
	// Set up window's title.
	system("title MS Helper");

	// Get the target window.
	HWND hWindow = FindWindow(0, L"MapleStory");
	if (hWindow == NULL)
	{
		cout << "Window not found." << endl;
		return 0;
	}

	// Get the target graphic context.
	HDC hContext = GetDC(hWindow);
	if (hContext == NULL)
	{
		cout << "Context not found." << endl;
		return 0;
	}

	// Generate the BMP picture file.
	//BmpDrawer::Hdc2Bmp("data.bmp", hContext, 1280, 720);

	// Start the process.
	Helper::Processing(hWindow, hContext);
	return 0;
}
