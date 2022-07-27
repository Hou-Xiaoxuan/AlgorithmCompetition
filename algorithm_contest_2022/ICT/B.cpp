/*
 * @Author: linxuan
 * @Date: 2022-07-19 20:44:13
 * @Description: file content   
 * @FilePath: /Algorithm/algorithm_contest_2022/ICT/B.cpp
 */
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
const int N =  1e6 + 5;
int main()
{
    IOS;
    # ifdef _DEBUG
    // freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);  
    # endif
    
    int n, k;
    cin >> n >> k;
    vector<int> a(n+1);
    vector<LL> sum(n+1);
    LL ans = -501;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
        ans = max(ans, (LL)a[i]);
    }
    // 快速获知区间最小值
    deque<int> que;
    que.push_back(0);
    for(int i=1; i<=n ;i++)
    {
        while(que.front() + k < i)
            que.pop_front();
        ans = max(ans, sum[i] - sum[que.front()]);
        while(que.empty() == false and sum[que.back()] >= sum[i]) // 不满足递增
            que.pop_back();
        que.push_back(i);
    }
    cout<<ans<<endl;
    return 0;
}
