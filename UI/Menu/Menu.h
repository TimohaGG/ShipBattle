#pragma once
#include"../../Core/Entities/Player/Player.h"
void printRules();
char LoadFields;

struct Menu {
	Menu(Player& a, Player& b) {
		int choise;
		cout << "����� ���������� � ������� ���!!!" << endl;
		do {
			cout << "1. ������� ����� ����" << endl << "2. ������� ����" << endl << "3. �����" << endl;
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
			cout << "1. ����� ����" << endl;
			cout << "2. ���������� ����" << endl;
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
	system("pause");
	system("cls");
}