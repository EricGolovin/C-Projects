// PR-Lab05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//

#include <iostream>
#include <math.h>

int arithmeticalMean(int array[], int n) {
    int sumArray = 0;
    for (int i = 0; i < n; ++i) {
        sumArray += array[i];
    }

    return sumArray / n;
}

int geometricMean(int array[], int n) {
    int productArray = 1;
    for (int i = 0; i < n; ++i) {
        productArray *= array[i];
    }

    return pow(productArray, n);
}

int main()
{
    int array[10] = { 4, 5, 1, 3, 8, 2, 4, 6, 43, 76 };

    int arrayArithMean = arithmeticalMean(array, 10);
    int arrayGeomMean = geometricMean(array, 10);

    std::cout << "Arithmetical Mean = " << arrayArithMean << std::endl;
    std::cout << "Geometric Mean = " << arrayGeomMean << std::endl;
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
