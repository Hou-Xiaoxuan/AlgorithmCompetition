/*
 * @Author: linxuan
 * @Date: 2022-07-19 21:52:03
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/ICT/D.cpp
 */
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
# define x first
# define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

int main()
{
    IOS;
    # ifdef _DEBUG
    freopen("out.txt","w",stdout);
    freopen("in.txt","r",stdin);  
    # endif
    int n, m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0; i<n ;i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<int> ans(m+1, inf); // m=i时的答案
    ans[0] = 0;
    for(int i=1; i<=m; i++)
    {
        int minn = -1e9;
        for(int k:a){
            if(i >= k){
                ans[i] = min(ans[i], ans[i-k]+1);
            }
        }
    }
    if(ans[m] == inf) cout<<-1<<endl;
    else cout<<ans[m]<<endl;
    return 0;
}
