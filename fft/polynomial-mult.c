// naive method for polynomial multiplication - O(n^2)
#include <stdio.h>
#include <stdlib.h>

void main()
{
    // take first polynomial as user input
    int deg1, deg2;
    double *coeff1, x1, *coeff2, x2;

    printf("Enter the degree of polynomial 1: ");
    scanf("%d", &deg1);

    coeff1 = (double *)malloc((deg1 + 1) * sizeof(double));
    printf("Enter the coefficients of polynomial 1 in increasing order of degree: ");
    for (int i = 0; i <= deg1; i++)
        scanf("%lf", &coeff1[i]);

    // take second polynomial as user input
    printf("Enter the degree of polynomial 2: ");
    scanf("%d", &deg2);

    coeff2 = (double *)malloc((deg2 + 1) * sizeof(double));
    printf("Enter the coefficients of polynomial 2 in increasing order of degree: ");
    for (int i = 0; i <= deg2; i++)
        scanf("%lf", &coeff2[i]);

    // multiply the two polynomials
    double *coeff3;
    int deg3 = deg1 + deg2;
    coeff3 = (double *)malloc((deg3 + 1) * sizeof(double));

    for (int i = 0; i <= deg3; i++)
        coeff3[i] = 0;

    for (int i = 0; i <= deg1; i++)
    {
        for (int j = 0; j <= deg2; j++)
        {
            coeff3[i + j] += coeff1[i] * coeff2[j];
        }
    }

    // print the coefficients of the multiplied polynomial
    for (int i = 0; i <= deg3; i++)
        printf("%lf ", coeff3[i]);
}