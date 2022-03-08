#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    vector<LL> a(t+1);
    priority_queue<int> que1;
    priority_queue<int,vector<int>,greater<int>> que2;

    cin>>a[1];
    cout<<a[1]<<" ";
    LL tmp=a[1];
    que1.push(a[1]);
    for(int i=2;i<=t;i++)
    {
        cin>>a[i];
        a[i]=tmp*a[i]%t+1;
        if(que1.size()>que2.size())
        {
            if(a[i]<=que1.top()){
                que2.push(que1.top());
                que1.pop();
                que1.push(a[i]);
            }
            else
                que2.push(a[i]);
        }
        else if(que1.size()<que2.size())
        {
            if(a[i]>=que2.top()){
                que1.push(que2.top());
                que2.pop();
                que2.push(a[i]);
            }
            else
                que1.push(a[i]);
        }
        else
        {
            if(a[i]<=que1.top())
                que1.push(a[i]);
                else que2.push(a[i]);
        }
        
        int v=(i+1)>>1;
        if(v==que1.size()) tmp=que1.top();
        else tmp=que2.top();
        cout<<tmp<<' ';
    }cout<<endl;
    

    return 0;
}