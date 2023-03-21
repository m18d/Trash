#include<iostream>
#include<string>
#include<time.h>


using namespace std;


void PrintMas(const int* arr, int N, int comparisos, int forwarding)
{
	if (comparisos >= 0) { cout << "Число сравнений: " << comparisos << " Количество пересылок: " << forwarding << endl; }
	cout << "========================================================" << endl;
	cout << "Массив: [ ";
	for (int i = 0; i < N; i++) { cout << arr[i] << " "; }
	cout << "]" << endl;
}

void PrintMas(const int* arr, int N)
{
	cout << "========================================================" << endl;
	cout << "Массив: [ ";
	for (int i = 0; i < N; i++) { cout << arr[i] << " "; }
	cout << "]" << endl;
}

void sortingByChoice(int *&arr, int N)
{
	system("cls");
	int comparisons = -1, forwarding = 0;
	PrintMas(arr, N);
	for (int i = 0; i < N; i++)
	{
		comparisons = 0;
		int tmp = arr[i];
		int min = arr[i], minIndex;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < min)
			{
				comparisons++;
				min = arr[j];
				minIndex = j;
			}
		}
		if (min == tmp) { continue; }
		arr[i] = min;
		arr[minIndex] = tmp;
		forwarding++;
		PrintMas(arr, N, comparisons, forwarding);
	}
}

void sotringByInserts(int*& arr, int N)
{
	int tmp;
	int comparisons = -1, forwarding = 0;
	PrintMas(arr, N);
	for (int i = 1; i < N; i++)
	{
		tmp = arr[i];
		comparisons = 0;
		int j = i - 1;
		while (tmp < arr[j])
		{
			arr[j + 1] = arr[j];
			j--;
			comparisons++;
		}
		arr[j + 1] = tmp;
		forwarding++;
		PrintMas(arr, N, comparisons, forwarding);
	}
}

int isInt(string txt)
{
	char number[10] = { '0','1','2','3','4','5','6','7','8','9' };
	int Count = 0;
	for (int i = 0; i < txt.length(); i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (txt[i] == number[j])
			{
				Count++;
				break;
			}
		}
	}
	return Count;
}

int menu()
{
	while (true)
	{
		system("cls");
		cout << "==============================Меню=========================" << endl;
		cout << "1. Сортировка выбором." << endl;
		cout << "2. Сортировка вставками." << endl;
		cout << "3. Изменить размер массива." << endl;
		cout << "4. Выход." << endl;
		cout << "Ввод: ";
		string choice;
		cin >> choice;
		if (isInt(choice))
		{
			if (stoi(choice) > 0 && stoi(choice) < 5)
			{
				return stoi(choice);
			}
			else
			{
				system("cls");
				cout << "Диапазон ввода от 1 до 4 включительно!!!" << endl;
				system("pause");
			}
		}
		else
		{
			system("cls");
			cout << "На вход принимаются только числа!!!" << endl;
			system("pause");
		}
	}
}

void fillArray(int * arr, const int N)
{
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand();
	}
}

int SizeAr()
{
	while (true)
	{
		system("cls");
		cout << "==============================Количество элементов=========================" << endl;
		cout << "1.10." << endl;
		cout << "2. 100." << endl;
		cout << "3. 1000." << endl;
		cout << "4. 10000." << endl;
		cout << "Ввод: ";
		string choice;
		cin >> choice;
		if (isInt(choice))
		{
			if (stoi(choice) > 0 && stoi(choice) < 5)
			{
				switch (stoi(choice))
				{
				case 1:
					return 10;
				case 2:
					return 100;
				case 3:
					return 1000;
				case 4:
					return 10000;
				}
			}
			else
			{
				system("cls");
				cout << "Диапазон ввода от 1 до 4 включительно!!!" << endl;
				system("pause");
			}
		}
		else
		{
			system("cls");
			cout << "На вход принимаются только числа!!!" << endl;
			system("pause");
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int N = SizeAr();
	int* massiv = new int[N];
	fillArray(massiv, N);
	while (true)
	{
		switch (menu())
		{
		case 1:
			sortingByChoice(massiv, N);
			system("pause");
			break;
		case 2:
			sotringByInserts(massiv, N);
			system("pause");
			break;
		case 3:
			N = SizeAr();
			delete[] massiv;
			massiv = new int[N];
			fillArray(massiv, N);
			break;
		case 4:
			delete[] massiv;
			exit(0);
		}
	}
}