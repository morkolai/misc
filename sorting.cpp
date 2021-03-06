//implementation of the sorting algorithms from the book algorithms in c++ by robert sedgewick

#include <iostream>

typedef int itemtype;

itemtype arr[] = {0,4,5,2,7,3,6,8,2,4,1,3,9,9,9};

const int LEN = sizeof(arr) / sizeof(*arr) + 1;

void print(itemtype a[], int N);
void swap(itemtype a[], int i, int j);
void validateSort(itemtype a[], int N);
void selectionSort(itemtype a[], int N);
void insertionSort(itemtype a[], int N);
void bubbleSort(itemtype a[], int N);
void shellSort(itemtype a[], int N);
void distributedCounting(itemtype a[], int N);
void quicksort(itemtype a[], int l, int r);
int biggestValue(itemtype a[], int N);

int main() {

	validateSort(arr, LEN);
	print(arr, LEN);

	return 0;
}

void print(itemtype a[], int N) {

	for (int i = 1; i <= N; i++) {
		std::cout << '['<< i << "] = " << a[i] << std::endl;
	}
	std::cout << std::endl;
}

void swap(itemtype a[], int i, int j) {
	itemtype t = a[i];
	a[i] = a[j];
	a[j] = t;
}

void validateSort(itemtype a[], int N) {
	
	for (int i = 0; i < N; i++) {
		if (a[i + 1] < a[i]) {
			std::cout << "ERROR: [" << i << "] = " << a[i] << " > [" <<
				i + 1 << "] = " << a[i + 1] << std::endl;
		}
	}
}

void selectionSort(itemtype a[], int N) {
	
	int min, i, j;
	for (i = 1; i < N; i++) {
		min = i;
		for (j = i + 1; j <= N; j++) {
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
	for (int i = 2; i <= N; i++) {
		v = a[i];
		j = i;
		while (a[j - 1] > v) {
			a[j] = a[j - 1];
			j--;
		}
		a[j] = v;
	}
}

void bubbleSort(itemtype a[], int N) {

	int i, j;
	for (i = N; i >= 1; i--) {
		for (j = 2; j <= i; j++) {
			if (a[j - 1] > a[j]) {
				swap(a, j - 1, j);
			}
		}
	}
}

void shellSort(itemtype a[], int N) {
	
	int i, j, h;
	itemtype v;
	for (h = 1; h <= N / 9; h = 3 * h + 1);			//sets the value of h
	for (; h > 0; h /= 3) {
		for (i = h + 1; i <= N; i += 1) {
			v = a[i];
			j = i;
			while (j > h && a[j - h] > v) {
				a[j] = a[j - h];
				j -= h;
			}
			a[j] = v;
		}
	}
}

void distributedCounting(itemtype a[], int N) {

	const int M = 10; //biggestValue(arr, LEN) + 1;

	itemtype count[M], b[LEN+1];

	for (int j = 0; j < M; j++) {
		count[j] = 0;
	}

	for (int i = 1; i <= N; i++) {
		count[a[i]]++;
	}

	for (int j = 1; j < M; j++) {
		count[j] += count[j - 1];
	}

	for (int i = N; i >= 1; i--) {
		b[count[a[i]]--] = a[i];
	}

	for (int i = 1; i <= N; i++) {
		a[i] = b[i];

	}
}

void quicksort(itemtype a[], int l, int r) {
	
	int i, j;
	itemtype v;
	if (r > l) {
		v = a[r];
		i = l - 1;
		j = r;
		for (;;) {
			while (a[++i] < v);
			while (a[--j] > v);
			if (i >= j) {
				break;
			}
			swap(a, i, j);
		}
		swap(a, i, r);
		quicksort(a, l, i - 1);
		quicksort(a, i + 1, r);
	}
}

int biggestValue(itemtype a[], int N) {

	int max = a[1];
	for (int i = 1; i <= N; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		return max;
	}
}