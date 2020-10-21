#include <iostream>
#include <iomanip>
using namespace std;
typedef double(*pointer)(double, double, int&);
double decomposition_y(double, double, int&);
double decomposition_s(double, double, int &);
void output(double, double, double, double, pointer);

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << setw(8) << "x" << setw(15) << "y(x)" << setw(20) << "iterations" << endl;
    output(-1, 1.3, 0.1, 10e-5, decomposition_y);
    cout << endl;
    cout << setw(8) << "x" << setw(15) << "s(x)" << setw(20) << "iterations" << endl;
    output(-1, 1.3, 0.1, 10e-5, decomposition_s);
    return 0;
}


void output(double a, double b, double h,double e, pointer pntr) {
    int iterations_number = 0;
    double sum;
    for (double x = a; x <= b+h/2; x += h) {
        sum = pntr(x, e, iterations_number);
        cout << setw(8) << x << setw(15) << sum << setw(20) << iterations_number << endl;
    }

}

double decomposition_y(double x, double e, int &iterations_number) {
    return (2 * x * sin(x) - 2 + cos(x)) / 4;
}

double decomposition_s(double x, double e, int &iterations_number) {
    double term, sum, buffer;
    sum = buffer = term;
    iterations_number = 1;
    int k = 2;
    while (term >= e) {
        term = pow(-1, k%2) * cos (k * x) / (k*k - 1);
        buffer *= -term;
        sum += term;
        iterations_number++;
        k++;
        
    }
    return sum;
}





