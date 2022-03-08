#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
//#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<double,double>
#define k first
#define b second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
double esp=1e-15;

bool cmp(P &a,P &b){
    if(a.k==b.k) return a.b<b.b;
    return a.k<b.k;
}
P lin[int(1e6+5)];
int main()
{
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int size_lin=0;
        int n;
        scanf("%d",&n);
        vector<int> infi;
        double x1,y1,x2,y2;
        for(int i=1;i<=n;i++)
        {
            // cin>>x1>>y1>>x2>>y2;
            scanf("%lf,%lf,%lf,%lf",&x1,&y1,&x2,&y2);
            if(x1==x2){//竖直
                infi.push_back(int(x1));
            }
            else
            {
                P st;
                st.k=(y2-y1)/(x2-x1);
                st.b=y1-st.k*x1;
                lin[size_lin++]=st;
            }
        }

        LL ans=0;
        ans=LL(n)*(n-1)/2;
        LL cnt=1;
        sort(infi.begin(),infi.end());
        ans-=LL(infi.size())*(infi.size()-1)/2;
        for(int i=0;i<infi.size();i++)
        {
            if(infi[i]==infi[i-1])
                cnt++;
            else{
                ans+=(cnt-1)*cnt/2;
                cnt=1;
            }
        }
        ans+=cnt*(cnt-1)/2;
        cnt=1;
        sort(lin,lin+size_lin,cmp);
        for(int i=1;i<size_lin;i++)
        {
            if(fabs(lin[i].k-lin[i-1].k)<esp)//斜率相等
            {
                if(fabs(lin[i].b-lin[i-1].b)>esp)//截距不等
                {
                    cnt++;
                }
                else
                {
                    ans-=cnt*(cnt-1)/2;
                    cnt=1;
                }
                
            }
            else
            {
                ans-=cnt*(cnt-1)/2;
                cnt=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}