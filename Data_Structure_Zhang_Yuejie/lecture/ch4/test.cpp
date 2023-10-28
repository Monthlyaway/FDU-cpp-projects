#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string pat = "abaa";
	int px = -1;
	cout << (px < (int)pat.size() ? "true" : "false") << endl;

	int pSize = pat.size();
	cout << (px < pSize ? "true" : "false") << endl;

	return 0;
}