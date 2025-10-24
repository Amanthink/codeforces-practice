#include <iostream>
#include <string>
using namespace std;

int main() {
    int k;
    string n;
    cin >> n >> k;
    while (k--) {
        int num = stoi(n);
        if (num % 10 == 0) num /= 10;
        else num--;
        n = to_string(num);
    }
    cout << n << endl;
    return 0;
}
