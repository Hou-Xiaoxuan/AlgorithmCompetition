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
//��С������ �� Kruskal ģ��
// https://www.luogu.com.cn/problem/P3366
const int N=5005;
int fa[N];
struct Edge
{
    int u;
    int v;
    int value;
    bool operator <(const Edge & s){
        return this->value<s.value;
    } 
};
// ���鼯����
int get_father(int x){
    return fa[x]= x==fa[x]? x:get_father(fa[x]);
}
bool unio(int x,int y){
    int a=get_father(x);
    int b=get_father(y);
    fa[a]=b;
    if(a==b) return false;
    else return true;
}
// ���ɲ���(ÿ�β�ѯȡ����С�ߣ�Ȼ���ж��Ƿ����߽ڵ��Ƿ��Ѿ���������)
LL solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) fa[i]=i;
    vector<Edge> edg(m+1);
    for(int i=1;i<=m;i++){
        cin>>edg[i].u>>edg[i].v>>edg[i].value;
    }
    sort(edg.begin()+1,edg.end());
    LL ans=0;
    int k=0;
    for(int i=1;i<=m;i++)
    {
        if(unio(edg[i].u,edg[i].v)){
            k++;
            ans+=edg[i].value;
        }
        if(k==n-1) break;
    }
    if(k==n-1) return ans;//�������ɣ������ֵ
    else return inf;//���򣬷���inf
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    
    LL ans=solve();
    if(ans==inf) cout<<"orz"<<endl;
    else cout<<ans<<endl;

    return 0;
}
