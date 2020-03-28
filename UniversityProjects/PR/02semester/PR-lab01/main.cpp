#include <iostream>
//#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

typedef struct AEROFLOT {
    string destinationName;
    int flightNumber;
    string planeModel;
} AEROFLOT;

//void printArrayOfStructs(vector<AEROFLOT> str) {
//    cout << endl;
//    for (int i = 0; i < str.size(); i++) {
//        cout << "struct #" << i + 1 << endl;
//        cout << "Destination Name" << str[i].destinationName << endl;
//        cout << "Flight Number" << str[i].flightNumber << endl;
//        cout << "Plane Model" << str[i].planeModel << endl << endl;
//    }
//}

void printArrayOfStructs(AEROFLOT str[], int num) {
    cout << endl << "--------------Array of flights Data:--------------" << endl;
    for (int i = 0; i < num; i++) {
        cout << "struct #" << i + 1 << endl;
        cout << "Destination Name" << str[i].destinationName << endl;
        cout << "Flight Number " << str[i].flightNumber << endl;
        cout << "Plane Model" << str[i].planeModel << endl << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

string readFileData(string fileName, int *numOfFlights) {
    fstream outFile;
    stringstream stringStream;
    
    outFile.open(fileName, ios_base::in);
    
    if (outFile.is_open()) {
        cout << "File open successful. It contains: " << endl;
        string fileContent;
        
        while (outFile.good()) {
            getline(outFile, fileContent);
            stringStream << *numOfFlights << "-" << fileContent << endl;
            *numOfFlights += 1;
        }
        
        outFile.close();
    }
    
    return stringStream.str();
}

int main(int argc, char *argv[]) {
    //    vector<AEROFLOT> dynArrayOfAeroflots (0);
    int totalFlights = 0;
    
    string fileData = readFileData("testFile.txt", &totalFlights);
    AEROFLOT arrayOfFlights[totalFlights];
    
    for (int i = 0; i < totalFlights; i++) {
        stringstream stringNumStream;
        AEROFLOT someFlight;
        string destName;
        int flightNum;
        string planeModl;
        
        for (int index = 0, flag = 0, parameterNumber = 0; index < fileData.length() - 1; index++) {
            if (fileData[index] == '{') {
                flag = 1;
                parameterNumber++;
                continue;
            } else if (fileData[index] == '}') {
                flag = 0;
                continue;
            }
            if (flag) {
                if (parameterNumber == 1) {
                    someFlight.destinationName += fileData[index];
                } else if (parameterNumber == 2) {
                    stringNumStream << fileData[index];
                } else if (parameterNumber == 3) {
                    stringNumStream >> someFlight.flightNumber;
                    someFlight.planeModel += fileData[index];
                }
            }
        }
        cout << someFlight.destinationName << ", " << someFlight.flightNumber << ", " << someFlight.planeModel << endl;
        arrayOfFlights[i] = someFlight;
    }
    
    printArrayOfStructs(arrayOfFlights, totalFlights);
    
    return 0;
}
