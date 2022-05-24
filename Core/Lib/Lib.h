#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>
#include<fstream>

using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::ios;
using std::ifstream;
using std::ofstream;

struct ship {
	int x = 0;
	int y = 0;
	int direction = 0;
	int deckNum = 0;
	bool isDestroyed = false;
};



#define width 10