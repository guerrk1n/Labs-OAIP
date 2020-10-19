#include <iostream>
using namespace std;

const int number_users = 3;
struct Info {
    string surname;
    string name;
    string patronymic;
    string address;
    double rating;

};
struct Info_output {
	string surname;
	string name;
	string patronymic;
	string address;
	double rating;

};
int main()
{
    setlocale(LC_ALL, "Russian");
    Info info;
    Info_output info_output;
	int counter = 0;
	string buffer_string;
	double buffer_double;


	for (int i = 0; i < number_users; i++) {
		
		cin >> info.surname[i] >> info.name[i] >> info.patronymic[i] >> info.address[i] >> info.rating[i];

	}
	for (int i = 0; i < number_users; i++) {
		if (info.address[i].compare("minsk") == 0 && info.rating[i] >= 4.5) {
			info_output.surname[counter] = info.surname[i];
			info_output.name[counter] = info.name[i];
			info_output.patronymic[counter] = info.patronymic[i];
			info_output.address[counter] = info.address[i];
			info_output.rating[counter] = info.rating[i];
			counter++;
		}
	}

	// Сортировка первого массива методом пузырька
	for (int i = 0; i < counter; i++) {
		for (int j = 1; j < counter; j++) {
			if ((int)(info_output.surname[j][0]) < (int)(info_output.surname[j - 1][0])) {
				buffer_string = info_output.surname[j];
				info_output.surname[j] = info_output.surname[j - 1];
				info_output.surname[j - 1] = buffer_string;

				buffer_string = info_output.name[j];
				info_output.name[j] = info_output.name[j - 1];
				info_output.name[j - 1] = buffer_string;

				buffer_string = info_output.patronymic[j];
				info_output.patronymic[j] = info_output.patronymic[j - 1];
				info_output.patronymic[j - 1] = buffer_string;

				buffer_string = info_output.address[j];
				info_output.address[j] = info_output.address[j - 1];
				info_output.address[j - 1] = buffer_string;

				buffer_double = info_output.rating[j];
				info_output.rating[j] = info_output.rating[j - 1];
				info_output.rating[j - 1] = buffer_double;
			}
		}
	}


	for (int i = 0; i < counter; i++) {
		cout << info_output.surname[i] << " " << info_output.name[i] << " " << info_output.patronymic[i] << " " << info_output.address[i] << " " << info_output.rating[i] <<  endl;
	}

	return 0;
}
