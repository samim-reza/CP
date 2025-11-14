    #include <bits/stdc++.h>
    using namespace std;
    
    #define yes cout<<"YES"<<endl
    #define no cout<<"NO"<<endl
    #define endl "\n"
    #define vi(v) vector<long long>v
    #define ll long long
    #define Test int n; cin>>n; while(n--)
    #define always while(true)

    //decimal to binary
    //bitset<8>  b1(number);

    //convert hexadecimal to decimal
    //stoi(hexNumber, zero, base)

    //convert decimal to hexadecimal and assing to a integer variable
    //stoi(decimalNumber, nullptr, 16);

    // bool isPrime(ll n)
    // {
    //     if(n==2) return true;
    //     if(n==1)return false;
    //     for(ll i=2;i*i<=n;i++)
    //         {
    //             if(n%i==0)
    //             {
    //                 return false;
    //             }
    //         }
    //     return true;
    // }
    // vector<int> primes;

    // void gen_primes(int n) {
    //     vector<bool> prime(n+1, true);
    //     prime[0] = prime[1] = false;
    //     for (ll i = 2; i <= n; i++) {
    //         if (prime[i]) {
    //             primes.push_back(i);
    //             for (ll j = i * i; j <= n; j += i) {
    //                 prime[j] = false;
    //             }
    //         }
    //     }
    // }

    // vector<ll> fact;
    // void precompute_factorials(int n) {
    //     fact.resize(n+1);
    //     fact[0] = 1;
    //     for (int i = 1; i <= n; i++) {
    //         fact[i] = (fact[i-1] * i) % mod;
    //     }
    // }

    // ll modExp(ll base, ll exp, ll modulus) {
    //     base %= modulus;
    //     ll res = 1;
    //     while (exp > 0) {
    //         if (exp & 1) 
    //             res = (res * base) % modulus;
    //         base = (base * base) % modulus;
    //         exp >>= 1;
    //     }
    //     return res;
    // }

    // ll BigMod(ll base, ll exp, ll mod) {
    //     ll res = 1;
    //     base %= mod; // Ensure base is within modulo range
    //     while (exp > 0) {
    //         if (exp % 2 == 1) res = (res * base) % mod;
    //         base = (base * base) % mod;
    //         exp /= 2;
    //     }
    //     return res;
    // }

    // string decimalToBase(ll n, int base) {
    //     // Handle invalid base
    //     if (base < 2 || base > 36) 
    //         return "";
        
    //     // Handle zero
    //     if (n == 0)
    //         return "0";
        
    //     string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    //     string result;
    //     bool isNegative = false;
    //     unsigned ll num;

    //     // Process negative numbers
    //     if (n < 0) {
    //         isNegative = true;
    //         if (n == LLONG_MIN) {
    //             num = static_cast<unsigned ll>(LLONG_MAX) + 1;
    //         } else {
    //             num = -n;
    //         }
    //     } else {
    //         num = n;
    //     }

    //     // Convert to target base
    //     while (num > 0) {
    //         unsigned remainder = num % base;
    //         num /= base;
    //         result = digits[remainder] + result;  // Prepend remainder digit
    //     }

    //     // Add negative sign if needed
    //     if (isNegative)
    //         result = '-' + result;

    //     return result;
    // }

    // // Efficient modular exponentiation using binary decomposition
    // ll bigmod(ll base, ll exponent, ll modulus) {
    //     if (modulus == 1) return 0;  // Anything mod 1 is 0
    //     ll result = 1;
    //     base %= modulus;  // Normalize base within modulus

    //     while (exponent > 0) {
    //         // Process set bit (LSB is 1)
    //         if (exponent & 1) {
    //             result = (result * base) % modulus;
    //         }
    //         // Prepare for next bit (square base)
    //         base = (base * base) % modulus;
    //         // Shift to next bit
    //         exponent >>= 1;
    //     }
    //     return result;
    // }

    // // Safe version for very large numbers (using __int128)
    // ll bigmod_safe(ll base, ll exponent, ll modulus) {
    //     if (modulus == 1) return 0;
    //     ll result = 1;
    //     base %= modulus;
        
    //     while (exponent > 0) {
    //         if (exponent & 1) {
    //             result = (static_cast<__int128>(result) * base) % modulus;
    //         }
    //         base = (static_cast<__int128>(base) * base) % modulus;
    //         exponent >>= 1;
    //     }
    //     return result;
    // }

    // // Helper function to compute GCD using Euclidean algorithm
    // ll gcd(ll a, ll b) {
    //     // Make sure we work with positive numbers
    //     a = std::abs(a);
    //     b = std::abs(b);
    //     while (b != 0) {
    //         ll temp = b;
    //         b = a % b;
    //         a = temp;
    //     }
    //     return a;
    // }

    // // Simplifies fraction to lowest terms
    // pair<ll, ll> simplifyFraction(ll numerator, ll denominator) {
    //     // Handle division by zero
    //     if (denominator == 0) {
    //         throw std::invalid_argument("Denominator cannot be zero");
    //     }

    //     // Handle zero numerator
    //     if (numerator == 0) {
    //         return {0, 1}; // 0/n = 0/1
    //     }

    //     // Compute GCD of absolute values
    //     ll divisor = gcd(numerator, denominator);

    //     // Simplify by dividing by GCD
    //     ll simple_num = numerator / divisor;
    //     ll simple_den = denominator / divisor;

    //     // Ensure denominator is positive
    //     if (simple_den < 0) {
    //         simple_num = -simple_num;
    //         simple_den = -simple_den;
    //     }

    //     return {simple_num, simple_den};
    // }
    //auto [num1, den1] = simplifyFraction(15, 25);
