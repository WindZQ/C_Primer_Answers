#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int byte;
    FILE *source;
    int filect;

    if(1 == argc)
    {
        printf("Usage: %s filenams[s].\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for(filect = 1; filect < argc; ++filect)
    {
        if((source = fopen(argv[filect], "r")) == NULL)
        {
            printf("Could not open file %s for input.\n", argv[filect]);
            continue;
        }
        while((byte = getc(source)) != EOF)
            putchar(byte);
        if(fclose(source) != 0)
            printf("Could not close file %s\n", argv[1]);
    }
    return 0;
}
