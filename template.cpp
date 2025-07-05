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

// long long BigMod(long long base, long long exp, long long mod) {
//     long long res = 1;
//     base %= mod; // Ensure base is within modulo range
//     while (exp > 0) {
//         if (exp % 2 == 1) res = (res * base) % mod;
//         base = (base * base) % mod;
//         exp /= 2;
//     }
//     return res;
// }

// string decimalToBase(long long n, int base) {
//     // Handle invalid base
//     if (base < 2 || base > 36) 
//         return "";
    
//     // Handle zero
//     if (n == 0)
//         return "0";
    
//     string digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//     string result;
//     bool isNegative = false;
//     unsigned long long num;

//     // Process negative numbers
//     if (n < 0) {
//         isNegative = true;
//         if (n == LLONG_MIN) {
//             num = static_cast<unsigned long long>(LLONG_MAX) + 1;
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
// long long bigmod(long long base, long long exponent, long long modulus) {
//     if (modulus == 1) return 0;  // Anything mod 1 is 0
//     long long result = 1;
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
// long long bigmod_safe(long long base, long long exponent, long long modulus) {
//     if (modulus == 1) return 0;
//     long long result = 1;
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
// long long gcd(long long a, long long b) {
//     // Make sure we work with positive numbers
//     a = std::abs(a);
//     b = std::abs(b);
//     while (b != 0) {
//         long long temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }

// // Simplifies fraction to lowest terms
// pair<long long, long long> simplifyFraction(long long numerator, long long denominator) {
//     // Handle division by zero
//     if (denominator == 0) {
//         throw std::invalid_argument("Denominator cannot be zero");
//     }

//     // Handle zero numerator
//     if (numerator == 0) {
//         return {0, 1}; // 0/n = 0/1
//     }

//     // Compute GCD of absolute values
//     long long divisor = gcd(numerator, denominator);

//     // Simplify by dividing by GCD
//     long long simple_num = numerator / divisor;
//     long long simple_den = denominator / divisor;

//     // Ensure denominator is positive
//     if (simple_den < 0) {
//         simple_num = -simple_num;
//         simple_den = -simple_den;
//     }

//     return {simple_num, simple_den};
// }
//auto [num1, den1] = simplifyFraction(15, 25);

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
 
}