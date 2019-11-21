#include <stdio.h>
#include <stdlib.h>

void show(int *a, int n)
{
int i;
    for(i = 0; i < n; i++)
        printf("%1d", a[i]);
    printf("\n");
}

void gen_all_numbers(int r, int n)
{
int i;
int *a;
    if(r < 2 || n < 1)          /* parameter check */
        return;
    r -= 1;                     /* r = max digit value */
    a = (int *) malloc(n * sizeof(int));
    for(i = 0; i < n; i++)      /* start with all zeroes */
        a[i] = 1;
    show(a, n);
    while(1){
        i = n - 1;
        while(a[i] < r){        /* increment last digit */
            a[i]++;
            show(a,n);
        }
        /* find next digit to increment */
        while(i >= 0 && a[i] == r)
            i--;
        if(i < 0)break;         /* return if done */
        a[i]++;
        while(++i < n)          /* zero following digits */
            a[i] = 1;
        show(a,n);
    }
    free(a);
}

int main()
{
    gen_all_numbers(3,7);
    return 0;
}
