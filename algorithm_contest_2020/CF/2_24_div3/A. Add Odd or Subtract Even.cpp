#include<bits/stdc++.h>
using namespace std;
//AC
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int a,b;
        cin>>a>>b;
        if(a==b){
            cout<<0<<endl;
            continue;
        }
        if(a<b)
        {
            if((b-a)&1)
                cout<<1<<endl;
            else
                cout<<2<<endl;           
        }
        else
        {
            if((a-b)&1)
                cout<<2<<endl;
            else 
                cout<<1<<endl;           
        }
    }

    return 0;
}