#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> cnta,cntb;
        int x;
       for(int i=1;i<=n;i++){
            cin>>x;
            if(x&1) cnta.push_back(i);
            else cntb.push_back(i);
        }
            if(cntb.size()!=0)
                cout<<1<<endl<<cntb[0]<<endl;
            else if(cnta.size()>=2)
                cout<<2<<endl<<cnta[0]<<" "<<cnta[1]<<endl;
            else cout<<-1<<endl;
        
    }
    return 0;
}

