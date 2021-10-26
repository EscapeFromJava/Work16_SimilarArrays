#include <iostream>

using namespace std;

int* createArr(int size);
bool otherElem(int mas1[], int masSize1, int mas2[], int masSize2);
bool searchOtherElem(int mas1[], int masSize1, int temp);

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Введите размер 1 и 2 массива: ";
	int size1, size2;
	cin >> size1 >> size2;
	if (size1 < 1 || size1 > 16000 || size2 < 1 || size2 > 16000) {
		cout << "Введены некорректные размеры массива" << endl;
		return 0;
	}
	cout << "Введите " << size1 << " элем. 1 массива: " << endl;
	int* arr1 = createArr(size1);
	cout << "Введите " << size2 << " элем. 2 массива: " << endl;
	int* arr2 = createArr(size2);

	if (otherElem(arr1, size1, arr2, size2) == true) {
		cout << "Результат: 1" << endl;
	}
	else
		cout << "Результат: 0" << endl;
	delete[] arr1, arr2;
	return 0;
}

int* createArr(int size)
{
	int* arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}
	return arr;
}

bool otherElem(int mas1[], int masSize1, int mas2[], int masSize2)
{
	bool flag = true;
	int temp1, temp2, count = 0;
	for (int i = 0; i < masSize1; i++) {
		for (int j = 0; j < masSize2; j++) {
			if (mas1[i] != mas2[j]) {
				temp1 = mas1[i];
				temp2 = mas2[j];
				if (searchOtherElem(mas1, masSize1, temp2) == false || searchOtherElem(mas2, masSize2, temp1) == false) {
					flag = false;
				}
			}
		}
	}
	return flag;
}

bool searchOtherElem(int mas[], int masSize, int temp)
{
	for (int i = 0; i < masSize; i++) {
		if (mas[i] == temp)
			return true;
	}
	return false;
}