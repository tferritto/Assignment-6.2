#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long int poly_t;

long rCalcPoly(int x, const int c[], int n);
void rShowPoly(int x, const int c[], int degree, long value);
void rShowPolyAux(int x, const int c[], int degree, long value, int numTerm);

int main()
{
    int coeff[] = {-1, 8, -4, 7, 0, -3, -6, 2, 5};
    
    rShowPoly( -2, coeff, 0, rCalcPoly(-2, coeff, 0) );
    rShowPoly( -1, coeff, 0, rCalcPoly(-1, coeff, 0) );
    rShowPoly( 0, coeff, 0, rCalcPoly(0, coeff, 0) );
    rShowPoly( 1, coeff, 0, rCalcPoly(1, coeff, 0) );
    rShowPoly( 2, coeff, 0, rCalcPoly(2, coeff, 0) );
    cout << endl;
    rShowPoly( -2, coeff, 1, rCalcPoly(-2, coeff, 1) );
    rShowPoly( -1, coeff, 1, rCalcPoly(-1, coeff, 1) );
    rShowPoly( 0, coeff, 1, rCalcPoly(0, coeff, 1) );
    rShowPoly( 1, coeff, 1, rCalcPoly(1, coeff, 1) );
    rShowPoly( 2, coeff, 1, rCalcPoly(2, coeff, 1) );
    cout << endl;
    rShowPoly( -2, coeff, 3, rCalcPoly(-2, coeff, 3) );
    rShowPoly( -1, coeff, 3, rCalcPoly(-1, coeff, 3) );
    rShowPoly( 0, coeff, 3, rCalcPoly(0, coeff, 3) );
    rShowPoly( 1, coeff, 3, rCalcPoly(1, coeff, 3) );
    rShowPoly( 2, coeff, 3, rCalcPoly(2, coeff, 3) );
    cout << endl;
    rShowPoly( -2, coeff, 5, rCalcPoly(-2, coeff, 5) );
    rShowPoly( -1, coeff, 5, rCalcPoly(-1, coeff, 5) );
    rShowPoly( 0, coeff, 5, rCalcPoly(0, coeff, 5) );
    rShowPoly( 1, coeff, 5, rCalcPoly(1, coeff, 5) );
    rShowPoly( 2, coeff, 5, rCalcPoly(2, coeff, 5) );
    cout << endl;
    rShowPoly( -2, coeff, 8, rCalcPoly(-2, coeff, 8) );
    rShowPoly( -1, coeff, 8, rCalcPoly(-1, coeff, 8) );
    rShowPoly( 0, coeff, 8, rCalcPoly(0, coeff, 8) );
    rShowPoly( 1, coeff, 8, rCalcPoly(1, coeff, 8) );
    rShowPoly( 2, coeff, 8, rCalcPoly(2, coeff, 8) );
    cout << endl;
    
    return EXIT_SUCCESS;
}

long rCalcPoly( int x, const int c[], int n ) {
        if ( n < 0 )
            return (long) 0;
        return c[0] + x * rCalcPoly(x, c+1, n-1);
}

void rShowPoly(int x, const int c[], int n, long value){
    int numTerm = 0;
	return rShowPolyAux( x, c, n,  value, numTerm);
}

void rShowPolyAux(int x, const int c[], int n, long value, int numTerm){
    if (numTerm == 0)
        cout << "p(x,n) = p(" << x << "," << n << ") = ";
    else{
        if(c[-1] >= 0)
            cout << "+";
        cout << c[-1] << "x^" << numTerm-1 << " ";
    }
    if (n < 0){
        cout << "= " << value << endl;
        return;
    }
    rShowPolyAux(x, c+1, n-1, value, numTerm+1);
}
