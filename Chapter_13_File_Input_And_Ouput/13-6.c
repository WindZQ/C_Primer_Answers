#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10

int main()
{
    FILE *in, *out;
    int ch;
    char dest[N], source[N];
    int count = 0;

    printf("Please enter the source file name:");
    scanf("%s", source);

    if((in = fopen(source, "r")) == NULL)
    {
        fprintf(stderr, "I couldn't open the file \"%s\"\n", source);
        exit(EXIT_FAILURE);
    }

    strncpy(dest, source, N - 5);
    dest[N - 5] = '\0';
    strcat(dest, ".red");
    if((out = fopen(dest, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    while((ch = getc(in)) != EOF)
    {
        if(count++ % 3 == 0)
            putc(ch, out);
    }

    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files.\n");

    return 0;
}
