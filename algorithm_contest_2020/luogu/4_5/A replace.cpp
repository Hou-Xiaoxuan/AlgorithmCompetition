#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
struct nod
{
    LL x;
    double d;
    LL t;
    nod(LL a=1,double b=1,LL c=0){
        x=a;d=b;t=c;
    }
};
double num[300];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    num[1]=1;
    for(int i=2;i<=250;i++)
        num[i]=num[i-1]*10;
    const ULL mod=1e9+7;
    int n,k;
    cin>>n>>k;
    vector<LL> a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i];
    nod ans(0,0,0);
    /*if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            if(i<n and a[i]==a[i+1])
            {
                nod tmp=((a[i]*a[i+1])%mod,double(a[i])*double(a[i+1]),0);
                for(int j=1;i-j>=1 and i+1+j<=n;j++)
                {
                    if(a[i+1+j]!=a[i-j]) break;
                    tmp.x*=a[i+j+1];
                    tmp.x%=mod;
                    tmp.x*=a[i-j];
                    tmp.x%=mod;
                    tmp.d*=double(a[i+j+1]);
                    tmp.d*=double(a[i-j]);
                    while(tmp.d>10){
                        tmp.d/=10;
                        tmp.t++;
                    }
                }
                if(ans.t<tmp.t or (ans.t==tmp.t and ans.d<tmp.d))
                ans=tmp;
            }
            else
            {
                nod tmp(a[i],double(a[i]),0);
                for(int j=1;i-j>=1 and i+j<=n;j++)
                {
                    if(a[i+j]!=a[i-j]) break;
                    tmp.x*=a[i+j];
                    tmp.x%=mod;
                    tmp.x*=a[i-j];
                    tmp.x%=mod;
                    tmp.d*=double(a[i+j]);
                    tmp.d*=double(a[i-j]);
                    if(tmp.d>1e200)
                    {
                        int aa=lower_bound(num+1,num+251,tmp.d)-num-1;
                        tmp.d/=num[aa-1];
                        tmp.t+=aa-2;
                    }
                }
                if(ans.t<tmp.t or (ans.t==tmp.t and ans.d<tmp.d))
                ans=tmp;
            }
        }
    }
    else
    */
    {
        for(int i=1;i<=n;i++)//长度为i
        { 
            for(int j=1;j+i-1<=n;j++)//从j开始
            {
                nod tmp(1,1.0,0);
                int cnt=0;
                int l=j,r=j+i-1;
                for(int ia=l;ia<=l+r-ia;ia++)
                {
                    if(a[ia]!=a[l+r-ia]) cnt++;
                    if(cnt>k) break;
                    tmp.x*=a[ia]; tmp.x%=mod;
                    tmp.d*=double(a[ia]);
                    //while(tmp.d>10){tmp.d/=10;tmp.t++;}
                    if(ia!=l+r-ia)
                    {
                        tmp.x*=a[l+r-ia]; tmp.x%=mod;
                        tmp.d*=double(a[l+r-ia]);
                        //while(tmp.d>10){tmp.d/=10;tmp.t++;}
                    }
                    if(tmp.d>1e200)
                    {
                        int aa=lower_bound(num+1,num+251,tmp.d)-num;
                        tmp.d/=num[aa];
                        tmp.t+=aa-1;
                    }
                }
                int aa=lower_bound(num+1,num+251,tmp.d)-num;
                tmp.d/=num[aa];
                tmp.t+=aa-1;
                if(cnt<=k)
                    if(ans.t<tmp.t or (ans.t==tmp.t and ans.d<tmp.d))
                        ans=tmp;
            }
        }
    }
    cout<<ans.x%mod<<endl;

    return 0;
}