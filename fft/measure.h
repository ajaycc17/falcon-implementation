#include "fft.h"
#include <time.h>
#define compare 10000

// to calculate and print the practical time taken by the recursive fft and non-recursive fft
clock_t startt, endt;

// function to calculate run time
// for recursive fft
double runtimeR(vector<vector<cd>> &dft, vector<vector<cd>> &coeff)
{
    startt = clock();
    for (int i = 0; i < compare; i++)
    {
        for (int j = 0; j < coeff.size(); j++)
            dft[j] = fft(coeff[j], 0);
    }
    endt = clock();
    return (double)(endt - startt) / CLOCKS_PER_SEC;
}

// for non-recursive fft
double runtimeNR(vector<vector<cd>> &dftnr, vector<vector<cd>> &coeff)
{
    startt = clock();
    for (int i = 0; i < compare; i++)
    {
        for (int j = 0; j < coeff.size(); j++)
            dftnr[j] = nrfft(coeff[j]);
    }
    endt = clock();
    return (double)(endt - startt) / CLOCKS_PER_SEC;
}