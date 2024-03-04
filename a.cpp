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
 
int main()
{
    int n,t;
    cin>>n>>t;
    string s;
    cin>>s;
    for(int i=0; i<t; i++){
        for(int j=0; j<n-1; j++){
            if(s[j]=='B' && s[j+1]=='G'){
                swap(s[j], s[j+1]);
                j++;
            }
        }
    }
    cout<<s<<endl;  
}