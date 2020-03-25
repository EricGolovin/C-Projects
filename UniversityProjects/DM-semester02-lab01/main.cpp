//
//  main.cpp
//  DM-semester02-lab01
//
//  Created by Eric Golovin on 25.03.2020.
//  Copyright © 2020 Eric Golovin. All rights reserved.
//
//
#include <iostream>
using namespace std;

struct Graph {
    int x;
    int y;
};

void adjacency(int adjacencyMatrix[9][9], int reachabilityMatrix[9][9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            reachabilityMatrix[i][j]=adjacencyMatrix[i][j];
        }
    }
    
    for (int k = 0; k < 9; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9 ; j++) {
                reachabilityMatrix[i][j]=(reachabilityMatrix[i][j]||(reachabilityMatrix[k][j]&&reachabilityMatrix[i][k]));
            }
        }
    }
}

int main() {
    setlocale(0,"");
    
    Graph g[28] = {{1, 1}, {1, 2}, {1, 3}, {1, 5}, {2, 1}, {2, 3}, {2, 4}, {2, 9}, {3, 1}, {3, 3}, {3, 4}, {3, 6}, {4, 1}, {4, 2}, {4, 4}, {5, 1}, {5, 3}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 6}, {7, 3}, {7, 6}, {9, 1}, {9, 2}, {9, 5}, {9, 9}};
    
    int adjacencyMatrix[9][9] = { 0 };
    int incidenceMatrix[9][28] = { 0 };
    int rechabilityMatrix[9][9] = { 0 };
    
    for (int i = 0; i < 28; ++i) {
        adjacencyMatrix[g[i].x - 1][g[i].y - 1] = 1;
    }
    
    cout << "Матрица смежности:" << endl;
    
    for (int i = 0; i < 9; ++i, cout << '\n') {
        for (int j = 0; j < 9; ++j) {
            cout.width(3);
            cout << adjacencyMatrix[i][j] << ' ';
        }
    }
    
    for (int i = 0; i < 28; ++i) {
        incidenceMatrix[g[i].x - 1][i] = 1;
        incidenceMatrix[g[i].y - 1][i] = -1;
        
        if (g[i].x - 1 == g[i].y - 1) {
            incidenceMatrix[g[i].x - 1][i] = 2;
            incidenceMatrix[g[i].y - 1][i] = 2;
        }
    }
    
    
    cout << "\nМатрица инцедентности:\n";
    
    for (int i = 0; i < 9; ++i, cout << '\n') {
        for (int j = 0; j < 28; ++j) {
            cout.width(2);
            cout << incidenceMatrix[i][j];
        }
    }
    
    
    cout << "\nМатрица достижимости\n";
    
    adjacency(adjacencyMatrix, rechabilityMatrix);
    
    for (int i = 0; i < 9; ++i, cout << '\n') {
        for (int j = 0; j < 9; ++j) {
            cout.width(3);
            cout << rechabilityMatrix[i][j] << ' ';
        }
    }
    
    // the end
    
    return 0;
    
}
