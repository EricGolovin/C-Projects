//
//  main.c
//  PR-Lab03
//
//  Created by Eric Golovin on 10/23/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    char sentence[81] = "Today I saw an incredible house of my friends"; // should change my to ours
    char resultArray[81];
    char terminator[2] = " ";
    char *token;
    
    token = strtok(sentence, terminator);
    
    while( token != NULL ) {
        if (strcmp(token, "my") == 0) {
            token = "ours";
        }
        
        printf( " %s\n", token);
        
        strcat(resultArray, token);
        strcat(resultArray, " ");
        
        token = strtok(NULL, terminator);
    }
    
    for (int i = 0; i <= 81; i++) {
        sentence[i] = resultArray[i];
    }
    
    printf("Result Sentence: %s\n", sentence);
    
    return 0;
}
