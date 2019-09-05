#include <stdio.h>

void Fibonacci(int n)
{
    int Fn = 0;
    int Fn1 = 0;
    int Fn2 = 1;
    int counter = 0;

    printf("All Fibonacci numbers that smaller than %d are:\n", n);
    while(Fn < n)
    {
        printf("%d", Fn);
        printf("\n");
        Fn = Fn1 + Fn2;
        if(counter % 2 == 0)
            Fn1 = Fn;
        else
            Fn2 = Fn;
        counter++;
    }
}

int main()
{
    int n;
    printf("Please enter an integer:");
    scanf("%d", &n);
    Fibonacci(n);
    return 0;
}
