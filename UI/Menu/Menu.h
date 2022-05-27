#pragma once
#include"../../Core/Entities/Player/Player.h"
void printRules();
char LoadFields;

struct Menu {
	Menu(Player& a, Player& b) {
		int choise;
		cout << "����� ���������� � ������� ���!!!" << endl;
		do {
			cout << "1. ����� ����" << endl << "2. ���������� ����" << endl << "3. ������� ����" << endl << "4. �����" << endl;
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
	
		cout << "������� ����� ������� ��� �� ������ ����" << endl;
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

	cout << "������� ���� � ������� ���" << endl;
	cout << "1.\t= - ������ ������ " << endl << "\tS - ������� " << endl << "\t� - ����������� �������" << endl;
	cout << "2.\t������� ������ ����������� ����� ���� � ������" << endl << "\t(������ ���)\n";
	cout << "\t  0 1 2 3 4 5 6 7 8 9" << endl << "\tA = = = = = = = = = =" << endl << "\tB = = = = = S S S = =" << endl << "\tC = = S S S = = = = =" << endl << "\tD = = = = = = = = = =" << endl;
	cout << "3.\t��� ���������� ���� ������� \"save\""<<endl;
	system("pause");
	system("cls");
}