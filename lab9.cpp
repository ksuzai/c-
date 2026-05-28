#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    stack<string> stack;

    stack.push("First");
    stack.push("Second");
    stack.push("Third");

    while (!stack.empty()) {
        cout << stack.top() << endl;
        stack.pop();
    }

    return 0;
}
