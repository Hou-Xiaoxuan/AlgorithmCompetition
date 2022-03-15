/*
 * @Author: LinXuan
 * @Date: 2022-03-12 15:35:36
 * @Description: 签到
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-15 13:14:53
 * @FilePath: /Algorithm/algorithm_contest_2022/传智杯/C.cpp
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
    #ifdef _DEBUG
    freopen("algorithm_contest_2022/传智杯/in.txt", "r", stdin);
    freopen("algorithm_contest_2022/传智杯/out.txt", "w", stdout);

    #endif
    IOS
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> a(n), target(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            cin>>target[i];
        }
        vector<pair<int, int>> ans;
        bool flag = true;

        for(size_t i=0; i<n and flag; i++)
        {
            if(a[i]==target[i]) continue;
            for (size_t j=i + 1; j<n; j++)
            {
                if(target[i]==a[j])
                {
                    // 把元素j移动到i的位置
                    while(j > i){
                        swap(a[j], a[j-1]);
                        ans.push_back(make_pair(j, j-1));
                        j--;
                    }
                    break;
                }
            }
            if(a[i] != target[i]) flag =false;
        }
        if(flag == true)
        {
            cout<<"YES\n";
            // 艹，从1计数
            for(auto item: ans){
                cout<<item.first + 1<<" "<<item.second + 1<<"\n";
            }
            cout<<"0 0\n";
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}
