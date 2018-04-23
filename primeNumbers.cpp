using namespace std;

#include <iostream>

bool isPrime(int a);

int main() {

	cout << "Prime numbers less than 100\n";

	for (int i = 1; i < 100; i++) {
		
		if (isPrime(i))
			cout << i << endl;
	}

	return 0;
}

bool isPrime(int a) {

	for (int i = a-1; i > 1; i--) {

		if (a % i == 0)
			return false;
	}

	return true;
}
