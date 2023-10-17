#include <iostream>
using namespace std;
int fib(int n, int& prev) {
	/*
	* fib(n) = prev + prevPrev;
	* prev = fib(n - 1, prevPrev) computes prev and prevPrev at the same time.
	* prevPrev to n is prev to n - 1;
	*/
	if (n == 0) {
		prev = 1;
		return 0;  // fib(0) = 1, set fib(-1) = 1
	}

	int prevPrev;
	prev = fib(n - 1, prevPrev);
	return prev + prevPrev;
}

int main(void) {
	int prev;
	cout << "----------------------------------\n"
		<< "       Fibonacci Series           \n"
		<< "----------------------------------\n";
	for (int ix = 0; ix < 10; ix++) {
		cout << fib(ix, prev) << " ";
	}
	cout << endl;

	return 0;
}