// Stack STL in C++
#include <iostream>
#include <stack> 
using namespace std;
template <typename T>

// c++ stack:
// method   | return type | time    | description 
// -------- | ----------- | ------- | -----------
// .push(x) | void        | O(1)    | push element x at the back of the stack (void)
// .pop()   | void        | O(1)    | remove the top element (void)
// .top()   | type        | O(1)    | get the top element (type)
// .empty() | bool        | O(1)    | check if the stack is empty (bool)
// .size()  | int         | O(1)    | get the size of the stack (int)

void print(stack<T> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    stack<int> s;
    s.push(10); s.push(20); s.push(30); s.push(40);
    s.pop();
    cout << s.top() << "\n";
    cout << s.empty() << "\n";
    cout << s.size() << "\n";

    print(s);
    return 0;
}

// References:
// 1) https://www.geeksforgeeks.org/stack-in-cpp-stl/