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
		cout << "����� 1 ����������� �������...\n";
		system("pause");
		a.SettingFlot();
		a.PrintField(a.field);
		cout << "������� ������� �����������!\n";
		system("pause");
		system("cls");
		cout << "����� 2 ����������� �������...\n";
		system("pause");
		b.SettingFlot();
		if(!b.autoPlay)b.PrintField(b.field);
		cout << "������� ����� ������� ��� �� ������ ����\n";
		_getch();
	}
};