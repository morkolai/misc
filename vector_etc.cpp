#include <vector>
#include <deque>
//#include <list>
#include <map>						//?
#include <set>						//?
#include <unordered_map>			//?
#include <unordered_set>			//?
#include <iterator>					// nja litt ?
#include <algorithm>				// litt ? her å
#include <numeric>					//?
#include <functional>				// ?
#include <iostream>						
#include <string>

void printVector(std::vector<int> vec);
void printDeque(std::deque<std::string> deq);

class MyClass
{
public:
	MyClass();
	~MyClass();

private:
	int number;
	std::string text;
	bool babadibobadibooooo;
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main() {

	/*auto a = 69;

	std::vector<int> bob;

	for(int i = 0; i < 10; i++)
		bob.push_back(a++);

	std::cout << bob.size() << std::endl << bob[5];*/

	int a;

	std::cin >> a;
	
	std::vector<int> evenNumbers;

	for (int i = 1; i < a; i++) {

		if (i % 2 == 0)
			evenNumbers.push_back(i);
	}

	printVector(evenNumbers);

	std::string factsAboutBob = "Bob is top rocking fucking awsome";

	std::deque<std::string> boyah;

	boyah.push_back("babadibooooo!");
	boyah.push_front("gagagaga!");

	std::string word;

	std::cin >> word;

	boyah.push_back(word);

	printDeque(boyah);

	return 0;
}

void printVector(std::vector<int> vec) {

	for (int i = 0; i < vec.size(); i++)
		std::cout << vec[i] << std::endl;
}

void printDeque(std::deque<std::string> deq) {

	for (int i = 0; i < deq.size(); i++)
		std::cout << deq[i] << std::endl;
}