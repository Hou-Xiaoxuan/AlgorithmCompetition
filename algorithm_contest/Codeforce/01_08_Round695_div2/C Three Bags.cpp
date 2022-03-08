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
// 忽然想起来这题还没补……

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    // int n1,n2,n3;
    // while(cin>>n1>>n2>>n3)
    // {

    //     priority_queue<int,vector<int>,greater<int>> que;
    //     vector<int> a1(n1+1),a2(n2+1),a3(n3+1);
    //     int ans=0;
    //     for(int i=1;i<=n1;i++){
    //         cin>>a1[i];
    //         ans+=a1[i];
    //         que.push(a1[i]);
    //     }
    //     for(int i=1;i<=n2;i++){
    //         cin>>a2[i];
    //         ans+=a2[i];
    //         que.push(a2[i]);
    //     }
    //     for(int i=1;i<=n3;i++){
    //         cin>>a3[i];
    //         ans+=a3[i];
    //         que.push(a3[i]);
    //     }
    //     int cnt=(n1==1)+(n2==1)+(n3==1);
    //     if(cnt==3)
    //     {//特判1 1 1
    //         ans-=que.top();ans-=que.top();
    //         cout<<ans<<endl;
    //         continue;
    //     }
    //     else if(cnt==2)//特判1 1 2
    //     {
    //         if(n1!=1){
    //             swap(n1,n3);
    //             swap(a1,a3);
    //         }
    //         if(n2!=1){
    //             swap(n2,n3);
    //             swap(a1,a3);
    //         }
            

    //     }
    //     // n1,n2,n3都大于1的情况
    //     ans-=que.top();ans-=que.top();que.pop();
    //     ans-=que.top();ans-=que.top();que.pop();
    //     cout<<ans<<endl;
    // }
    return 0;
}
