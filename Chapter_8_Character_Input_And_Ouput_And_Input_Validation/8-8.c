#include <stdio.h>

void menu(void)
{
    printf("Enter the operation of your choice:\n");
    printf("a. add           s. subtract\n");
    printf("m. multiply      d. divide\n") ;
    printf("q. quit\n");
}

int main()
{
    char choice;
    char input;
    float first_num, second_num;
    float answer;

    menu();
    while((choice = getchar()) != 'q')
    {
        while(getchar() != '\n')
            continue;

        if(choice != 'a' && choice != 's' && choice != 'm' && choice != 'd')
        {
            printf("Please enter a or s or m or d:");
            continue;
        }
        printf("Enter the first number:");
        while(scanf("%g", &first_num) != 1)
        {
            while((input = getchar()) != '\n')
                putchar(input);
            printf("is not an number.\n");
            printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
        }
        printf("Enter the second number:");
                while (scanf("%g", &second_num) != 1 || (second_num == 0 && choice == 'd'))
        {
            if (second_num != 0) // if "scanf("%g", &second_num) != 1"
            {
                while ((input = getchar()) != '\n')
                    putchar(input);
                printf(" is not an number.\n");
                printf("Please enter a number, such as 2.5, -1.78E8, or 3: ");
            }
            else // if "second_num == 0 && choice == 'd' "
            {
                while (getchar() != '\n')
                    continue;
                printf("Enter a number other than 0: ");
                second_num = -1; // so that "second_num != 0" again
            }
        }
        while (getchar() != '\n')
            continue;

        switch (choice)
        {
            case 'a': answer = first_num + second_num;
                      printf("%g + %g = %g\n", first_num, second_num, answer);
                      break;

            case 's': answer = first_num - second_num;
                      printf("%g - %g = %g\n", first_num, second_num, answer);
                      break;

            case 'm': answer = first_num * second_num;
                      printf("%g * %g = %g\n", first_num, second_num, answer);
                      break;

            case 'd': answer = first_num / second_num;
                      printf("%g / %g = %g\n", first_num, second_num, answer);
                      break;

            default : return 0;
        }
        menu();
    }
    printf("See your again!\n");
    return 0;
}
