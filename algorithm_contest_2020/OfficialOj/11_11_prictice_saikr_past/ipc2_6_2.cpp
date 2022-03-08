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
// 这应该是标准题解，现在还没过
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,m;
    cin>>n>>m;
    {
        vector<int> a(n+1);
        vector<pair<LL,int> > b(m+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=m;i++){
            cin>>b[i].first;
            b[i].second=i;
        }
        sort(b.begin()+1,b.end());
        priority_queue<LL> que_left;//默认大根堆，堆顶最大
        priority_queue<LL,deque<LL>,greater<LL> > que_right;//小根堆，堆顶最小

        int pos=1;
        vector<LL> ans(m+1);
        b.push_back(m_p(n,n));
        for(int i=1;i<=m;i++)
        {
            for(int j=b[i-1].first+1;j<=b[i].first;j++)
                que_left.push(a[j]);
            while(que_left.size()<b[i].second){
                que_left.push(que_right.top());
                que_right.pop();
            }
            while(que_left.size()>b[i].second){
                que_right.push(que_left.top());
                que_left.pop();
            }
            ans[b[i].second]=que_left.top();

        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    }
    return 0;
}
