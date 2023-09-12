# include <iostream>

void my_swap(int num1, int num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}
void p_swap(int* pn1, int* pn2) {
	int tmp = *pn1;
	*pn1 = *pn2;
	*pn2 = tmp;
}
void r_swap(int& var1, int& var2) {
	int tmp = var1;
	var1 = var2;
	var2 = tmp;
}

template<typename T>
void print_Arr(T arr[], const int length) {
	std::cout << "{ ";
	for (short i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

int& rmax(int arr[], const int length) {
	int max_Index = 0;
	for (short i = 1; i < length; i++)
		max_Index = arr[i] > arr[max_Index] ? i : max_Index;
	return arr[max_Index];
}

template<typename T>
void ref_Dbl(T& var1, T& var2);

int* grater_Arr(int arr1[], const int length1, int arr2[], const int length2, bool& first);

int main() {
	setlocale(LC_ALL, "Russian");
	int n = 7, m = 15;
	
	// Ссылки на переменные
	int& refn = n;
	std::cout << "n = " << n << std::endl;
	std::cout << "refn = " << refn << std::endl;
	n = 15;
	std::cout << "refn = " << refn << std::endl;
	refn = 42;
	std::cout << "n = " << n << std::endl;

	// Ссылки, как параменты функции
	std::cout << "n = " << n << "; m = " << m << ";\n";
	// my_swap(n,m) // не работает
	// p_swap(&n,&m) // работает, но неудобно
	r_swap(n, m); // работает, удобно
	std::cout << "n = " << n << "; m = " << m << ";\n";

	// Ссылки, как результат работы функции
	const int size = 5;
	int arr[size]{ 6,7,2,7,5 };
	print_Arr(arr, size);
	std::cout << std::endl;
	std::cout << "Максимум: " << rmax(arr, size) << "\n\n";
	rmax(arr, size) = -1;
	print_Arr(arr, size);

	// Задача 1. Квадрат или обнуление
	std::cout << "Task 1.\n\nEnter two numbers -> ";
	std::cin >> n >> m;
	ref_Dbl(n, m);
	std::cout << "n = " << n << "; m = " << m << "\n\n";

	// Задача 2. Указатель на массив
	std::cout << "Task 2. Point on array\n\nFirst array: ";
	const int sizeA = 5, sizeB = 7;
	int A[sizeA]{ 1,2,3,4,5 };
	int B[sizeB]{ 10,20,30,40,50,60,70 };
	print_Arr(A, sizeA);
	std::cout << "Second array: ";
	print_Arr(B, sizeB);
	std::cout << std::endl;
	std::cout << "Longerst: ";
	bool f = true;
	int* pointer = grater_Arr(A, sizeA, B, sizeB, f);
	print_Arr(pointer, f ? sizeA : sizeB);

	return 0;
}

template<typename T>
void ref_Dbl(T& var1, T& var2) {
	if (var1 > var2) {
		var1 *= var1; // var1=pow(var1,2);
		var2 *= var2; // var1=pow(var2,2);
		return;
	}
	var1 = 0;
	var2 = 0;
}

int* grater_Arr(int arr1[], const int length1, int arr2[], const int length2, bool& first) {
	return (first = length1 > length2) ? arr1 : arr2;
}