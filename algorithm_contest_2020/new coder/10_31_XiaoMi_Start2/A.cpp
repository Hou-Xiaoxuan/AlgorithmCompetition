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
// 题解: 二分
/*
先递推搞一遍再说
29
20200022000022200220200000000
输出4,答案5
原因：中间是会交叉的，不一定有明显的分界线。只要满足每一对不冲突就可以了
题解二分尝试一下
感觉确实不难啊
 */
char s[int(1e6+5)];
int n;
#define _M_

#ifdef _M_
bool check(int k)
{
    // 大概是我写出锅了……不过我看懂衣老师的代码了……
    // 我没有写出锅！！！！特么二分边界写错了
    vector<P> cnt_left(k+1);
    vector<bool> vis(n+1);
    int il=1,ir=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==true) continue;
        if(s[i]=='2' and il<=k){
            cnt_left[il++].x=i;
            vis[i]=true;
        }
        if(s[i]=='0' and ir<il){
            cnt_left[ir++].y=i; 
            vis[i]=true;
        }
    }
    if(il<=k or ir<=k) return false;
    vector<P> cnt_right(k+1);
    il=ir=1;
    for(int i=n;i>=1;i--)
    {
        if(vis[i]==true) continue;
        if(s[i]=='0' and ir<=k){
            cnt_right[ir++].y=i;
            vis[i]=true;
        }
        if(s[i]=='2' and il<ir){
            cnt_right[il++].x=i; 
            vis[i]=true;
        }
    }
    if(il<=k or ir<=k) return false;

    reverse(cnt_right.begin()+1,cnt_right.end());
    for(int i=1;i<=k;i++)
    {
        if(cnt_left[i].y<cnt_right[i].x) continue;
        else return false;
    }
    return true;
}
#endif
#ifdef _Y_
vector<int> zero,two;
vector<int> now[100005];
bool check(int k)
{
    if(2*min(zero.size(),two.size())<k) return false;
    for(int i=1;i<=k;i++) vector<int>().swap(now[i]);
    int i0=0,i2=0;

    for(int i=1;i<=k;i++){
        now[i].push_back(two[i2++]);
    }
    for(int i=1;i<=k;i++){
        while(i0<zero.size() and zero[i0]<now[i].back()) i0++;
        if(i0>=zero.size()) return false;
        now[i].push_back(zero[i0++]);
    }
    for(int i=1;i<=k;i++){
        while(i2<two.size() and two[i2]<now[i].back()) i2++;
        if(i2>=two.size()) return false;
        now[i].push_back(two[i2++]);
    }
    for(int i=1;i<=k;i++){
        while(i0<zero.size() and zero[i0]<now[i].back()) i0++;
        if(i0>=zero.size()) return false;
        now[i].push_back(zero[i0++]);
    }
    return true;
}
#endif
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    while(cin>>n)
    {
        cin>>(s+1);
        #ifdef _Y_
        vector<int>().swap(zero);
        vector<int>().swap(two);
        for(int i=1;i<=n;i++)
            if(s[i]=='2') two.push_back(i);
            else if(s[i]=='0') zero.push_back(i);
        #endif
        // vector<int> cnt_front(n+5),cnt_back(n+5);
        // string a;
        // cin>>a;
        // a=' '+a;
        // int cnt_0=0,cnt_2=0;
        // for(int i=1;i<=n;i++)
        // {
        //     cnt_front[i]=cnt_front[i-1];
        //     if(a[i]=='2') cnt_2++;
        //     if(a[i]=='0' and cnt_2>0){
        //         cnt_2--;
        //         cnt_front[i]++;
        //     }
        // }
        // cnt_0=cnt_2=0;
        // for(int i=n;i>=1;i--)
        // {
        //     cnt_back[i]= i==n?0:cnt_back[i+1];
        //     if(a[i]=='0') cnt_0++;
        //     if(a[i]=='2' and cnt_0>0){
        //         cnt_0--;
        //         cnt_back[i]++;
        //     }
        // }
        // int ans=0;
        // for(int i=1;i<=n;i++) cout<<setw(2)<<cnt_front[i]<<' ';
        // cout<<endl;
        // for(int i=1;i<=n;i++) cout<<setw(2)<<cnt_back[i]<<' ';
        // cout<<endl;

        // for(int i=1;i<=n;i++) ans=max(ans,min(cnt_front[i],cnt_back[i+1]));
        // cout<<ans<<endl;

        int l=1,r=n;
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid)){
                l=mid+1;
                ans=mid;
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}