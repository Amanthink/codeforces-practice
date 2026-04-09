#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using ll=long long ;

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
 while(t--){
        ll a,b,c,m;
        cin >> a >> b >> c >> m;

        ll A = m/a;
        ll B = m/b;
        ll C = m/c;

        ll ab = lcm(a,b);
        ll ac = lcm(a,c);
        ll bc = lcm(b,c);
        ll abc = lcm(ab,c);

        ll AB = m/ab;
        ll AC = m/ac;
        ll BC = m/bc;
        ll ABC = m/abc;

        ll onlyA = A - AB - AC + ABC;
        ll onlyB = B - AB - BC + ABC;
        ll onlyC = C - AC - BC + ABC;

        ll ABonly = AB - ABC;
        ll AConly = AC - ABC;
        ll BConly = BC - ABC;

        ll Alice = 6*onlyA + 3*ABonly + 3*AConly + 2*ABC;
        ll Bob   = 6*onlyB + 3*ABonly + 3*BConly + 2*ABC;
        ll Carol = 6*onlyC + 3*AConly + 3*BConly + 2*ABC;

        cout << Alice << " " << Bob << " " << Carol << "\n";
    }
 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}