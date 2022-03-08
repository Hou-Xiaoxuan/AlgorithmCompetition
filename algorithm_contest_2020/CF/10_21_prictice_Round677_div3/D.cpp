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
        int n; cin>>n;
        // map<int,int> ma;
        // vector<P > a(1);
        // for(int i=1;i<=n;i++)
        // {
        //     int x;cin>>x;
        //     ma[x]++;
        //     a.push_back(m_p(x,i));
        // }
        // bool flag=true;
        // for(auto&i:ma)
        // {
        //     if(i.second*2>n){
        //         flag=false;
        //         break;
        //     }
        // }
        // if(flag==false) cout<<"NO"<<endl;
        // else
        // {
        //     cout<<"YES"<<endl;
        //     sort(a.begin(),a.end());
        //     int m=n/2+(n&1);
        //     for(int i=m+1;i<=n;i++)
        //     {
        //         cout<<a[i-m].y<<" "<<a[i].y<<endl;
        //         if(i-m+1<=m)cout<<a[i-m+1].y<<' '<<a[i].y<<endl;
        //     }
        // }
        

        map<int,vector<int> > a;
        for(int i=1;i<=n;i++)
        {
            int x;cin>>x;
            a[x].push_back(i);
        }
        if(a.size()<=1) cout<<"NO"<<endl;
        else
        {
            cout<<"YES"<<endl;
            for(auto i=a.begin();i!=a.end();i++)
            {
                if(i==a.begin())
                {
                    auto ed=a.end();
                    ed--;
                    for(int j=1;j<i->second.size();j++)
                        cout<<ed->second[0]<<' '<<i->second[j]<<endl;
                }
                else
                {
                    auto st=i;
                    st--;
                    for(auto j:i->second){
                        cout<<j<<" "<<st->second[0]<<endl;
                    }
                }
                
            }
        }
        
    }
    return 0;
}