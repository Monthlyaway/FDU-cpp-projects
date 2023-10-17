#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        for (auto& op : operations) {
            if (op == "+") {
                int prev = scores.top();
                scores.pop();
                int prevPrev = scores.top();
                scores.pop();
                int sum = prev + prevPrev;
                scores.push(prevPrev);
                scores.push(prev);
                scores.push(sum);
            }
            else if (op == "D") {
                int prev = scores.top();
                scores.pop();
                int prevPrev = scores.top();
                scores.pop();
                int multi = prev * prevPrev;
                scores.push(prevPrev);
                scores.push(prev);
                scores.push(multi);
            }
            else if (op == "C") {
                scores.pop();
            }
            else {
                scores.push(stoi(op));
            }
        }
        int sum = 0;
        while (!scores.empty()) {
            int temp = scores.top();
            sum += temp;
            scores.pop();
        }
        return sum;
    }
};

int main(void) {
    Solution* obj = new Solution();
    vector<string> operations{ "5","2","C","D","+" };
    cout << obj->calPoints(operations);
}