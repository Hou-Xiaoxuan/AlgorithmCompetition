/*
 * @Author: LinXuan
 * @Date: 2022-03-27 10:35:20
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-27 10:47:50
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛冬季赛/B.cpp
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
    int n;
    cin>>n;
    vector<LL>a(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    LL l=0, r=1e9 + 10;
    LL ans;
    auto check = [&](LL eps)->bool{
        // 检查是否合法
        vector<LL> minborder(n+1);
        vector<LL> maxborder(n+1);
        minborder[1] = a[1] - eps;
        maxborder[1] = a[1] + eps;
        for(int i=2; i<=n; i++){
            minborder[i] = max(minborder[i-1] + 1, a[i] - eps);
            maxborder[i] = a[i] + eps;
            if(minborder[i] > maxborder[i]){
                return false;
            }
        }
        return true;
    };
    while(l<=r){
        int mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        } else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
