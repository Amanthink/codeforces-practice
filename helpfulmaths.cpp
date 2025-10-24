#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string s, p = "";
    cin >> s;

    if (s.size() < 1) {
        cout << s;
    } else {
        vector<int> arr;
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) arr.push_back(s[i] - '0'); 
        }

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            p += to_string(arr[i]);
            if (i != arr.size() - 1) p += "+"; 
        }

        cout << p;
    }
}
