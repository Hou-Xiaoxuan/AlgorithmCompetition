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

//�������㷨��ͨ���ݹ�ƥ��
const int N=505;
vector<int> link[N];
bool vis[N];//������εݹ���ʹ�����
int use[N];//������B��Ŀǰƥ�䣨��
bool match(int x)//������A�ĵ�xƥ��
{
    //y�Ǽ���B�У�x�Ǽ���A�У����ʱ��������A->B,use[B]=A;
    for(int i=0;i<link[x].size();i++)
    {
        int y=link[x][i];
        if(!vis[y])//yû�б����ʹ�
        {
            vis[y]=true;//����y
            if(use[y]==false or match(use[y])==true){//���yû�б���� or ����ռy����һ��������ѡ��ʱ
                use[y]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    
    int k,n,m;
    while(cin>>n>>m>>k)
    {
        int u,v;
        memset(use,0,sizeof(use));
        for(int i=1;i<=n;i++) link[i].clear();
        for(int i=1;i<=k;i++){
            cin>>u>>v;
            // cout<<i<<" "<<u<<" "<<v<<endl;
            if(count(link[u].begin(),link[u].end(),v)==0)
                link[u].push_back(v);
        }
        int sum=0;
        
        for(int i=1;i<=n;i++){
            memset(vis,0,sizeof(vis));
            if(match(i)==true)
                sum++;
        }
        // for(int i=1;i<=n;i++)
        //     cout<<i<<" "<<use[i]<<endl;
        // cout<<sum<<endl;
    }
    return 0;
}
