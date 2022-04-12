/*
 * @Author: LinXuan
 * @Date: 2022-03-27 12:58:39
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-27 13:37:13
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛冬季赛/F.cpp
 */
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
// # define x first
// # define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
long double foo(long double x1,long double y1,long double x2,long double y2)
{
    return (x1 * y2 - y1 * x2);
}

int main()
{
    IOS;
    # ifdef _DEBUG
    freopen("in.txt","r",stdin);  
    # endif
    int n; cin >> n;
    vector<LD> x(n+1), y(n+1), p(n+1);
    LD ans = 0.0;
    for(int i = 1;i <= n; i++){
        cin >> x[i] >> y[i];
        cin >> p[i];
    }
    LD s;
    for(int i = 1;i <= n; i++)
    {
        for(int j = 1;j <= n; j++)
        {
            if(i != j)
            {
                s = foo(x[i],y[i],x[j],y[j]) * p[i] * p[j];
                for(int k = 1;k <= n; k++)
                {
                    if(k != i && k != j)
                    {
                        // 不共线则累加
                        // 影响经度
                        if(foo(x[k] - x[i],y[k] - y[i],x[j] - x[i],y[j] - y[i]) < 0.0)
                            s = s * ((LD)(1.0) - p[k]);
                    }
                }
                ans = ans + s;
            }
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(6);
    cout << abs(ans / 2) << endl;
    return 0;
}
