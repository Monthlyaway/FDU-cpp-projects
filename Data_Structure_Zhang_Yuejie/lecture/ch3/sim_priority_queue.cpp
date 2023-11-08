#include <iostream>
#include <vector>

using namespace std;

void adjust(vector<int>& vec) {
	int rear = vec[vec.size() - 1];
	for (int ix = vec.size() - 2; ix >= 0; ix--) {
		if (vec[ix] > rear) {
			vec[ix + 1] = vec[ix];
		}
		else {
			vec[ix + 1] = rear;
			break;
		}
	}
}

int main(void) {
	vector<int> vec{ 1,2,3,6,8,12,12, 15, 18,10 };
	cout << "Before adjustment: ";
	for (auto u : vec) {
		cout << u << " ";
	}
	cout << "\nAfter adjustment: ";
	adjust(vec);
	for (auto u : vec) {
		cout << u << " ";
	}

	return 0;
}