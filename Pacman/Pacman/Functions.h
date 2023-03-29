#pragma once
#include<iostream>
#include<conio.h>
using namespace std;

int charPac = 254;
int row, column;

char** createBoard(int size) {
	char** board = new char* [size] {};
	for (int i = 0; i < size; i++) board[i] = new char[size] {};
	return board;
}

void createBarrier(char** arr, int size) {
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (i == 0 || i == size - 1 || j == 0 || j == size - 1) arr[i][j] = '*';
			else arr[i][j] = ' ';
		}
	}
}

void printBoard(char** arr, int size) {
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++) {
			cout << arr[i][j] << ' ';
		}cout << endl;
	}
}

void createPac(char** arr, int size) {
	srand(time(0));
	while (true) {
		int row_rand = 1 + (rand() % (size - 2)), col_rand = 1 + (rand() % (size - 2));
		if (arr[row_rand][col_rand] != ' ') continue;
		else {
			arr[row_rand][col_rand] = arr[row_rand][col_rand] = charPac;
			row = row_rand, column = col_rand;
			break;
		}	
	}
}

int createRandApple(char** arr, int size) {
	srand(time(0));
	int appleCount = 2 + (rand() % (apples + 1));
	for (int i = 0; i < appleCount; i++){
		while (true) {
			int row_rand = (rand() % (size - 1)), col_rand = (rand() % (size - 1));
			if (arr[row_rand][col_rand] != ' ') continue;
			else arr[row_rand][col_rand] = 250;
			break;
		}
	}
	return appleCount;
}

void createWall(char** arr, int size) {
	int randomWallCount = (size / 4) + rand() % (size / 3);
	int row = 1 + rand() % (size - 2), col = rand() % 2;
	if (col != 0) col = size - 1;
	for (int i = 1; i < randomWallCount; i++){
		if (col != 0) arr[row][col - i] = '-';
		else arr[row][col + i] = '-';
	}
}

void appleCounter(char** arr) {
	if (arr[row][column] == -6) score++;
	else if (arr[row][column] == 45) checkWall = true;
	sleep_for(1ms);
}

bool isCheck(int change, int value, int size) {
	if (change + value > size - 2 || change + value == 0) return true;
	return false;
}

bool isWin(int appleCount) {
	if (score == appleCount) return true;
	else return false;
}

void move(char** arr, int size) {
	int arrowOpt = _getch();
	switch (arrowOpt) {
	case 72:// Up
		if (isCheck(-1, row, size)) break;
		row--;
		appleCounter(arr);
		if (checkWall == false) {
			arr[row + 1][column] = ' ';
			arr[row][column] = charPac;
		}
		system("cls");
		printBoard(arr, size);
		cout << "Score -- " << score << endl;
		break;
	case 75:// Left
		if (isCheck(-1, column, size)) break;
		column--;
		appleCounter(arr);
		if (checkWall == false) {
			arr[row][column + 1] = ' ';
			arr[row][column] = charPac;
		}
		system("cls");
		printBoard(arr, size);
		cout << "Score -- " << score << endl;
		break;
	case 77:// Right
		if (isCheck(1, column, size)) break;
		column++;
		appleCounter(arr);
		if (checkWall == false) {
			arr[row][column - 1] = ' ';
			arr[row][column] = charPac;
		}
		system("cls");
		printBoard(arr, size);
		cout << "Score -- " << score << endl;
		break;
	case 80:// Down
		if (isCheck(1, row, size)) break;
		row++;
		appleCounter(arr);
		if (checkWall == false) {
			arr[row - 1][column] = ' ';
			arr[row][column] = charPac;
		}
		system("cls");
		printBoard(arr, size);
		cout << "Score -- " << score << endl;
		break;
	default:
		break;
	}
}