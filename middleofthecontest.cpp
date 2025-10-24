#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int h1 = stoi(a.substr(0, 2));
    int m1 = stoi(a.substr(3, 2));
    int h2 = stoi(b.substr(0, 2));
    int m2 = stoi(b.substr(3, 2));

    int t1 = h1 * 60 + m1;
    int t2 = h2 * 60 + m2;

    int mid = (t1 + t2) / 2;
    int mh = mid / 60;
    int mm = mid % 60;

    cout << setw(2) << setfill('0') << mh << ":"
         << setw(2) << setfill('0') << mm << "\n";

    return 0;
}
