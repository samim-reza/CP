#include <bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int *pc, c;
    c = 5;
    pc = &c;
    printf("%d\n", *pc); 
}