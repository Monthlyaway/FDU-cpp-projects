#include <iostream>
using namespace std;

int main(void) {
	const int MAXSIZE = 100;
	char str[MAXSIZE] = "12345";
	cout << "str= " << str << endl;

	int result = 0;
	for (int ix = 0; ix < strlen(str); ix++) {
		result = result * 10 + (str[ix] - '0');
	}
	cout << "result = " << result << endl;

	return 0;
}