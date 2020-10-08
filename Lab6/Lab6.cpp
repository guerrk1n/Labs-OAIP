#include <iostream>

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian"); // Функция устанавливает определенный параметр для поддержки кирилицы в консоли
	char sent[] = "wikipedia is a free online encyclopedia created and edited by volunteers around the world and hosted by the wikimedia foundation";
	int buffer, length_sent = strlen(sent), number_spaces = 0;

	cout << "Исходная строка: " << sent << endl;

	// Подсчитываем кол-во пробелов. Кол-во слов = кол-во пробелов + 1
	for (int i = 0; i < length_sent; i++) {
		if (sent[i] == ' ') {
			number_spaces++;
		}
	}

	// Обьявление динамического массива words, который хранит первую букву каждого слова
	int* words = new int[number_spaces + 1];
	words[0] = sent[0];
	int counter = 1;
	// Занесение каждой первой буквы в массив words
	for (int i = 0; i < length_sent; i++) {
		if (sent[i] == ' ') {
			words[counter] = (int)sent[i + 1]; // занесение значения буквы в массив words
			counter++;
		}

	}
	// Сортировка массива words методом пузырька, для расставления в алфавитном порядке
	for (int i = 0; i < number_spaces+1; i++) {
		for (int j = 1; j < number_spaces+1; j++) {
			if (words[j] < words[j - 1]) {
				buffer = words[j];
				words[j] = words[j - 1];
				words[j - 1] = buffer;

			}
		}
	}
	// Каждой букве массива words соотв. своё слово из исходного массива. 
	// Алгоритм выводит итоговые слова в алфавитном порядке
	cout << "Полученная строка: ";
	for (int i = 0; i < number_spaces + 1; i++) {
		for (int j = 0; j < length_sent; j++) {
			if (words[i] == sent[j] && sent[j-1] == ' ' || words[i] == sent[j] && j == 0){
				int p = j;
				while (sent[p] != ' ' && p < length_sent) {
					cout << sent[p];
					sent[p] = (char)((int)(sent[p]) - 32);
					p++;
				}
				cout << " ";
			
			}
		}
	}
	cout << endl;
	delete[] words;
	return 0;
}