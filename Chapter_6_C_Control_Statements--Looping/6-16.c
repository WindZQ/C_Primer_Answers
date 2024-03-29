#include <stdio.h>

int main()
{
    const float rate_Daphne = 10.0 / 100;
    const float rate_Deridre = 5.0 / 100;
    const float original_investment = 100;
    int years = 0;
    float value_Daphne = original_investment;
    float value_Deridre = original_investment;

    while(value_Daphne >= value_Deridre)
    {
        value_Daphne += original_investment * rate_Daphne;
        value_Deridre += value_Deridre * rate_Deridre;
        years++;
    }

    printf("It takes %d years for the value of Deridre's investment to exceed\nthe value of Daphne's investment.\n", years);
    printf("At that time, the value of Daphne's investment is %f,\nand the value of Deridre's investment is %f.\n", value_Daphne, value_Deridre);
    return 0;
}
