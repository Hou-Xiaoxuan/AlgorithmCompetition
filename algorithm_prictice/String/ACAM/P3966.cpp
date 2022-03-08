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
//我还不会！！！
class ACTM
{
public:
    static const int TN=1e6+5;
    static const int TM=26;
    int next[TN][TM];
    int fail[TN];
    int cnt[TN];
    int num[TN];
    int ans[TN];
    int pos;
    ACTM()
    {
        pos=0;
        memset(next[0],0,sizeof(next[0]));
        fail[0]=cnt[0]=num[0]=0;
    }

    int newnode()
    {
        pos++;
        memset(next[pos],0,sizeof(int)*TM);
        fail[pos]=0;
        return pos;
    }
    void insert(char *s,int order)
    {
        int len=strlen(s);
        int p=0;
        for(int i=0;i<len;i++)
        {
            int id=s[i]-'a';
            p=next[p][id];
            if(p==0)
                next[p][id]=newnode();      
        }
        cnt[p]++;
        num[p]=order;
    }
    void get_fail()
    {
        queue<int> que;
        for(int i=0;i<TM;i++)
        {
            if(next[0][i]){
                fail[next[0][i]]=0;
                que.push(next[0][i]);
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
                    fail[p]=next[fail[x]][i];
                    que.push(p);
                }
                else 
                    next[x][i]=next[fail[x]][i];
            }
        }
    }
    int query(const char *s)
    {
        int len=strlen(s);
        int p=0;
        for(int i=0;i<len;i++)
        {
            p=next[p][s[i]-'a'];
            for(int j=p;j;j=fail[j]){
                ans[num[j]]++;
            }
        }
        return 0;
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
    
    int n;cin>>n;
    ACTM *tt=new ACTM();
    string str;
    for(int i=1;i<=n;i++){
        cin>>s;
        tt->insert(s,i);
        str+=string(s);
    }
    tt->get_fail();
    tt->query(str.c_str());
    for(int i=1;i<=n;i++)
        cout<<tt->ans[i]<<endl;
    return 0;
}