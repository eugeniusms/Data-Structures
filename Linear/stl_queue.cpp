// Queue STL in C++
#include <iostream>
#include <queue> 
using namespace std;
template <typename T>

// c++ queue:
// method   | return type | time    | description 
// -------- | ----------- | ------- | -----------
// .push(x) | void        | O(1)    | push element x at the back of the queue (void)
// .pop()   | void        | O(1)    | remove the front element (void)
// .front() | type        | O(1)    | get the front element (type)
// .back()  | type        | O(1)    | get the back element (type)
// .empty() | bool        | O(1)    | check if the queue is empty (bool)
// .size()  | int         | O(1)    | get the size of the queue (int)

void print(queue<T> q) {
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(10); q.push(20); q.push(30); q.push(40);
    q.pop();
    cout << q.front() << "\n";
    cout << q.back() << "\n";
    cout << q.empty() << "\n";
    cout << q.size() << "\n";

    print(q);
    return 0;
}

// References:
// 1) https://www.geeksforgeeks.org/queue-cpp-stl/
