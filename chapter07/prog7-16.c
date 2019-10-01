#include <stdio.h>

void autop_static(void) {
    int autoVar = 1; // or auto int autoVar = 1;
    static int staticVar = 1;

    printf("automatic = %i, static = %i\n", autoVar, staticVar);

    autoVar++;
    staticVar++;
}

int main(void) {
    int i;
    void autop_static(void);

    for (i = 0; i < 5; i++) {
        autop_static();
    }
    return 0;
}