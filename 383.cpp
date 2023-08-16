#include <iostream>
#include <string>

using namespace std;


bool canConstruct(string ransomNote, string magazine) {
    int record[26] = {0};
    int flag = true;
    for (int i = 0; i < ransomNote.length(); i++) {
        record[ransomNote[i] - 'a'] += 1;
    }
    for (int i = 0; i < magazine.length(); i++) {
        record[magazine[i] - 'a'] -= 1;
    }
    for (int i = 0; i < 26; i++) {
        if (record[i] < 0) {
            flag = false;
            break;
        }
    }
    return flag;
}
int main() {
    string a = "aa";
    string b = "aab";
    cout << canConstruct(a, b) << endl;
}