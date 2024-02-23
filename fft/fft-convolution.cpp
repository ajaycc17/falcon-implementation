#include "measure.h"

int main()
{
    // to store the time taken by recursive and non-recursive fft
    double tr, tnr;

    // some sample coefficients of polynomials
    vector<vector<cd>> coeff = {{2, 3, 5, 0, 0, 0, 7, 0},
                                {3, -11, 4, 0, -5, 10, 3, 9},
                                {2, 3, 7, 0, 0, 6, 0, 0},
                                {3, -11, 4, 0, -5, 10, 3, 9},
                                {2, 3, 5, 0, 8, 0, 0, 0},
                                {3, -1, 5, 0, -5, 10, 3, 9},
                                {2, 3, 5, 0, 0, 0, 0, 0},
                                {3, 12, 4, 0, -5, 10, 3, 9},
                                {9, 3, 7, 0, 0, 0, 0, 0},
                                {3, -5, 4, 8, -5, 10, 3, 9}};

    // size of the coefficients for polynomial multiplication
    // only two polynomials are considered for multiplication
    int numberOfPoly = coeff.size();
    int n = coeff[0].size();

    // vectors to store DFTs of the polynomials using both recursive and non-recursive fft
    vector<vector<cd>> dft(numberOfPoly), dftnr(numberOfPoly), inv_dft(numberOfPoly);
    vector<cd> product(n), inv_product(n);

    // compute dft using recursive and non-recursive fft algorithm
    for (int i = 0; i < dft.size(); i++)
    {
        dft[i] = fft(coeff[i], 0);
        dftnr[i] = fft(coeff[i], 0);
    }

    // inverting fft using recursive fft
    for (int i = 0; i < dft.size(); i++)
        inv_dft[i] = fft(dft[i], 1);

    // print the dft
    // printDFT(dft);

    // printing the inverse dft
    // printDFT(inv_dft);

    // multiplying the first two polynomials i.e. coeff[0] and coeff[1]
    inv_product = convolution(dft);

    // printing the coefficients of the product polynomial
    cout << "\nCoefficients of the product polynomial:" << endl;
    for (int i = 0; i < n; i++)
        cout << inv_product[i] << endl;

    // compare practical time taken by recursive and non-recursive fft
    tr = runtimeR(dft, coeff);
    tnr = runtimeNR(dftnr, coeff);
    cout << "Time taken by recursive fft: " << tr << endl;
    cout << "Time taken by non-recursive fft: " << tnr << endl;
    cout << "Time taken by recursive/Time taken by non-recursive: " << tr / tnr << endl;
}
