#include <iostream>
#include <string>

using namespace std;

int main(void) {
	int result = 0;
	char task;
	char input;

	cin >> task;

	while (cin >> input) {
		if (atoi(&input) == 1) {
			result = 1 - result;
		}
	}

	if (task == 'O') {
		cout << (1 - result);
	}
	else {
		cout << result;
	}


	return 0;
}