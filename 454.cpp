#include <iostream>
#include <unordered_map>

using namespace std;
    
    
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    int count = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < nums1.size(); i++) {
        for (int j = 0; j < nums2.size(); j++) {
            umap[nums1[i] + nums2[j]] ++;
        }
    }

    for (int i = 0; i < nums3.size(); i ++) {
        for (int j = 0; j < nums4.size(); j ++) {
            auto it = umap.find(0 - nums3[i] - nums4[j]);
            if (it != umap.end()) {
                count += it->second;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4 = {0, 2};
    cout << fourSumCount(nums1, nums2, nums3, nums4) << endl;
    return 0;
}