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
// WA了，而且只过完样例就WA了……
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n;
    while(cin>>n)
    {
        vector<int> a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int r=1;
        vector<P> ans;
        queue<P> que;
        bool flag=true;
        for(int i=n;i>=1;i--)
        {
            if(a[i]==0) continue;
            else if(a[i]==1)
            {
                ans.push_back(m_p(i,r));
                que.push(m_p(r++,i));
            }
            else if(a[i]==2)
            {
                if(que.empty()){
                    flag=false;
                    break;
                }
            
                P st=que.front();
                que.pop();
                ans.push_back(m_p(i,st.x));
            }
            else if(a[i]==3)
            {
                // 对3的处理出错了，尽管3会使用一次机会，但是那个机会却仍然可以供2使用
                if(que.empty()){
                    flag=false;
                    break;
                }
                // P st=que.front();
                // que.pop();
                // ans.push_back(m_p(i,r));//i列r行
                // ans.push_back(m_p(st.y,r++));

            }
            if(r>n+1){
                flag=false;
                break;
            }
        }
        if(flag==false){//行用超了或者中间已经无法构造了的话
            cout<<-1<<endl;
            continue;
        }
        sort(ans.begin(),ans.end(),[](P& a,P& b){
            return a.x<b.x;
        });
        cout<<ans.size()<<endl;
        for(auto st:ans){
            cout<<n-st.y+1<<" "<<st.x<<endl;
        }
    }

    return 0;
}