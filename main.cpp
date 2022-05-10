#include"Core/Entities/Player/Player.h"
int main() {
	setlocale(0,"");
	Player a;
	Player b;
	Gamemode(a.autoPut, b.autoPut, a.autoPlay, b.autoPlay);
	a.SettingFlot();
	a.PrintField(a.field);
}