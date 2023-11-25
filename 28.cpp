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

// kmp算法求解 遍历字符串 比较前后缀末尾是否相同 i为后缀末尾 j为前缀末尾
void getNext(int *next, const string &s) {
    int len = s.length();
    int j = -1;
    next[0] = j;
    for (int i = 1; i < len; i++) { // 从一开始是因为当只有一个字符时候没有前后缀
        while (j >= 0 && s[i] != s[j + 1]) { // 前缀的末尾和后缀末尾不相同
            j = next[j]; // 回溯
        }
        if (s[i] == s[j + 1]) { // 相等情况
            j++;
        }
        next[i] = j;
    }
}

int main() {
    string haystack = "abb";
    string needle = "aabaaf";
    int next[6] = {0};
    getNext(next, needle);
    // cout << strStr(haystack, needle) << endl;
    // cout  << (int)haystack.length() - (int)needle.length() << endl;
    return 0;
}