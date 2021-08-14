
#include <iostream>
#include <ctime>
#include <random> // для генератора,
#include <cstring> 
#include <algorithm>

using namespace std;

int generator(const int A, const int B)
{
	mt19937 gen(time(0));
	uniform_int_distribution<> uid(A, B);
	return uid(gen);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	const int FAIL = 8; // Макс ошибок
	const string WORD[] = { "lox","help","dadada","kakdela" };
	const string guss = WORD[generator(0, 3)]; // Выбор слова
	string sec(guss.size(), '-'), used = ""; // откоытые буквы и использованные буквы
	int att = 0; // кол неудачных попыток

	while ((att < FAIL) && (sec != guss))
	{
		cout << "Осталось попыток: " << FAIL - att << endl;
		cout << "Использованные буквы: " << used << endl;
		cout << "Отгаданное слово: " << sec << endl;

		char letter;
		cout << "Введите букву: ";
		cin >> letter;

		while (used.find(letter) != string::npos)
		{
			cout << "Эта буква уже была" << endl << "Введите другую букву: ";
			cin >> letter;
		}

		used += letter;

		if (guss.find(letter) != string::npos)
		{
			cout << "Буква угадана" << endl << endl;
			for (unsigned int i = 0; i < guss.size(); i++)
				if (guss[i] == letter)
					sec[i] = letter;
		}
		else
		{
			cout << "Не фартануло не повезло" << endl << endl;
			att++;
		}
	}
}

