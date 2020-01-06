//
//  main.c
//  CLang-book-chapter09
//
//  Created by Eric Golovin on 10/26/19.
//  Copyright © 2019 Eric Golovin. All rights reserved.
//

#include <stdio.h>

#include "prog9-01.h"
#include "prog9-02.h"
#include "prog9-04.h"
#include "prog9-06.h"
#include "prog9-07.h"

void prog01() {
    printf("\tProg01\t\n");
    printf("--------------\n");
    
    void concat(char result[], const char str1[], int n1, const char str2[], int n2);
    
    const char s1[5] = {'T', 'e', 's', 't', ' '};
    const char s2[6] = {'w', 'o', 'r', 'k', 's', '.'};
    char s3[12];
    int i;
    
    concat(s3, s1, 5, s2, 6);
    
    for (i = 0; i < 12; i++) {
        printf("%c", s3[i]);
    }
    printf("\n\n");
}

void prog02() {
    printf("\tProg02\t\n");
    printf("--------------\n");
    
    int stringLength(const char string[]);
    
    const char word1[] = {'a', 's', 't', 'e', 'r', '\0'};
    const char word2[] = {'a', 't', '\0'};
    const char word3[] = {'a', 'w', 'e', '\0'};
    
    printf("%i\t%i\t%i\n\n", stringLength(word1), stringLength(word2), stringLength(word3));
}

void prog03() {
    printf("\tProg03\t\n");
    printf("--------------\n");
    
    _Bool equalStrings(const char s1[], const char s2[]);
    
    const char stra[] = "string compare test";
    const char strb[] = "string";
    
    printf("%i\n", equalStrings(stra, strb));
    printf("%i\n", equalStrings(stra, stra));
    printf("%i\n", equalStrings(strb, "string"));
    
    printf("\n");
}

void prog05() {
    printf("\tProg05\t\n");
    printf("--------------\n");
    char s1[81], s2[81], s3[81];
    
    printf("Enter text:\n");
    
    scanf("%s%s%s", s1, s2, s3);
    
    printf("\ns1 = %s\ns2 = %s\ns3 = %s\n", s1, s2, s3);
    printf("\n");
}

void prog06() {
    printf("\tProg06\t\n");
    printf("--------------\n");
    void readLine(char buffer[]);
    
    int i;
    char line[81];
    
    for (i = 0; i < 3; i++) {
        printf("Enter text:\n");
        readLine(line);
        printf("Entered text:\n");
        printf("%s\n\n", line);
    }
    printf("\n");
}

void prog07() {
    printf("\tProg07\t\n");
    printf("--------------\n");
    int countWords(const char string[]);
    
    const char text1[] = "Well, here goes.";
    const char text2[] = "And here we go... again.";
    
    printf("%s - words = %i\n", text1, countWords(text1));
    printf("%s - words - %i\n", text2, countWords(text2));
    printf("\n");
}

int main(int argc, const char * argv[]) {
    prog01();
    prog02();
    prog03();
//    prog05();
//    prog06();
    prog07();
    
    return 0;
}
