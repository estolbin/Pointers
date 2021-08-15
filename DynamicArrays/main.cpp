#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n);
void push_back(int*& arr, int &p, int new_item);
void fillArrayFromArray(int*& arr, int n, int* sourceArray);
void push_front(int*& arr, int& p, int new_item);
void insert(int*& arr, int& p, int new_item, int indx);
void pop_back(int*& arr, int& p);
void pop_front(int*& arr, int& p);
void erase(int*& arr, int& p, int indx);


void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n] {};

	FillRand(arr, n);
	Print(arr, n);

	// push_back
	int new_item = rand() % 100;
	push_back(arr, n, new_item);
	Print(arr, n);

	int new_item2 = rand() % 100; // or cin >> new_item2;
	push_front(arr, n, new_item2);
	Print(arr, n);

	int new_item3 = rand() % 100;
	insert(arr, n, new_item3, 2);
	Print(arr, n);

	pop_back(arr, n);
	Print(arr, n);

	pop_front(arr, n);
	Print(arr, n);

	int indx = 2;
	erase(arr, n, indx);
	Print(arr, n);

	delete[] arr;
}

void push_front(int*& arr, int& p, int new_item)
{
	int n = p;
	n++;
	int* tmpArr = new int[n] {};
	tmpArr[0] = new_item;
	for (int i = 1; i < n; i++)
	{
		tmpArr[i] = arr[i - 1];
	}
	delete[] arr;

	arr = new int[n] {};
	fillArrayFromArray(arr, n, tmpArr);
	delete[] tmpArr;
	p = n;
}

void push_back(int*& arr, int &p, int new_item)
{
	int n = p;
	n++;
	int* tmpArr = new int[n] {};
	fillArrayFromArray(tmpArr, n, arr);
	tmpArr[n-1] = new_item;
	delete[] arr;

	arr = new int[n] {};
	fillArrayFromArray(arr, n, tmpArr);
	delete[] tmpArr;
	p = n;
}

void insert(int*& arr, int& p, int new_item, int indx)
{
	int n = p;
	n++;
	int* tmpArr = new int[n]{};

	for (int i = 0; i < indx; i++)
	{
		tmpArr[i] = arr[i];
	}
	tmpArr[indx] = new_item;
	for (int i = indx+1; i < n; i++)
	{
		tmpArr[i] = arr[i - 1];
	}
	delete[] arr;


	arr = new int[n] {};
	fillArrayFromArray(arr, n, tmpArr);
	delete[] tmpArr;
	p = n;
}

void pop_back(int*& arr, int& p)
{
	int n = p;
	n--;
	int* tmpArr = new int[n] {};
	fillArrayFromArray(tmpArr, n, arr);
	delete[] arr;

	arr = new int[n] {};
	fillArrayFromArray(arr, n, tmpArr);
	delete[] tmpArr;
	p = n;
}

void pop_front(int*& arr, int& p)
{
	int n = p;
	n--;
	int* tmpArr = new int[n] {};
	for (int i = 0; i < n; i++)
	{
		tmpArr[i] = arr[i + 1];
	}
	delete[] arr;

	arr = new int[n] {};
	fillArrayFromArray(arr, n, tmpArr);
	delete[] tmpArr;
	p = n;
}

void erase(int*& arr, int& p, int indx)
{
	int n = p;
	n--;
	int* tmpArr = new int[n] {};
	for (int i = 0; i < n; i++)
	{
		tmpArr[i] = arr[(i >= indx) ? i + 1 : i];
	}
	delete[] arr;

	arr = new int[n] {};
	fillArrayFromArray(arr, n, tmpArr);
	delete[] tmpArr;
	p = n;
}

void fillArrayFromArray(int*& arr, int n, int* sourceArray)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = sourceArray[i];
	}
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;

}