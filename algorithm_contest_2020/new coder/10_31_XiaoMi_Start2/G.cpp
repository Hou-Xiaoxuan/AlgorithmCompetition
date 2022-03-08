#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// hash 
const LL base[] = {1313131, 233333};
const LL mod[] = {19260817, 19970219};
LL qmod[2];
LL qpow(LL a,LL b,LL m){
    LL ans=1;
    LL k=a;
    while(b){
        if(b&1)ans=ans*k%m;
        k=k*k%m;
        b>>=1;
    }
    return ans;
}
// 双哈希判重，wc，过了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n;
    while(cin>>n)
    {
        qmod[0]=qpow(base[0],n,mod[0]);
        qmod[1]=qpow(base[1],n,mod[1]);
        vector<int> a(n+1);
        map<P ,bool> ma;
        for(int i=1;i<=n;i++) cin>>a[i];
        LL hash_r[2]={0};
        LL hash_l[2]={0};
        // 正着操作
        for(int i=1;i<=n;i++){
            hash_r[0]=(hash_r[0]*base[0]+a[i])%mod[0];
            hash_r[1]=(hash_r[1]*base[1]+a[i])%mod[1];
        }
        for(int i=1;i<=n;i++){
            hash_r[0]=(hash_r[0]*base[0]+a[i])%mod[0];
            hash_r[1]=(hash_r[1]*base[1]+a[i])%mod[1];

            hash_l[0]=(hash_l[0]*base[0]+a[i])%mod[0];
            hash_l[1]=(hash_l[1]*base[1]+a[i])%mod[1];
            P st;
            st.first = ((hash_r[0]-qmod[0]*hash_l[0])%mod[0]+mod[0])%mod[0];
            st.second = ((hash_r[1]-qmod[1]*hash_l[1])%mod[1]+mod[1])%mod[1];
            ma[st]=1;
        }
        
        // 倒着操作
        reverse(a.begin()+1,a.end());
        hash_r[0]=hash_r[1]=0;
        hash_l[0]=hash_l[1]=0;
        for(int i=1;i<=n;i++){
            hash_r[0]=(hash_r[0]*base[0]+a[i])%mod[0];
            hash_r[1]=(hash_r[1]*base[1]+a[i])%mod[1];
        }
        for(int i=1;i<=n;i++){
            hash_r[0]=(hash_r[0]*base[0]+a[i])%mod[0];
            hash_r[1]=(hash_r[1]*base[1]+a[i])%mod[1];

            hash_l[0]=(hash_l[0]*base[0]+a[i])%mod[0];
            hash_l[1]=(hash_l[1]*base[1]+a[i])%mod[1];
            P st;
            st.first = ((hash_r[0]-qmod[0]*hash_l[0])%mod[0]+mod[0])%mod[0];
            st.second = ((hash_r[1]-qmod[1]*hash_l[1])%mod[1]+mod[1])%mod[1];
            ma[st]=1;
        }

        LL ans=0;
        for(auto &st:ma)
            if(st.second==true) 
                ans++;
        cout<<ans<<endl;
    }
    return 0;
}