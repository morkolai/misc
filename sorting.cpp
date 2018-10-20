#include <iostream>

typedef int itemtype;

itemtype arr[] = {45,5,4,2,4,5,2,5,6,43,876,32,75,2};

const int LEN = sizeof(arr) / sizeof(*arr);

void print(itemtype a[], int N);
void swap(itemtype a[], int i, int j);
bool validateSort(itemtype a[], int N);
void selectionSort(itemtype a[], int N);
void insertionSort(itemtype a[], int N);

int main() {

	selectionSort(arr, LEN);
	validateSort(arr, LEN);
	print(arr, LEN);


	return 0;
}

void print(itemtype a[], int N) {

	for (int i = 0; i <= N; i++) {
		std::cout << ' ' << a[i];
	}
	std::cout << std::endl;
}

void swap(itemtype a[], int i, int j) {
	itemtype t = a[i];
	a[i] = a[j];
	a[j] = t;
}

bool validateSort(itemtype a[], int N) {
	
	for (int i = 0; i < N; i++) {
		if (a[i + 1] < a[i]) {
			std::cout << "ERROR: [" << i << "] = " << a[i] << " > [" <<
				i + 1 << "] = " << a[i + 1] << std::endl;
			return false;
		}
	}
}

void selectionSort(itemtype a[], int N) {
	
	int min;
	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i + 1; j <= N; j++) {
			if (a[j] < a[min]) {
				min = j;
			}
		}
		swap(a, min, i);
	}
}

void insertionSort(itemtype a[], int N) {

	int j;
	itemtype v;
	for (int i = 0; i <= N; i++) {
		v = a[i];
		j = i;
		while (a[j - 1] > v && j > 0) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}
