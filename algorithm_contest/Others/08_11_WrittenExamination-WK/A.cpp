/*
 * @Author: LinXuan
 * @Date: 2021-08-11 09:14:58
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-08-11 09:19:10
 * @FilePath: \c++\A.cpp
 */
#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
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
    #ifdef _DEBUG
    freopen("D:\\CODE\\c++\\out.txt","w",stdout);
    freopen("D:\\CODE\\c++\\in.txt","r",stdin);  
    #endif
    
    int n, q;
    cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum = 0;
    for(int i=1;i<=q;i++){
        int tmp;
        cin>>tmp;
        sum += tmp;
    }
    sum %= n;
    for(int i=sum; i<n; i++) cout<<a[i]<<' ';
    for(int i=0; i<sum; i++) cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