//--------------------------------------------------------------
// this is for miller rabin
    // ll mulmod(ll a, ll b, ll mod) {
    //     ll res = 0;
    //     a %= mod;
    //     while (b) {
    //         if (b & 1) res = (res + a) % mod;
    //         a = (a * 2) % mod;
    //         b >>= 1;
    //     }
    //     return res;
    // }

    // ll powmod(ll base, ll exp, ll mod) {
    //     ll res = 1;
    //     base %= mod;
    //     while (exp) {
    //         if (exp & 1) res = mulmod(res, base, mod);
    //         base = mulmod(base, base, mod);
    //         exp >>= 1;
    //     }
    //     return res;
    // }

    // bool miller_rabin(ll n, ll a) {
    //     if (n % a == 0) return false;
    //     ll d = n - 1;
    //     while (d % 2 == 0) d >>= 1;
    //     ll x = powmod(a, d, n);
    //     if (x == 1 || x == n-1) return true;
    //     while (d != n - 1) {
    //         x = mulmod(x, x, n);
    //         d <<= 1;
    //         if (x == 1) return false;
    //         if (x == n - 1) return true;
    //     }
    //     return false;
    // }

    // bool isPrime(ll n) {
    //     if (n <= 1) return false;
    //     if (n <= 3) return true;
    //     if (n % 2 == 0) return false;
        
    //     vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    //     for (ll a : bases) {
    //         if (n == a) return true;
    //         if (!miller_rabin(n, a)) return false;
    //     }
    //     return true;
    // }
// miller rabin end
//--------------------------------------------------------------
// polard rho factorization start
// ll gcd(ll a, ll b) {
//     a = abs(a);
//     b = abs(b);
//     return b == 0 ? a : gcd(b, a % b);
// }
// ll gcd(ll a, ll b) {
//     // a = abs(a);
//     // b = abs(b);
//     while (b != 0) {
//         ll temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// ll mulmod(ll a, ll b, ll mod) {
//     ll res = 0;
//     a %= mod;
//     while (b) {
//         if (b & 1) res = (res + a) % mod;
//         a = (a * 2) % mod;
//         b >>= 1;
//     }
//     return res;
// }

// ll powmod(ll a, ll e, ll mod) {
//     ll res = 1;
//     a %= mod;
//     while (e) {
//         if (e & 1) res = mulmod(res, a, mod);
//         a = mulmod(a, a, mod);
//         e >>= 1;
//     }
//     return res;
// }

// bool isPrime(ll n) {
//     if (n < 2) return false;
//     if (n == 2) return true;
//     if (n % 2 == 0) return false;
    
//     ll d = n - 1;
//     int s = 0;
//     while (d % 2 == 0) {
//         d /= 2;
//         s++;
//     }
    
//     vector<ll> bases = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    
//     for (ll a : bases) {
//         if (a % n == 0) continue;
//         ll x = powmod(a, d, n);
//         if (x == 1 || x == n - 1) continue;
        
//         bool composite = true;
//         for (int i = 0; i < s - 1; i++) {
//             x = mulmod(x, x, n);
//             if (x == n - 1) {
//                 composite = false;
//                 break;
//             }
//         }
//         if (composite) return false;
//     }
//     return true;
// }

// ll pollardRho(ll n) {
//     if (n == 1) return 1;
//     if (n % 2 == 0) return 2;
    
//     ll x = rand() % (n - 2) + 2;
//     ll y = x;
//     ll c = rand() % (n - 1) + 1;
//     ll d = 1;
    
//     while (d == 1) {
//         x = (mulmod(x, x, n) + c) % n;
//         y = (mulmod(y, y, n) + c) % n;
//         y = (mulmod(y, y, n) + c) % n;
//         d = gcd(abs(x - y), n);
        
//         if (d == n) return pollardRho(n);
//     }
//     return d;
// }

// void factorize(ll n, vector<ll>& factors) {
//     if (n == 1) return;
    
//     if (isPrime(n)) {
//         factors.push_back(n);
//         return;
//     }
    
//     ll divisor = pollardRho(n);
//     factorize(divisor, factors);
//     factorize(n / divisor, factors);
// }

// void make_factorization_list()
// {
//         ll a;
//         cin >> a;
        
//         if (a == 1) {
//             cout << "0\n";
//             return;
//         }
        
//         vector<ll> factors;
//         factorize(a, factors);
//         sort(factors.begin(), factors.end());
        
//         cout << factors.size();
//         for (ll factor : factors) {
//             cout << " " << factor;
//         }
//         cout << "\n";
// }
// polard rho factorization end
//--------------------------------------------------------------

    int main()
    {
        cin.tie(0);
        ios_base::sync_with_stdio(0);
        Test{
            
        }
    }