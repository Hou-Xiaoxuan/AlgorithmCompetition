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
//模板
struct Trie
{
    /*!!!!*/
    static const int TN=1e6+10;
    static const int TM=26;
    int next[TN][26];//代表下一层取哪里
    int val[TN];//代表以这一层为前缀有多少个字符串
    int pos;
    void insert(const string &s)
    {
        int p=0;
        for(int i=0;i<s.size();i++){
            int n=s[i]-'a';
            if(!next[p][n])
                next[p][n]=++pos;
            p=next[p][n];
            // val[p]++;
        }
    }
    int find(const string &s)
    {
        int p=0;
        for(int i=0;s[i];i++)
        {
            int n=s[i]-'a';
            if(next[p][n]==0)
                return 0;
            p=next[p][n];
        }
        return val[p];
    }
    
}tr;

void insert2(const string& s)
{
    // 重复插入建立val数组，只在已经存在的节点添加
    vector<int> sum(26);
    for(auto i:s) sum[i-'a']++;
    int p=0;
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<26;j++)
            if(sum[j] and tr.next[p][j])
                tr.val[tr.next[p][j]]++;
        sum[s[i]-'a']--;
        p=tr.next[p][s[i]-'a'];
    }
}
char ss[int(1e6+5)];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif

    int n;
    cin>>n;
    // scanf("%d",&n);
    vector<string> str(n+1);
    for(int i=1;i<=n;i++){
        cin>>str[i];
        // scanf("%s",ss);
        // str[i]=ss;
        reverse(str[i].begin(),str[i].end());
        tr.insert(str[i]);
    }
    LL ans=0;
    for(int i=1;i<=n;i++) insert2(str[i]);
    for(int i=1;i<=n;i++) ans+=tr.find(str[i])-1;
    cout<<ans<<endl;
    // printf("%lld\n",ans);
    return 0;
}
