#include <iostream>
#include <vector>
using namespace std;

typedef struct AEROFLOT {
    const char* destinationName;
    int flightNumber;
    const char *planeModel;
} AEROFLOT;

void printArrayOfStructs(vector<AEROFLOT> str) {
    cout << endl;
    for (int i = 0; i < str.size(); i++) {
        cout << "struct #" << i + 1 << endl;
        cout << "Destination Name" << str[i].destinationName << endl;
        cout << "Flight Number" << str[i].flightNumber << endl;
        cout << "Plane Model" << str[i].planeModel << endl << endl;
    }
}

int main(int argc, char *argv[]) {
    AEROFLOT flight = {"Denmark", 342, "Boing"};
    
    vector<AEROFLOT> dynArrayOfAeroflots (0);
    
    for (int i = 0; i < 5; i++) {
        AEROFLOT someFlight = {"Santa Clara", 277, "BoingHQR"};
        dynArrayOfAeroflots.push_back(someFlight);
    }
    
    printArrayOfStructs(dynArrayOfAeroflots);
    
    return 0;
}
