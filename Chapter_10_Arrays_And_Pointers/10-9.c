#include <stdio.h>
#define N 4
void function(int array1[], int array2[], int array3[], int number)
{
    for(int i = 0; i < number; ++i)
        array3[i] = array1[i] + array2[i];
}

int main()
{
    int array1[N] = {2, 4, 5, 8};
    int array2[N] = {1, 0, 4, 6};
    int array3[N];

    function(array1, array2, array3, N);
    printf("The contents of the third array:");
    for(int i = 0; i < N; ++i)
        printf("%d ", array3[i]);
    printf("\n");
    return 0;
}
