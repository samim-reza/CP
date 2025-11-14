#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll mulmod(ll a, ll b, ll mod) {
    ll res = 0;
    a %= mod;
    while (b) {
        if (b & 1) res = (res + a) % mod;
        a = (a * 2) % mod;
        b >>= 1;
    }
    return res;
}

ll powmod(ll a, ll e, ll mod) {
    ll res = 1;
    a %= mod;
    while (e) {
        if (e & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        e >>= 1;
    }
    return res;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    
    // Test these bases for numbers up to 2^64
    vector<ll> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    
    for (ll a : bases) {
        if (a % n == 0) continue;
        ll x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        
        bool composite = true;
        for (int i = 0; i < s - 1; i++) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

ll pollardRho(ll n) {
    if (n == 1) return 1;
    if (n % 2 == 0) return 2;
    
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;
    
    while (d == 1) {
        x = (mulmod(x, x, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        y = (mulmod(y, y, n) + c) % n;
        d = gcd(abs(x - y), n);
        
        if (d == n) return pollardRho(n);
    }
    return d;
}

void factorize(ll n, vector<ll>& factors) {
    if (n == 1) return;
    
    if (isPrime(n)) {
        factors.push_back(n);
        return;
    }
    
    ll divisor = pollardRho(n);
    factorize(divisor, factors);
    factorize(n / divisor, factors);
}

void make_factorization_list()
{
        ll a;
        cin >> a;
        
        if (a == 1) {
            cout << "0\n";
            return;
        }
        
        vector<ll> factors;
        factorize(a, factors);
        sort(factors.begin(), factors.end());
        
        cout << factors.size();
        for (ll factor : factors) {
            cout << " " << factor;
        }
        cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q;
    cin >> Q;
    
    while (Q--) {
        make_factorization_list();
    }
}