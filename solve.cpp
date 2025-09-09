#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    ll b;
    cin >> b;
    
    // Key insight: For a given b, LCM(a,b) = a*b/gcd(a,b)
    // The possible values of gcd(a,b) are the divisors of b
    // For each divisor d of b, we can find how many numbers from 1 to 10^18
    // will have gcd(a,b) = d
    
    // Find all divisors of b
    vector<ll> divisors;
    for (ll i = 1; i * i <= b; i++) {
        if (b % i == 0) {
            divisors.push_back(i);
            if (i * i != b) {
                divisors.push_back(b / i);
            }
        }
    }
    
    // For each divisor d, calculate b/d = b'
    // LCM(a,b) = (a/d)*b = (a/d)*d*b' = a*b'
    // This means that for all a that have gcd(a,b) = d,
    // LCM(a,b) will be a multiple of b'
    unordered_set<ll> distinct_lcms;
    
    const ll MAX_A = 1e18;
    
    for (ll d : divisors) {
        // For each divisor d of b:
        // We need to find all a where gcd(a,b) = d
        // These are numbers of the form a = d*k where k is coprime with b/d
        // The LCM for such numbers will be a*b/d = d*k*b/d = k*b
        
        // For each such d, we get a sequence of LCMs: b, 2b, 3b, ...
        // But we only care about those where a ≤ 10^18
        
        // The formula is: lcm = (a/d) * b
        // Since a ≤ 10^18, we have (a/d) ≤ 10^18/d
        ll max_multiple = MAX_A / d;
        
        // Each a that has gcd(a,b) = d will produce LCM = (a/d) * b
        // So the distinct values are b, 2b, 3b, ..., up to (max_multiple * b)
        // But we need to count unique values
        
        ll b_prime = b / d;
        for (ll k = 1; k <= max_multiple; k++) {
            if (gcd(k, b_prime) == 1) {
                distinct_lcms.insert(k * b);
            }
        }
    }
    
    cout << distinct_lcms.size() << endl;
    return 0;
}