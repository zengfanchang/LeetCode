#include <iostream>
#include <vector>
using namespace std;



int last_value(int x, vector<vector<int>> &vec,int value) {
    int i, j;
    for (i = x; i < vec.size() - x - 1; i++)
        vec[x][i] = value++;
    // 考虑竖向越界
    vec[x][i] = value++;
    if (x + 1 >= vec.size() - x)
        return value;

    for (j = x + 1; j < vec.size() - x - 1; j++) // 减去前面x个加后面一个
        vec[j][i] = value++;
    
    for (; i > x; i--) 
        vec[j][i] = value++;
    vec[j][i] = value++;


    for (j -= 1; j > x; j--)
        vec[j][i] = value++;
    return value;

}

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> vec(n, vector<int>(n, 0));
    int tmp = 1, x = 0;
    while (tmp != n * n + 1) {
        tmp = last_value(x++, vec, tmp);
    }
    return vec;
}



int main() {
    vector<vector<int>> vec = generateMatrix(2);
    return 0;
}