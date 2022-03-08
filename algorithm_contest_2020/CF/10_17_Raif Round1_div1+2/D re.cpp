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
/*
*节点1增加可用节点（2，3可用）
*节点2消耗可用节点，产生一个仅3可用的节点
*节点3消耗可用节点/专属节点，产生一个专属节点
*///A了，原因就是因为考虑的不够晚上，3的构造条件比2要稀疏
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
        queue<P> que,que3;//通用节点+专属节点
        bool flag=true;
        for(int i=n;i>=1;i--)
        {
            if(a[i]==0) continue;
            else if(a[i]==1)
            {
                ans.push_back(m_p(r,i));
                que.push(m_p(r++,i));
            }
            else if(a[i]==2)
            {
                if(que.empty()){
                    flag=false;
                    continue;
                }
                P st=que.front();
                que.pop();
                ans.push_back(m_p(st.x,i));
                que3.push(m_p(st.x,i));
            }
            else if(a[i]==3)
            {
                if(que.empty() and que3.empty()){
                    flag=false;
                    break;
                }
                P st;
                if(!que3.empty()){//优先选择专属节点
                    st=que3.front();
                    que3.pop();
                }
                else{
                    st=que.front();
                    que.pop();
                }
                ans.push_back(m_p(r,st.y));
                ans.push_back(m_p(r,i));
                que3.push(m_p(r++,i));
            }
        }
        if(flag==false){//行用超了或者中间已经无法构造了的话
            cout<<-1<<endl;
            continue;
        }
        sort(ans.begin(),ans.end(),[](P& a,P& b){//没必要的排序
            return a.x<b.x;
        });
        cout<<ans.size()<<endl;
        for(auto st:ans){
            cout<<n-st.x+1<<" "<<st.y<<endl;
        }
    }

    return 0;
}