#include <iostream>
#include <string>
#include <vector>

using namespace std;

void computeNext(vector<int>& nvec, const string& pattern) {
	nvec.resize(pattern.size());
	nvec[0] = -1;
	int j = 0, k = -1;

	while (j < pattern.size() - 1) {
		if (k == -1 || pattern[k] == pattern[j]) {
			nvec[j + 1] = k + 1;
			k++;
			j++;
		}
		else {
			k = nvec[k];
		}
	}
}

int kmpMatch(const string& target, const string& pattern) {
	int px = 0, tx = 0;
	vector<int> nextVec;
	computeNext(nextVec, pattern);
	int psize = pattern.size();
	int tsize = target.size();
	while (px < psize && tx < tsize) {
		if (px == -1 || target[tx] == pattern[px]) {
			tx++;
			px++;
		}
		else {
			px = nextVec[px];
		}
		cout << "px = " << px << " pattern.size() = " << pattern.size() << endl;
		cout << "tx = " << tx << " target.size() = " << target.size() << endl;

	}

	if (px < psize) {
		return -1;
	}
	else {
		return tx - px;
	}

}

int main(void) {
	string target = "abacfadaaabaavbdfab";
	string pattern = "abaa";

	cout << "Found a match at index " << kmpMatch(target, pattern) << endl;


	return 0;
}