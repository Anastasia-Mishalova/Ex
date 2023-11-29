// Ex.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
#include <algorithm>
using namespace std;

//Создайте консольную версию игры «Виселица».
//■ Слово выбирается компьютером из списка слов.
//■ Список слов находится в файле в зашифрованном виде.
//■ По завершении игры на экран выводится статистика игры :
//• количество времени;
//• количество попыток;
//• искомое слово;
//• буквы игрока.
class Game
{
private:
	const string fileName = "words.txt";
	string word;

public:

	string randomWord()
	{
		ifstream file(fileName);
		vector<string> words;

		while (file >> word)
		{
			words.push_back(word);
		}

		srand(time(nullptr));
		int i = rand() % words.size();

		return words[i];
	}

	string encryptWord(const string& word)
	{
		string encr = word;

		replace_if(encr.begin(), encr.end(), [](char a) {return isalpha(a); }, '*');
		return encr;
	}

	bool gameOver(const string& guessedWord, const string targetWord)
	{
		return guessedWord == targetWord;
	}

	void print(const string& targetWord, const string& guessedLetters, int attempts, time_t startTime)
	{
		cout << "Игра окончена! ";
		if (attempts < 6)
		{
			cout << "Вы победили!" << endl;;
		}
		cout << "* Статистика *" << endl;

		hiddenWord(targetWord, guessedLetters);
		gameTime(startTime);
		attempt(attempts);
	}

	void start()
	{
		cout << "*\t\t\tВИСЕЛИЦА\t\t\t*" << endl;
		cout << "Загадывается слово, задача - угадать его по буквам. У тебя 6 попыток! " << endl << endl << endl;
	}
	void gameTime(time_t startTime)
	{
		time_t endTime = time(nullptr);
		int elapsedTime = endTime - startTime;
		cout << "Секунд затрачено: " << elapsedTime << endl;
	}

	void attempt(int attempts)
	{
		cout << "Количество неверных попыток: " << attempts << endl;
	}

	void hiddenWord(const string& targetWord, const string& guessedLetters)
	{
		cout << "Загаданное слово: " << targetWord << endl;
		cout << "Введённые буквы: " << guessedLetters << endl;
	}

	void letterError(int attempts)
	{
		if (attempts == 1)
		{
			system("cls");
			cout << "    ****************\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n"
				"                       *\n";
		}
		else if (attempts == 2)
		{
			system("cls");
			cout << "    ********************\n"
				"                           *\n"
				"                           *\n"
				"             O             *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n";
		}
		else if (attempts == 3)
		{
			system("cls");
			cout << "    ********************\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"             O             *\n"
				"             |             *\n"
				"             |             *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n";
		}
		else if (attempts == 4)
		{
			system("cls");
			cout << "    ********************\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"             O             *\n"
				"           / | |           *\n"
				"             |             *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n";
		}
		else if (attempts == 5)
		{
			system("cls");
			cout << "    ********************\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n"
				"             O             *\n"
				"           / | |           *\n"
				"             |             *\n"
				"            / /            *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n";
		}
		else if (attempts == 6)
		{
			system("cls");
			cout << "    ********************\n"
				"             |             *\n"
				"             |             *\n"
				"             |             *\n"
				"             |             *\n"
				"             O             *\n"
				"           / | |           *\n"
				"             |             *\n"
				"            / /            *\n"
				"                           *\n"
				"                           *\n"
				"                           *\n";
		}

	}
};

//Создайте систему управления персональными финансами. Система должна иметь следующие возможности :
//■ Пополнение кошельков и карт;
//■ Внесение затрат.Каждая затрата относится к определенной категории;
//■ Формирование отчетов по затратам и категориям :
//• день;
//• неделя;
//• месяц.
//■ Формирование рейтингов по максимальным суммам :
//• ТОП - 3 затрат : неделя месяц.
//• ТОП - 3 категорий:
//неделя;
//месяц.
//■ Сохранение отчетов и рейтингов в файл


class FinManagement  // Начала, не успела
{
private:
	string name;
	int balance, pin;
	const string finFN = "fin.txt";
	ofstream accInfo;

public:

	void menu()
	{

		int i = 0;
		int num;
		cout << "\t\t\t ОПЦИИ" << endl;
		cout << "\t1. Регистрация аккаунта" << endl;
		cout << "\t2. Проверка счета" << endl;
		cout << "\t3. Внести средства на счет" << endl;
		cout << "\t4. Снять средства со счета" << endl;
		cout << "\t5. Посмотреть отчет" << endl;
		cout << "\t6. Выход" << endl;

		cin >> num;

		switch (num)
		{
		case 1:
		{
			registration();
			// регистрация
			break;
		}
		case 2:
		{
			// проверка счета
			break;
		}
		case 3:
		{
			// внести
			break;
		}
		case 4:
		{
			// снять
			break;
		}
		case 5:
		{
			// инфо
			break;
		}
		case 6:
		{
			// выход
			break;
		}
		default:
		{
			cout << "Ошибка ввода!";
			break;
		}
		}

	}

	void registration()
	{
		accInfo.open(finFN);
		cout << "Введите имя персоны: ";
		cin >> name;
		accInfo << name << "\n";

		do
		{
			cout << "Создайте пин-код (4 цифры): ";
			cin >> pin;
		} while (pin > 9999 || pin < 1000);

		accInfo << pin << "\n";
		cout << "Внесите первоначальную сумму на счет: ";
		cin >> balance;
		accInfo << balance << "\n";
		cout << "\nАккаунт создан!" << endl;
	}

	void checkingBalance()
	{
		int userPin;
		string temp;
		ifstream file2(finFN);
		vector<string> info;

		while (file2 >> temp)
		{
			info.push_back(temp);
		}
		cout << "Введите ваш пин-код: ";
		cin >> userPin;

		/*if (userPin == )*/


	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	//-----------------------------------------------------------
	Game p1;
	string targetWord = p1.randomWord();
	string guessedWord = p1.encryptWord(targetWord);
	string guessedLetters;
	time_t startTime = time(nullptr);
	int attempts = 0;


	p1.start();

	while (!p1.gameOver(guessedWord, targetWord))
	{
		cout << "Угаданное слово: " << guessedWord << endl;

		char guess;

		cout << "Введите букву: ";
		cin >> guess;

		if (guessedLetters.find(guess) != string::npos)
		{
			cout << "Вы уже вводили эту букву!" << endl;
		}

		if (targetWord.find(guess) != string::npos)
		{
			for (int i = 0; i < targetWord.length(); i++)
			{
				if (targetWord[i] == guess)
				{
					guessedWord[i] = guess;
				}
			}
		}
		else if (targetWord.find(guess) == string::npos)
		{
			cout << "Такой буквы нет! " << endl;
			attempts++;
		}

		guessedLetters += guess;
		p1.letterError(attempts);

		if (attempts == 6)
		{
			cout << "Вы проиграли!";
			break;
		}
	}

	p1.print(targetWord, guessedLetters, attempts, startTime);
	//-----------------------------------------------------------

	/*FinManagement fm;
	fm.menu();*/
}