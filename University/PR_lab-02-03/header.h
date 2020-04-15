#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

typedef struct {
    int day;
    int month;
    int year;
    string date(void) {
        stringstream resultDate;
        resultDate << day << "/" << month << "/" << year;
        return resultDate.str();
    }
} Date;

typedef struct {
    string name;
    string surname;
    string facultyTitle;
} Author;

typedef struct {
    vector <Date> debtDate;
    string studentNaming;
} StudentLending;
