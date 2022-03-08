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

void solve_1()
{
    // AC,参考 ： https://blog.csdn.net/Joker_He/article/details/107515829
    int t;cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string a,b;
        cin>>a>>b;
        a=" "+a;
        b=" "+b;

        queue<int> ans;
        bool fp=false;
        int l=1,r=n;
        for(int i=n;i>=1;i--)
        {
            if(fp==false)
            {
                if(a[r]==b[i]){
                    r--;
                    continue;
                }
                if(a[l]==b[i])
                    ans.push(1);
                ans.push(i);
                l++;
                fp=true;
            }
            else//fp状态下，01是反的
            {
                if(a[l]!=b[i]){
                    l++;
                    continue;
                }
                if(a[r]!=b[i])
                    ans.push(1);
                ans.push(i);
                r--;
                fp=false;  
            }
        }
        cout<<ans.size()<<' ';
        while(!ans.empty()){
            cout<<ans.front()<<' ';
            ans.pop();
        } cout<<endl;

    }

}
void solve_2()
{
    //  AC 参考： https://blog.csdn.net/li_wen_zhuo/article/details/107524910
    // 思路： 把a全变成一样的，b全变成一样的由于过程可逆……

    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string a,b;
        cin>>a>>b;
        a=" "+a;
        b=" "+b;
        queue<int> ans1;
        stack<int> ans2;
        for(int i=2;i<=n;i++) if(a[i]!=a[i-1]) ans1.push(i-1);
        for(int i=2;i<=n;i++) if(b[i]!=b[i-1]) ans2.push(i-1);

        if(a[n]!=b[n])  ans1.push(n);

        cout<<ans1.size()+ans2.size()<<' ';
        while(!ans1.empty()){
            cout<<ans1.front()<<' ';
            ans1.pop();
        }
        while(!ans2.empty()){
            cout<<ans2.top()<<' ';
            ans2.pop();
        }
        cout<<endl;
        
        
    }

}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    solve_2();
    return 0;
}