using namespace std;

#include <iostream>

bool isPrime(int a);
void primeNumbers(int k);
void primeNumbersOpt(int k);

int main() {

	int input;

	cin >> input;
	primeNumbers(input);

	cin >> input;
	primeNumbersOpt(input);

}

bool isPrime(int a) {					//Checks if a number is a prime number

	for (int i = a-1; i > 1; i--) {

		if (a % i == 0)
			return false;
	}

	return true;
}

void primeNumbers(int k) {				//General function

	for (int i = 2; i < k; i++) { 

		if (isPrime(i))
			cout << i << endl;
	}
}

void primeNumbersOpt(int k) {			//Optimized function

	if (k >= 2)
		cout << "2\n";

	for (int i = 3; i < k; i += 2) {

		if (isPrime(i))
			cout << i << endl;
	}
}