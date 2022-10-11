#include <iostream>

using namespace std;
struct DynamicArray
{
	int* Array;
	int Capacity;
	int Length;
};

/// <summary>
/// Функция создания и инициализации полей массива.
/// </summary>
/// <param name="dynamicArray"></param>
void CreateArray(DynamicArray* dynamicArray)
{
	int capacity = 4;
	dynamicArray->Capacity = capacity;
	dynamicArray->Length = 0;
	dynamicArray->Array = new int[dynamicArray->Capacity];
	delete[] dynamicArray;
}

/// <summary>
/// Функция заполнения массива рандомными числами.
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
int* MakeRandomArray(DynamicArray* dynamicArray)
{
	srand(time(NULL));

	int* arr = new int[dynamicArray->Capacity];
	{
		for (int i = 0; i < dynamicArray->Capacity; i++)
		{
			arr[i] = rand() % 10;
		}
	}
	return arr;
}

/// <summary>
/// Функция вывода массива на экран.
/// </summary>
/// <param name="dynamicArray"></param>
void ShowArray(DynamicArray* dynamicArray)
{
	for (int i = 0; i < dynamicArray->Length; i++)
	{
		cout << dynamicArray->Array[i] << " ";
	}

	cout << endl;
}

/// <summary>
/// Вставка элемента в конец массива.
/// </summary>
/// <param name="arr"></param>
/// <param name="size"></param>
/// <param name="value"></param>
void InsertElementEnd(int*& arr, int& size, const int value)
{
	int* newArray = new int[size + 1];

	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}

	newArray[size] = value;
	size++;
	delete[] arr;
	arr = newArray;
}

int main()
{
	setlocale(LC_ALL, "ru");

	DynamicArray* dynamicArray = new DynamicArray;

	cout << "Введите номер функции, которую хотите выполнить" << endl <<
		"1) Вставить элемент в конец массива" << endl <<
		"2) Вставить элемент в начало массива" << endl;

	int value;
	cin >> value;
	cout << "Вы выбрали задание под номером " << value << endl;

	switch (value)
	{
	case 1:
		int* myArray = MakeRandomArray(dynamicArray);
		cout << "Введите элемент, который хотите добавить в массив: " << endl;
		int elements;
		cin >> elements;
		InsertElementEnd(myArray, dynamicArray->Capacity, value);
	}
}

