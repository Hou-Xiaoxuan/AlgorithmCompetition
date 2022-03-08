#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
using namespace std;
const int maxn=1e3+10;
int bit[maxn][maxn];
int n,m;
//板子，二位线段树
void add(int x,int y,int d){
    for(int i=x;i<=n;i+=i&-i){
        for(int j=y;j<=m;j+=j&-j){
            bit[i][j]+=d;
        }
    }
}
int sum(int x,int y){
    int ans=0;
    for(int i=x;i;i-=i&-i){
        for(int j=y;j;j-=j&-j){
            ans+=bit[i][j];
        }
    }
    return ans;
}
int main(){
    //IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif

    int t,k;
    cin>>t;
    while(t--)
    {
         cin>>n>>m>>k;
         memset(bit,0,sizeof(bit));
         while(k--)
         {
            char c;
            cin>>c;
            if(c=='B'){
                int x,y;
                cin>>x>>y;
                if(sum(x,y)&1) printf("I want five star!\n");
                else printf("I want five star next time!\n");
            }
            else{
                int x1,x2,y1,y2;
                cin>>x1>>y1>>x2>>y2;
                add(x1,y1,1);
                add(x2+1,y1,-1);
                add(x1,y2+1,-1);
                add(x2+1,y2+1,1);
            }
         }
    }
    return 0;
}