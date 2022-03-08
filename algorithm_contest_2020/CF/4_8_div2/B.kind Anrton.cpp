#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n+1),b(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++){
            cin>>b[i];
            b[i]-=a[i];
        }
        bool flag1=false,flag2=false,flag=true;
        for(int i=1;i<=n;i++){
            if(a[i-1]>0) flag1=true;
            else if(a[i-1]<0) flag2=true;

            if(b[i]==0) continue;  
            else if(b[i]>0 and flag1==true) continue;
            else if(b[i]<0 and flag2==true) continue;
            else flag=false;
        }

        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}