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
		cout << endl;
	}
	cout << endl << endl;
}

bool putMode() {

	cout << "1. Автоматическая расстановка кораблей"<<endl<<"2. Ручная расстановка кораблей"<<endl;
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
	cout << "1.Одиночный режим"<<endl<<"2. Мультиплеер"<<endl;
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
		cout << "Игрок 1 выбирает расстановку:"<<endl;
		autoPut1 = putMode();
		system("cls");
		cout << "Игрок 2 выбирает расстановку:" << endl;
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
	
	string yStr;
	do {
		if (bot) {
			x = rand() % 9;
			y = rand() % 9;
		}
		else {
			string coords;
			do {
				
				cout << "Куда ставить корабль (Например А5)?" << endl;
				cin >> coords;
			} while (coords.length()!=2 || coords[0] < 'A' || coords[0]>'J'||!isdigit(coords[1]));
			x = changeLetter(coords[0]);
			yStr = coords[1];
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
			cout << "В какую сторону продолжить корабль?"<<endl<<"1. Впрво" << endl << "2. Влево" << endl << "3. Вниз" << endl << "4. Вверх" << endl;
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

char Player::SettingFlot(int player)
{
	cout << "Игрок "<<player<<" расставляет корабли..." << endl;
	PrintField(field);
	system("pause");
	int shipTotal = 0;
	for (size_t decks = 1, shipAmount = 4; decks <= 4; decks++, shipAmount--)//decks amount
	{
		for (int shipNumber = 0; shipNumber < shipAmount; shipNumber++) {//amount of ships
			int x, y, direction;

			while (!setCoordinates(x, y, autoPut, field) || !directionChose(x, y, decks, field, direction,autoPut) || !checkSides(decks, x, y, field, direction)) {
				if (!autoPut) {
					cout << "Ошибка постановки корабля!!!" << endl;
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

			
		}
	}

	
	cout << "Корабли успешно расставлены" << endl;
	system("pause");
	system("cls");
	return field[width][width];
}

void cheats(Player enemy) {
	cout << "ВЫ АКТИВИРОВАЛИ ЧИТЫ!!!" << endl;
	cout << "Введите команду..." << endl;
	char command[256];
	cin >> command;
	system("cls");
	char cheatCommands[] = { "/show_enemy_field" };

	if (strcmp(cheatCommands, command) == 0) {
		enemy.PrintField(enemy.field);
		Sleep(1500);
		system("cls");
	}
	else {
		cout << "Упс. Такой команды нету. В следуйщий раз повезет!" << endl;
	}

}

void SaveGameProgressStruct(ship* flot,int size, string filename) {
	ofstream f1(filename, ios::binary | ios::out);
	for (size_t i = 0; i < size; i++)
	{
		f1.write((char*)&flot[i], sizeof(flot[i]));
	}
	f1.close();
}

void SaveGameProgress(Player player, string filename) {
	ofstream f1(filename, ios::binary | ios::out);
	if (f1.is_open()) {
		f1.write((char*)&player, sizeof(player));
		f1.close();
	}
	else {
		cout << "Error opening file!!!" << endl;
	}	
}

void LoadGame(Player& a, string filename) {
	ifstream f1(filename, ios::binary | ios::in);
	if (f1.is_open()) {
		f1.read((char*)&a, sizeof(a));
		f1.close();
	}
	else {
		cout << "Error opening file" << endl;
	}
}

bool setCoordinatesToKill(int& x, int& y, int bot, Player enemy, bool& cheatActivated, Player me) {
	char xStr;
	string yStr;
	if (bot) {
		x = rand() % 9;
		y = rand() % 9;
	}
	else {
		string coords;
		do {

			cout << "Куда ставить корабль (Например А5)?" << endl;
			cin >> coords;
			if (coords == "save")
				break;
		} while (coords.length() != 2 || !isdigit(coords[1]));
		if (coords[0] == '/') {
			cheats(enemy);
			return true;
		}
		else if (coords == "save") {
			SaveGameProgress(me, "Files\\Player 1.bin");
			/*SaveGameProgress(me.field, "Files/Player1Field.txt");
			SaveGameProgress(me.fieldForKills, "Files/Player1Kills.txt");
			SaveGameProgress(enemy.field, "Files/Player2Field.txt");
			SaveGameProgress(enemy.fieldForKills, "Files/Player2Kills.txt");
			SaveGameProgressStruct(me.flot, 10,"Files/Player_1_Flot.bin");
			SaveGameProgressStruct(me.flot, 10, "Files/Player_2_Flot.bin");*/
			cout << "Спасибо за игру!!!";
			exit(0);
		}
		else {
			x = changeLetter(coords[0]);
			yStr = coords[1];
			y = stoi(yStr);
			return false;
		}
		
	

	}
	return false;
}

bool findCoords(ship flot, int x, int y) {
	bool thisShip = false;
	for (size_t i = 0; i < flot.deckNum; i++)
	{
		switch (flot.direction) {
		case 1: {			//right
			if (flot.x + i == x && flot.y == y)return true;
			else if (flot.x - i == x && flot.y == y)return true;
			else thisShip = false;
			break;
		}
		case 2: {			//left
			if (flot.x - i == x && flot.y == y) return true;
			else if (flot.x + i == x && flot.y == y)return true;
			else thisShip = false;
			break;
		}
		case 3: {			//bottom
			if (flot.x == x && flot.y + i == y) return true;
			else if (flot.x == x && flot.y - i == y)return true;
			else thisShip = false;
			break;
		}
		case 4: {			//top
			if (flot.x == x && flot.y - i == y) return true;
			else if (flot.x == x && flot.y - i == y)return true;
			else thisShip = false;
			break;
		}
		default:return false;
		}
	}
	return false;
}

int findShipIndex(int x, int y, ship* flot) {
	for (size_t i = 0; i < 10; i++)
	{
		if (x == flot[i].x && y == flot[i].y || findCoords(flot[i], x, y)) {
			return i;
		}
	}
}


bool checkKill(int shipIndex, char fieldEnemy[width][width], ship* flotEnemy) {
	int x, y;

	x = flotEnemy[shipIndex].x;
	y = flotEnemy[shipIndex].y;
	for (size_t i = 0; i < flotEnemy[shipIndex].deckNum; i++)
	{
		switch (flotEnemy[shipIndex].direction) {
		case 0: {
			flotEnemy[shipIndex].isDestroyed = true;
			return true;
			break;
		}
		case 1: {
			if (fieldEnemy[y][x + i] == 'S')
				return false;
			break;
		}
		case 2: {
			if (fieldEnemy[y][x - i] == 'S')
				return false;
			break;
		}
		case 3: {
			if (fieldEnemy[y + i][x] == 'S')
				return false;
			break;
		}
		case 4: {
			if (fieldEnemy[y - i][x] == 'S')
				return false;
			break;
		}
		}
	}
	flotEnemy[shipIndex].isDestroyed = true;
	return true;
}


char circleKill(ship flot, char myFieldForKills[width][width]) {
	int x = flot.x;
	int y = flot.y;

	for (size_t i = 0; i < flot.deckNum; i++)
	{
		if (x + 1 <= 9)
			if (myFieldForKills[y][x + 1] != 'X')
				myFieldForKills[y][x + 1] = '·';
		if (x - 1 >= 0)
			if (myFieldForKills[y][x - 1] != 'X')
				myFieldForKills[y][x - 1] = '·';
		if (y + 1 <= 9)
			if (myFieldForKills[y + 1][x] != 'X')
				myFieldForKills[y + 1][x] = '·';
		if (y - 1 >= 0)
			if (myFieldForKills[y - 1][x] != 'X')
				myFieldForKills[y - 1][x] = '·';
		switch (flot.direction) {
		case 0: {
			return myFieldForKills[width][width];
			break;
		}
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
	return myFieldForKills[width][width];
}


int turnToKill(Player& a, Player& b, bool& turn) {
	if (!a.autoPlay) {
		cout << "Ваше поле" << endl;
		a.PrintField(a.field);
		cout << "Поле для ходов" << endl;
		a.PrintField(a.fieldForKills);
	}
	int killX, killY;
	bool cheatActivated = false;
	
	if (!setCoordinatesToKill(killX, killY, a.autoPlay, b, cheatActivated, a)) {
		if (b.field[killY][killX] == 'S') {
			cout << "Попал" << endl;
			Sleep(2000);
			system("cls");
			b.field[killY][killX] = 'X';
			a.fieldForKills[killY][killX] = 'X';
			int shipIndex = findShipIndex(killX, killY, b.flot);
			if (checkKill(shipIndex, b.field, b.flot)) {
				cout << "Убил!" << endl;
				system("pause");
				system("cls");
				circleKill(b.flot[shipIndex], a.fieldForKills);
			}
		}
		else {
			cout << "Мимо!" << endl;
			a.fieldForKills[killY][killX] = '·';
			if (a.autoPlay)a.PrintField(a.fieldForKills);
			system("pause");
			system("cls");
			if (turn)
				turn = false;
			else
				turn = true;


			return 0;
		}
	}
	else {
		cout << "Чит успешно применен" << endl;
		cheatActivated = false;
		system("pause");
		system("cls");
		if (turn)
			turn = false;
		else
			turn = true;
	}

}

bool win(ship* flot) {
	for (size_t i = 0; i < 10; i++)
	{
		if (flot[i].isDestroyed == false) {
			return false;
		}
	}
	return true;
}

bool Player::PlayerTurn(Player& a,Player& b, int playerNum, bool& turn)
{
	cout << "Ходит игрок "<<playerNum<<endl;
	system("pause");
	turnToKill( a,  b, turn);
	if (win(b.flot)) {
		return true;
	}
	else {
		return false;
	}
}
