#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int openedFile = open(argv[1], O_RDWR);
    char buffChar = ' ';
    char stringNum[32];
    int index = 0;

    int columns = 0;
    int rows = 0;

    bool sizeSwitcher = true;

    while (read(openedFile, &buffChar, 1))
    {
        printf("%c", buffChar);
        if (isdigit(buffChar))
        {
            stringNum[index] = buffChar;
            index++;
        }
        if (isspace(buffChar))
        {
            if (sizeSwitcher)
            {
                rows = atoi(stringNum);
                sizeSwitcher = false;
                int i = 0;
                while (index != 0)
                {
                    stringNum[index] = '\0';
                    index--;
                }
                stringNum[index] = '\0';
            }
            else
            {
                columns = atoi(stringNum);
                while (index != 0)
                {
                    stringNum[index] = '\0';
                    index--;
                }
                stringNum[index] = '\0';
                break;
            }
        }
    }
    printf(" -> \n");

    int newArray[rows][columns];
    int rowIndex = 0;
    int columnIndex = 0;

    while (read(openedFile, &buffChar, 1))
    {
        if (isdigit(buffChar) || buffChar == '-')
        {
            stringNum[index] = buffChar;
            index++;
        }
        if (isspace(buffChar) && stringNum[0] != '\0')
        {
            newArray[rowIndex][columnIndex] = atoi(stringNum);
            printf("newArray[%i][%i] = %s\n", rowIndex, columnIndex, stringNum);

            while (index != 0)
            {
                stringNum[index] = '\0';
                index--;
            }
            stringNum[index] = '\0';

            if (columnIndex < columns - 1)
            {
                columnIndex++;
            }
            else
            {
                columnIndex = 0;
                rowIndex++;
            }
        }
    }

    printf("\nrows = %i", rows);
    printf("\ncolumns = %i", columns);

    printf("\nNew Array:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%i ", newArray[i][j]);
        }
        printf("\n");
    }

    close(openedFile);

    //int newFile = create("outData.txt", O_RDWR);

    // finding sum of columns with no negative elements
    int nonNegColSum = 0;
    int exceptionalArray[columns];

    int principalDiagonalSum = 0;
    int secondaryDiagonalSum = 0;

    for (int i = 0; i < columns; i++)
    {
        exceptionalArray[i] = 0;
    }

    for (int i = 0, index = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (newArray[i][j] < 0)
            {
                exceptionalArray[j] = 1;
                for (int g = i - 1; g >= 0; g--)
                {
                    nonNegColSum -= newArray[i][g];
                }
            }
            if (exceptionalArray[j] == 0)
            {
                nonNegColSum += newArray[i][j];
            }
        }
    }

    int sumDiagonals[columns + 1];
    for (int i = 0; i < columns + 1; i++)
    {
        sumDiagonals[i] = 0;
    }
    for (int counter = 0, index = rows - 1; counter <= columns; counter++, index--)
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (index == 0)
                {
                    index = -1;
                }
                if ((i + j + index) == (columns - 1))
                {
                    printf("addedSecon = %i newArray[%i][%i]\n", newArray[i][j], i, j);
                    if (newArray[i][j] < 0)
                    {
                        sumDiagonals[counter] += -newArray[i][j];
                    }
                    else
                    {
                        sumDiagonals[counter] += newArray[i][j];
                    }
                    printf("sumDiagonal[%i] = %i\n", counter, newArray[i][j]);
                }
            }
        }
    }
    printf("\n");

    int diagonalMin = 0;
    for (int i = 0; i < columns + 1; i++)
    {
        if (diagonalMin < sumDiagonals[i])
        {
            printf("diagonalMin = %i sumDiagonal[%i] = %i\n", diagonalMin, i, sumDiagonals[i]);
            diagonalMin = sumDiagonals[i];
        }
    }

    for (int i = 0; i < columns + 1; i++)
    {
        printf("sumDiagonals[%i] = %i\n", i, sumDiagonals[i]);

    }

    printf("diagonalMin = %i\n", diagonalMin);
    printf("\nnonNegSum = %i\n", nonNegColSum);
    printf("\nsecondaryDiagonalSum = %i\n", secondaryDiagonalSum);

    return 0;
}
