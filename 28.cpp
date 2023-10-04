#include <iostream>
#include <string>

using namespace std;

int strStr(string haystack, string needle) {
    bool flag = true;
    for (int i = 0; i < (int)haystack.size() - (int)needle.size() + 1; i++) {
        for (int j = 0; j < needle.size(); j++) {
            if (haystack[i + j] != needle[j]) {
                flag = false; // 不等就wei false
                break;
            }
            flag = true;
        }
        if (flag == true) {
            return i;
        }
    }
    return -1;
}

int main() {
    string haystack = "abb";
    string needle = "abaaa";
    cout << strStr(haystack, needle) << endl;
    // cout  << (int)haystack.length() - (int)needle.length() << endl;
    return 0;
}