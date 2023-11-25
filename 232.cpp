#include <iostream>
#include <stack>

using namespace std;

bool test() {
    stack<int> s;
    int x;
    s.push(1);
    s.pop();
    return x;
}
int main() {
    cout << test() << endl;
    return 0;
}