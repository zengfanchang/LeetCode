#include <iostream>
#include <string>

using namespace std;

// void skip(string s, int &pos) {
//     while (pos >= 0 && s[pos] == ' ') {
//         pos--;
//     }
// }
// string reverseWords(string s) {
//     string res = "";
//     int right = s.length() - 1;
//     skip(s, right); 
//     int left = right;
//     for (; left >= 0; left--) { 
//         if (s[left] == ' ') {
//             res += s.substr(left + 1, right - left);
//             skip(s, left); // 直接跳到-1 abort
//             if (left >= 0)
//                 res += ' ';
//             right = left;
//         }
//     }
//     if (left == -1)
//         res += s.substr(left + 1, right - left);
//     return res;
// }

void skip(string s, int &pos) {
    int len = s.length();
    while (pos < len && s[pos] == ' ') {pos++;}
}
void removeblank(string &s) { // 覆盖 截取
    int len = s.length();
    int fast = 0, slow = 0;
    skip(s, fast); // 跳过前面空格
    while (fast < len) {
        if (fast > 0 && s[fast] == ' ' && s[fast - 1] == ' ')  {fast++;continue;}
        else {
            s[slow++] = s[fast++];
        }    
    }
    if (slow > 1 && s[slow - 1] == ' ') {
        s.resize(slow - 1); 
    } else {
        s.resize(slow);
    }
}

void reversestr(string &s, int left, int right) {
    int start = left;
    char tmp;
    for (; left < right - (left - start) - 1; left++) {// 左闭右开区间
        tmp = s[left];
        s[left] = s[right - left + start- 1];
        s[right - left + start - 1] = tmp;
    }
}

string reverseWords(string s) {

    int left = 0, right = 0;
    removeblank(s);
    // 在原字符串上重新定义新的字符串
    reversestr(s, 0, s.length());
    int len = s.length();
    while (right < len) {
        if (s[right] == ' ') {
            reversestr(s, left, right);
            left = right + 1;
        }
        right ++;
    }
    reversestr(s, left, right);
    return s;
}


int main() {
    string s = "a good   example";
    cout << reverseWords(s) << endl;

    return 0;
}