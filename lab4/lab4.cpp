#include <iostream>
#include <ctime>
using namespace std;


const int array_length1 = 5, array_length2 = 7;
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int array1[array_length1], array2[array_length2],buffer, min, counter=0, choice;
    
    cout << "Выберите вариант заполения массивов:" << endl;
    cout << "1. Автоматически" << endl;
    cout << "2. В ручную" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    
    switch (choice) {
        
    case 1:
        for (int i = 0; i < array_length1; i++) {
            
            array1[i] = rand() % 100 - rand() % 100;
            
        }
        for (int i = 0; i < array_length2; i++) {
            array2[i] = rand() % 100 - rand() % 100;
        }

        break;
    
    case 2:

        for (int i = 0; i < array_length1; i++) {
            cout << "Введите значение array1[" << i << "]: ";
            cin >> array1[i];
        }

        for (int i = 0; i < array_length2; i++) {
            cout << "Введите значение array2[" << i << "]: ";
            cin >> array2[i];
        }
        break;
    
    default:
        cout << "Ни один из предложенных вариантов не был выбран";
        return 0;
    }

    if (choice == 1) {
        cout << "Полученные случайные массивы чисел:" << endl;
        for (int i = 0; i < array_length1; i++) {
            cout << "array1[" << i << "]: " << array1[i] << "\n";

        }

        cout << "------------------------------" << endl;
        for (int i = 0; i < array_length2; i++) {
            cout << "array2[" << i << "]: " << array2[i] << "\n";

        }
    }
    // Сортировка методом пузырька
    for (int i = 0; i < array_length1; i++){
        for (int j = 1; j < array_length1; j++) {
            if (array1[j] < array1[j -1]) {
                buffer = array1[j];
                array1[j] = array1[j - 1];
                array1[j - 1] = buffer;

            }
        }
    }
    min = array1[0];
    for (int i = 0; i < array_length1; i++) {
        for (int j = 0; j < array_length2; j++) {
            if (array1[i] != array2[j]) {
                counter++;
            }
            else {
                counter = 0;
                break;
            }
        }
        if (counter == array_length2) {
            min = array1[i];
            cout << min << endl;
            break;
        }
        if (i == array_length1 - 1) {
            cout << "Наименьше значения среди элементов первого массива, которые не входят во второй, нет";
        }
    }

    return 0;
}


