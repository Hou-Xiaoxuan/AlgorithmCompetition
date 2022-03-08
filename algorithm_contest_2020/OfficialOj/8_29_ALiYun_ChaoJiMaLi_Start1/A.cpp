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
int a[int(1e5+5)];
int get_int(string& st)
{
    static int l=0;
    int ct=l+1;
    int ans=0;
    while(ct<st.size() and st[ct]<='9' and st[ct]>='0')
    {
        ans=ans*2+st[ct++]-'0';
    }
    if(l==ct-1) 
        return -1;
    l=ct;
    return ans;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    string dat;cin>>dat;
    int d;cin>>d;
    int n=0;
    int tmp=get_int(dat);
    while(tmp!=-1) {
        a[++n]=tmp;
        cout<<a[n]<<endl;
        tmp=get_int(dat);
    }
    int l=1,r=2;
    int cnt=0;
    while(r<=n)
    {
        if(a[r]-a[l]>=d) {
            l=r;
            r++;
        }
        else{
            cnt++;
            r++;
        }
    }
    cout<<cnt<<endl;
   
    return 0;
}