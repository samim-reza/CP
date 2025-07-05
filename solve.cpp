#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod = 1e9 + 7;
vector<ll> fact;
void precompute_factorials(int n) {
    fact.resize(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
}
// ll bigModExp(ll base, const string &exp, ll modulus) {
//     ll result = 1;
//     for (char digit : exp) {
//         result = modExp(result, 10, modulus);
//         result = (result * modExp(base, digit - '0', modulus)) % modulus;
//     }
//     return result;
// }

ll modExp(ll base, ll exp, ll modulus) {
    base %= modulus;
    ll res = 1;
    while (exp > 0) {
        if (exp & 1) 
            res = (res * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return res;
}

ll nCr(int n, int r) {
    if (r < 0 || r > n) 
        return 0;
    ll numerator = fact[n];
    ll denominator = (fact[r] * fact[n - r]) % mod;
    ll inv_denom = modExp(denominator, mod-2, mod);
    return numerator * inv_denom % mod;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    precompute_factorials(n);
    ll k = n / 2;
    ll comb = nCr(n, k);
    ll inv_k1 = modExp(k+1, mod-2, mod);
    ll result = comb * inv_k1 % mod;
    cout << result << endl;
}