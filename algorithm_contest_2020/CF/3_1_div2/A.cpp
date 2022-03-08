#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        int ia=0,ib=0;
        for(int i=1;i<=n;i++)
            if(a[i]>b[i]) ia++;
            else if(a[i]<b[i]) ib++;
        
        if(ia==0)
            cout<<-1<<endl;
        else if(ia>ib)
        cout<<1<<endl;
        else if(ib==1)
            cout<<2<<endl;
        else if(ib>1) {
            int cnt=(ib-1)/ia+1;
            while(ia*cnt<=ib) cnt++;
            cout<<cnt<<endl;
        }




    }


    return 0;
}