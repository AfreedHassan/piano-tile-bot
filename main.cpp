#include <iostream>
#include <windows.h>
#include <conio.h>

//find position of tile;
//if tile found, move mouse to it and click.
//repeat


//Tile 1: (720,400)
//Tile 2: (880,400)
//Tile 3: (1030,400)
//Tile 4: (1180,400)


int tile1[2] {720,600};

int tile2[2] {880,600};

int tile3[2] {1030,600};

int tile4[2] {1180,600};

//color black: (0,0,0)

const int targetColor[3] = {0,0,0};

const COLORREF rgbBlack =  0x00000000; //from microsoft's website

const int KEY_Q = 0x51;

using namespace std;

bool checkColor(COLORREF c);

void displayPixelColor(COLORREF c);

void mouseClick(int*); 

void mainScript();

int main() {
	Sleep(2000); // wait 2s;
	mainScript();
    return 0;
}

void mainScript() {
	while (!(GetAsyncKeyState(KEY_Q) && 0x01)) { // while 'q' is not pressed, or has not been pressed (essentially) continue.
		HDC hdc = GetDC(NULL);

		COLORREF point1 = GetPixel(hdc, tile1[0],tile1[1]);
		COLORREF point2 = GetPixel(hdc, tile2[0],tile2[1]);
		COLORREF point3 = GetPixel(hdc, tile3[0],tile3[1]);
		COLORREF point4 = GetPixel(hdc, tile4[0],tile4[1]);
		

		if (checkColor(point1)) mouseClick(tile1);

		if (checkColor(point2)) mouseClick(tile2);

		if (checkColor(point3)) mouseClick(tile3);
		
		if (checkColor(point4)) mouseClick(tile4);

		ReleaseDC(NULL, hdc);
	}
}

bool checkColor(COLORREF c) {
	int* pixelColor = new int[3] {(int)GetRValue(c),(int)GetGValue(c),(int)GetBValue(c)};
	bool same = (pixelColor[0] == targetColor[0] && pixelColor[1] == targetColor[1] && pixelColor[2] == targetColor[2]);
	delete[] pixelColor;
	return same;
}

int* getPixelColor(COLORREF c) {
	int* color = new int[3] {(int)GetRValue(c),(int)GetGValue(c),(int)GetBValue(c)};
	return color;
}

void displayPixelColor(COLORREF c) {
	cout<<"("; 
	cout<<(int)GetRValue(c)<<", "; 
	cout<<(int)GetGValue(c)<<", "; 
	cout<<(int)GetBValue(c)<<")";	
}

void mouseClick(int* pos) {
	SetCursorPos(pos[0],pos[1]);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(50); 
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}