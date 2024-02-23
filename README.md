# Implementation of Falcon Digital Signature

## To compute SHAKE Digest for any input file

After compilation of `shake.c`, run the code on bash with the command-line arguments as follows:

```bash
-f filepath -d desired-output-bits
```

Following is an example of how the program is run:

```bash
gcc ./shake.c -o shake.o
./shake.o -f my\ file.pdf -d 256
```

In the above example, the filename is `my file.pdf`, to use blank space in command-line argument an escape character i.e. `\` is used before blank space.

## References

- [Introduction to Algorithms- Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest and Clifford Stein](https://mitpress.mit.edu/9780262046305/introduction-to-algorithms/)
- [SHA-3 Standard: Permutation-Based Hash and
Extendable-Output Functions](https://nvlpubs.nist.gov/nistpubs/fips/nist.fips.202.pdf)
- [Falcon: Fast-Fourier Lattice-based Compact Signatures over NTRU](https://falcon-sign.info/falcon.pdf)
