//也是模板，只不过求的东西发生了一些改变，再次默写模板
#include<bits/stdc++.h>
using namespace std;

struct ACTM
{
public:
    static const int TN=1e6+5;
    static const int TM=26;
    int next[TN][TM];
    int fail[TN];
    int cnt[TN];
    int ans[TN],num[TN];//多出来的部分
    int pos;
    ACTM()
    {
        pos=0;
        fail[0]=0;
        memset(next[0],0,sizeof(next[0]));
    }
    void intsert(char *s,int order)
    {
        int len=strlen(s);
        int p=0;
        for(int i=0;i<len;i++)
        {
            int id=s[i]-'a';
            if(next[p][id]==0){
                next[p][id]=++pos;
                fail[pos]=0;
                memset(next[pos],0,sizeof(next[pos]));
            }
            p=next[p][id];
        }
        // cnt[p]++;
        num[p]=order;//本题不需要统计次数，只需要标记 序号
    }
    void get_fail()
    {
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
                    fail[p]=next[fail[x]][i];
                    que.push(p);
                }
                else
                    next[x][i]=next[fail[x]][i];
            }
        }
    }
    void query(char *s)
    {
        int len=strlen(s);
        int p=0;
        for(int i=0;i<len;i++)
        {
            int id=s[i]-'a';
            p=next[p][id];
            for(int j=p;j;j=fail[j])
                ans[num[j]]++;//中间过程的num全是0，不用管

        } 
    }

};

char s[ACTM::TN];
int main()
{
    //IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif

    int n;
    while(cin>>n and n)
    {
        vector<string> str(n+1);
        ACTM* tt=new ACTM();
        for(int i=1;i<=n;i++){
            cin>>s;
            tt->intsert(s,i);
            str[i]=string(s);
        }
        cin>>s;
        tt->get_fail();
        tt->query(s);
        int mm=-1;
        for(int i=1;i<=n;i++)
            mm=max(tt->ans[i],mm);
        cout<<mm<<endl;
        for(int i=1;i<=n;i++)
            if(mm==tt->ans[i])
                cout<<str[i]<<endl;
    }

    return 0;
}