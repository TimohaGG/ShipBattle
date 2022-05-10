#pragma once
#include"../../Lib/Lib.h"

struct Player {
	char field[width][width];
	char fieldForKills[width][width];
	bool autoPut = true;
	bool autoPlay=false;
	Player() {
		CreateField(field);
		CreateField(fieldForKills);
		PrintField(field);
	}
	char CreateField(char field[width][width]);
	
	void PrintField(char field[width][width]);
	ship* flot=new ship[10];
	char SettingFlot();
	
};
void Gamemode(bool& autoPut1, bool& autoPut2, bool& autoPlay1, bool& autoPlay2);
