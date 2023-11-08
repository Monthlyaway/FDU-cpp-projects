#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	q.push(1);
	q.push(1);
	q.push(0);
	int left = 0, right;

	int level;
	cout << "Input level of the Yang Triangle: ";
	cin >> level;

	for (int row = 1; row <= level; row++) {
		for (int jx = 0; jx < row + 2; jx++)
		{
			right = q.front();
			q.pop();
			if (jx != row + 1) {
				cout << right << " ";
			}
			q.push(left + right);
			left = right;
		}
		q.push(0);
		cout << endl;
	}

	return 0;
}