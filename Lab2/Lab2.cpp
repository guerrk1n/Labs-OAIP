

#include <iostream> // директива препроцессора
#include <math.h>
using namespace std;

int main()
{
    double x, y,function,result;
    int choose;
    cout << "Vvedite x:";
    cin >> x;
    cout << "Vvedite y:";
    cin >> y;
    cout << "Viberite funciu (1 - sh(x), 2 - x^2, 3 - e^x):";
    cin >> choose;
    switch (choose) // выбор функции
    {
    case 1: function = sinh(x);
        cout << "Vipolnaetsia 1 vetka" << endl;
        break;
    case 2: function = pow(x, 2);
        cout << "Vipolnaetsia 2 vetka" << endl;
        break;
    case 3: function = exp(x);
        cout << "Vipolnaetsia 3 vetka" << endl;
        break;
    default:
        cout << "Funcii ne vibrano,takoi funcii net";
        return 1;
    }
    if (x * y > 0) {
        result = tan(function) + (x / pow(y, 1.0 / 3.0));
        cout << "Result b= " << result;
    }
    else if (x * y < 0) {
        
        result = log(pow(function, 2)) * y;
        cout << "Result b= " << result;
    }
    else {
        
        result = pow(function, 2) + pow(sin(y), 2);
        cout << "Result b= " << result;
    }
}
