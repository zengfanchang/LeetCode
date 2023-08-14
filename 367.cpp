# include <iostream>

using namespace std;

bool isPerfectSquare(int num) {
    for (int i = 1; i <= num; i += 2) {
        num -= i;
    }
    return num == 0;
}


int main() {
    int a = 16;
    cout << isPerfectSquare(a) << endl;
}