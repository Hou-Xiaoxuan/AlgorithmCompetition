/*
 * @Author: LinXuan
 * @Date: 2022-03-12 15:54:32
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-15 13:14:59
 * @FilePath: /Algorithm/algorithm_contest_2022/传智杯/D.cpp
 */
/*
 * @Author: LinXuan
 * @Date: 2022-03-12 15:35:36
 * @Description: 签到
 * @LastEditors: LinXuan
 * @LastEditTime: 2022-03-12 15:51:24
 * @FilePath: /Algorithm/algorithm_contest_2022/传智杯/A.cpp
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
    // freopen("algorithm_contest_2022/传智杯/out.txt", "w", stdout);

    #endif
    IOS

    // 二分答案
    size_t n, days;
    cin>>n>>days;
    vector<size_t> nums(n);
    size_t l = 0, r = 0;
    for(size_t i = 0; i<n; i++){
        cin>>nums[i];
        nums[i]*=nums[i];
        r+=nums[i];
    }
    auto check = [&](size_t mid)->bool{
        // 查看mid是否可行
        size_t tmp = 0;
        size_t cnt = 1;
        for(auto i:nums)
        {
            if(i+tmp>mid){
                tmp = i;
                cnt++;
            }else{
                tmp += i;
            }
            if(cnt > days || tmp>mid){
                return false;
            }
        }
        return true;
    };
    size_t ans=r;
    while(l <= r)
    {
        auto mid = (l+r)>>1;
        if(check(mid)){
            ans = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
