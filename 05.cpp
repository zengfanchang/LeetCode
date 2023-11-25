#include <iostream>
#include <string>

using namespace std;


class parent {
public:
    parent() {
        cout << "parent" << endl;
        x = 10;
    }
    ~parent() {
        cout << "~parent" << endl;
    }
    int x;
};

class child : public parent  {
    public:
        void setX(int x) {
            parent::x = x;
        }
        void print() {
            cout << x << endl;
        }
};

int main() {
    child *p = new child();
    p->print();
    // string s = "We are happy";
    // int count = 0;
    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] == ' ') {
    //         count++;
    //     }
    // }
    // cout << count << endl;
    // s.resize(s.size() + count * 2);
    // int j = s.size() - 1;
    
    // string item = "";
    // for (int i = 0; i < s.size(); i++) {
    //     if (s[i] == ' ') {
    //         item += "%20";
    //     } else {
    //         item += s[i];
    //     }
    // }
    // cout << item << endl;
}

