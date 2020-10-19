#include <iostream>
using namespace std;
double y(double i);

void y1(double a, double b, double h) {
    for (double i = a; i <= b; i += h) {
        cout << y(i) << endl;
    }

}

double y(double i) {
    return (2 * i * sin(i) - 2 + cos(i)) / 4;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    double a, b, e, h;
    cout << "Введите a,b,e через пробел:";
    cin >> a >> b >> e;
    h = (b - a) / 10;
    y1(a, b, h);
}



