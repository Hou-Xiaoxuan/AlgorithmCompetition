#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// 排列组合问题。但是数据太大了，用唯一分解定理判断。
// PE,多组样例……能不能明显一点啊，快三个小时，要吐了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    
    int n,m;
    while(cin>>n>>m)
    {
        vector<P > dm;//m的唯一分解x即出现的次数y
        for(int i=2;i<=sqrt(m) and m>1;i++)
        {
            if(m%i==0)
            {
                dm.push_back(m_p(i,0));
                while(m%i==0){
                    dm.back().y++;
                    m/=i;
                }
            }
        }
        if(m>1) dm.push_back(m_p(m,1));
        vector<int> a(dm.size());//dm的分解x在当前的系数中出现的次数
        vector<int> ans;
        vector<bool> flag(n+1);
        n--;//排列是c（n-1，k）
        /*未知错误*/
        // for(int k=1;k<n;k++)
        // {
        //     int ia=n-k+1,ib=k;
        //     bool flag=true;
        //     for(int i=0;i<dm.size();i++)
        //     {
        //         while(ia%dm[i].x==0){
        //             ia/=dm[i].x;
        //             a[i]++;
        //         }
        //         while(ib%dm[i].x==0){
        //             ib/=dm[i].x;
        //             a[i]--;
        //         }
        //         if(a[i]<dm[i].y) flag=false;
        //     }

        //     if(flag==true){
        //         ans.push_back(k+1);
        //     }
        // }
        for(int i=0;i<dm.size();i++)
        {
            int cure=0;
            for(int k=1;k<n;k++)
            {
                int ia=n-k+1,ib=k;
                while(ia%dm[i].x==0){
                    ia/=dm[i].x;
                    cure++;
                }
                while(ib%dm[i].x==0){
                    ib/=dm[i].x;
                    cure--;
                }
                if(cure<dm[i].y) flag[k]=1;
            }
        }
        for(int i=1;i<n;i++) if(flag[i]==0) ans.push_back(i+1);
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            if(i==ans.size()-1) cout<<ans[i];
            else cout<<ans[i]<<' ';
        cout<<endl;
    }
    return 0;
}