#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    unordered_set<int> s;
    for (int i = 10; i < 20; i++) {
        s.insert(i);
    }

    auto it = s.find(15);
    if (it != s.end()) {
        cout << "Found " << *it << endl;
    } else {
        cout << "Not found" << endl;
    }
    return 0;
}
