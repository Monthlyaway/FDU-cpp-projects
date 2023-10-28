#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool areAnagrams(const string& s1, const string& s2) {
	if (s1.size() != s2.size()) {
		return false;
	}
	unordered_map<char, int> charCounts;
	for (char ch : s1) {
		charCounts[ch]++;
	}
	for (char ch : s2) {
		if (charCounts[ch] == 0) {
			return false;
		}
		charCounts[ch]--;
	}
	return true;
}

int main(void) {
	string s1 = "12321";
	string s2 = "32211";
	cout << "s1 and s2 " << (areAnagrams(s1, s2) ? "are " : "are not ")
		<< "anagrams" << endl;

	return 0;
}