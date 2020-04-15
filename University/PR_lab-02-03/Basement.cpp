#include "header.h"

template <typename T>
class Basement {
private:
    vector<T> elements;
public:
    void addElement(T element) {
        elements.push_back(element);
    }
    
    void deleteElementByIndex(int index) {
        elements.erase(elements.begin() + index);
    }
    
    int numOfElements() {
        return elements.size();
    }
    
    T getElementByIndex(int index) {
        return elements[index];
    }
    
    void printWithInt(string str, int num) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '~') {
                stringstream destinationStrStream;
                destinationStrStream << num;
                cout << destinationStrStream.str();
            } else {
                cout << str[i];
            }
        }
        cout << endl;
    }
    
    void printWithArguments(string str, int arr[], int num) {
        for (int i = 0, arrIndex = 0; i < str.size(); i++) {
            if (str[i] == '~') {
                stringstream destinationStrStream;
                destinationStrStream << arr[arrIndex];
                cout << destinationStrStream.str();
                arrIndex += 1;
            } else {
                cout << str[i];
            }
        }
        cout << endl;
    }
    
    string getStringWith_strs(string str, string arr[], int num) {
        string result = "";
        for (int i = 0, arrIndex = 0; i < str.size(); i++) {
            if (str[i] == '~') {
                stringstream destinationStrStream;
                destinationStrStream << arr[arrIndex];
                result += destinationStrStream.str();
                arrIndex += 1;
            } else {
                result += str[i];
            }
        }
        return result + "\n";
    }
    
    string getStringWith_ints(string str, int arr[], int num) {
        string result = "";
        for (int i = 0, arrIndex = 0; i < str.size(); i++) {
            if (str[i] == '~') {
                stringstream destinationStrStream;
                destinationStrStream << arr[arrIndex];
                result += destinationStrStream.str();
                arrIndex += 1;
            } else {
                result += str[i];
            }
        }
        return result + "\n";
    }
    
    void printWithStrArguments(string str, string arr[], int num) {
        for (int i = 0, arrIndex = 0; i < str.size(); i++) {
            if (str[i] == '~') {
                stringstream destinationStrStream;
                destinationStrStream << arr[arrIndex];
                cout << destinationStrStream.str();
                arrIndex += 1;
            } else {
                cout << str[i];
            }
        }
        cout << endl;
    }
    
    void print(string sen) {
        cout << sen;
    }
    
};

