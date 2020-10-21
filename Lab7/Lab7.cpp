#include <iostream>
using namespace std;
struct Info {
    string surname;
    string name;
    string patronymic;
    string address;
    double rating;
};

int main()
{
    setlocale(LC_ALL, "Russian");
	int number_users, counter = 0;
	string buffer_string;
	double buffer_double;

	cout << "Введите количество абитуриентов:";
	cin >> number_users;
    Info* info = new Info[number_users];
	

	cout << "Введите Фамилию, Имя, Отчество, адрес и средний балл через пробел" << endl;
	for (int i = 0; i < number_users; i++) {
		cout << "Абитуриент №" << i+1 << ": ";
		cin >> info[i].surname >> info[i].name >> info[i].patronymic >> info[i].address >> info[i].rating;
	}
	// Подсчет кол-ва абитуриентов, у который адрес Минск и средний балл >= 4.5
	for (int i = 0; i < number_users; i++) {
		if (info[i].address.compare("Minsk") == 0 && info[i].rating >= 4.5) {
			counter++;
		}
	}
	Info* info_output = new Info[counter];
	counter = 0;
	// Занесение абитуриентов, у который адрес Минск и средний балл >= 4.5, в структуру info_output для дальнейшней сортировки
	for (int i = 0; i < number_users; i++) {
		if (info[i].address.compare("Minsk") == 0 && info[i].rating >= 4.5) {
			info_output[counter].surname = info[i].surname;
			info_output[counter].name = info[i].name;
			info_output[counter].patronymic = info[i].patronymic;
			info_output[counter].address = info[i].address;
			info_output[counter].rating = info[i].rating;
			counter++;
		}
	}
	// Сортировка структуры вывода методом пузырька
	for (int i = 0; i < counter; i++) {
		for (int j = 1; j < counter; j++) {
			if ((int)(info_output[j].surname[0]) < (int)(info_output[j-1].surname[0])) {
				buffer_string = info_output[j].surname;
				info_output[j].surname = info_output[j-1].surname;
				info_output[j - 1].surname = buffer_string;

				buffer_string = info_output[j].name;
				info_output[j].name = info_output[j - 1].name;
				info_output[j - 1].name = buffer_string;

				buffer_string = info_output[j].patronymic;
				info_output[j].patronymic = info_output[j - 1].patronymic;
				info_output[j - 1].patronymic = buffer_string;

				buffer_string = info_output[j].address;
				info_output[j].address = info_output[j - 1].address;
				info_output[j - 1].address = buffer_string;

				buffer_double = info_output[j].rating;
				info_output[j].rating = info_output[j - 1].rating;
				info_output[j - 1].rating = buffer_double;
			}
		}
	}

	cout << "Фамилию, Имя, Отчество, адрес и средний балл абитуриентов, проживающие в г. Минск и со средним баллом больше 4.5" << endl;
	// Вывод итоговой структуры в алфавитном порядке ( сортировка по фамилии )
	for (int i = 0; i < counter; i++) {
		cout << info_output[i].surname << " " << info_output[i].name << " " << info_output[i].patronymic << " " << info_output[i].address << " " << info_output[i].rating <<  endl;
	}
	delete[] info;
	delete[] info_output;
	return 0;
}
