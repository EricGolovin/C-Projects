// PR-Lab04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct companies {
    char name[81];
    int earnings[12];
};

void swapCompanies(struct companies *c1, struct companies *c2) {
    struct companies temp = *c1;
    *c1 = *c2;
    *c2 = temp;
}

int main()
{
    void swapCompanies(struct companies* c1, struct companies* c2);

    struct companies listOfCompanies[5];

    // adding names to companies
    strcpy_s(listOfCompanies[0].name, "Apple");
    strcpy_s(listOfCompanies[1].name, "Google");
    strcpy_s(listOfCompanies[2].name, "Microsoft");
    strcpy_s(listOfCompanies[3].name, "Amazon");
    strcpy_s(listOfCompanies[4].name, "Facebook");

    // adding earnigns to companies by months
    for (int i = 0; i < 5; ++i) {
        for (int month = 0; month < 12; ++month) {
            listOfCompanies[i].earnings[month] = 100 + rand() % 9899;
        }
    }

    // printing
    for (int i = 0; i < 5; ++i) {
        std::cout << "\t" << listOfCompanies[i].name << std::endl;
        for (int month = 0; month < 12; ++month) {
            switch (month) {
            case 0:
                std::cout << "Jan = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 1:
                std::cout << "Feb = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 2:
                std::cout << "Mar = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 3:
                std::cout << "May = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 4:
                std::cout << "Apt = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 5:
                std::cout << "Jun = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 6:
                std::cout << "Jul = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 7:
                std::cout << "Aug = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 8:
                std::cout << "Sep = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 9:
                std::cout << "Oct = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 10:
                std::cout << "Nov = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            case 11:
                std::cout << "Dec = " << listOfCompanies[i].earnings[month] << std::endl;
                break;
            default:
                break;
            }
        }
    }

    // sorting companies by earnings
    for (int i = 0; i < 4; i++) {
        for (int month = 0; month <= 11; ++month) {
            if (listOfCompanies[i].earnings[month] > listOfCompanies[i + 1].earnings[month]) 
            {
                std::cout << listOfCompanies[i].name << " earnings" << month + 1 << " = " << listOfCompanies[i].earnings[month] << std::endl;
                std::cout << listOfCompanies[i + 1].name << " earnings" << month + 1 << " = " << listOfCompanies[i + 1].earnings[month] << "\n\n";

                swapCompanies(&listOfCompanies[i], &listOfCompanies[i + 1]);
            }
        }
    }

    std::cout << "\n\n\t\tEnded sorting\n\n";

}