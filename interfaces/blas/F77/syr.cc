#include <algorithm>
#include <cctype>
#include BLAS_HEADER
#include <interfaces/blas/F77/xerbla.h>
#include <ulmblas/ulmblas.h>

extern "C" {

void
F77BLAS(ssyr)(const char        *upLo_,
              const int         *n_,
              const float       *alpha_,
              const float       *x,
              const int         *incX_,
              float             *A,
              const int         *ldA_)
{
//
//  Dereference scalar parameters
//
    bool lower   = (toupper(*upLo_) == 'L');
    int n        = *n_;
    float alpha  = *alpha_;
    int incX     = *incX_;
    int ldA      = *ldA_;

//
//  Test the input parameters
//
    int info = 0;

    if (toupper(*upLo_)!='L' && toupper(*upLo_)!='U') {
        info = 1;
    } else if (n<0) {
        info = 2;
    } else if (incX==0) {
        info = 5;
    } else if (ldA<std::max(1,n)) {
        info = 7;
    }

    if (info!=0) {
        F77BLAS(xerbla)("SSYR  ", &info);
    }

//
//  Start the operations.
//
    if (incX<0) {
        x -= incX*(n-1);
    }

    if (lower) {
        ulmBLAS::sylr(n, alpha, x, incX, A, 1, ldA);
    } else {
        ulmBLAS::sylr(n, alpha, x, incX, A, ldA, 1);
    }
}

void
F77BLAS(dsyr)(const char        *upLo_,
              const int         *n_,
              const double      *alpha_,
              const double      *x,
              const int         *incX_,
              double            *A,
              const int         *ldA_)
{
//
//  Dereference scalar parameters
//
    bool lower   = (toupper(*upLo_) == 'L');
    int n        = *n_;
    double alpha = *alpha_;
    int incX     = *incX_;
    int ldA      = *ldA_;

//
//  Test the input parameters
//
    int info = 0;

    if (toupper(*upLo_)!='L' && toupper(*upLo_)!='U') {
        info = 1;
    } else if (n<0) {
        info = 2;
    } else if (incX==0) {
        info = 5;
    } else if (ldA<std::max(1,n)) {
        info = 7;
    }

    if (info!=0) {
        F77BLAS(xerbla)("DSYR  ", &info);
    }

//
//  Start the operations.
//
    if (incX<0) {
        x -= incX*(n-1);
    }

    if (lower) {
        ulmBLAS::sylr(n, alpha, x, incX, A, 1, ldA);
    } else {
        ulmBLAS::sylr(n, alpha, x, incX, A, ldA, 1);
    }
}

} // extern "C"
