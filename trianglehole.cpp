#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int h, k;
    cin >> h >> k;
    double area = pow(h, 2) / sqrt(3);
    area /= pow(4, k); 
    cout << fixed << area;
    return 0;
}
