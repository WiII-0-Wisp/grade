#include <iostream>
#include <string>
#include <cstdlib>
#include <Windows.h>

int main() {
	using namespace std;
	setlocale(0, "");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, max_i;
	double sum, sum_coef, max;
	string* names;
	double** mas;
	double* mas_sum, * mas_coef;
	cout << "Введите количество критериев оценки предмета (1 <= N <= 7): ";
	cin >> N;
	cout << endl;
	names = new string[N];
	mas = new double* [N];
	mas_sum = new double[N];
	mas_coef = new double[N];
	for (int i = 0; i < N; i++) {
		mas[i] = new double[N];
		cout << "Введите критерий №" << i + 1 << ": ";
		cin >> names[i];
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		mas[i][i] = 1;
		for (int j = i + 1; j < N; j++) {
			cout << "На сколько критерий <<" << names[i] << ">> важнее критерия <<" << names[j] << ">>? : ";
			cin >> mas[i][j];
			mas[j][i] = 1 / mas[i][j];
		}
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	sum = 0;
	for (int i = 0; i < N; i++) {
		mas_sum[i] = 0;
		for (int j = 0; j < N; j++) {
			mas_sum[i] += mas[i][j];
		}
		sum += mas_sum[i];
	}

	for (int i = 0; i < N; i++) {
		cout << mas_sum[i] << " ";
	}
	cout << "\nИтого: " << sum << endl << endl;

	sum_coef = 0;
	for (int i = 0; i < N; i++) {
		mas_coef[i] = mas_sum[i] / sum;
		sum_coef += mas_coef[i];
	}

	for (int i = 0; i < N; i++) {
		cout << mas_coef[i] << " ";
	}
	cout << "\nИтого: " << sum_coef;

	cout << "\n\n----------Округление----------\n\n";

	sum_coef = 0;
	for (int i = 0; i < N; i++) {
		mas_coef[i] = round(mas_coef[i] * 100) / 100;
		sum_coef += mas_coef[i];
		cout << mas_coef[i] << " ";
	}
	cout << "\nИтого: " << sum_coef;

	cout << "\n\n----------Пересчёт округления----------\n\n";

	max = -1;
	for (int i = 0; i < N; i++) {
		if (max < mas_coef[i]) {
			max = mas_coef[i];
			max_i = i;
		}
	}
	if (sum_coef > 1) {
		mas_coef[max_i] = mas_coef[max_i] - (sum_coef - 1);
	}
	else {
		mas_coef[max_i] = mas_coef[max_i] + (1 - sum_coef);
	}

	sum_coef = 0;
	for (int i = 0; i < N; i++) {
		sum_coef += mas_coef[i];
		cout << mas_coef[i] << " ";
	}
	cout << "\nИтого: " << sum_coef << "\n\n";

	for (int i = 0; i < N; i++) {
		delete[] mas[i];
	}
	delete[] names, mas;
	system("pause");
	return 0;
}

