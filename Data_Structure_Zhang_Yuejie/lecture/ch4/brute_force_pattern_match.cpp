#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string input;
	string pattern = "abaa";
	cin >> input;
	cout << "Input is " << input << endl;

	for (int start = 0; start <= input.size() - pattern.size(); start++) {
		int end = start;
		while (input[end] == pattern[end - start]) {
			end++;
			if (end - start == pattern.size()) {
				cout << "Found a match starting at " << start << endl;
				break;
			}
		}
	}

	return 0;
}