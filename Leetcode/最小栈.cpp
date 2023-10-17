#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
private:
    stack<long long> dataStack;
    long long currMin;
public:
    MinStack() {

    }

    void push(int val) {
        if (dataStack.empty()) {
            currMin = (long long)val;
            dataStack.push(0);
        }
        else {
            dataStack.push((long long)val - currMin);
            cout << "push: " << (long long)val - currMin << endl;
            /*
             * Runtime error: signed integer overflow
             * e.g. val = 2147483647, currMin = -2147483648
            */
            currMin = std::min((long long)val, currMin);
        }

    }

    void pop() {
        long long top = dataStack.top();
        if (top < 0) {
            currMin = currMin - top;
        }
        dataStack.pop();
    }

    int top() {
        if (dataStack.top() < 0) {
            return currMin;
        }
        else {
            return currMin + dataStack.top();
        }
    }

    int getMin() {
        return currMin;
    }
};

int main(void) {
    MinStack* obj = new MinStack();
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    cout << "top: " << obj->top() << endl;
    obj->pop();
    cout << "min: " << obj->getMin() << endl;
    obj->pop();
    cout << "min: " << obj->getMin() << endl;
    obj->pop();
    obj->push(2147483647);
    cout << "top: " << obj->top() << endl;
    cout << "min: " << obj->getMin() << endl;
    obj->push(-2147483648);
    cout << "top: " << obj->top() << endl;
    cout << "min: " << obj->getMin() << endl;
    obj->pop();
    cout << "min: " << obj->getMin() << endl;


    return 0;
}