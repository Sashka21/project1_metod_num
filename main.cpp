#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;


// --------------------- FUNK ---------------------
double funk(double x) {

    // Y = (x-4)*(x+3)^2
    double y, a, b;
    a = -4;
    b = 3;
    y = (x-4)*pow(x+3, 2);
    return y;

}

// --------------------- POCHODNA ---------------------
double pochodna(double x) {

    double y;

    y = 3*pow(x, 2) + 4*x - 15;
    return y;

}

// ----------------------- U(x) -----------------------
double U(double x) {

    double u;
    u = funk(x) / pochodna(x);
    return u;

}

// ----------------- ROWNIANIE ZADANE -----------------
double rownianie(double x) {

    double y = 1.0/2*x + sin(x) - M_PI/2;
    return y;
}

// ----------------- POCHODNA ZADANEGO ROWNIANIA -----------------
double poch_rown(double x) {

    double y = cos(x) + 1.0/2;
    return y;

}

// --------------- U_ROWN ---------------
double U_rown(double x) {

    double U = rownianie(x) / poch_rown(x);
    return U;

}

// ----------------------- A(x) -----------------------
double A(double x) {

    double A;
    A = x - U(x) + (U(x)*funk(x-U(x))) / (2*funk(x-U(x)) - funk(x));
    //A = x - U_rown(x) + (U_rown(x)*rownianie(x - U_rown(x))) / (2.0*rownianie(x - U_rown(x)) - rownianie(x));

    //cout << endl << x << "-" << U_rown(x) << "+(U_rown(x)*rownianie(x - U_rown(x))) / (2.0 * " << "rownianie(" << x - U_rown(x) << ")" << " - " << "rownianie(" << x << ")";
    return A;

}


// -------------------- MAIN --------------------
int main()
{

    cout.precision(15);

    int n = 20;

    double e, x = 40, x1 = 4, x2 = -3, h1, h2;
    //double e, x = 22, x1 = 1.246098386555812, x3 = M_PI, x2 = 5.037086920623774, h1, h2, h3, h=0;

    int k = 0, index = 7;

    e = pow(10, -index);

    cout << "X0 = " << x << "\t E = 1.e-" << 1+index << endl;

    do{
        x = x - U(x);
        //x = A(x);
        h1 = fabs(x1 - x) / fabs(x1);
        h2 = fabs(x2 - x) / fabs(x2);
        //h3 = fabs(x3 - x) / fabs(x3);
        k++;

        /*
        if(h1 < h2 && h1 < h3) {
            h = h1;
        }
        else if(h2 < h1 && h2 < h3) {
            h = h2;
        }

        else if(h3 < h1 && h3 < h2)
            h = h3;
        //*/


        cout << endl << endl << "X" << k << " = " << x << "\tBlad = " << h1 << "\tk = " << k;
    //}while(h1 > e && h2 > e && h3 > e);
    }while(h1 > e);
    //*/

    cout << endl;

    return 0;
}
