#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;

long long int fibonacciRekursion(int n)
{
	if (n == 1 || n == 2) { return 1; }
	else 
	{ 
		return fibonacciRekursion(n - 1) + fibonacciRekursion(n - 2);
	}
}

long long int fibonacciIterate(int n)
{
	if (n == 0) { return 0; }
	else if (n == 1) { return 0; }
	else if (n == 2) { return 1; }
	else if (n == 3) { return 1; }
	else
	{
		long long int obecny = 2;
		long long int poprzedni = 1;
		long long int wynik = 3;
		for (int i = 4; i < n; i++)
		{
			poprzedni = obecny;
			obecny = wynik;
			wynik = poprzedni + obecny;
		}
		return wynik;
	}
}

int main()
{
	int n = 0;
	while (n != 9090)
	{
		cout << "Podaj wyraz ciagu: ";
		cin >> n;

		auto start1 = std::chrono::steady_clock::now();
		long long int FR = fibonacciRekursion(n);
		auto end1 = std::chrono::steady_clock::now();
		auto elapsed1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - start1);

		auto start2 = std::chrono::steady_clock::now();
		long long int FI = fibonacciIterate(n);
		auto end2 = std::chrono::steady_clock::now();
		auto elapsed2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - start2);

		cout << endl;
		cout << "REKURENCJA" << endl;
		cout << "wynik: " << FR << endl;
		cout << "czas: " << elapsed1.count() << " ns" << endl;
		cout << endl;
		cout << "ITERATOR" << endl;
		cout << "wynik: " << FI << endl;
		cout << "czas: " << elapsed2.count() << " ns" << endl;
		cout << endl;
	}

	system("pause");
	return 0;
}