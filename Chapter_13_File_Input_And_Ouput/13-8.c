#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *file;
    int ch, fct;
    int count = 0;

    if(argc < 3)
    {
        printf("Usage: %s character filename[s].\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    for(fct = 2; fct < argc; ++fct)
    {
        if((file = fopen(argv[fct], "r")) == NULL)
            fprintf(stderr, "Can't open %s.\n", argv[fct]);
        else
        {
            if(ferror(file) != 0)
                fprintf(stderr, "Error in reading file %s.\n", argv[fct]);
            ch = (char)getc(file);
            while(ch != EOF)
            {
                if(argv[1][0] == ch)
                    count++;
                ch = (char)getc(file);
            }
            printf("The character %s has appeared in file %s for %d times.\n", argv[1], argv[fct], count);
            count = 0;
            fclose(file);
        }
    }
    return 0;
}
