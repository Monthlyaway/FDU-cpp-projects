#include <iostream>
#include <string>
#include <vector>

using namespace std;

int kmp(string target, string pattern);
void getNext(string str, vector<int>& vec);
void getNextTest();

int main(void) {
	string target = "bcbd;fadnabcdaf";
	string pattern = "abc";
	cout << "Found pattern \"" << pattern
		<< "\" at index " << kmp(target, pattern);

	return 0;
}

int kmp(string target, string pattern) {
	vector<int> nextVec;
	getNext(pattern, nextVec);
	int tx = 0, px = 0;
	while (tx < target.size() && px < (int)pattern.size()) {
		if (px == -1 || target[tx] == pattern[px]) {
			tx++;
			px++;
		}
		else {
			px = nextVec[px];
		}
	}

	return px < pattern.size() ? -1 : tx - pattern.size();
}
void getNext(string str, vector<int>& vec) {
	vec.resize(str.size(), 0);
	int jx = 0, k = -1;
	vec[0] = -1;
	while (jx < str.size() - 1) {
		if (k == -1 || str[jx] == str[k]) {
			jx++;
			k++;
			vec[jx] = k;
		}
		else {
			k = vec[k];
		}
	}

}

void getNextTest() {
	string str = "abaabcac";
	vector<int> next;
	getNext(str, next);
	for (auto u : next) {
		cout << u << " ";
	}
	cout << endl;
}