#pragma once
#include"../../Core/Entities/Player/Player.h"
void printRules();
char LoadFields;

struct Menu {
	Menu(Player& a, Player& b) {
		int choise;
		cout << "Добро пожаловать в морской бой!!!" << endl;
		do {
			cout << "1. Новая игра" << endl << "2. Продолжить игру" << endl << "3. Правила игры" << endl << "4. Выход" << endl;
			cin >> choise;
			system("cls");
			switch (choise) {
			case 1: {
				Gamemode(a.autoPut, b.autoPut, a.autoPlay, b.autoPlay);
				int playerNumber = 1;
				a.SettingFlot(playerNumber);
				playerNumber = 2;
				b.SettingFlot(playerNumber);
			}break;
			case 2: {
				LoadGame(a, "Files\\Player 1.bin", "Files\\Player 1 Flot.bin");
				LoadGame(b, "Files\\Player 2.bin", "Files\\Player 2 Flot.bin");
			}break;
			
			case 3:
				printRules();
				break;
			default:exit(0);
			}
			system("cls");
		} while (choise != 1&&choise!=2);
	
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
	cout << "3.\tДля сохранения игры введите \"save\""<<endl;
	system("pause");
	system("cls");
}