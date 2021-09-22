// CandyCrush.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "game.h"
#include <iostream>

int main()
{
	std::vector <int> test;
	int dimensiune_test = 0;
	std::cout << "Introduceti numarul de bile:\n";
	std::cin >> dimensiune_test;
	std::cout << "Introduceti culorile:\n";
	int culoare = 0;
	for (int i = 0; i < dimensiune_test; i++) {
		std::cin >> culoare;
		test.push_back(culoare);
	}
	system("CLS");
	for (auto it = test.begin(); it != test.end(); it++)
	{
		std::cout << (*it) << ' ';
	}
	std::cout << std::endl;
	sequenceDestroyer(test);
}

