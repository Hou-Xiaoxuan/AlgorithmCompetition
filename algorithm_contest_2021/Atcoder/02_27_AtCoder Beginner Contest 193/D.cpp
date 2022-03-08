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
// AC
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #endif
    
    string a,b;
    int k;cin>>k;
    vector<LL> num(10,k);
    pair<LL,LL> ans;
    cin>>a>>b;
    a[4]='0';
    b[4]='0';
    auto get_score=[](const string a)->LL{
        vector<int> cnt(10);
        for(auto ch:a) cnt[ch-'0']++;
        LL ans=0;
        for(int i=1;i<=9;i++) ans+=i*pow(10,cnt[i]);
        return ans;
    };
    for(auto ch:a) num[ch-'0']--;
    for(auto ch:b) num[ch-'0']--;

    for(int i=1;i<=9;i++)
    {
        if(num[i]==0) continue;
        num[i]--;
        a[4]=i+'0';
        for(int j=1;j<=9;j++)
        {
            if(num[j]==0) continue;
            else ans.second+=(num[i]+1)*num[j];
            b[4]=j+'0';
            if(get_score(a)>get_score(b)) ans.first+=(num[i]+1)*num[j];
        }
        num[i]++;
    }
    cout<<double(ans.first)/double(ans.second);
    return 0;
}
