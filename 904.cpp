# include <iostream>
#include <vector>
using namespace std;

int totalFruit(vector<int>& fruits) {
    // 快慢指针
    int slow = 0, fast = 0;
    int len = fruits.size();
    int basket[4] = {-1, 0, -1, 0};
    int count = 0;
    int front = -1;
    while (fast < len) {
        if (basket[0] == -1) {
            basket[0] = fruits[fast++];
            basket[1] ++;
            if (basket[2] == -1) {
                front = 0;
            }
            continue;
        }
        if (basket[0] == fruits[fast]) {
            basket[1] ++;
            fast++;
            continue;
        }
        if (basket[2] == -1) {
            basket[2] = fruits[fast++];
            basket[3] ++;
            if (basket[0] == -1) {
                front = 2;
            }
            continue;
        }
        if (basket[2] == fruits[fast]) {
            basket[3]++;
            fast++;
            continue;
        }
        // 非结果 谁先谁后
        count = max(count, basket[1] + basket[3]);
        int temp = fast-1;
        basket[0] = fruits[fast];
        basket[1] = 1;
        basket[2] = fruits[temp];
        basket[3] = 0;
        while (fruits[temp] == fruits[fast-1] && temp >= 0) {  
            basket[3]++;
            temp--;
        }
        fast++;
    }
    count = max(count, basket[1] + basket[3]);
    return count;
}
int main() {
    vector<int> fruits = {1, 0, 1, 4, 1, 4, 1, 2, 3};
    cout << totalFruit(fruits) << endl;
    return 0;
}