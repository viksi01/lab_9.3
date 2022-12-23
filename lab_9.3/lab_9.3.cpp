#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

struct Price
{
	string ProductName;				
	string StoreName;			
	double cost;						
};

void Create(Price* p, const int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "Товар № " << i + 1 << ":" << endl;
		cout << "Назва товару: "; cin >> p[i].ProductName;
		cout << "Назва магазину, в якому продається товар: "; cin >> p[i].StoreName;
		cout << "Вартість товару у гривнях: "; cin >> p[i].cost;
		cout << endl;
	}
}

void Print(Price* p, const int N)
{
	cout << "------------------------------------------------------"
		<< endl;
	cout << "| № | Назва товару | Назва магазину | Вартість, грн |"
		<< endl;
	cout << "------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << i + 1;
		cout << "| " << setw(13) << p[i].ProductName;
		cout << "| " << setw(14) << p[i].StoreName;
		cout << "| " << setw(15) << p[i].cost << "| " << endl;
		cout << "------------------------------------------------------"
			<< endl;
	}
	cout << endl;
}

void Sort(Price* p, const int N)
{
	Price tmp;
	for (int i = 0; i < N - 1; i++)
		for (int j = 0; j < N - i - 1; j++)
		{
			if (p[j].ProductName > p[j + 1].ProductName)
			{
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
		}
}
void Search(Price* p, const int N, string StoreName)
{
	for (int r = 0; r < N; r++)
	{
		if (p[r].StoreName == StoreName)
		{
			cout << "------------------------------------------------------"
				<< endl;
			cout << "| № | Назва товару | Назва магазину | Вартість, грн |"
				<< endl;
			cout << "------------------------------------------------------"
				<< endl;

			
				//cout << "| " << setw(2) << r + 1;
				cout << "| " << setw(13) << p[r].ProductName;
				cout << "| " << setw(14) << p[r].StoreName;
				cout << "| " << setw(15) << p[r].cost << "| " << endl;
				cout << "------------------------------------------------------"
					<< endl;
			    cout << endl;
				
		}
		
	}
	cout << "Такого магазину немає" << endl;

}



void SaveToFile(Price* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary);
	fout.write((char*)&N, sizeof(N));
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Price));
	fout.close();
}

void LoadFromFile(Price*& p, int& N, const char* filename)
{
	delete[] p;
	ifstream fin(filename, ios::binary);
	fin.read((char*)&N, sizeof(N));
	p = new Price[N];
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Price));
	fin.close();
}

int BinSearch(Price* p, const int N, const string product)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].ProductName == product)
			return m;
		if (p[m].ProductName > product)

		{
			L = m + 1;
		}

		else
		{
			R = m - 1;
		}

	} while (L <= R);
	return -1;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість товарів:  "; cin >> N;

	char filename[100];

	Price* p = new Price[N];

	int menuItem;
	string store;
	int index = -1;
	int found;

	do
	{
		cout << endl;
		cout << "Виберіть дію:" << endl
			<< "1. Введення даних" << endl
			<< "2. Вивід даних" << endl
			<< "3. Фізичне впорядкування даних" << endl
			<< "4. Вивід інформації про товари" << endl
			<< "5. Запис даних у файл" << endl
			<< "6. Зчитування даних із файлу" << endl
			<< "0. Завершити роботу програми" << endl; cin >> menuItem;
		cout << endl;

		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			Print(p, N);
			break;
		case 4:
			cin.get();
			cin.sync();
			cout << "Введіть назву магазину: "; cin >> store;
			Search(p, N, store);
			break;
			
		case 5:
			cin.get();
			cin.sync();

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 6:
			cin.get();
			cin.sync();

			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "Нерозпізнана дія\n";
		}

	} while (menuItem != 0);

	return 0;
}
