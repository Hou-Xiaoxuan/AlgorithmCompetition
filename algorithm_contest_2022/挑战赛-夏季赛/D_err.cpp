/*
 * @Author: linxuan
 * @Date: 2022-07-24 12:11:20
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛-夏季赛/D.cpp
 */
#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                   \
 ios::sync_with_stdio(false); \
 cin.tie(0);                  \
 cout.tie(0);
#define m_p make_pair
#define x   first
#define y   second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;

// int get_ans(int c)
// {
//     if (c % 2 == 1)
//     {
//         // 格点多边形变长一定是偶数
//         return -1;
//     }
//     else
//     {
//         int ans = inf;
//         // 枚举三角形
//         for (int i = 1; i <= c / 2; i++)
//             for (int j = 1; j <= c / 2; j++)
//             {
//                 // 判断满足直角三角形
//                 int k = c - i - j;
//                 if (i + k > j && j + k > i && i + j > k)
//                     if (i * i + j * j == k * k or i * i + k * k == j * j or j * j + k * k == i * i)
//                     {
//                         int tmp = min(max(i, max(j, k)) - min(i, min(j, k)), ans);
//                         if(tmp < ans){
//                             ans = tmp;
//                             cout<<i<<" "<<j<<" "<<k<<endl;
//                         }
//                     }
//             }
//         if (ans == inf)
//         {
//             if (c % 4 == 0)
//                 ans = 0;
//             else
//                 ans = 1;
//         }
//         return ans;
//     }
// }


int main()
{
    IOS;
    // #ifdef _DEBUG
    //     freopen("out.txt", "w", stdout);
    //     freopen("in.txt", "r", stdin);
    // #endif
    set<int> s;
    vector<int> ans(5001, inf);
    for(int i=1; i<=5000; i++)
        for(int j=i; j<=5000; j++)
        {
            double k = sqrt(i*i + j*j);
            if(k != (int)k)
                continue;
            int a = min(min(i, j), (int)k);
            int c = max(max(i, j), (int)k);
            int b = i + j + k - a - c;
            s.insert(a*5000*5000+b*5000+c);
            int cost = c - a;
            for(int t = 1; t * (a + b + c)<=5000; t+=t){
                ans[t * (a + b + c)] = min(ans[t * (a + b + c)], t * cost);
            }
            cost = max(2*a, c) - min(2*a, c);
            for(int t = 1; t * (2*a + 2*c)<=5000; t+=t){
                ans[t * (2*a + 2*c)] = min(ans[t * (2*a + 2*c)], t * cost);
            }
            cost = max(2*b, c) - min(2*b, c);
            for(int t=1; t * (2*b + 2*c)<=5000; t+=t){
                ans[t * (2*b + 2*c)] = min(ans[t * (2*b + 2*c)], t * cost);
            }
        }
    cout<<s.size()<<endl;
    for(int i=4; i<=5000; i++)
    {
        if(ans[i] == inf)
        {
            if(i % 4 == 0)
                ans[i] = 0;
            else if(i % 2 == 0)
                ans[i] = 1;
        }
    }

    int c;
    cin>>c;
    if(ans[c] == inf) cout<<-1<<endl;
    else cout<<ans[c]<<endl;
    
    return 0;
}
