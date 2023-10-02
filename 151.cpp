#include <iostream>
#include <string>

using namespace std;

void skip(string s, int &pos) {
    while (pos >= 0 && s[pos] == ' ') {
        pos--;
    }
}
string reverseWords(string s) {
    string res = "";
    int right = s.length() - 1;
    skip(s, right); 
    int left = right;
    for (; left >= 0; left--) { 
        if (s[left] == ' ') {
            res += s.substr(left + 1, right - left);
            skip(s, left); // 直接跳到-1 abort
            if (left >= 0)
                res += ' ';
            right = left;
        }
    }
    if (left == -1)
        res += s.substr(left + 1, right - left);
    return res;
}

int main() {
    string s = "the sky is blue";
    cout << reverseWords(s) << endl;
    return 0;
}