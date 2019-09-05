#include <stdio.h>

void to_base_n(unsigned long n, unsigned base)
{
    int r;
    r = n % base;
    if(n >= base)
        to_base_n(n / base, base);
    putchar('0' + r);
    return ;
}

int main()
{
    unsigned long number;
    unsigned base;
    int count;

    printf("Please enter integer (q to quit):");
    while(scanf("%lu", &number) == 1)
    {
        printf("Please enter the number base(2-10):");
        while((count = scanf("%lu", &base)) == 1 && (base < 2 || base > 10))
            printf("The base should be in the range 2-10:");
        if(count != 1)
            break;
        printf("Base-%u equivalent: ", base);
        to_base_n(number, base);
        putchar('\n');
        printf("Please enter an integer(q to quit):");
    }
    printf("Done!\n");
    return 0;
}
