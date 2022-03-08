#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> a(n+1);
        int cnt[2]={0};
        for(int i=1;i<=n;i++){
            cin>>a[i];
            cnt[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            int x,k;
            cin>>x>>k;
            if(x==1)
            { 
                if(a[k]==1){//1修改为0
                    cnt[1]--;
                    cnt[0]++;
                    a[k]=0;
                }
                else{
                    cnt[1]++;
                    cnt[0]--;
                    a[k]=1;
                }
            }
            else if(x==2)
            {
                if(k<=cnt[1]) cout<<1<<endl;//1的数量足够k个
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}
