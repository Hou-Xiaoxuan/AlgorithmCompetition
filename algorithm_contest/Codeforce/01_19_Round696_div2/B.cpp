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
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

void get_prime(vector<int> & prime,int upper_bound){ // 传引用
    if(upper_bound < 2)return;
    vector<bool> Is_prime(upper_bound+1,true);
    for(int i = 2; i <= upper_bound; i++){
        if(Is_prime[i])
            prime.push_back(i);
        for(int j = 0; j < prime.size() and i * prime[j] <= upper_bound; j++){
            Is_prime[ i*prime[j] ] = false;
            if(i % prime[j] == 0)break;// 保证了一个数只被筛一次。
        }
    }
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    vector<int> prime;
    get_prime(prime, 10000001);
    int t;
    cin>>t;
    while(t--)
    {
        int d;cin>>d;
        LL a=lower_bound(prime.begin(),prime.end(),d+1)-prime.begin();
        a=prime[a];
        LL b=lower_bound(prime.begin(),prime.end(),d+a)-prime.begin();
        b=prime[b];
        cout<<a*b<<endl;

    }
    return 0;
}
