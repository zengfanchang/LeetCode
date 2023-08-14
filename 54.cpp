#include <iostream>
#include <vector>

using namespace std;
void getOrder(vector<vector<int>> &matrix, vector<int> &vec, int x, int y, int m, int n) {
    if (vec.size() == m * n) {
        return ;
    }
    if (m == 1) {
        for (int i = y; i < n - y; i++) 
            vec.push_back(matrix[x][i]);
        return ;
    }
    if (n == 1) {
        for (int i = x; i < m - x; i++) 
            vec.push_back(matrix[i][y]);
        return ;
    }
    if (m >= n && m % 2 == 1 && x == m / 2) {
        for (int i = x; i < n - x; i++) 
            vec.push_back(matrix[i][y]);
        return ;
    }
    if (n > m && n % 2 == 1 && y == n / 2) {
        for (int i = y; i < m - y; i++) 
            vec.push_back(matrix[x][i]);
        return ;
    }
    int i, j;
    for (j = y; j < n - y - 1; j++) {
        vec.push_back(matrix[x][j]);
    }

    for (i = x; i < m - x - 1; i++) {
        vec.push_back(matrix[i][j]);
    }

    for (; j > y; j--) {
        vec.push_back(matrix[i][j]);
    }

    for (; i > x; i--) {
        vec.push_back(matrix[i][j]);
    }
    getOrder(matrix, vec, x+1, y+1, m, n);
}
vector<int> spiralOrder(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> vec;
    return getOrder(matrix, vec, 0, 0, m, n);
}
int main() {
    vector<vector<int>> matrix = {{1,2,3},{8, 9, 4},{7, 6, 5}};
    spiralOrder(matrix);
    return 0;
}