//
//  main.cpp
//  DM-semester02-lab01
//
//  Created by Eric Golovin on 25.03.2020.
//  Copyright © 2020 Eric Golovin. All rights reserved.
//
//
//#include "main.h"
//
////1,1;1,2;1,3;1,5;2,1;2,3;2,4;2,9;3,1;3,3;3,4;3,6;4,1;4,2;4,4;5,1;5,3;6,1;6,2;6,3;6,4;6,6;7,3;7,6;9,1;9,2;9,5;9,9
//
//int main(int argc, char* argv[]) {
//    
//    printAdjacencyMatrix();
//    cout << endl;
//    printIncidenceMatrix();
//    
//    return 0;
//}

#include <iostream>
using namespace std;

struct Graph {
    int x;
    int y;
};

void adjacency(int adjacencyMatrix[11][11], int reachabilityMatrix[11][11]) {
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            reachabilityMatrix[i][j]=adjacencyMatrix[i][j];
        }
    }
    
    for (int k = 0; k < 11; k++) {
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 11 ; j++) {
                reachabilityMatrix[i][j]=(reachabilityMatrix[i][j]||(reachabilityMatrix[k][j]&&reachabilityMatrix[i][k]));
            }
        }
    }
}

int main() {
    setlocale(0,"");
    
    Graph g[28] = {{1, 1}, {1, 2}, {1, 3}, {1, 5}, {2, 1}, {2, 3}, {2, 4}, {2, 9}, {3, 1}, {3, 3}, {3, 4}, {3, 6}, {4, 1}, {4, 2}, {4, 4}, {5, 1}, {5, 3}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 6}, {7, 3}, {7, 6}, {9, 1}, {9, 2}, {9, 5}, {9, 9}};
    
    int smezhn[11][11] = { 0 };
    int intsed[11][35] = { 0 };
    int dostezh[11][11] = { 0 };
    
    for (int i = 0; i < 28; ++i) {
        smezhn[g[i].x - 1][g[i].y - 1] = 1;
    }
    
    cout << "Матрица смежности:" << endl;
    
    for (int i = 0; i < 11; ++i, cout << '\n') {
        for (int j = 0; j < 11; ++j) {
            cout.width(3);
            cout << smezhn[i][j] << ' ';
        }
    }
    
    for (int i = 0; i < 28; ++i) {
        intsed[g[i].x - 1][i] = 1;
        intsed[g[i].y - 1][i] = -1;
        
        if (g[i].x - 1 == g[i].y - 1) {
            intsed[g[i].x - 1][i] = 2;
            intsed[g[i].y - 1][i] = 2;
        }
    }
    
    
    cout << "\nМатрица инцедентности:\n";
    
    for (int i = 0; i < 11; ++i, cout << '\n') {
        for (int j = 0; j < 28; ++j) {
            cout.width(2);
            cout << intsed[i][j];
        }
    }
    
    
    cout << "\nМатрица достижимости\n";
    
    adjacency(smezhn,dostezh);
    
    for (int i = 0; i < 11; ++i, cout << '\n') {
        for (int j = 0; j < 11; ++j) {
            cout.width(3);
            cout << dostezh[i][j] << ' ';
        }
    }
    
    return 0;
    
}
