#include <stdio.h>
#include <math.h>

struct rect
{
    double x;
    double y;
};

struct polar
{
    double r;
    double theta;
};

struct rect p_to_r(const struct polar *ppol)
{
    static const double deg_red = 3.141592654 / 180.0;
    struct rect res;
    double ang = deg_red * ppol->theta;

    res.x = ppol->r * cos(ang);
    res.y = ppol->r * sin(ang);

    return res;
}

int main()
{
    struct polar input;
    struct rect answer;

    printf("Please magnitude and angle in degrees: ");
    while(scanf("%lf %lf", &input.r, &input.theta) == 2)
    {
        answer = p_to_r(&input);
        printf("polar coord: %g %g\n", answer.x, answer.y);
        printf("Please enter magnitude and angle in degrees(q to quit):");
    }
    printf("See your again!\n");
    return 0;
}
