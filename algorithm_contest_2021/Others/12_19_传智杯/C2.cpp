/*
 * @Author: LinXuan
 * @Date: 2021-12-19 16:09:26
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-12-19 16:17:04
 * @FilePath: /Algorithm/algorithm_contest/Others/12_19_传智杯/C2.cpp
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
    freopen("in.txt","r",stdin);  
    # endif
    
    int n, k;
    cin>>n>>k;
    vector<vector<int>> a;
    while(n--)
    {
        int op;
        cin>>op;
        if(op == 1)
        {
            vector<int> data(k+1);
            int p; cin>>p;
            while(p--)
            {
                int x, y;
                cin>>x>>y;
                data[x] = y;
            }
            a.push_back(data);
        }
        else
        {
            int x, ymin, ymax;
            cin>>x>>ymin>>ymax;
            int ans = 0;
            for(auto data:a)
            {
                if(data[x]>=ymin and data[x]<=ymax)
                    ans++;
            }
            cout<<ans<<endl;
        }
    }

    return 0;
}
