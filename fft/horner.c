#include <stdio.h>
#include <stdlib.h>

// Horner's method to evaluate a polynomial
double Horner(int degree, double *coeff, double x)
{
    int i;
    double result = coeff[degree];
    for (i = degree - 1; i >= 0; i--)
        result = result * x + coeff[i];
    return result;
}

void main()
{
    int degree;
    double *coeff, result, x;

    // take the degree of polynomial as user input
    printf("Enter the degree of polynomial: ");
    scanf("%d", &degree);

    // allocate memory for the array of coefficients and take user inputs
    // if n = 3, then we need 4 coefficients
    // e.g. if 2x^3 + 3x^2 + 4x + 5, then we need 4 coefficients
    // coeff[0] = 5, coeff[1] = 4, coeff[2] = 3, coeff[3] = 2
    coeff = (double *)malloc((degree + 1) * sizeof(double));
    printf("Enter the coefficients of polynomial in increasing order of degree: ");
    for (int i = 0; i <= degree; i++)
        scanf("%lf", &coeff[i]);

    // take the value of x i.e. variable as user input
    printf("Enter the value of x: ");
    scanf("%lf", &x);

    // calculate the value of polynomial using Horner's method
    result = Horner(degree, coeff, x);
    printf("The value of polynomial is: %lf\n", result);
}