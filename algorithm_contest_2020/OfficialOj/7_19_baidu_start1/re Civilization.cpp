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
const int inf=0x3f3f3f3f;
//补题：
//直接枚举所有的地点即可
//奇怪的卡题方式……
int a[505][505];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
   int t;cin>>t;
   while(t--)
   {
       int n; P st;
       cin>>n>>st.x>>st.y;
        // 读入点数
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cin>>a[i][j];
        
        int ans=inf;
        //枚举建城点
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                P tmp=m_p(i,j);
                vector<int> allpoints(25);//这个n可能会小于3，因此位置会不够，为了防止越界访问，给一些0，代表失业
                int Round=(abs(st.x-i)+abs(st.y-j)+1)/2;//移动到这里
                int Grain=0;
                int force=a[i][j];
                int turn=(7+force)/force;
                Round+=turn;
                Grain+=turn*force;
                // 统计点数
                for(int i=max(tmp.x-3,1);i<=min(tmp.x+3,n);i++)
                    for(int j=max(tmp.y-3,1);j<=min(tmp.y+3,n);j++){
                        if(i==tmp.x and j==tmp.y) continue;//不统计本身
                        if(abs(tmp.x-i)+abs(tmp.y-j)<=3) allpoints.push_back(a[i][j]);
                    }
                sort(allpoints.begin(),allpoints.end());//升序排列
                vector<int> person;
                
                person.push_back(a[tmp.x][tmp.y]);

                // while(person.size()<9)//嗨，还不能这样搞，TLE了，确实得计算每次的个数
                // { 
                //     Round++;
                //     for(auto i:person)//所有人生产食物
                //         Grain+=i;
                //     while(Grain>=8*pow(person.size(),2)){//检测是否满足增加人员的条件
                //         person.push_back(allpoints.back());
                //         allpoints.pop_back();
                //     }
                   
                // }  
                for(int tree=2;tree<9;tree++)
                {   
                    force+=allpoints.back();
                    allpoints.pop_back();
                    turn=(8*tree*tree-Grain+force-1)/force;
                    Grain+=turn*force;
                    Round+=turn;
                }
                ans=min(Round,ans);
            }
        cout<<ans<<endl;
   }

    return 0;
}
