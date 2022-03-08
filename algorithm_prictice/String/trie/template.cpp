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

//模板，大概理解
struct Trie
{
    static const int TN=1e5+10;
    static const int TM=26;
    int next[TN][26];//代表下一层取哪里
    int val[TN];//代表以这一层为前缀有多少个字符串
    int pos;
    Trie(){
        pos=0;val[0]=0;
        memset(next[0],0,sizeof(next[0]));
    }

    void insert(char *s)
    {
        int p=0;
        for(int i=0;i<strlen(s);i++){
            int n=s[i]-'a';
            if(!next[p][n])
                next[p][n]=++pos;
            p=next[p][n];
            val[p]++;
        }
    }
    int find(char *s)
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
};

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    


    return 0;
}