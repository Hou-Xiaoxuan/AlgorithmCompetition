/*
 * @Author: LinXuan
 * @Date: 2022-03-27 10:18:57
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-27 10:25:35
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛冬季赛/L.cpp
 */
/*
 * @Author: LinXuan
 * @Date: 2022-03-27 09:06:24
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-27 09:56:48
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛冬季赛/std.cpp
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
int main(int argc, char const *argv[])
{
    vector<LL> cnt(21);
    cnt[0] = 1;
    for(int i=1; i<=20; i++){
        cnt[i] = cnt[i-1]*2;
    }
    for(int i=1; i<=20; i++){
        cnt[i] += cnt[i-1];
    }
    int n, m; cin>>n>>m;
    int k=0, tmp=n;
    while(tmp > 1){
        k++;
        tmp>>=1;
    }
    LL times = cnt[k]; // 倍乘系数

    LL sum = 0;
    for(int i=1; i<=n; i++){
        LL x;
        cin>>x;
        sum+=times*x;
    }
    while(m--){
        LL l, r, x;
        cin>>l>>r>>x;
        sum+= (r + 1 - l)*x*times;
        cout<<sum<<endl;
    }
    return 0;
}
