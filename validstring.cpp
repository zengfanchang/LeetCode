#include <iostream>
#include <string>
#include <stack>


using namespace std;

class node {
    public: 
        node(char c, char level) {
            this->c = c;
            this->level = level;
        }

    public:
        char c;
        char level;
};


int main() {
    string s = "ababcabcc";
    stack<node> st;
    int len = s.length();

    for (int i = 0; i < len; i++) {
        switch (s[i]) {
            case 'a':
                st.push(node('a', '1'));
                break;
            case 'b':
                if (st.top().level == '1') {
                    st.push(node('b', '2'));
                } else {
                    cout << "invalid string" << endl;
                    return 0;
                }
                break;
            case 'c':
                if (st.top().level == '2') {
                    for (int j = 0; j < 2; j++) {
                        st.pop();
                    }
                } else {
                    cout << "invalid string" << endl;
                    return 0;
                }
                break;
            default:
                cout << "invalid string" << endl;
                return 0;
        }
    }
    if (st.empty()) {
        cout << "valid string" << endl;
    } else {
        cout << "invalid string" << endl;
    }
    return 0;
}
