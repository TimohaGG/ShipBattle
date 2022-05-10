#include"Player.h"
char Player::CreateField(char field[width][width]) {
	for (size_t i = 0; i < width; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			field[i][j] = '=';
		}
	}
	return field[width][width];
}


void Player::PrintField(char field[width][width]) {
	char symbol = 65;
	int number = 0;

	for (int i = -1; i < width; i++)
	{
		for (int j = -1; j < width; j++)
		{
			if (i == -1 && j < 0) {
				cout << " ";
			}
			else if (i == -1 && j < width) {
				cout << " " << symbol;
				symbol++;
			}
			else if (i >= 0 && j == -1 && i < width + 1) {
				cout << number;
				number++;
			}
			else if (i != -1 && j != -1) {
				cout << " " << field[i][j];
			}
			else {
				cout << " ";
			}

		}
		cout << "\n";
	}
	cout << "\n" << "\n";
}

bool putMode() {

	cout << "1. Автоматическая расстановка кораблей\n2. Ручная расстановка кораблей\n";
	int choise;
	cin >> choise;
	switch (choise) {
	case 1: {
		return true;
		break;
	}
	case 2: {
		return false;
		break;
	}
	}
}

void Gamemode(bool& autoPut1, bool& autoPut2, bool& autoPlay1, bool& autoPlay2)
{
	cout << "1.Одиночный режим\n2. Мультиплеер\n";
	int choise;
	cin >> choise;
	system("cls");
	switch (choise) {
	case 1: {
		autoPut1 = putMode();
		autoPut2 = true;
		autoPlay2 = true;
		break;
	}
	case 2: {
		cout << "Игрок 1 выбирает расстановку:\n";
		autoPut1 = putMode();
		system("cls");
		cout << "Игрок 2 выбирает расстановку:\n";
		autoPut2 = putMode();
		break;
	}
	}
}



int changeLetter(char symbol) {
	switch (symbol) {
	case 'A':
		return 0;
		break;
	case'B':
		return 1;
		break;
	case 'C':
		return 2;
		break;
	case 'D':
		return 3;
		break;
	case 'E':
		return 4;
		break;
	case 'F':
		return 5;
		break;
	case 'G':
		return 6;
		break;
	case 'H':
		return 7;
		break;
	case'I':
		return 8;
		break;
	case 'J':
		return 9;
		break;
	}

}

bool setCoordinates(int& x, int& y, bool bot, char field[width][width]) {
	//ставим первую координату и проверем нет ли на ней корабля
	char xStr;
	string yStr;
	do {
		if (bot) {
			x = rand() % 9;
			y = rand() % 9;
		}
		else {
			do {
				cout << "Введите Х\n";
				cin >> xStr;
			} while (xStr < 65 || xStr>74);
			x = changeLetter(xStr);
			do {
				cout << "Введите У\n";
				cin >> yStr;
			} while (yStr < "0" || yStr>"9" || yStr.length() > 1);
			y = stoi(yStr);
		}
	} while (field[y][x] == 'S');
	return true;
}

char setShip(char field[width][width], int direction, int decks, int x, int y) {
	for (size_t i = 0; i < decks; i++)
	{
		switch (direction) {
		case 0: {
			field[y][x] = 'S';
			break;
		}
		case 1: {
			field[y][x + i] = 'S';
			break;
		}
		case 2: {
			field[y][x - i] = 'S';
			break;
		}
		case 3: {
			field[y + i][x] = 'S';
			break;
		}
		case 4: {
			field[y - i][x] = 'S';
			break;
		}

		}
	}
	return field[width][width];
}

bool directionChose(int x, int y, int decks, char field[width][width], int& direction, bool bot) {
	//Эта функция проверяет нет ли на пути других кораблей и выход за поле
	if (decks > 1) {
		if (bot) {
			direction = rand() % (5 - 1) + 1;
		}
		else {
			cout << "В какую сторону продолжить корабль?\n1. Впрво\n2. Влево\n3. Вниз\n4. Вверх\n";
			cin >> direction;
		}
		for (size_t i = 0; i < decks; i++)
		{
			switch (direction) {
			case 1: {
				if (field[y][x + i] == 'S' || x + i >= 10)
					return false;
				break;
			}
			case 2: {
				if (field[y][x - i] == 'S')
					return false;
				else if (x - i == -1) {
					return false;
				}
				break;
			}
			case 3: {
				if (field[y + i][x] == 'S' || y + i >= 10)
					return false;
				break;
			}
			case 4: {
				if (field[y - i][x] == 'S' || y - i == -1)
					return false;
				break;
			}
			}
		}
	}
	else {
		direction = 0;
	}
	return true;
}

bool checkSides(int decks, int x, int y, char field[width][width], int direction) {
	for (size_t i = 1; i < decks + 1; i++)
	{
		if (x + 1 <= 9)
			if (field[y][x + 1] == 'S')
				return false;
		if (x - 1 >= 0)
			if (field[y][x - 1] == 'S')
				return false;
		if (y + 1 <= 9)
			if (field[y + 1][x] == 'S')
				return false;
		if (y - 1 >= 0)
			if (field[y - 1][x] == 'S')
				return false;
		switch (direction) {
		case 0:
			return true;
		case 1: {
			x += 1;
			break;
		}
		case 2: {
			x -= 1;
			break;
		}
		case 3: {
			y += 1;
			break;
		}
		case 4: {
			y -= 1;
			break;
		}
		}
	}
}

char Player::SettingFlot()
{
	int shipTotal = 0;
	for (size_t decks = 1, shipAmount = 4; decks <= 4; decks++, shipAmount--)//decks amount
	{
		for (int shipNumber = 0; shipNumber < shipAmount; shipNumber++) {//amount of ships
			int x, y, direction;

			while (!setCoordinates(x, y, autoPut, field) || !directionChose(x, y, decks, field, direction,autoPut) || !checkSides(decks, x, y, field, direction)) {
				if (!autoPut) {
					cout << "Ошибка постановки корабля!!!\n";
					system("pause");
					system("cls");
					if (!autoPlay)PrintField(field);
				}
			}
			flot[shipTotal].x = x;
			flot[shipTotal].y = y;
			flot[shipTotal].direction = direction;
			flot[shipTotal].deckNum = decks;
			shipTotal++;
			system("cls");
			setShip(field, direction, decks, x, y);
			if (!autoPut)PrintField(field);

			if (!autoPut)system("pause");
		}
	}
	return field[width][width];
}
