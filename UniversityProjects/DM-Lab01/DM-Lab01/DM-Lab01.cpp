// DM-Lab01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int implication(int a, int b) {
	if (a == b) {
		return 1;
	} else if (a > b) {
		return 0;
	} else if (a < b) {
		return 1;
	}
}

int main() {
	int a, b, c, d;

	printf("|a|\t|b|\t|c|\t|d|\n");

	for (a = 0; a <= 1; a++) {
		for (b = 0; b <= 1; b++) {
			for (c = 0; c <= 1; c++) {
				for (d = 0; d <= 1; d++) {
					printf("|%i|\t|%i|\t|%i|\t|%i|\t\t|%i|\n", a, b, c, d, implication(a && b && !d && c, ((a && !c) && (!a && b && d)) && !(a && c && d)));
				}
			}
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
