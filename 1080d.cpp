#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using u64 = unsigned long long;
using u32 = unsigned;

const int inf = 1e9;
const long long INF = 1e18;

bool isprime(long long n){
    for(long long i=2;i*i<=n;i++){ if(n%i==0) return false; }
    return true;
}

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

bool isPowerOfTwo(long long n) {
    return n > 0 && (n & (n - 1)) == 0;
}

long long popcount(long long n) {
    long long cnt = 0;
    while (n) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

long long reverse_digits(long long n) {
    long long r = 0;
    while (n) {
        r = r * 10 + n % 10;
        n /= 10;
    }
    return r;
}

long long digit_sum(long long n) {
    long long s = 0;
    while (n) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

void solve(){
    
 int t;cin>>t;
 while (t--){
     int n;cin>>n;    
  vector<long long> f(n);
        for (int i = 0; i < n; ++i) cin >> f[i];
        long long S = (f[0] + f[n - 1]) / (n - 1);
        vector<long long> d(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            d[i] = f[i + 1] - f[i];
        }
        vector<long long> a(n);
        a[0] = (d[0] + S) / 2;
        for (int i = 1; i <= n - 2; ++i) {
            a[i] = (d[i] - d[i - 1]) / 2;
        }
        a[n - 1] = (S - d[n - 2]) / 2;
        for (int i = 0; i < n; ++i) {
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
        }
 }
 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}