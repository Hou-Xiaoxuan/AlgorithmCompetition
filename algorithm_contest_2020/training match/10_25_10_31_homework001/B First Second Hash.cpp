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

// 我觉的Hash可以的，莽一波……
// 有点理解错题目了
// WA了……今天有点不想搞了……
// 怎么优化也只能过20个
// 双哈希不用map能过
// A了
const ULL p=131,mod=19970219;
const ULL p2=137,mod2=19260817;
vector<int> ma[int(2e7)];
int main()
{
    // IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int n;
    cin>>n;
    vector<string> str(n+1);
    // unordered_map<ULL,int> ma;
    for(int i=1;i<=n;i++){
        cin>>str[i];
        reverse(str[i].begin(),str[i].end());
    }
    sort(str.begin(),str.end(),[](const string&a,const string&b){return a.size()<b.size();});
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        string& s=str[i];
        int len=s.size();
        ULL hash=0,hash2=0;
        int num[26]={0};
        for(auto i:s){
            num[i-'a']++;
        }
        // bool flag=1;
        for(int j=0;j<len;j++)
        {
            if(j!=len-1)//不是最后一个字母
            {
                for(int k=0;k<26;k++)
                    if(num[k]>0){
                        // ans+=ma[(hash*p+ULL('a'+k))%mod];
                        ULL first=(hash*p+ULL(k+'a'))%mod,second=(hash2*p+ULL(k+'a'))%mod2;
                        // cout<<first<<" "<<second<<" :"<<count(ma[first].begin(),ma[first].end(),second)<<endl;
                        ans+=count(ma[first].begin(),ma[first].end(),second);
                    }
            }
            num[s[j]-'a']--;
            hash=(hash*p+s[j])%mod;//前缀、再枚举最后一个字母
            hash2=(hash2*p+s[j])%mod2;
        }
        ma[hash].push_back(hash2);
        // ma[hash]++;
    }
    cout<<ans<<endl;
    return 0;
}