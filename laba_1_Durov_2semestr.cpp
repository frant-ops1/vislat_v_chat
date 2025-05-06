#include <iostream>
#include <iomanip>
#include <cstdlib>  // Для rand() и srand()
#include <ctime>    // Для time()
#include <locale.h>
using namespace std;

int main() {
	setlocale(LC_ALL,"Russian");
	const int MAX_N = 10;
	int N;
	double A[MAX_N][MAX_N];

	// Инициализация генератора случайных чисел
	srand(time(0));

	// Ввод размера матрицы
	cout << "Введите размер матрицы N (N <= 10): ";
	cin >> N;

	// Проверка на корректность размера
	if (N <= 0 || N > MAX_N) {
		cout << "Некорректный размер матрицы!" << endl;
		return 1;
	}

	// Автоматическое заполнение матрицы случайными значениями от 0.0 до 99.99
	cout << "Сгенерированная матрица:" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = (rand() % 10000) / 100.0; // Генерация чисел от 0.00 до 99.99
			cout << fixed << setprecision(2) << setw(8) << A[i][j];
		}
		cout << endl;
	}

	// Вычисление и вывод среднего арифметического четных строк
	cout << "\nСреднее арифметическое четных строк:" << endl;
	for (int i = 1; i < N; i += 2) { // Четные строки (индексация с 0)
		double sum = 0.0;
		for (int j = 0; j < N; j++) {
			sum += A[i][j];
		}
		double average = sum / N;
		cout << "Строка " << i + 1 << ": " << fixed << setprecision(2) << average << endl;
	}

	return 0;
}