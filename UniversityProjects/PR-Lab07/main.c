#include <stdio.h>
#include <ctype.h> // isdigit
#include <stdbool.h>
#include <stdlib.h> // atoi

void mx_printTextToFiles(FILE *fileName01, FILE *fileName02, char text[]) {
    fprintf(fileName01, "%s", text);
    fprintf(fileName02, "%s", text);
}

void mx_printIntToFiles(FILE *fileName01, FILE *fileName02, int integer) {
    fprintf(fileName01, "%i", integer);
    fprintf(fileName02, "%i", integer);
}

int main(int argc, char *argv[])
{
    FILE *openedFile = fopen(argv[1], "r");
    FILE *newFile = fopen("outData.txt", "w");
    FILE *binFile = fopen("outBin.bin", "wb");

    char buffChar = ' ';
    char stringNum[32];

    int index = 0;
    int columns = 0;
    int rows = 0;

    // finding the number of rows and columns

    bool sizeSwitcher = true;

    while ((buffChar = fgetc(openedFile)) != EOF)
    {
        printf("%c", buffChar);
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
    printf("(the first 2 digits in %s file)", argv[1]);
    
    fprintf(newFile, "(the first 2 digits in %s file)", argv[1]);
    fprintf(binFile, "(the first 2 digits in %s file)", argv[1]);
    mx_printTextToFiles(newFile, binFile, "\n\nrows = ");
    mx_printIntToFiles(newFile, binFile, rows);
    mx_printTextToFiles(newFile, binFile, "\ncolumns = ");
    mx_printIntToFiles(newFile, binFile, columns);
    mx_printTextToFiles(newFile, binFile, "\n\n");

    printf("\n\nrows = %i", rows);
    printf("\ncolumns = %i\n\n", columns);

    // creating and printing our array of numbers

    int newArray[rows][columns];
    int rowIndex = 0;
    int columnIndex = 0;

    while ((buffChar = fgetc(openedFile)) != EOF)
    {
        if (isdigit(buffChar) || buffChar == '-')
        {
            stringNum[index] = buffChar;
            index++;
        }
        if (isspace(buffChar) && stringNum[0] != '\0')
        {
            newArray[rowIndex][columnIndex] = atoi(stringNum);            
            mx_printTextToFiles(newFile, binFile, "-->\tnewArray[");
            mx_printIntToFiles(newFile, binFile, rowIndex);
            mx_printTextToFiles(newFile, binFile, "][");
            mx_printIntToFiles(newFile, binFile, columnIndex);
            mx_printTextToFiles(newFile, binFile, "] = ");
            mx_printTextToFiles(newFile, binFile, stringNum);
            mx_printTextToFiles(newFile, binFile, "\n");
            printf("-->\tnewArray[%i][%i] = %s\n", rowIndex, columnIndex, stringNum);

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
    fclose(openedFile);

    mx_printTextToFiles(newFile, binFile, "\n\nNew Array:\n");

    printf("\nNew Array:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            mx_printIntToFiles(newFile, binFile, newArray[i][j]);
            mx_printTextToFiles(newFile, binFile, " ");
            printf("%i ", newArray[i][j]);
        }
        mx_printTextToFiles(newFile, binFile, "\n");
        printf("\n");
    }

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
                    if (newArray[i][j] < 0)
                    {
                        sumDiagonals[counter] += -newArray[i][j];
                    }
                    else
                    {
                        sumDiagonals[counter] += newArray[i][j];
                    }
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
            diagonalMin = sumDiagonals[i];
        }
    }

    // printing the results to the files and console

    mx_printTextToFiles(newFile, binFile, "\ndiagonalMin = ");
    mx_printIntToFiles(newFile, binFile, diagonalMin);

    mx_printTextToFiles(newFile, binFile, "\nnonNegSum = ");
    mx_printIntToFiles(newFile, binFile, nonNegColSum);

    printf("diagonalMin = %i\n", diagonalMin);
    printf("nonNegSum = %i\n", nonNegColSum);

    fclose(newFile);
    fclose(binFile);

    return 0;
}
