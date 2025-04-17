#include <bits/stdc++.h>
using namespace std;

#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define endl "\n"
#define ll long long

int main()
{
    ll n;
    cin>>n;
    ll count=1;
    string s,s1;
    n--;
    cin>>s;
    while(n--)
    {
        // cout<<s<<endl;
        cin>>s1;
        if(s!=s1) {count++;
            s=s1;}
        else{s=s1;}
    }
    cout<<count<<endl;
}