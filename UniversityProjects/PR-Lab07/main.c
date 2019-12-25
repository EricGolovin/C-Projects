#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void mx_writeint(int n, FILE *file) {
	int num = n;
	int number;
	int index = 0;

	while (num > 0)
        {
		number = num % 10;
		++index;
		num /= 10;
        }

	num = n;
	int array[index];
	int i = 0;

	while (num > 0)
        {
                number = num % 10;
                array[i] = number;
		i++;
                num /= 10;
        }

	for (i = index - 1; i >= 0; --i) {
		char numCh = array[i] + '0';
        fwrite(&numCh, 1, sizeof(numCh), file);
	}
}

int main(int argc, char *argv[])
{
    int openedFile = open(argv[1], O_RDWR);
    char buffChar = ' ';
    char stringNum[32];
    int index = 0;

    FILE *newFile = fopen("outData.txt", "w");
    FILE *binFile = fopen("outBin.bin", "wb");

    int columns = 0;
    int rows = 0;

    bool sizeSwitcher = true;

    while (read(openedFile, &buffChar, 1))
    {

	    fwrite(&buffChar, 1, sizeof(buffChar), newFile);
        fwrite(&buffChar, 1, sizeof(buffChar), binFile);
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
    fwrite(" -> \n", 1, sizeof(" -> \n"), newFile);
    fwrite(" -> \n", 1, sizeof(" -> \n"), binFile);

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
	    fwrite("newArray[", 1, sizeof("newArray["), newFile);
	    fwrite("newArray[", 1, sizeof("newArray["), binFile);
        char rowIndexCh = rowIndex + '0';
        fwrite(&rowIndexCh, 1, sizeof(rowIndexCh), newFile);
	    fwrite(&rowIndexCh, 1, sizeof(rowIndexCh), binFile);
        fwrite("][", 1, sizeof("]["), newFile);
        fwrite("][", 1, sizeof("]["), binFile);
	    char columnIndexCh = columnIndex + '0';
        fwrite(&columnIndexCh, 1, sizeof(columnIndexCh), newFile);
	    fwrite(&columnIndexCh, 1, sizeof(columnIndexCh), binFile);
        fwrite("] = ", 1, sizeof("] = "), newFile);
        fwrite("] = ", 1, sizeof("] = "), binFile);
        fwrite(stringNum, 1, sizeof(stringNum), newFile);
        fwrite(stringNum, 1, sizeof(stringNum), binFile);
	    fwrite("\n", 1, sizeof("\n"), newFile);
        fwrite("\n", 1, sizeof("\n"), binFile);
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

    fwrite("\nrows = ", 1, sizeof("\nrows = "), newFile);
    fwrite("\nrows = ", 1, sizeof("\nrows = "), binFile);
    char rowsCh = rows + '0';
    fwrite(&rowsCh, 1, sizeof(rowsCh), newFile);
    fwrite(&rowsCh, 1, sizeof(rowsCh), binFile);

    fwrite("\ncolumns = ", 1, sizeof("\ncolumns = "), newFile);
    fwrite("\ncolumns = ", 1, sizeof("\ncolumns = "), binFile);
    char columnsCh = columns + '0';
    fwrite(&columnsCh, 1, sizeof(columnsCh), newFile);
    fwrite(&columnsCh, 1, sizeof(columnsCh), binFile);
    fwrite("\n", 1, sizeof("\n"), newFile);
    fwrite("\n", 1, sizeof("\n"), binFile);

    printf("\nrows = %i", rows);
    printf("\ncolumns = %i", columns);

    fwrite("\nNew Array:\n", 1, sizeof("\nNew Array:\n"), newFile);
    fwrite("\nNew Array:\n", 1, sizeof("\nNew Array:\n"), binFile);

    printf("\nNew Array:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
		char nArrayIndexCh;
		if (newArray[i][j] < 0) {
			nArrayIndexCh = -newArray[i][j] + '0';
		} else {
			nArrayIndexCh = newArray[i][j] + '0';
		}
        fwrite(&nArrayIndexCh, 1, sizeof(nArrayIndexCh), newFile);
        fwrite(&nArrayIndexCh, 1, sizeof(nArrayIndexCh), binFile);
        fwrite(" ", 1, sizeof(" "), binFile);
		printf("%i ", newArray[i][j]);

        }
        fwrite("\n", 1, sizeof("\n"), newFile);
        fwrite("\n", 1, sizeof("\n"), binFile);

        printf("\n");
    }

    close(openedFile); 
    
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

    // finding the sum of all diagonnals parallel to the secondary diagonal
    
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

    // writing data to the txt file  
    fwrite("diagonalMin = ", 1, sizeof("diagonalMin = "), newFile);
    fwrite("diagonalMin = ", 1, sizeof("diagonalMin = "), binFile);
    mx_writeint(diagonalMin, newFile); 
    mx_writeint(diagonalMin, binFile); 
    fwrite("\nnonNegSum = ", 1, sizeof("\nnonNegSum = "), newFile);
    fwrite("\nnonNegSum = ", 1, sizeof("\nnonNegSum = "), binFile);
    mx_writeint(diagonalMin, newFile); 
    mx_writeint(diagonalMin, binFile); 
    fwrite("\n", 1, sizeof("\n"), newFile);
    fwrite("\n", 1, sizeof("\n"), binFile);

    printf("diagonalMin = %i\n", diagonalMin);
    printf("\nnonNegSum = %i\n", nonNegColSum);

    fclose(newFile);
    fclose(binFile);
    
    return 0;
}
