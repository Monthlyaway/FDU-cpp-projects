#include <iostream>
#include <utility>
#include <string>

using namespace std;

void display(int arr[], int n, string message = "") {
	cout << message << endl;
	for (int ix = 0; ix < n; ix++) {
		cout << arr[ix] << " ";
	}	
	cout << endl;
}

int* bubblesort1A(int arr[], int n) {
	bool sorted = false;

	while (!sorted)
	{
		sorted = true;
		for (int ix = 0; ix <= n - 2; ix++) {

			if (arr[ix] > arr[ix + 1]) {
				std::swap(arr[ix], arr[ix + 1]);
				sorted = false;
			}
		}
		n--;
	}
	return arr;
}

int main(void) {
	int arr[10] = { 9,8,7,6,5,4,3,2,1,0 };
	display(arr, 10, "Original Array:");
	bubblesort1A(arr, 10);
	display(arr, 10, "Sorted Array:");

	return 0;
}