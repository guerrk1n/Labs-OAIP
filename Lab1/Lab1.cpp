
#include <iostream> // директива препроцессора
#include <math.h>
using namespace std;

int main()
{
    double x, y, z,s,first_term,numerator,denominator,second_term;
    cout << "Vvedite x:";
    cin >> x; // операция взятия из потока
    cout << "Vvedite y:";
    cin >> y;
    cout << "Vvedite z:";
    cin >> z;
    first_term = pow(y, pow(abs(x),1.0/3.0)); // Вычисление первого слагаемого
    numerator = (abs(x - y)) * (1 + (pow(sin(z), 2) / sqrt(x + y))); //Вычисления числителя дроби
    denominator = exp(abs(x - y)) + (x / 2); // Вычисления знаменателя дроби
    second_term = pow(cos(y), 3) * numerator / denominator; // Вычисления второго слагаемого
    s = first_term + second_term;
    cout << "Result s= " << s;
}

    
