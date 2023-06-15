#include <iostream>
#include <windows.h>
#include <wingdi.h>
#include <string>

using namespace std;

static class BmpDrawer
{
public:
	static void Hdc2Bmp(string const& filename, HDC hdc, int width, int height);

private:
	static HDC CopyHDC(HDC hdc, int width, int height);
	static BITMAPFILEHEADER BitmapFileHeaderFactory(int width, int height);
	static BITMAPINFOHEADER BitmapInfoHeaderFactory(int width, int height);
};
