#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int h = 0;
    while (true) {
        int next = h + 1;
        long long need = 1LL * next * (next + 1) * (next + 2) / 6;
        if (need <= n) h = next;
        else break;
    }
    cout << h << "\n";
    return 0;
}
