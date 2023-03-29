#pragma once


char** createBoard(int);
void createBarrier(char**, int);
void printBoard(char**, int);
void createPac(char**, int);
void move(char**, int);
bool isCheck(int, int);
int createRandApple(char**, int);