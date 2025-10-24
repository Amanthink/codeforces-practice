#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isVowel(char c) {
    c = tolower(c);
    return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='y');
}

int main() {
    string s;
    cin >> s;

    // Convert to lowercase
    for (int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }

    string p = "";
    for (int i = 0; i < s.size(); i++) {
        if (!isVowel(s[i])) {
            p.push_back('.');
            p.push_back(s[i]);
        }
    }

    cout << p;
    return 0;
}
