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
    int n; cin>>n;
    int num_len=0, tmp=n;
    while(tmp>0){
        num_len++;
        tmp/=10;
    }
    vector<string> ans;
    function<void(int, int)> f=[&](int val, int len){
        if(len > num_len or ans.size()>=50){
            return;
        }
        for(int i=0; i<=9; i++){
            if(val*10+i<=n){
                ans.push_back(to_string(val*10+i));
                f(val*10+i, len+1);
            } else{
                return;
            }
        }
    };
    for(int i=1; i<=9; i++){
        if(ans.size() >=50){
            break;
        }
        ans.push_back(to_string(i));
        f(i, 2);
    }
    for(int i=0; i<50; i++){
        cout<<ans[i]<<".mp4"<<endl;
    }
    return 0;
}
