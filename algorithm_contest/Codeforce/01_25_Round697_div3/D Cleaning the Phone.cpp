#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
// 补题
// 只能从1，2两个数组里面去，肯定优先大的
// 求出前缀和，枚举cnt[1]取的长度，就能二分地取出cht[2]中的长度。
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<LL> a(n+1);
        for(int i=1;i<=n;i++)   cin>>a[i];
        vector<LL> cnt[3];
        cnt[2].push_back(0);
        cnt[1].push_back(0);
        for(int i=1;i<=n;i++){
            int b;  cin>>b;
            cnt[b].push_back(a[i]);
        }

        sort(cnt[1].begin()+1,cnt[1].end(),greater<int>());
        sort(cnt[2].begin()+1,cnt[2].end(),greater<int>());
        for(size_t i=1;i<cnt[1].size();i++) cnt[1][i]+=cnt[1][i-1];
        for(size_t i=1;i<cnt[2].size();i++) cnt[2][i]+=cnt[2][i-1];

        LL ans=LLinf;
        for(size_t i=0;i<cnt[1].size();i++)//枚举1中取的个数
        {
            size_t k=lower_bound(cnt[2].begin(),cnt[2].end(),m-cnt[1][i])-cnt[2].begin();
            if(k==cnt[2].size()) continue;//没找到
            ans=min(ans,LL(i+k*2));
        }
        // 特殊考虑1中一个都不取
        cout<<(ans==LLinf?-1:ans)<<endl;
    }
    return 0;
}
