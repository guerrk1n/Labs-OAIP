#include <iostream> //директра препроцессора
#include <math.h>

using namespace std; // использование пространства имен;

int main()
{
    double a,h,minuend,deduction,result,sum,r,k; // объявление вещественных переменных
    int b,n; // объявление целочисленных переменных
    cout << "Vvedite a: ";
    cin >> a;
    cout << "Vvedite b: ";
    cin >> b;
    cout << "Vvedite n: ";
    cin >> n;
    h = (b - a) / 10;

    for (double x = a; x <= b; x += h) { // цикл с шагом h
        
        r = sum = 1; // начальное значение рекуррентного ряда
        for (int i = 1; i <= n; i++) {
            k = (2 * i * i + 1) / (2 * (i - 1) * (i - 1) + 1); // коэффициент  отличия последующего члена от предыдущего  
            r = -r * x * x * k / (2 * i); // определение n-ого члена ряда
            sum += r; // сумма ряда
        }

        minuend = (1 - (pow(x, 2) / 3)) * cos(x); // вычисление уменьшаемое
        deduction = x / 2 * sin(x); // вычисление вычитаемого
        result = minuend - deduction; // вычисление разности

        cout << "x= " << x << "\t"; // вывод с горизонтальной табуляцией
        cout << "S= " << sum << "\t";
        cout << "Y= " << result << endl;
    }

    return 0;
}


