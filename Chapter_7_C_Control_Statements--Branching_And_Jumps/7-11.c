#include <stdio.h>
#define artichoke_per_pound 1.25
#define beet_per_pound 0.65
#define carrot_per_pound 0.89
#define discount_tier 100
#define discount_rate 0.05
#define shipping_tier_1 5
#define shipping_tier_2 20
#define shipping_cost_1 6.50
#define shipping_cost_2 14.00
#define shipping_cost_3 0.50

int main()
{
    char choice;
    float pounds_of_artichokes = 0, pounds_of_beets = 0, pounds_of_carrots = 0, pounds_of_all = 0;
    float new_pounds_of_artichokes, new_pounds_of_beets, new_pounds_of_carrots;
    float total_charges, discount = 0, shipping_charges, grand_total;
    float cost_for_artichokes, cost_for_beets, cost_for_carrots;

    printf("Please order:\n");
    printf("a. artichokes\n");
    printf("b. beets\n");
    printf("c. carrots\n");
    printf("q. Finished!\n");

        while ((choice = getchar()) != 'q')
    {
        if (choice == '\n')
            continue;
        while (getchar() != '\n')
            continue;
        switch (choice)
        {
            case 'a' : printf("How many pounds of artichokes do you want to add?\n");
                       while (scanf("%f", &new_pounds_of_artichokes) != 1)
                       {
                            printf("Please enter a number:\n");
                            while (getchar() != '\n')
                                continue;
                       }
                       pounds_of_artichokes += new_pounds_of_artichokes;
                       break;

            case 'b' : printf("How many pounds of beets do you want to add?\n");
                       while (scanf("%f", &new_pounds_of_beets) != 1)
                       {
                            printf("Please enter a number:\n");
                            while (getchar() != '\n')
                                continue;
                       }
                       pounds_of_beets += new_pounds_of_beets;
                       break;

            case 'c' : printf("How many pounds of carrots do you want to add?\n");
                       while (scanf("%f", &new_pounds_of_carrots) != 1)
                       {
                            printf("Please enter a number:\n");
                            while (getchar() != '\n')
                                continue;
                       }
                       pounds_of_carrots += new_pounds_of_carrots;
                       break;

            default  : printf("Please enter 'a' or 'b' or 'c' or 'q':\n");
        }
        printf("Please order:\n");
        printf("a. artichokes\n");
        printf("b. beets\n");
        printf("c. carrots\n");
        printf("q. Finished!\n");
    }

    cost_for_artichokes = artichoke_per_pound * pounds_of_artichokes;
    cost_for_beets = beet_per_pound * pounds_of_beets;
    cost_for_carrots = carrot_per_pound * pounds_of_carrots;

    total_charges = cost_for_artichokes + cost_for_beets + cost_for_carrots;

    if (total_charges >= discount_tier)
        discount = total_charges * discount_rate;

    pounds_of_all = pounds_of_artichokes + pounds_of_beets + pounds_of_carrots;
    if (pounds_of_all <= 0)
        shipping_charges = 0;
    else if (pounds_of_all < shipping_tier_1)
        shipping_charges = shipping_cost_1;
    else if (pounds_of_all > shipping_tier_1 && pounds_of_all < shipping_tier_2)
        shipping_charges = shipping_cost_2;
    else
        shipping_charges = shipping_cost_2 + (pounds_of_all - shipping_tier_2) * shipping_cost_3;

    grand_total = total_charges - discount + shipping_charges;

    printf("The price of artichoke is $%g per pound, and you ordered %g pounds,\nso it's $%g pounds for artichokes.\n",
            artichoke_per_pound, pounds_of_artichokes, cost_for_artichokes);
    printf("The price of beet is $%g per pound, and you ordered %g pounds,\nso it's $%g pounds for beets.\n",
            beet_per_pound, pounds_of_beets, cost_for_beets);
    printf("The price of carrot is $%g per pound, and you ordered %g pounds,\nso it's $%g pounds for carrots.\n",
            carrot_per_pound, pounds_of_carrots, cost_for_carrots);
    printf("The total cost of the order is $%g.\n", total_charges);
    printf("The discount is $%g.\n", discount);
    printf("The shipping charge is $%g.\n", shipping_charges);
    printf("The grand total of all charges is $%g.\n", grand_total);
    return 0;
}
