#include <iostream>
using namespace std;

const int number_users = 1;
struct Info {
    string surname[number_users];
    string name[number_users];
    string patronymic[number_users];
    string address[number_users];
    double rating[number_users];

};
int main()
{
    setlocale(LC_ALL, "Russian");
    Info info;
    for (int i = 1; i <= number_users; i++) {
        cout << "Фамилия абитуриента " << i << " : ";
        cin >> info.surname[i];
        cout << "Имя абитуриента " << i << " : ";
        cin >> info.name[i];
        cout << "Отчетсов абитуриента " << i << " : ";
        cin >> info.patronymic[i];
        cout << "Адрес абитуриента " << i << " : ";
        cin >> info.address[i];
        cout << "Средний балл " << i << " : ";
        cin >> info.rating[i];

    }

    for (int i = 1; i <= number_users; i++) {
        if (info.address[i] == "Минск" && info.address[i] == "минск" && info.rating[i] >= 4.5) {
        cout << 
        }
    }

}
