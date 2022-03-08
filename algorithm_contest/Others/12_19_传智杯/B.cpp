/*
 * @Author: LinXuan
 * @Date: 2021-12-19 15:39:20
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-12-19 17:56:45
 * @FilePath: /Algorithm/algorithm_contest/Others/12_19_传智杯/B.cpp
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

vector<bool> prime(1e5+5);
// 欧拉筛
void get_prime(vector<int> & prime,int upper_bound)// 传引用
{ 
    if(upper_bound < 2)return;
    vector<bool> Is_prime(upper_bound+1,true);
    for(int i = 2; i <= upper_bound; i++)
    {
        if(Is_prime[i])
            prime.push_back(i);
        for(int j = 0; j < prime.size() and i * prime[j] <= upper_bound; j++){
            Is_prime[ i*prime[j] ] = false;
            if(i % prime[j] == 0) break;// 保证了一个数只被筛一次。
        }
    }
}

int main()
{
    IOS;
    # ifdef _DEBUG
    freopen("in.txt","r",stdin);  
    # endif
    
    vector<int> prime;
    const int N = 2e6;
    get_prime(prime, N);
    // 打表
    vector<int> cnt = vector(N+1, 0);
    for(int i=1, j=0; i<=N; i++)
    {
        cnt[i] = cnt[i-1];
        if(i == prime[j]){
            cnt[i]+=1;
            j++;
        }
    }

    int n;
    cin>>n;
    auto sove = [&](int x)->int{
        // cout<<endl<<x<<endl; //
        int ans = 0;
        int ct=0;
        int tmp = x;
        while(tmp){
            if(tmp&1 == 1){
                // cout<<"add: "<<(1<<(ct+1) -1)<<" - "<<(1<<ct)<<endl; //
                ans += cnt[(1<<(ct+1))-1] - cnt[(1<<ct)-1];
            }
            ct++;
            tmp>>=1;
        }
        // cout<<ans<<endl;
        return ans;
    };
    while(n--)
    {
        int x;
        cin>>x;
        cout<<sove(x)<<endl;
    }
    // int T = 1000;
    // while(T--)
    // {
    //     int cc = 0;
    //     for(int i=0; i<T; i++)
    //     {
    //         int num = i^T;
    //         if(cnt[num] - cnt[num-1]>0) cc++;
    //     }
    //     cout<<(cc!=sove(T))<<endl;
    //     cout<<endl;
    // }
    return 0;
}
