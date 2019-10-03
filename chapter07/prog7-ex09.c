#include <stdio.h>

int gcd(int u, int v) {
	int temp;

	while (v != 0) {
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

int lcm(int u, int v) {
    if (u >= 0 && v >= 0) {
        return u * v / gcd(u, v);
    } else {
        return 0;
    }
}

int main(void) {
    printf("The least common multiple of 15 and 10 is %i", lcm(15, 10));

    return 0;
}