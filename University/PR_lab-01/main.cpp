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
        cout << "Destination Name: " << str[i].destinationName << endl;
        cout << "Flight Number: " << str[i].flightNumber << endl;
        cout << "Plane Model: " << str[i].planeModel << endl << endl;
    }
    cout << "--------------------------------------------------" << endl;
}

string readFileData(string fileName, int *numOfFlights) {
    fstream outFile;
    stringstream stringStream;
    
    outFile.open(fileName, ios_base::in);
    
    if (outFile.is_open()) {
        cout << "File opened successfuly." << endl << endl;
        string fileContent;
        
        while (outFile.good()) {
            getline(outFile, fileContent);
            stringStream << "-" << fileContent << endl;
            *numOfFlights += 1;
        }
        
        outFile.close();
    }
    
    return stringStream.str();
}

string findByPlaneModel(string planeToFind, AEROFLOT inArray[], int numOfElements) {
    stringstream outputStringStream;
    for (int i = 0; i < numOfElements; i++) {
        if (planeToFind == inArray[i].planeModel) {
            outputStringStream << "--------------------------------" << endl;
            outputStringStream << "Index in the list: " << i + 1 << endl;
            outputStringStream << "Detination Name: " << inArray[i].destinationName << endl;
            outputStringStream << "Flight number: " << inArray[i].flightNumber << endl;
            outputStringStream << "--------------------------------" << endl;
        }
    }
    
    if (outputStringStream.str() == "") {
        return "--------------------------------\nThis flight does not exist.\n--------------------------------\n";
    } else {
        return outputStringStream.str();
    }
} 

string findByCityName(string nameToFind, AEROFLOT inArray[], int numOfElements) {
    stringstream outputStringStream;
    for (int i = 0; i < numOfElements; i++) {
        if (inArray[i].destinationName.find(nameToFind) != string::npos) {
            outputStringStream << "--------------------------------" << endl;
            outputStringStream << "Index in the list: " << i + 1 << endl;
            outputStringStream << "Flight number: " << inArray[i].flightNumber << endl;
            outputStringStream << "Plane Model: " << inArray[i].planeModel << endl;
            outputStringStream << "--------------------------------" << endl;
        }
    }
    
    if (outputStringStream.str() == "") {
        return "--------------------------------\nThis flight does not exist.\n--------------------------------\n";
    } else {
        return outputStringStream.str();
    }
}

bool stringSorting(AEROFLOT flight01, AEROFLOT flight02) {
    return flight01.destinationName < flight02.destinationName;
}

int main(int argc, char *argv[]) {
    //    vector<AEROFLOT> dynArrayOfAeroflots (0);
    int totalFlights = 0;
    string fileData = readFileData("inputTestFile.txt", &totalFlights);
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
        // cout << someFlight.destinationName << ", " << someFlight.flightNumber << ", " << someFlight.planeModel << endl;
        arrayOfFlights[i] = someFlight;
        fileData.erase(fileData.find('D'), fileData.find('\n'));
    }
    
    sort(arrayOfFlights, arrayOfFlights + totalFlights, stringSorting);
    
    string typeOfSearch;
    string searchParameter;
    ofstream outputFile("outputFile.txt");
    
    cout << "Search by Plane Model or by Destination city Name (type <plane> or <city> down below): " << endl;
    cin >> typeOfSearch;
    
    while (1) {
        if (typeOfSearch == "plane" || typeOfSearch == "<plane>") {
            cout << "Enter plane model: ";
            cin >> searchParameter;
            cout << endl;
            
            outputFile << findByPlaneModel(searchParameter, arrayOfFlights, totalFlights);
            cout << findByPlaneModel(searchParameter, arrayOfFlights, totalFlights) << endl;
            
        } else if (typeOfSearch == "city" || typeOfSearch == "<city>") {
            cout << "Enter Destination city Name: ";
            cin >> searchParameter;
            cout << endl;
            
            outputFile << findByCityName(searchParameter, arrayOfFlights, totalFlights);
            cout << findByCityName(searchParameter, arrayOfFlights, totalFlights) << endl;
        } else {
            cout << "You have Entered nonexistent search Option." << endl;
            cout << "Please, Enter <plane> or <city> down below: " << endl;
            typeOfSearch = "";
            cin >> typeOfSearch;
            
        }
        string exitOption;
        cout << endl << "type <continue> to Continue running of the search" << endl << "or" << endl << "Type <stop> to Stop running of the search" << endl;
        cin >> exitOption;
        cout << endl;

        if (exitOption == "stop" || exitOption == "<stop>") {
            break;
        }
    }
    
    outputFile.close();
    
    return 0;
}
