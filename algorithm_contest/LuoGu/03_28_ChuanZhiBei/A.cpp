#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
const int inf=0x3f3f3f3f;


int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/run/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/run/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif

    int n,m;
    cin>>n>>m;
    vector<int> a[3];
    for(int k=0;k<3;k++)
    {
        a[k]=vector<int>(m+1);
        a[k][0]=n;
        int tmp;
        for(int i=1;i<=n;i++){
            cin>>tmp;
            a[k][tmp]++;
        }
    }
    int win=-1;
    int k=0,before=0;
    P lot={0,0};//x张y
    while(win==-1)
    {
        k%=3;
        if(before==k)//自己随意出
        {
            for(int i=1;i<=m;i++)
                if(a[k][i]>=1)
                {
                    a[k][i]--;
                    a[k][0]--;
                    if(a[k][0]==0) win=k;
                    before=k;
                    lot=P(1,i);
                    break;
                }
        }
        else
        {
            for(int j=lot.x;j<=a[k][0] and before!=k;j++)//尝试打出j张牌
                for(int i=1;i<=m;i++)
                {
                    if(a[k][i]>=j)//可以打牌
                    {
                        if((j==lot.x and i>lot.y) or j>lot.x)//相同点数大 or 张数多
                        {
                            a[k][i]-=j;
                            a[k][0]-=j;
                            if(a[k][0]==0) win=k;
                            before=k;
                            lot=P(j,i);
                            break;
                        }
                    }
                }
        }
        // if(k==before) cout<<k<<"打出了"<<lot.x<<"张"<<lot.y<<endl;//debug
        // else cout<<k<<"要不起"<<endl;

        k++;
    }
    cout<<win+1<<endl;
    return 0;
}
