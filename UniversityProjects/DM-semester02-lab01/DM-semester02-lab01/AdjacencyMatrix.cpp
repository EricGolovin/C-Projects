//
//  AdjacencyMatrix.cpp
//  DM-semester02-lab01
//
//  Created by Eric Golovin on 25.03.2020.
//  Copyright © 2020 Eric Golovin. All rights reserved.
//

#include "main.h"

int vertArr[20][20];

void printIncidenceMatrix(void);

void displayMatrixAdjacency(int count) {
    for(int i = 0; i < count; i++) {
        for(int j = 0; j < count; j++) {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edgeAdjacency(int u, int v) {
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}

void printAdjacencyMatrix() {
    int vertices = 10;    //there are 10 vertices in the graph
    add_edgeAdjacency(1, 1);
    add_edgeAdjacency(1, 2);
    add_edgeAdjacency(1, 3);
    add_edgeAdjacency(1, 5);
    add_edgeAdjacency(2, 1);
    add_edgeAdjacency(2, 3);
    add_edgeAdjacency(2, 4);
    add_edgeAdjacency(2, 9);
    add_edgeAdjacency(3, 1);
    add_edgeAdjacency(3, 3);
    add_edgeAdjacency(3, 4);
    add_edgeAdjacency(3, 6);
    add_edgeAdjacency(4, 1);
    add_edgeAdjacency(4, 2);
    add_edgeAdjacency(4, 4);
    add_edgeAdjacency(5, 1);
    add_edgeAdjacency(5, 3);
    add_edgeAdjacency(6, 1);
    add_edgeAdjacency(6, 2);
    add_edgeAdjacency(6, 3);
    add_edgeAdjacency(6, 4);
    add_edgeAdjacency(6, 6);
    add_edgeAdjacency(7, 3);
    add_edgeAdjacency(7, 6);
    add_edgeAdjacency(9, 1);
    add_edgeAdjacency(9, 2);
    add_edgeAdjacency(9, 5);
    add_edgeAdjacency(9, 9);
    
    displayMatrixAdjacency(vertices);
}
