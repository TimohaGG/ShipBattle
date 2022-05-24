#pragma once
#include"../../Lib/Lib.h"

struct Player {
	//--------fields---------
	char field[width][width];
	char fieldForKills[width][width];
	bool autoPut = true;
	bool autoPlay=false;
	ship* flot = new ship[10];
	//--------constructor---------
	Player() {
		CreateField(field);
		CreateField(fieldForKills);
	}
	//--------methods---------
	char CreateField(char field[width][width]);
	void PrintField(char field[width][width]);
	char SettingFlot(int player);
	bool PlayerTurn(Player& a,Player& b, int playerNum, bool& turn);
};
void Gamemode(bool& autoPut1, bool& autoPut2, bool& autoPlay1, bool& autoPlay2);
void SaveGameProgress(char field[width][width]);