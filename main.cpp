#include"UI/Menu/Menu.h"
const int col = 100; // ширина окна консоли
const int row = 40;

int main() {
	setlocale(0,"");
	//--------window size--------
	HANDLE wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
	SMALL_RECT windowSize = { 0,0,col - 1,row - 1 };
	SetConsoleWindowInfo(wHnd, TRUE, &windowSize);
	COORD bufferSize = { col,row }; 	
	SetConsoleScreenBufferSize(wHnd, bufferSize);
	//--------------------------
	
	Player a;
	Player b;
	Menu menu(a,b);
	menu.StartGame(a,b);
}