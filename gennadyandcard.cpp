#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;   // your card (e.g., "4D")

    bool flag = false;

    for (int i = 0; i < 5; i++) {
        string a;
        cin >> a;
        if (a[0] == s[0] || a[1] == s[1]) {
            flag = true;
        }
    }

    if (flag) cout << "YES";
    else cout << "NO";

    return 0;
}
