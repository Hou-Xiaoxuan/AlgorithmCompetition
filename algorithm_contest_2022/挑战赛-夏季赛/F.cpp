/*
 * @Author: linxuan
 * @Date: 2022-07-24 09:38:51
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/挑战赛-夏季赛/F.cpp
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
    string a, b;
    cin>>a>>b;
    int cnt=0;
    for(int i=n-1, j=n-1; i>0; i--)
    {
        if(a[i] == b[j]){
            cnt++;
            j--;
        }
    }
    cout<<n - cnt<<endl;

    return 0;
 }
    
