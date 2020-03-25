//
//  main.cpp
//  DM-semester02-lab01
//
//  Created by Eric Golovin on 25.03.2020.
//  Copyright © 2020 Eric Golovin. All rights reserved.
//

#include<iostream>
using namespace std;

int vertArr[20][20]; //the adjacency matrix initially 0
int count = 0;

void displayMatrix(int v) {
    int i, j;
    for(i = 0; i < v; i++) {
        for(j = 0; j < v; j++) {
            cout << vertArr[i][j] << " ";
        }
        cout << endl;
    }
}

void add_edge(int u, int v) {       // function to add edge into the matrix
    vertArr[u][v] = 1;
    vertArr[v][u] = 1;
}

1,1;1,2;1,3;1,5;2,1;2,3;2,4;2,9;3,1;3,3;3,4;3,6;4,1;4,2;4,4;5,1;5,3;6,1;6,2;6,3;6,4;6,6;7,3;7,6;9,1;9,2;9,5;9,9.

int main(int argc, char* argv[]) {
    int v = 9;    //there are 9 vertices in the graph
    add_edge(1, 1);
    add_edge(1, 2);
    add_edge(1, 2);
    add_edge(1, 4);
    add_edge(1, 5);
    add_edge(2, 3);
    add_edge(2, 5);
    add_edge(5, 3);
    add_edge(5, 4);
    displayMatrix(v);
    
    return 0;
}
