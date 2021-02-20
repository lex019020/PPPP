#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void print_matrix(int** matrix, int m, int n, const char caption[]);
void init_zero_matrix(int** matrix, int m, int n);
void fill_submatrix(int** source, int** dest, int size, int i_delta, int j_delta);

int main()
{
	srand(time(NULL));
	int matr_1_size_n, matr_1_size_m, matr_2_size_n, matr_2_size_m, fill_method, matr_size_max = 2;
	system("chcp 1251");
	cout << "Вас приветствует программа" << endl <<
		"быстрого перемножения матриц методом Штрассена\n\n";

	//	Ввод размеров матрицы пользователем
	do
	{
		cout << "Введите размеры первой матрицы\n";
		cin >> matr_1_size_n >> matr_1_size_m;
	} while (matr_1_size_n <= 0 || matr_1_size_m <= 0);

	do
	{
		cout << "Введите размеры второй матрицы\n";
		cin >> matr_2_size_n >> matr_2_size_m;
	} while (matr_2_size_n <= 0 || matr_2_size_m <= 0);

	auto matrix_1 = new int* [matr_1_size_n];
	for (auto i = 0; i < matr_1_size_n; i++)
		matrix_1[i] = new int[matr_1_size_m];

	auto matrix_2 = new int* [matr_2_size_n];
	for (auto i = 0; i < matr_2_size_n; i++)
		matrix_2[i] = new int[matr_2_size_m];

	//	Выбор способа заполнения и заполнение матриц
	do
	{
		cout << "Выберите способ заполнения матриц\n" <<
			"1 - Вручную \n2 - Случайным образом\n";
		cin >> fill_method;
	} while (fill_method < 1 || fill_method > 2);

	switch (fill_method)
	{
	case 1:
		for (auto i = 0; i < matr_1_size_n; i++)
			for (auto j = 0; j < matr_1_size_m; j++)
				cin >> matrix_1[i][j];

		for (auto i = 0; i < matr_2_size_n; i++)
			for (auto j = 0; j < matr_2_size_m; j++)
				cin >> matrix_2[i][j];

		print_matrix(matrix_1, matr_1_size_m, matr_1_size_n, "Матрица 1");
		print_matrix(matrix_2, matr_2_size_m, matr_2_size_n, "Матрица 2");

		break;

	case 2:
		for (auto i = 0; i < matr_1_size_n; i++)
			for (auto j = 0; j < matr_1_size_m; j++)
				matrix_1[i][j] = rand() % 10;

		for (auto i = 0; i < matr_2_size_n; i++)
			for (auto j = 0; j < matr_2_size_m; j++)
				matrix_2[i][j] = rand() % 10;

		print_matrix(matrix_1, matr_1_size_m, matr_1_size_n, "Матрица 1");
		print_matrix(matrix_2, matr_2_size_m, matr_2_size_n, "Матрица 2");

		break;
	}

	//	Приведение матриц к требуемому размеру

	while (matr_size_max < matr_1_size_n || matr_size_max < matr_2_size_n 
		|| matr_size_max < matr_1_size_m || matr_size_max < matr_2_size_m)
			matr_size_max *= 2;

	auto matrix_1_resized = new int* [matr_size_max];
	init_zero_matrix(matrix_1_resized, matr_size_max, matr_size_max);

	auto matrix_2_resized = new int* [matr_size_max];
	init_zero_matrix(matrix_2_resized, matr_size_max, matr_size_max);

	for (auto i = 0; i < matr_1_size_n; i++)
	{
		for (auto j = 0; j < matr_1_size_m; j++)
			matrix_1_resized[i][j] = matrix_1[i][j];
	}

	for (auto i = 0; i < matr_2_size_n; i++)
	{
		for (auto j = 0; j < matr_2_size_m; j++)
			matrix_2_resized[i][j] = matrix_2[i][j];
	}

	cout << "Приведенные матрицы\n";

	print_matrix(matrix_1_resized, matr_size_max, matr_size_max, "Матрица 1");
	print_matrix(matrix_2_resized, matr_size_max, matr_size_max, "Матрица 2");

	//	Разбиение матриц на подматрицы и их заполнение
	auto sub_matrix_1 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_1_resized, sub_matrix_1, 
		matr_size_max / 2, 0, 0);

	auto sub_matrix_2 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_1_resized, sub_matrix_2, 
		matr_size_max / 2, 0, matr_size_max / 2);

	auto sub_matrix_3 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_1_resized, sub_matrix_3, 
		matr_size_max / 2, matr_size_max / 2, 0);

	auto sub_matrix_4 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_1_resized, sub_matrix_4,
		matr_size_max / 2, matr_size_max / 2, matr_size_max / 2);

	auto sub_matrix_5 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_2_resized, sub_matrix_5,
		matr_size_max / 2, 0, 0);

	auto sub_matrix_6 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_2_resized, sub_matrix_6, 
		matr_size_max / 2, 0, matr_size_max / 2);

	auto sub_matrix_7 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_2_resized, sub_matrix_7,
		matr_size_max / 2, matr_size_max / 2, 0);

	auto sub_matrix_8 = new int* [matr_size_max / 2];
	fill_submatrix(matrix_2_resized, sub_matrix_8, 
		matr_size_max / 2, matr_size_max / 2, matr_size_max / 2);

	
	//	Создание промежуточных матриц

	auto intermed_matr_1 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_1, matr_size_max / 2, matr_size_max / 2);

	auto intermed_matr_2 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_2, matr_size_max / 2, matr_size_max / 2);

	auto intermed_matr_3 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_3, matr_size_max / 2, matr_size_max / 2);

	auto intermed_matr_4 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_4, matr_size_max / 2, matr_size_max / 2);

	auto intermed_matr_5 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_5, matr_size_max / 2, matr_size_max / 2);

	auto intermed_matr_6 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_6, matr_size_max / 2, matr_size_max / 2);

	auto intermed_matr_7 = new int* [matr_size_max / 2];
	init_zero_matrix(intermed_matr_7, matr_size_max / 2, matr_size_max / 2);

	//	Вычисление значений промежуточных матриц

	for (auto i = 0; i < matr_size_max / 2; i++)
	{
		for (auto j = 0; j < matr_size_max / 2; j++)
		{
			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_1[i][j] += (sub_matrix_1[i][z] + sub_matrix_4[i][z]) *
					(sub_matrix_5[z][j] + sub_matrix_8[z][j]);
			}

			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_2[i][j] += (sub_matrix_3[i][z] + sub_matrix_4[i][z]) *
					sub_matrix_5[z][j];
			}

			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_3[i][j] += sub_matrix_1[i][z] *
					(sub_matrix_6[z][j] - sub_matrix_8[z][j]);
			}

			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_4[i][j] += sub_matrix_4[i][z] * 
					(sub_matrix_7[z][j] - sub_matrix_5[z][j]);
			}

			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_5[i][j] += (sub_matrix_1[i][z] + sub_matrix_2[i][z]) * 
					sub_matrix_8[z][j];
			}

			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_6[i][j] += (sub_matrix_3[i][z] - sub_matrix_1[i][z]) * 
					(sub_matrix_5[z][j] + sub_matrix_6[z][j]);
			}

			for (auto z = 0; z < matr_size_max / 2; z++)
			{
				intermed_matr_7[i][j] += (sub_matrix_2[i][z] - sub_matrix_4[i][z]) * 
					(sub_matrix_7[z][j] + sub_matrix_8[z][j]);
			}
		}
	}

	//	Создание вспомогательных матриц

	auto support_matr_1 = new int* [matr_size_max / 2];
	init_zero_matrix(support_matr_1, matr_size_max / 2, matr_size_max / 2);

	auto support_matr_2 = new int* [matr_size_max / 2];
	init_zero_matrix(support_matr_2, matr_size_max / 2, matr_size_max / 2);

	auto support_matr_3 = new int* [matr_size_max / 2];
	init_zero_matrix(support_matr_3, matr_size_max / 2, matr_size_max / 2);

	auto support_matr_4 = new int* [matr_size_max / 2];
	init_zero_matrix(support_matr_4, matr_size_max / 2, matr_size_max / 2);

	//	Подсчет значений вспомогательных матриц из промежуточных

	for (auto i = 0; i < matr_size_max / 2; i++)
	{
		for (auto j = 0; j < matr_size_max / 2; j++)
		{
			support_matr_1[i][j] = intermed_matr_1[i][j] + intermed_matr_4[i][j]
				- intermed_matr_5[i][j] + intermed_matr_7[i][j];
			
			support_matr_2[i][j] = intermed_matr_3[i][j] + intermed_matr_5[i][j];
			
			support_matr_3[i][j] = intermed_matr_2[i][j] + intermed_matr_4[i][j];
			
			support_matr_4[i][j] = intermed_matr_1[i][j] - intermed_matr_2[i][j]
				+ intermed_matr_3[i][j] + intermed_matr_6[i][j];
		}
	}

	//	Создание результирующей матрицы

	auto result_matrix = new int* [matr_size_max];
	for (auto i = 0; i < matr_size_max; i++)
	{
		result_matrix[i] = new int[matr_size_max];
	}

	//	Занесение информации из вспомогательных матриц в результирующую

	for (auto i = 0; i < matr_size_max / 2; i++)
	{
		for (auto j = 0; j < matr_size_max / 2; j++)
		{
			result_matrix[i][j] = support_matr_1[i][j];
			
			result_matrix[i][j + matr_size_max / 2] = support_matr_2[i][j];
			
			result_matrix[i + matr_size_max / 2][j] = support_matr_3[i][j];
			
			result_matrix[i + matr_size_max / 2][j + matr_size_max / 2] = 
				support_matr_4[i][j];
		}
	}

	//	Выравнивание границ результирующей матрицы

	auto x = 0, final_matrix_n = 100, final_matrix_m = 100;
	for (auto i = 0; i < matr_size_max; i++)
	{
		x = 0;
		for (auto j = 0; j < matr_size_max; j++)
		{
			if (result_matrix[i][j] != 0)
			{
				x++;
				final_matrix_n = 100;
			}
		}
		if (x == 0 && i < final_matrix_n)
		{
			final_matrix_n = i;
		}
	}
	
	for (auto i = 0; i < matr_size_max; i++)
	{
		x = 0;
		for (auto j = 0; j < matr_size_max; j++)
		{
			if (result_matrix[j][i] != 0)
			{
				x++;
				final_matrix_m = 100;
			}
		}
		if (x == 0 && i < final_matrix_m)
		{
			final_matrix_m = i;
		}
	}


	//	Вывод результирующей матрицы
	print_matrix(result_matrix, final_matrix_m, final_matrix_n, 
		"Результирующая матрица");

	system("pause");

	//	Очистка динамической памяти

	for (auto i = 0; i < matr_1_size_n; i++)
		delete[] matrix_1[i];
	
	for (auto i = 0; i < matr_2_size_n; i++)
		delete[] matrix_2[i];
	
	for (auto i = 0; i < matr_size_max; i++)
	{
		delete[] matrix_1_resized[i];
		delete[] matrix_2_resized[i];
		delete[] result_matrix[i];
	}
	
	for (auto i = 0; i < matr_size_max / 2; i++)
	{
		delete[] sub_matrix_1[i];
		delete[] sub_matrix_2[i];
		delete[] sub_matrix_3[i];
		delete[] sub_matrix_4[i];
		delete[] sub_matrix_5[i];
		delete[] sub_matrix_6[i];
		delete[] sub_matrix_7[i];
		delete[] sub_matrix_8[i];
		delete[] support_matr_1[i];
		delete[] support_matr_2[i];
		delete[] support_matr_3[i];
		delete[] support_matr_4[i];
		delete[] intermed_matr_1[i];
		delete[] intermed_matr_2[i];
		delete[] intermed_matr_3[i];
		delete[] intermed_matr_4[i];
		delete[] intermed_matr_5[i];
		delete[] intermed_matr_6[i];
		delete[] intermed_matr_7[i];
	}
	
	delete[] matrix_1, matrix_2, matrix_1_resized, matrix_2_resized, result_matrix;
	
	delete[] sub_matrix_1, sub_matrix_2, sub_matrix_3, sub_matrix_4, sub_matrix_5,
	sub_matrix_6, sub_matrix_7, sub_matrix_8, support_matr_1, support_matr_2,
	support_matr_3, support_matr_4;
	
	delete[] intermed_matr_1, intermed_matr_2, intermed_matr_3, intermed_matr_4,
	intermed_matr_5, intermed_matr_6, intermed_matr_7;

	return 0;
}


void print_matrix(int** matrix, const int m, const int n, 
	const char caption[] = "") {

	if(caption != "")
		cout << endl << caption << endl << endl;

	for (auto i = 0; i < n; i++)
	{
		for (auto j = 0; j < m; j++)
			cout << matrix[i][j] << " ";

		cout << endl;
	}
}

void init_zero_matrix(int** matrix, const int m, const int n) {

	for (auto i = 0; i < n; i++)
	{
		matrix[i] = new int[m];

		for (auto j = 0; j < m; j++)
			matrix[i][j] = 0;
	}
}

void fill_submatrix(int** source, int** dest, const int size, 
	const int i_delta = 0, const int j_delta = 0) {
	for (auto i = 0; i < size; i++)
	{
		dest[i] = new int[size];
		for (auto j = 0; j < size; j++)
			dest[i][j] = source[i + i_delta][j + j_delta];
	}
}