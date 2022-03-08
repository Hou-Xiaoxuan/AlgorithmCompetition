/*
 * @Author: LinXuan
 * @Date: 2021-12-19 15:31:35
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-12-19 15:34:14
 * @FilePath: /Algorithm/algorithm_contest/Others/12_19_传智杯/A.cpp
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
    int n;
    cin>>n;
    int minn = inf, maxn = -1;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, a[i]);
    }
    for(int i=1; i<=n; i++){
        cout<<100*(a[i] - minn)/(maxn - minn)<<" ";
    }
    return 0;
}
