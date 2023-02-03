#include <iostream>
#include <iomanip>
using namespace std;


void Memory_Allocation(int**& arr, int& row, int& col);//Выделение динамической для массива
void Create_Arr(int**& arr, int& row, int& col);//создание массива
void Show_Arr(int**& arr, int& row, int& col); //вывод массива
void Add_Col(int**& arr, int**& arrAddCol, int& row, int& col, int& ColAdd, int& pos); //добавление столбца 
void Del_Col(int**& arr, int**& arrDelCol, int& row, int& col, int& pos);//удаление столбца
void Shift_Arr(int**& matrix, int& row, int& col, int& shift, int& count);//циклический сдвиг строк и / или столбцов массива указанное количество раз и в указанную сторону
void Delete_Arr(int**&, int& row);//удаление

int main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));

	int row = 4;
	int col = 4;
	int colAdd = 5;
	int colDel = 3;
	int** arr;
	int** arrAddCol;
	int** arrDelCol;
	int posAdd = 0;
	int posDelete = 0;

	//Выделение памяти
	Memory_Allocation(arr, row, col);
	Memory_Allocation(arrAddCol, row, colAdd);
	Memory_Allocation(arrDelCol, row, col);

	//Задание 1.
	/*Написать функцию, добавляющую столбец двухмерному массиву в указанную позицию.*/

	//Вывод начального массива
	cout << "\tИзначальный массив: " << endl << endl;
	Create_Arr(arr, row, col);
	Show_Arr(arr, row, col);
	cout << endl << endl;

	cout << "Введите позицию для вставки столбца: ";
	cin >> posAdd;
	cout << endl;

	//Вывод массива с добавлением cтолбца
	Add_Col(arr, arrAddCol, row, col, colAdd, posAdd);
	Show_Arr(arrAddCol, row, colAdd);
	cout << endl << endl;

	//Задание 2.
	/*Написать функцию, удаляющую столбец двухмерного массива по указанному номеру.*/

	//Вывод начального массива
	cout << "\tИзначальный массив: " << endl << endl;
	Create_Arr(arr, row, col);
	Show_Arr(arr, row, col);
	cout << endl << endl;

	cout << "Введите позицию для удаления столбца: ";
	cin >> posDelete;
	cout << endl;

	//Вывод массива с удалением cтолбца
	Del_Col(arr, arrDelCol, row, colDel, posDelete);
	Show_Arr(arrDelCol, row, colDel);
	cout << endl << endl;

	//Задание 3.
	/*Дана матрица порядка M×N (M строк, N столбцов).
	Необходимо заполнить ее значениями и написать
	функцию, осуществляющую циклический сдвиг строк
	и/или столбцов массива указанное количество раз и в указанную сторону*/

	int shift_type;
	int count;
	int** matrix;

	Memory_Allocation(matrix, row, col);
	cout << "\t    Матрица\n\n";
	Create_Arr(matrix, row, col);
	Show_Arr(matrix, row, col);

	cout << "\nВведите направление сдвига: \n";
	cout << "1) Влево;\n"
		<< "2) Вправо;\n"
		<< "3) Вверх;\n"
		<< "4) Вниз;\n"
		<< endl << endl;
	cin >> shift_type;	
	cout << endl;
	cout << "Введите количество сдвигов: ";	cin >> count;
	cout << endl << endl;

	Shift_Arr(matrix, row, col, shift_type, count);
	Show_Arr(matrix, row, col);
	//удаление
	system("pause");
	Delete_Arr(arr, row);
	Delete_Arr(arrAddCol,row);
	Delete_Arr(arrDelCol,row);
	Delete_Arr(matrix,row);
}
//Выделение динамической для массива
void Memory_Allocation(int**& arr, int& row, int& col) {
	arr = new int* [row];
	for (int i = 0; i < col; i++) {
		arr[i] = new int[col];
	}
}
//создание массива
void Create_Arr(int**& arr, int& row, int& col) {
	for (int i = 0; i < row; i++) {
		arr[i] = new int[col];
		for (int j = 0; j < col; j++) {
			arr[i][j] = rand() % 10;
		}
	}
}
//вывод массива
void Show_Arr(int**& arr, int& row, int& col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << setw(6) << arr[i][j] << " ";
		}
		cout << endl;
	}
}
//добавление столбца 
void Add_Col(int**& arr, int**& arrAddCol, int& row, int& col, int& ColAdd, int& pos) {
	if (pos - 1 != 0) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < pos - 1; j++) {
				arrAddCol[i][j] = arr[i][j];
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = pos - 1; j < ColAdd; j++) {
			if (j == pos - 1)
				arrAddCol[i][j] = rand() % 10;
			else
				arrAddCol[i][j] = arr[i][j - 1];
		}
	}
}
//удаление столбца
void Del_Col(int**& arr, int**& arrDelCol, int& row, int& col, int& pos) {
	if (pos - 1 != 0) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < pos - 1; j++) {
				arrDelCol[i][j] = arr[i][j];
			}
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = pos - 1; j < col; j++) {
			arrDelCol[i][j] = arr[i][j + 1];
		}
	}
}
//циклический сдвиг строк и / или столбцов массива указанное количество раз и в указанную сторону
void Shift_Arr(int**& matrix, int& row, int& col, int& shift, int& count) {
	int temp;
	// сдвиг влево
	if (shift == 1)	{
		for (int i = 0; i < count; i++)	{
			for (int j = 0; j < row; j++){
				temp = matrix[j][0];
				for (int g = 0; g < col - 1; g++){
					matrix[j][g] = matrix[j][g + 1];
				}
				matrix[j][col - 1] = temp;
			}
		}
	}
	// сдвиг вправо
	else if (shift == 2){
		for (int i = 0; i < count; i++)	{
			for (int j = 0; j < row; j++){
				temp = matrix[j][col - 1];
				for (int g = col - 1; g > 0; g--){
					matrix[j][g] = matrix[j][g - 1];
				}
				matrix[j][0] = temp;
			}
		}
	}
	// сдвиг вверх
	else if (shift == 3) {
		for (int i = 0; i < count; i++)	{
			for (int j = 0; j < col; j++){
				temp = matrix[0][j];
				for (int g = 0; g < row - 1; g++){
					matrix[g][j] = matrix[g + 1][j];
				}
				matrix[row - 1][j] = temp;
			}
		}
	}
	// сдвиг вниз
	else if (shift == 4) {
		for (int i = 0; i < count; i++)	{
			for (int j = 0; j < col; j++){
				temp = matrix[row - 1][j];
				for (int g = row - 1; g > 0; g--){
					matrix[g][j] = matrix[g - 1][j];
				}
				matrix[0][j] = temp;
			}
		}
	}
}
//удаление
void Delete_Arr(int**& arr, int& row) {
	for (int i = 0; i < row; i++) {
		delete[]arr[i];
	}
	delete[]arr;
}