#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;cin>>T;
    while(T--)
    {
        int n;cin>>n;
        if(n>=6) cout<<2<<endl;
        else if(n==5) cout<<3<<endl;
        else if(n==4) cout<<3<<endl;
        else cout<<-1<<endl;
    }



    return 0;
}