#include<bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define P pair<int,int>
#define x first
#define y second
typedef long long LL;
const int inf=0x3f3f3f3f;
// WA，一样的思路，曲荣升A掉了，还不清楚锅在哪里

int main()
{
    #ifdef _DEBUG
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif
    const int N=5e6+2;
    vector<bool> a(int(5e6+5));
    a[1]=true;
    for(int i=1;i<=N;i++)
    {
        if(a[i]==true)
        {
            if(5*i+13<=N) a[5*i+13]=true;
            if(5*i-13>=1 and 5*i-13<=N) a[5*i-13]=true;
            if(13*i+5<=N) a[13*i+5]=true;
            if(13*i-5>=1) a[13*i-5 and 13*i-5<=N]=true;
        }
    }
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        if(a[n]==true) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}