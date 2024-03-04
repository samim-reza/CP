#include <bits/stdc++.h>
using namespace std;
 
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define for0(n) for(int i=0;i<n;i++)
#define for1(n) for(int i=1;i<n;i++)
#define vi(v) vector<long long>v
#define ll long long
#define Test int n; cin>>n; while(n--)
#define always while(true)
bool isPrime(ll n)
{
    if(n==2) return true;
    if(n==1)return false;
    for(ll i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                return false;
            }
        }
    return true;
}
vector<int> primes;

void gen_primes(int n) {
    vector<bool> prime(n+1, true);
    prime[0] = prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
}
 
int main()
{
    gen_primes(100);
    for(int i=0;i<primes.size();i++)
    {
        cout<<primes[i]<<" ";
    }
}