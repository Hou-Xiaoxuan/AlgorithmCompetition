#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<long long,int>
#define x first
#define y second 
typedef long long LL;
const int inf=-9223372036854775808;
bool cmp(const P& a,const P&b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
// Ac 类型转换问题。我输出了个-0.强制转int就AC了
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
        int n;cin>>n;
        vector<P > a(n+1);
        int cnta=0,cntb=0;
        int x;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(x<0){
                a[i]=m_p(-x,-1);
                cnta++;
            }
            else{
                a[i]=m_p(x,1);
                cntb++;
            }
        }
        sort(a.begin()+1,a.end(),cmp);
        if(n==5){//只有五个数
            cout<<int(pow(-1,cnta))*a[1].x*a[2].x*a[3].x*a[4].x*a[5].x<<endl;
        }
        else if(cntb==0){//没有正数，选择最小的就行
            cout<<a[1].x*a[2].x*a[3].x*a[4].x*a[5].x*(-1)<<endl;
        }
        else
        {
            // 答案是正数
            // 无非三种答案情况
            //  5+  3+  1+
            // 0算作正数
            LL ans[4]={0,inf,inf,inf};
            int cnt1[4]={0},cnt2[4]={0};
            for(int i=n;i>=1;i--)
            {
                if(a[i].y>0)
                {
                    if(cnt1[1]<5){
                        if(ans[1]==inf) ans[1]=a[i].x; 
                        else ans[1]*=a[i].x;
                        cnt1[1]++;
                    }
                    if(cnt1[2]<3){
                        if(ans[2]==inf) ans[2]=a[i].x; 
                        else ans[2]*=a[i].x;
                        cnt1[2]++;
                    }
                    if(cnt1[3]<1){
                        if(ans[3]==inf) ans[3]=a[i].x; 
                        else ans[3]*=a[i].x;
                        cnt1[3]++;
                    }
                }
                else if(a[i].y<0)
                {
                    if(cnt2[2]<2){
                        if(ans[2]==inf) ans[2]=a[i].x;
                        else ans[2]*=a[i].x;
                        cnt2[2]++;
                    }
                    if(cnt2[3]<4){
                        if(ans[3]==inf) ans[3]=a[i].x;
                        else ans[3]*=a[i].x;
                        cnt2[3]++;
                    }
                }
            }
            LL st=inf;
            for(int i=1;i<=3;i++)
            {
                if(cnt1[i]+cnt2[i]==5)//构造完成的答案
                    st=max(ans[i],st);
            }
            if(st==-1e16) st=0;//一个答案都没有构造好
            if(st==-0) st==0;
            cout<<st<<endl;
        }
        
    }
    return 0;
}