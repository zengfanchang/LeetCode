#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <array>

using namespace std;


void test(map<vector<int>, vector<int>> &m) {
    vector<int> arr(26);
    vector<int> arr2(26);
    arr[0] = 1;
    m[arr] = arr2;
    // m[arr] = 2;
    m[arr].push_back(1);
    // cout << m[arr] << endl;
    cout << arr.size() << endl;
    return ;
}


int main() {
    map<vector<int>, vector<int>> m;
    for (map<vector<int>, vector<int>>::iterator it = m.begin(); it != m.end(); it++) {
        cout << it->first << endl;
    }
    test(m);
    // cout << m[arr] << endl;
    cout << m.size() << endl;
    cout << m.size() << endl;
    return 0;
}