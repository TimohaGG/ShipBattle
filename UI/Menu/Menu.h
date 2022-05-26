#pragma once
#include"../../Core/Entities/Player/Player.h"
void printRules();
char LoadFields;

struct Menu {
	Menu(Player& a, Player& b) {
		int choise;
		cout << "Добро пожаловать в морской бой!!!" << endl;
		do {
			cout << "1. Выбрать режим игры" << endl << "2. Правила игры" << endl << "3. Выход" << endl;
			cin >> choise;
			system("cls");
			switch (choise) {
			case 1:
				Gamemode(a.autoPut, b.autoPut, a.autoPlay, b.autoPlay);
				break;
			case 2:
				printRules();
				break;
			default:exit(0);
			}
			system("cls");
		} while (choise != 1);
		/*do
		{
			cout << "1. Новая игра" << endl;
			cout << "2. Продолжить игру" << endl;
			cin >> choise;
			switch (choise)
			{
			case 1: {
				int playerNumber = 1;
				a.SettingFlot(playerNumber);
				playerNumber = 2;
				b.SettingFlot(playerNumber); }break;
			case 2: {
				LoadGame(a, "Files\\Player 1.bin");
				LoadGame(b, "Files\\Player 2.bin");
				}break;
			default:
				break;
			}
			break;
		} while (true);*/
		/*int playerNumber = 1;
		a.SettingFlot(playerNumber);
		playerNumber = 2;
		b.SettingFlot(playerNumber);*/
		cout << "Нажмите любую клавишу что бы начать игру" << endl;
		_getch();
	}
	void StartGame(Player a, Player b) {
		bool turn = true;
		bool gameOver = false;
		while (!gameOver) {
			while (turn) {
				gameOver=a.PlayerTurn(a,b, 1,turn);
			}
			while (!turn) {
				gameOver=b.PlayerTurn(b,a, 2,turn);
			}
		}
	}
};


void printRules() {

	cout << "Правила игры в морской бой" << endl;
	cout << "1.\t= - пустая клетка " << endl << "\tS - корабль " << endl << "\tХ - Уничтоженый корабль" << endl;
	cout << "2.\tКорабли нельзя располагать рядом друг с другом" << endl << "\t(только так)\n";
	cout << "\t  0 1 2 3 4 5 6 7 8 9" << endl << "\tA = = = = = = = = = =" << endl << "\tB = = = = = S S S = =" << endl << "\tC = = S S S = = = = =" << endl << "\tD = = = = = = = = = =" << endl;
	system("pause");
	system("cls");
}