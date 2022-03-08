//什么垃圾题目，莫名其妙的卡输入
//以后一切以std为准，被卡了再说
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

struct Trie
{
    static const int TN=2e5+5;
    static const int TM=26;
    int next[TN][TM],pos,rt;
    bool color[TN];
    Trie(){
        pos=0;
        color[0]=false;
    }
    void insert(char*s)
    {
        int p=0;
        int len=strlen(s);
        for(int i=0;i<len;i++)
        {
            int n=s[i]-'a';
            if(!next[p][n]){
                next[p][n]=(++pos);
                //color[pos]=false;
            }
            p=next[p][n];
           //val[p]++;
        }
        color[p]=true;
    }
    int count()
    {
        int ans=0;
        for(int i=1;i<=pos;i++)
            if(color[i]==true)
                ans++;
        return ans;
    }
};
char s[int(1e6)+5];
int main()
{
    //IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
   
    Trie *tt=new Trie();
    string s1;
    while(getline(cin,s1))
    {
        //cin>>s;
        if(s1[0]=='#') continue;
        stringstream ss(s1);
        memset(tt->color,0,sizeof(tt->color));
        memset(tt->next,0,sizeof(tt->next));
        tt->pos=0;
        while(ss>>s){
            tt->insert(s);
        }
        cout<<tt->count()<<endl;
    }
    //cout<<tt->count();
    return 0;
}