﻿#include <iostream>
#include <ctime>
using namespace std;
const int N = 3, M = 3;
int main()
{
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    int array1[N][M], choice,min_row,min_index,max;
    bool found;

    cout << "Выберите вариант заполения массивов:" << endl;
    cout << "1. Автоматически" << endl;
    cout << "2. В ручную" << endl;
    cout << "Ваш выбор: ";
    cin >> choice;
    switch (choice) {

    case 1:
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                array1[i][j] = rand() % 100 - rand() % 100;
            }
        }
        break;

    case 2:

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << "array1[" << i << "][" << j << "]: ";
                cin >> array1[i][j];
                
                

            }
            cout << "\n";
        }
        break;

    default:
        cout << "Ни один из предложенных вариантов не был выбран";
        return 0;
    }

    if (choice == 1) {
        cout << "Полученн массив случайных чисел:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << array1[i][j] << "\t";

            }
            cout << "\n";
        }
    }
    else {
        cout << "Полученн набор введеных чисел:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cout << array1[i][j] << "\t";

            }
            cout << "\n";
        }
    }
    
    found = false;
    for (int i = 0; i < N; i++) {
        min_row = array1[i][0];
        min_index = 0;

        for (int j = 0; j < M; j++) {
            if (min_row > array1[i][j]) {
                min_row = array1[i][j];
                min_index = j;
            }
        }
        int f;
        for (f = 0; f < M; f++) {
            if (min_row < array1[f][min_index]) {
                break;
            }

        }
        if (f == N) {
        
            cout << "Значение седловой точки: " << min_row << endl;
            found = true;
            
        }

        else if (f == N-1 && found == false) {
       
            cout << "Седловой точки нет ";
           
        }
    }


}

