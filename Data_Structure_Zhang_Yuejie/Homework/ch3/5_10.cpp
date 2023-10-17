#include <iostream>
#include <string>
#include <vector>


using namespace std;

void findCombinations(vector<vector<int> >& result, vector<int>& numbers, vector<int>& temp, int r, int start) {
    // base case
    if (r == 0) {
        result.push_back(temp);
        return;
    }


    // tree structure
    for (int ix = start; ix < numbers.size(); ix++) {
        temp.push_back(numbers[ix]);
        findCombinations(result, numbers, temp, r - 1, ix + 1);
        temp.pop_back();
    }

}

int main(void) {
    vector<vector<int> > result;
    vector<int> temp;
    vector<int> numbers = { 1,2,3,4,5 };
    findCombinations(result, numbers, temp, 3, 0);

    for (auto u : result) {
        for (auto v : u) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}