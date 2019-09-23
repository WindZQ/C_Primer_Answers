#include <stdio.h>
#include <limits.h>

unsigned int rotate_1(unsigned int n, unsigned int b)
{
    static const int size = CHAR_BIT * sizeof(int);
    unsigned int overflow;

    b %= size;

    overflow = n >> (size - b);
    return (n << b) | overflow;
}

char *itobs(int n, char *ps)
{
    int i;
    const static int size = CHAR_BIT * sizeof(int);

    for(i = size - 1; i >= 0; --i, n >>= 1)
        ps[i] = (01 & n) + '0';
    ps[size] = '\0';

    return ps;
}

int main()
{
    unsigned int val;
    unsigned int rot;
    unsigned int places;
    char bstr1[CHAR_BIT * sizeof(int) + 1];
    char bstr2[CHAR_BIT * sizeof(int) + 1];

    printf("Please enter an integer(q to quit):");
    while(scanf("%ud", &val))
    {
        printf("Please enter the number of bits to be rotated: ");
        if(scanf("%ul", &places) != 1)
            break;
        itobs(val, bstr1);
        itobs(rot, bstr2);
        printf("%u rotated is %u.\n", val, rot);
        printf("%u rotated is %s.\n", bstr1, bstr2);
        printf("Next value: ");
    }
    puts("Done!");
    return 0;
}
