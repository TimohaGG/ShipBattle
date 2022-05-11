#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<string>

#define width 10
using std::cin;
using std::cout;
using std::string;
using std::endl;


struct ship {
	int x = 0;
	int y = 0;
	int direction = 0;
	int deckNum = 0;
	bool isDestroyed = false;
};
