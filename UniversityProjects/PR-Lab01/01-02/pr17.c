//
// Created by Eric Golovin on 9/24/19.
//

int main(void) {
    double x = 1;
    double indexX = 0.5;
    double a = 2;
    double indexA = 1;

    for (a = 2; a <= 10; x += indexX, a += indexA) {
        printf("a2 + x = %lf", pow(a, 2) + x);
    }

    return 0;
}
