#include <iostream>
#include <stack>
#include <string>
#include <list>

using namespace std;

bool isPalindrome(const list<int>& lst) {
	stack<int> st;
	auto iter = lst.begin();

	for (int ix = 0; ix <= lst.size() / 2; ix++) {
		st.push(*iter);
		iter++;
	}
	if (lst.size() % 2 == 1) {
		st.pop();
	}
	while (iter != lst.end()) {
		if (st.empty()) {
			return false;
		}
		if (st.top() != *iter) {
			return false;
		}
		st.pop();
		iter++;
	}
	return true;
}

int main(void) {
	list<int> input = { 12,21,27,21,12 };
	cout << (isPalindrome(input) ? "true" : "false") << endl;

	return 0;
}