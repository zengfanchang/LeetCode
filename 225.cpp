#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.pop();
    int x = q.empty()? 0 : 1;
    cout << x << endl;
    switch(x) {
        case 0:
            return new int(1);
            break;
        case 1:
            return 0;
            break;
    }
}