#pragma once
#include"../../Core/Entities/Player/Player.h"
void printRules() {

	cout << "������� ���� � ������� ���\n";
	cout << "1.\t= - ������ ������ \n\tS - ������� \n\t� - ����������� �������\n";
	cout << "2.\t������� ������ ����������� ����� ���� � ������\n\t(������ ���)\n";
	cout << "\t  0 1 2 3 4 5 6 7 8 9\n\tA = = = = = = = = = =\n\tB = = = = = S S S = =\n\tC = = S S S = = = = =\n\tD = = = = = = = = = =\n";
	system("pause");
	system("cls");
}

struct Menu {
	Menu(Player a,Player b) {
		int choise;
		cout << "����� ���������� � ������� ���!!!\n";
		do {
			cout << "1. ������� ����� ����\n2. ������� ����\n3. �����\n";
			cin >> choise;
			system("cls");
			switch (choise) {
			case 1:
				Gamemode(a.autoPut, b.autoPut, a.autoPlay, b.autoPlay);
				break;
			case 2:
				printRules();
				break;
			}
			system("cls");
		} while (choise != 1);
		int playerNumber = 1;
		a.SettingFlot(playerNumber);
		playerNumber = 2;
		b.SettingFlot(2);
		cout << "������� ����� ������� ��� �� ������ ����\n";
		_getch();
	}
};