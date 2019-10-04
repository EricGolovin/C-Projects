//
//  main.c
//  CLang-book-chapter07
//
//  Created by Eric Golovin on 10/4/19.
//  Copyright © 2019 EricGolovin. All rights reserved.
//

#include <stdio.h>

#include "prog7-6.h"
#include "prog7-7.h"
#include "prog7-8.h"
#include "prog7-10.h"
#include "prog7-11.h"
#include "prog7-12.h"
#include "prog7-13.h"
#include "prog7-14.h"
#include "prog7-15.h"
#include "prog7-16.h"
#include "prog7-17.h"
#include "prog7-ex07.h"
#include "prog7-ex08.h"
#include "prog7-ex09.h"
#include "prog7-ex10.h"
#include "prog7-ex11.h"
#include "prog7-ex12.h"

void prog06(void) {
    int gcd(int u, int v);
    
    int result;
    
    result = gcd(150, 35);
    printf("The gcd of 150 and 35 is %i\n", result);
    
    result = gcd(1026, 405);
    printf("The gcd of 1026 and 405 is %i\n", result);
    
    printf("The gcd of 83 and 240 is %i\n", gcd(83, 240));
}

void prog07(void) {
    float absoluteValue(float x);
    float f1 = -15.5, f2 = 20.0, f3 = -5.0;
    int i1 = -716;
    float result;
    
    result = absoluteValue(f1);
    printf("result = %.2f\n", result);
    printf("f1 = %.2f\n", f1);
    
    result = absoluteValue(f2) + absoluteValue(f3);
    printf("result = %.2f\n", f1);
    
    result = absoluteValue((float)i1);
    printf("result = %.2f\n", result);
    
    result = absoluteValue(i1);
    printf("result = %.2f\n", result);
    
    printf("%.2f\n", absoluteValue(-6.0) / 4);
}

void prog08(void) {
    double  squereRoot(double  x, const double  epsilon);
    printf("squereRoot(2.0) = %la\n", squereRoot(2.0, .000001));
    printf("squereRoot(144.0) = %la\n", squereRoot(144.0, .0001));
    printf("squereRoot(17.5) = %la\n", squereRoot(17.5, .001));
}

void prog10(void) {
    int minimum(int values[], int numberOfElements);
    int array1[5] = {157 , -28, -37, 26, 10};
    int array2[7] = {12, 45, 1, 10, 5, 3, 22};
    int minimum(int values[], int numberOfElements);

    printf ("array1 minimum: %i\n", minimum(array1, 5));
    printf ("array2 minimum: %i\n", minimum(array2, 7));
}

void prog11(void) {
    void multiplyBy2(float array[], int n);
    float floatVals[4] = { 1.2f, -3.7f, 6.2f, 8.55f };
    int i;
    void multiplyBy2(float array[], int n);

    multiplyBy2(floatVals, 4);
    for (i = 0; i < 4; i++) {
        if (i > 0) {
            printf(" -> ");
        }
        printf("%.2f", floatVals[i]);
    }
    printf("\n");
}

void prog12(void) {
    int i;
    int array[16] = {34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11};
     void sort(int a[], int n, int order);

     printf("The array before the sort:\n");

     for (i = 0; i < 16; i++) {
         printf("%i - ", array[i]);
     }

     sort(array, 16, 1);

     printf("\n\nThe array after the sort:\n");

     for (i = 0; i < 16; i++) {
         if (i > 0) {
             printf(" -> ");
         }
         printf("%i", array[i]);
     }

     printf("\n");
}

void prog13(void) {
    void scalarMultiplySpecific(int matrix[3][5], int scalar);
    void displayMatrixSpecific(int matrix[3][5]);

    int sampleMatrix[3][5] = {{7, 16, 55, 13, 12}, {12, 10, 52, 0, 7}, {-2, 1, 2, 4, 9}};

    printf("Original matrix: \n");
    displayMatrixSpecific(sampleMatrix);

    scalarMultiplySpecific(sampleMatrix, 2);

    printf("\nMultiplied by 2:\n");
    displayMatrixSpecific(sampleMatrix);

    scalarMultiplySpecific(sampleMatrix, -1);

    printf("\nThen multiplied by -1:\n");
    displayMatrixSpecific(sampleMatrix);
}

void prog14(void) {
    void scalarMultiply(int nRows, int nCols, int matrix[nRows][nCols], int scalar);
    void displayMatrix(int nRows, int nCols, int matrix[nRows][nCols]);


    int sampleMatrix[3][5] = {{7, 16, 55, 13, 12}, {12, 10, 52, 0, 7}, {-2, 1, 2, 4, 9}};

    printf("Original matrix: \n");
    displayMatrix(3, 5, sampleMatrix);

    scalarMultiply(3, 5, sampleMatrix, 2);

    printf("\nMultiplied by 2:\n");
    displayMatrix(3, 5, sampleMatrix);

    scalarMultiply(3, 5, sampleMatrix, -1);

    printf("\nThen multiplied by -1:\n");
    displayMatrix(3, 5, sampleMatrix);
}

void prog15(void) {
    void getTheNumberAndBase(void), convertNumber(void), displayConvertedNumber(void);

    getTheNumberAndBase();
    convertNumber();
    displayConvertedNumber();
}

void prog16(void) {
    int i;
    void autop_static(void);

    for (i = 0; i < 5; i++) {
        autop_static();
    }
}

void prog17(void) {
    unsigned int j;
    unsigned long int factorial(unsigned int n);

    for (j = 0; j < 11; j++) {
        printf("%2u! = %lu\n", j, factorial(j));
    }
}

void prog_ex07(void) {
    long int x_to_the_n(void);
    printf("%li", x_to_the_n());
}

void prog_ex08(void) {
    void calcRoots(void);
    calcRoots();
}

void prog_ex09(void) {
    int lcm(int u, int v);
    printf("The least common multiple of 15 and 10 is %i\n", lcm(15, 10));
}

void prog_ex10(void) {
    int checkForPrime(int valueToCheck);
    
    int value;
    printf("Please, enter value to check for Prime: ");
    scanf("%i", &value);

    printf("%i is prime(1) or not prime(0) --> %i\n", value, checkForPrime(value));
}

void prog_ex11(void) {
    int sumOfArray(int array[], int count);
    int userArray[9];

    for (int i = 0; i <= 9; i++) {
        printf("Value for userArray[%i]: ", i);
        scanf("%i", &userArray[i]);
    }

    printf("Sum of all elements in userArray is %i\n", sumOfArray(userArray, 9));
}

void prog_ex13(void) {
    void transposeMatrix(int workingArray[3][5], int numberOfRows, int numberOfColumns);
    void displayMatrixSpecific(int matrix[3][5]);
    
    int array[3][5] = { {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}, {1, 2, 3, 4, 5} };
    transposeMatrix(array, 3, 5);
    displayMatrixSpecific(array);
}

int main(void) {
//    prog06();
//    prog07();
//    prog08();
//    prog10();
//    prog11();
//    prog12();
//    prog13();
//    prog14();
//    prog15();
//    prog16();
//    prog17();
//    prog_ex07();
//    prog_ex08();
//    prog_ex09();
//    prog_ex10();
//    prog_ex11();
//    prog_ex13();
    
    return 0;
}
