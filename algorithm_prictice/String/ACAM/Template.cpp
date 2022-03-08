#include<bits/stdc++.h>
// #include<iostream>
// #include<queue>
// #include<cstring>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

//AC自动机：KMP+Trie，再母串上匹配多个模式串，将所有的模式串建成字典树，并且分配类似KMP的fail指针
//为了得到一份不错的模板竟然就两个小时
class ACTM
{
public:
    static const int TN=1e6+5;
    static const int TM=26;
    int next[TN][TM],fail[TN],cnt[TN],pos;
    ACTM()
    {
        pos = 0;
        memset(cnt, 0,sizeof(cnt));
        memset(next[0], 0, sizeof(next[0]));
    }
    int newNode()
    {
        int p=++pos;
        memset(next[p],0,sizeof(next[p]));
        fail[p]=0;
        return pos;
    }
    void insert(char *s)
    {
        int len=strlen(s);
        int p=0;
        for(int i=0;i<len;i++)
        {
            int id=s[i]-'a';
            if(next[p][id]==0)
                next[p][id]=newNode();
            p=next[p][id];
        }
        cnt[p]++;
    }

    void build()
    {
        //BFS 构建fail数组
        //理解： 一个点的fail 从父亲的fail的子节点里找，不存在的就归根节点
        queue<int> que;
        for(int i=0;i<TM;i++)
        {
            int p=next[0][i];
            if(p!=0){
                fail[p]=0;
                que.push(p);
            }
        }
        while(!que.empty())
        {
            int x=que.front();
            que.pop();
            for(int i=0;i<TM;i++)
            {
                int p=next[x][i];
                if(p!=0){
                    fail[p]=next[fail[x]][i];//如果p代表的归宿旗下 没有i+‘a’,next[fail[x]][i]就是0，相当于回到根
                    que.push(p);
                }
                else{
                    next[x][i]=next[fail[x]][i];//不存在的点也回到，匹配失败，跟父节点匹配失败回到相同的点
                }
            }
        }
    }

    int query(char *s)
    {
        int p=0,ans=0,len=strlen(s);
        for(int i=0;i<len;i++)
        {
            //背住吧，只是懵懂的知道原因
            p=next[p][s[i]-'a'];
            for(int j=p;j!=0 and cnt[j]!=-1;j=fail[j]){
                ans+=cnt[j];
                cnt[j]=-1;
            }
        }
        return ans;
    }
};


char s[ACTM::TN];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    int n;
    ACTM * ac=new ACTM;
    cin>>n;
    while(n--){
        cin>>s;
        ac->insert(s);
    }
    ac->build();
    cin>>s;
    cout<<ac->query(s);
    return 0;
}
