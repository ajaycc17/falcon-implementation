#include <bits/stdc++.h>
#define PI 3.1415926535897932384626434
using namespace std;
typedef complex<double> cd;

// check if degree is power of 2 and return the next power of 2
int nearestPowerOfTwo(int degree)
{
    // if degree is 0 then return 0
    if (degree == 1 || degree == 0)
        return degree;
    double newDegree = ceil(log2(degree));
    return (int)pow(2, newDegree);
}

// bit reversal of the given number
unsigned int bit_reversal(unsigned int x, int bits)
{
    int n = 0;
    for (int i = 0; i < bits; i++)
    {
        n <<= 1;
        n |= (x & 1);
        x >>= 1;
    }
    return n;
}

// print the DFT or inverse DFT
void printDFT(vector<vector<cd>> &dft)
{
    for (int i = 0; i < dft.size(); i++)
    {
        cout << "DFT" << i + 1 << ": " << endl;
        for (int j = 0; j < dft[i].size(); j++)
            cout << dft[i][j] << endl;
        cout << endl;
    }
}

// FFT
vector<cd> fft(vector<cd> &coeff, bool invert)
{
    int degree = coeff.size();

    // if degree is 1 then return the value
    if (degree == 1)
        return vector<cd>(1, coeff[0]);

    // For n complex nth roots of unity
    cd wn;
    cd w = 1;
    double real = cos(2 * PI / degree);
    double imag = sin(2 * PI / degree) * (invert ? -1 : 1);
    wn = cd(real, imag);

    // odd and even coefficients
    vector<cd> evenCoeff(degree / 2), oddCoeff(degree / 2);
    for (int i = 0; 2 * i < degree; i++)
    {
        evenCoeff[i] = coeff[i * 2];
        oddCoeff[i] = coeff[i * 2 + 1];
    }

    // Recursive call FFT for even and odd indices
    vector<cd> yeven = fft(evenCoeff, invert);
    vector<cd> yodd = fft(oddCoeff, invert);

    // for storing values of the polynomial at chosen points
    vector<cd> y(degree);

    // adding the even and odd results
    for (int k = 0; 2 * k < degree; k++)
    {
        y[k] = yeven[k] + w * yodd[k];
        y[k + degree / 2] = yeven[k] - w * yodd[k];
        w *= wn;
        if (invert)
        {
            y[k] /= 2;
            y[k + degree / 2] /= 2;
        }
    }
    return y;
}

// non-recusive FFT
vector<cd> nrfft(vector<cd> &coeff)
{
    int degree = coeff.size();
    int bits = log2(degree);
    vector<cd> y(degree);

    // bit reversal of the given array of coefficients
    for (int i = 0; i < degree; ++i)
    {
        int rev = bit_reversal(i, bits);
        y[i] = coeff[rev];
    }

    const complex<double> iota(0, 1);
    for (int level = 1; level <= bits; ++level)
    {
        int m = 1 << level; // m = 2^s
        int mby2 = m >> 1;  // mby2 = m/2

        // initialize twiddle factor
        cd w(1, 0);

        // principle root of nth complex root of unity.
        cd wm = exp(iota * (PI / mby2));
        for (int j = 0; j < mby2; ++j)
        {
            for (int k = j; k < degree; k += m)
            {
                cd t = w * y[k + mby2];
                cd u = y[k];
                y[k] = u + t;
                y[k + mby2] = u - t;
            }
            w *= wm;
        }
    }
    return y;
}

// convolution of any two polynomials using DFTs
vector<cd> convolution(vector<vector<cd>> &dft)
{
    int degree = dft[0].size();
    vector<cd> product(degree);
    for (int i = 0; i < degree; i++)
        product[i] = dft[0][i] * dft[1][i];
    // get coefficients of the product polynomial by inverting the product dft
    return fft(product, 1);
}