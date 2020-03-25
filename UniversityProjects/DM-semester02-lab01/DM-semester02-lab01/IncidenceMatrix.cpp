//
//  IncidenceMatrix.cpp
//  DM-semester02-lab01
//
//  Created by Eric Golovin on 25.03.2020.
//  Copyright © 2020 Eric Golovin. All rights reserved.
//
//

#include "main.h"

int inc_arr[20][20];
int ed_no = 0;

void displayMatrixIncidence(int v, int e) {
    int i, j;
    for(i = 0; i < v; i++) {
        for(j = 0; j < e; j++) {
            cout << inc_arr[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edgeIncidence(int u, int v) { //function to add edge into the matrix with edge number
    inc_arr[u][ed_no] = 1;
    inc_arr[v][ed_no] = 1;
    ed_no++; //increase the edge number
}

void printIncidenceMatrix() {
    int v = 10; //there are 6 vertices in the graph
    int e = 9; //there are 9 edges in the graph
    add_edgeIncidence(1, 1);
    add_edgeIncidence(1, 2);
    add_edgeIncidence(1, 3);
    add_edgeIncidence(1, 5);
    add_edgeIncidence(2, 1);
    add_edgeIncidence(2, 3);
    add_edgeIncidence(2, 4);
    add_edgeIncidence(2, 9);
    add_edgeIncidence(3, 1);
    add_edgeIncidence(3, 3);
    add_edgeIncidence(3, 4);
    add_edgeIncidence(3, 6);
    add_edgeIncidence(4, 1);
    add_edgeIncidence(4, 2);
    add_edgeIncidence(4, 4);
    add_edgeIncidence(5, 1);
    add_edgeIncidence(5, 3);
    add_edgeIncidence(6, 1);
    add_edgeIncidence(6, 2);
    add_edgeIncidence(6, 3);
    add_edgeIncidence(6, 4);
    add_edgeIncidence(6, 6);
    add_edgeIncidence(7, 3);
    add_edgeIncidence(7, 6);
    add_edgeIncidence(9, 1);
    add_edgeIncidence(9, 2);
    add_edgeIncidence(9, 5);
    add_edgeIncidence(9, 9);
    
    displayMatrixIncidence(v, e);
}
