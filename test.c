#include <stdio.h>

int main()
{

    int a, b;
    printf("enter two number");
    scanf("%d%d", &a, &b);

    if (a > b)
        printf("A is big number");
    else
        printf("B is big number");

    return 0;
}