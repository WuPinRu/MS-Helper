#include "BMPDrawer.h"

void BmpDrawer::Hdc2Bmp(string const& filename, HDC hdc, int width, int height)
{
	BITMAPFILEHEADER bfh = BitmapFileHeaderFactory(width, height);
	BITMAPINFOHEADER bih = BitmapInfoHeaderFactory(width, height);

	HDC hdcMem = CopyHDC(hdc, width, height);

	FILE* f;
	fopen_s(&f, filename.c_str(), "wb");
	fwrite(&bfh, 1, sizeof(bfh), f);
	fwrite(&bih, 1, sizeof(bih), f);

	COLORREF color;
	for (int y = height; y > 0; y--) {
		for (int x = 0; x < width; x++) {
			color = GetPixel(hdcMem, x, y);
			int b = color >> 16 & 255;
			int g = color >> 8 & 255;
			int r = color >> 0 & 255;
			fwrite(&b, 1, 1, f);
			fwrite(&g, 1, 1, f);
			fwrite(&r, 1, 1, f);
		}
	}

	fclose(f);
	DeleteDC(hdcMem);
	cout << "Hdc2Bmp process is completed." << endl;
}

HDC BmpDrawer::CopyHDC(HDC hdc, int width, int height)
{
	HDC hdcMem = CreateCompatibleDC(hdc);
	HBITMAP hBmp = CreateCompatibleBitmap(hdc, width, height);
	SelectObject(hdcMem, hBmp);
	BitBlt(hdcMem, 0, 0, width, height, hdc, 0, 0, SRCCOPY);
	return hdcMem;
}

BITMAPFILEHEADER BmpDrawer::BitmapFileHeaderFactory(int width, int height)
{
	BITMAPFILEHEADER bfh;
	memcpy((char*)&bfh.bfType, "BM", 2);
	bfh.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 3 * height * width;
	bfh.bfReserved1 = 0;
	bfh.bfReserved2 = 0;
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	return bfh;
}

BITMAPINFOHEADER BmpDrawer::BitmapInfoHeaderFactory(int width, int height)
{
	BITMAPINFOHEADER bih;
	bih.biSize = sizeof(bih);
	bih.biWidth = width;
	bih.biHeight = height;
	bih.biPlanes = 1;
	bih.biBitCount = 24;
	bih.biCompression = BI_RGB;
	bih.biSizeImage = 3 * height * width;
	bih.biXPelsPerMeter = 2834;
	bih.biYPelsPerMeter = 2834;
	bih.biClrUsed = 0;
	bih.biClrImportant = 0;
	return bih;
}
