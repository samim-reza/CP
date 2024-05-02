#include <bits/stdc++.h>
using namespace std;

int main()
{
    cout<<"Enter the total memory available (in Bytes) – ";
    int total_memory;
    cin>>total_memory;
    cout<<endl;
    int check = total_memory;
    int process = 1;
    vector<int> memory_allocated;
    int allocated=0;
    while(1)
    {
        int memory_required;
        cout<<"Enter memory required for process "<<process<<"(in Bytes) – "; 
        cin>>memory_required;
        check-=memory_required;
        if(check<0)
        {
            cout<<"Memory is Full\n";
            break;
        }
        cout<<"Memory is allocated for Process "<<process++;
        cout<<"Do you want to continue(y/n):";
        char ch;
        cin>>ch;
        if(ch=='n')
        {
            break;
        }
        //cout<<check<<"k";
        total_memory-=memory_required;
        memory_allocated.push_back(memory_required);
        allocated+=memory_required;
    }


    cout<<"Total memory availabe: "<<total_memory<<endl;
    cout<<"\nprocess\t\tmemory-allocated\n";
    for(int i=0;i<memory_allocated.size();i++)
    {
        cout<<i+1<<"\t\t"<<memory_allocated[i]<<endl;
    }
    cout<<"total memory alocated: "<<allocated;
    cout<<"\ntotal external fragment: "<<total_memory;
    cout<<endl;
}