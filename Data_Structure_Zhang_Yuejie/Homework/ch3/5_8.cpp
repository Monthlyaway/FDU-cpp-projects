#include <iostream>
#include <deque>
#include <string>


using namespace std;
void showdq(const deque<int>& g)
{
    deque<int>::const_iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

deque<int> lastKInFib(int k, int max) {
    deque<int> result;

    int a = 1, b = 0, temp;
    for (int ix = 0; ix < k; ix++) {
        result.push_back(b);
        temp = b;
        b = a + b;
        a = temp;
    }

    // now the deque has k elements, every time
    // before we add a new element, first delete
    // one at the front
    do {
        result.pop_front();
        result.push_back(b);
        temp = b;
        b = a + b;
        a = temp;
    } while (b <= max);

    return result;

}

int main(void) {
	deque<int> result = lastKInFib(4, 90);
    showdq(result);

	return 0;
}