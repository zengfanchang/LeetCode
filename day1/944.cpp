# include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++) {
        nums[i] = nums[i] * nums[i];
    }
    sort(nums.begin(), nums.end());
    return nums;
}

int main(int argc, char **argv) {
    vector<int> nums = {-4, -1, 0, 3, 10};
    sortedSquares(nums);
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << endl;
    }
    return 0;
}