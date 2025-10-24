#include <bits/stdc++.h>
using namespace std;

int main() {
    unsigned long long id;
    unsigned long long row = id / 4;
    unsigned long long rem = id % 4;
    unsigned long long col = (row % 2 == 0) ? rem : (3 - rem);
    cout << row << " " << col << "\n";
    return 0;
}
