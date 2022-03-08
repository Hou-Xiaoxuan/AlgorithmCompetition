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
        LL n,k,ans=0;
        cin>>n>>k;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a.begin()+1,a.end(),greater<int>());

        /*思路二：
        *直接看题解：
        *优先队列+贪心啊
        */
        priority_queue<LL> que;//里面存的时可以用来捕鱼的小时间段
        ans=k+a[1];//抓第一条鱼的时间和炖第一条鱼的时间
        LL ct=a[1]/k;//可以完美捕a[1]/k条鱼
        if(a[1]%k) que.push(a[1]%k);//还剩下a[1]%k时间的小片段
        int i;
        for(i=2;i<=n;i++)
        {
            if(ct>0)
            {
                ct--;
                ans+=a[i];
                ct+=a[i]/k;//a[i]>k时，这个循环就不会结束。
                if(a[i]%k) que.push(a[i]%k);
            }
            else 
                break;
        }
        for(;i<=n;i++)
        {
            LL s=que.top();//目前最长的一个时间小片段
            que.pop();
            ans+=a[i];
            ans+=k-s;//这个小片段可以节省s的时间花费，因此捕鱼带来的时间增长变成k-s
            que.push(a[i]);//到这里的a[i]都是小于k的
        }
        cout<<ans<<endl;
        /*思路1：WA
        *仔细看题后发现，并没有说一次只能捕捞一条鱼*/
        // //首尾两项特殊处理
        // ans=k;//第一条鱼的捕捞时间
        // for(int i=1;i<n;i++)
        // {
        //     if(a[i]<=k) ans+=k;//烹饪时间小于下一条的捕捞时间，则把下一条鱼捕捞上来
        //     else ans+=a[i];//否则捕捞上来鱼之后再多等a[i]-k;
        // }
        // ans+=a[n];//最后一条鱼的烹饪时间
        // cout<<ans<<endl;
    }
    return 0;
}