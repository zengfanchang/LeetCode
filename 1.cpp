#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> twoSum1(vector<int>& nums, int target) {
    int length  = nums.size();
    vector<int> vec;
    for (int i = 0; i < length - 1; i++) {
        for (int j = i + 1; j < length; j++) {
            if (nums[i]  == target - nums[j]) {
                vec.push_back(i);
                vec.push_back(j);
                return vec;
            }
        }
    }
    return vec;
}

vector<int> twoSum(vector<int>& nums, int target) {
    multiset<int> s;
    vector<int> vec;
    int length = nums.size();

    for (int i = 0; i < length; i++) {
        s.insert(nums[i]);
    }

    for (int i = 0; i < length; i++) {
        // can't have two the same number
        int tmp = target - nums[i];
        auto it = s.find(tmp);
        if (it != s.end()) {
            vec.push_back(i);
            for (int j = 0; j < length; j++) {
                if (*it == nums[j]) {
                    vec.push_back(j);
                }
                break;
            }
            break;
        }

    }
    return vec;
}

int main() {
    vector<int> nums = {3, 2, 4, 3 };
    int target = 6;
    vector<int> vec = twoSum(nums, target);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << endl;
    }
    return 0;
}