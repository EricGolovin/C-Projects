#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void mx_printint(int n, int *file) {
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
		write(*file, &numCh, sizeof(numCh));
	}
}

int main(int argc, char *argv[])
{
    int openedFile = open(argv[1], O_RDWR);
    char buffChar = ' ';
    char stringNum[32];
    int index = 0;

    int newFile = creat("outData.txt", O_RDWR);
    int columns = 0;
    int rows = 0;

    bool sizeSwitcher = true;

    while (read(openedFile, &buffChar, 1))
    {
	write(newFile, &buffChar, sizeof(buffChar));
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
    write (newFile, " -> \n", sizeof(" -> \n"));

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
	    write(newFile, "newArray[", sizeof("newArray["));
	    char rowIndexCh = rowIndex + '0';
	    write(newFile, &rowIndexCh, sizeof(rowIndexCh));
	    write(newFile, "][", sizeof("]["));
	    char columnIndexCh = columnIndex + '0';
	    write(newFile, &columnIndexCh, sizeof(columnIndexCh));
	    write(newFile, "] = ", sizeof("] = "));
	    write(newFile, stringNum, sizeof(stringNum));
	    write(newFile, "\n", sizeof("\n"));
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

    write(newFile, "\nrows = ", sizeof("\nrows = "));
    char rowsCh = rows + '0';
    write(newFile, &rowsCh, sizeof(rowsCh));

    write(newFile, "\ncolumns = ", sizeof("\ncolumns = "));
    char columnsCh = columns + '0';
    write(newFile, &columnsCh, sizeof(columnsCh));
    write(newFile, "\n", sizeof("\n"));

    printf("\nrows = %i", rows);
    printf("\ncolumns = %i", columns);

    write(newFile, "\nNew Array:\n", sizeof("\nNew Array:\n"));

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
		write(newFile, &nArrayIndexCh, sizeof(nArrayIndexCh));
		write(newFile, " ", sizeof(" "));
		printf("%i ", newArray[i][j]);

        }
	write(newFile, "\n", sizeof("\n"));
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

    // writing data to the file  

    write(newFile, "diagonalMin = ", sizeof("diagonalMin = "));
    mx_printint(diagonalMin, &newFile); 
    write(newFile, "\n", 2);
    write(newFile, "nonNegSum = ", sizeof("nonNegSum = "));
    mx_printint(nonNegColSum, &newFile);
    write(newFile, "\n", sizeof("\n"));

    printf("diagonalMin = %i\n", diagonalMin);
    printf("\nnonNegSum = %i\n", nonNegColSum);
   

    return 0;
}
