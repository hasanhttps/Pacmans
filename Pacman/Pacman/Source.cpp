#include "Prototypes.h";
int score = 0, apples;
bool checkWall = false;
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread;     // sleep_for, sleep_until
using namespace std::chrono_literals; // ns, us, ms, s, h, etc.
using std::chrono::system_clock;
#include "Functions.h";
#include <iostream>	



int main() {
	system("color 2");
	while (true) {
		score = 0;
		int size;
		checkWall = false;
		cout << "Please enter the size of board : ";
		cin >> size;
		cout << "Please enter the count of max apples : ";
		cin >> apples;
		char** gameBoard = createBoard(size);
		createBarrier(gameBoard, size);
		int wallCount = 1 + rand() % 5;
		for (int i = 0; i < wallCount; i++) createWall(gameBoard, size);
		createPac(gameBoard, size);
		int count = createRandApple(gameBoard, size);
		printBoard(gameBoard, size);
		while (true) {
			move(gameBoard, size);
			if (checkWall) {
				cout << "Teesuf ki divara basmaga calisdiniz Uduzdunuz. Sansinizi bir daha sinayin !" << endl;
				sleep_for(3s);
				system("cls");
				break;
			}
			if (isWin(count)) {
				cout << "Tebrikler Siz qazandiniz" << endl;
				sleep_for(3s);
				system("cls");
				break;
			}
			sleep_for(20ms);
		}
	}
		
}