#include <iostream>
#include <windows.h>
#include <time.h>
#include <iomanip>
using namespace std;
struct Elem
{
	Elem* link;
	int info;
};
void CreateCycle(Elem*& first, int N, int Low, int High);
void Insert(Elem*& L, int value);
void Scanning(Elem* L, int x);
void Remove(Elem*& L);
void Print(Elem* L);
int main()
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Elem* L = NULL;
	int Low, High, N, x;
	cout << "Найменший елемент списку: "; cin >> Low;
	cout << "Найбільший елемент списку: "; cin >> High;
	cout << "Кількість елементів списку: "; cin >> N;
	cout << "Значення інформаційного поля: "; cin >> x;
	CreateCycle(L, N, Low, High);
	cout << "Оригінальний список:" << endl;
	Print(L);
	cout << "Новий список:" << endl;
	Scanning(L, x);
	Print(L);
	system("pause");
	return 0;
}
void CreateCycle(Elem*& first, int N, int Low, int High)
{
	for (int i = 0; i < N; i++)
	{
		int value = Low + rand() % (High - Low + 1);
		Insert(first, value);
	}
}
void Insert(Elem*& L, int value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;
		T->link = tmp;
	}
	else
	{
		L = tmp;
	}
	tmp->link = L;
}
void Scanning(Elem* L, int x)
{
	if (L == NULL)
		return;

	Elem* first = L;
	while (L->link != first)
	{
		if (L->info == x)
			Remove(L);
		else
			L = L->link;
	}
}
void Remove(Elem*& L)
{
	Elem* T = L->link;
	while (T->link != L->link)
		T = T->link;

	if (T != L->link)
	{
		Elem* tmp = L->link->link;
		delete L->link;
		L->link = tmp;
		T->link = L->link;
	}
	else
	{
		delete L->link;
		L->link = NULL;
	}
}

void Print(Elem* L)
{
	if (L == NULL)
		return;

	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}
