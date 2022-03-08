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

//AC�Զ�����KMP+Trie����ĸ����ƥ����ģʽ���������е�ģʽ�������ֵ��������ҷ�������KMP��failָ��
//Ϊ�˵õ�һ�ݲ����ģ�徹Ȼ������Сʱ
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
        //BFS ����fail����
        //��⣺ һ�����fail �Ӹ��׵�fail���ӽڵ����ң������ڵľ͹���ڵ�
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
                    fail[p]=next[fail[x]][i];//���p����Ĺ������� û��i+��a��,next[fail[x]][i]����0���൱�ڻص���
                    que.push(p);
                }
                else{
                    next[x][i]=next[fail[x]][i];//�����ڵĵ�Ҳ�ص���ƥ��ʧ�ܣ������ڵ�ƥ��ʧ�ܻص���ͬ�ĵ�
                }
            }
        }
    }

    int query(char *s)
    {
        int p=0,ans=0,len=strlen(s);
        for(int i=0;i<len;i++)
        {
            //��ס�ɣ�ֻ���¶���֪��ԭ��
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
