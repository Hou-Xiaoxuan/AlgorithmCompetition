#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

//补题：这个非质数<1000; 令a<=b,a*b<=1000 ,则 a<31(第11个质数)；//所以……很简单
/*
bool cmp1(P a,P b){return a.first<b.first;}
bool cmp2(P a,P b){return a.second<b.second;}
int main()
{
    //freopen("D:\\code_contest\\in.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);    
    int t;cin>>t;
    while(t--)
    {
        int n;  cin>>n;
        int tot=1;
        vector<int> cnt[12],ans(n+1),nod(n+1);
        
        int x;cin>>x;
        cnt[1].push_back(x);
        ans[1]=1;
        for(int i=2;i<=n;i++)
        {   
            cin>>x;
            for(int j=1;j<=tot;j++)
            {           
                bool flag=true;
                for(int k=0;k<cnt[j].size();k++)
                    if(gcd(cnt[j][k],x)<=1){
                        flag=false;
                        break;
                    }
                if(flag==true){
                    ans[i]=j;
                    cnt[j].push_back(x);
                    break;
                }
            }
            if(ans[i]==0){
                ans[i]=++tot;
                cnt[tot].push_back(x);
            }
        }
        cout<<tot<<endl;
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }


    return 0;
}
*/

/*
int main()
{
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);   
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> color(1005),ans(n+1);
        int x;
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            vector<int> a;
            cin>>x;
            //分解质因数
            for(int j=2;j<=x;j++)
            {
                if(x%j==0)
                {
                    a.push_back(j);
                    if(color[j]>0){
                        ans[i]=color[j];
                    }
                    while(x%j==0) x/=j;
                }
            }
            if(ans[i]==0)
                ans[i]=++tot;
            for(int j=0;j<a.size();j++){
        cout<<a[j]<<' ';//
                if(color[a[j]]==0) color[a[j]]=ans[i];
            }
        cout<<endl;//
        }
        cout<<tot<<endl;
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<' ';
        cout<<endl;
    }


    return 0;   
}
*/

int main()
{
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);
    int dot[]={0,2,3,5,7,11,13,17,19,23,29,31};
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<P > a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i].first;
        int tot=1;
        for(int i=1;i<=11;i++)
        {
            bool flag=false;
            for(int j=1;j<=n;j++)
                if(a[j].first%dot[i]==0)
                    if(a[j].second==0){
                        a[j].second=tot;
                        flag=true;
                    }
            
            if(flag==true) tot++;
        }
        cout<<tot-1<<endl;
        for(int i=1;i<=n;i++)
            cout<<a[i].second<<" ";
        cout<<endl;

    }

    return 0;
}