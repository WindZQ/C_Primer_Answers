#include <stdio.h>
#include <stdlib.h>
#define N 20

int main()
{
    int ch;
    FILE *fp;
    char file[N];
    unsigned long count = 0;

    printf("Please enter the filenames:");
    scanf("%s", file);

    if((fp = fopen(file, "r")) == NULL)
    {
        printf("Can't open %s\n",file);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch, stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %lu characters.\n", file, count);
    return 0;
}
