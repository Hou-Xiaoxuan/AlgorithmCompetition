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
// 重复匹配
// 匹配非最优解,怎么保证最优解？不能递归，遍历，快速寻找替代点
// 1 2 5 6 8 8（3）

// 题解： 二分。  由于匹配的性质，如果其中四个可以匹配的话，那么前两个和后两个一定也可以（因为中间可以匹配，更换成顶端差更大）
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    LL n,m;
    while(cin>>n>>m)
    {  
        vector<LL> a(n+1),b(n+1);
        vector<bool> vis(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a.begin()+1,a.end());
        int l=1,r=n>>1;//有边界保证每个数只能用一次
        int ans=0;
        while(l<=r)
        {
            int mid=l+r>>1;
            bool flag=true;
            for(int i=1;i<=mid;i++)
                if(a[n-mid+i]-a[i]<m)
                    flag=false;
            if(flag==true){
                ans=max(ans,mid);
                l=mid+1;
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}


 // tle
        // if(a[l1]>=b[l2])
        // {
        //     if(vis[l1]==false and vis[l2]==false)
        //     {
        //         ans++;
        //         vis[l2++]=true;
        //         vis[l1++]=true;
        //     }
        //     else if(vis[l2]==true)
        //     {
        //         int flag=-1;
        //         for(int i=l2+1;i<l1;i++)
        //             if(vis[i]==false){
        //                 flag=i;
        //                 break;
        //             }
        //         if(flag!=-1)//可以替代
        //         {
        //             ans++;
        //             vis[flag]=true;
        //             vis[l1++]=true;
        //             vis[l2++]=true;
        //         }
        //         else//不可替代
        //         {
        //             if(l1+1<=n)//可以后移一位
        //             {
        //                 vis[l1++]=true;
        //                 vis[l1++]=true;
        //                 vis[l2++]=true;
        //                 ans++;
        //             }
        //         }
        //     }
        // }
        // else l1++;
