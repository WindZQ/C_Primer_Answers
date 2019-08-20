#include <stdio.h>
#include <float.h>

int main()
{
    double nd = 1.0 / 3.0;
    float fd = 1.0 / 3.0;

    printf("double values:");
    printf("%.4lf %.12lf %.16lf\n", nd, nd, nd);
    printf("float values:");
    printf("%.4lf %.12lf %.16lf\n", fd, fd, fd);
    printf("\n");

    printf("float precision = %d digits\n", FLT_DIG);
    printf("double precision = %d digits\n", DBL_DIG);
    return 0;
}
