#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;

    string s;
    int index = 0;
    for (int step = 1; index < n; step++) {
        s.push_back(t[index]);
        index += step;
    }

    cout << s << endl;
    return 0;
}
