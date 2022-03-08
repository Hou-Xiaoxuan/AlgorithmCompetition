#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_k make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
double f[1005][1005]={0};//剩余i白和j黑时英的概率
//面向题解……
int main()
{
    //IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    int w,b;
    while(cin>>w>>b)
    {
        for(int i=0;i<=w;i++)
            memset(f[i],0,sizeof(double)*(b+1));
        for(int i=1;i<=w;i++) f[i][0]=1;
        for(int i=1;i<=w;i++)//白
            for(int j=1;j<=b;j++)//黑
            {
                //开局i白j黑，可能会怎样？
                f[i][j]+=double(i)/(i+j);//可能直接赢
                if(j>=2)//可能不赢，然后龙抽到黑鼠，又跑了一只黑鼠，跳出去一只白鼠，没关系，开局i-1白j-2黑的概率
                    f[i][j]+=(double(j)/(i+j))*(double(j-1)/(i+j-1))*(double(i)/(i+j-2))*f[i-1][j-2];
                if(j>=3)//龙抽到黑鼠，但是跑了一只黑鼠，那开局i白j-3黑的概率……
                    f[i][j]+=(double(j)/(i+j))*(double(j-1)/(i+j-1))*(double(j-2)/(i+j-2))*f[i][j-3];
            }
        printf("%.9f\n",f[w][b]);
    }
    
    return 0;
}