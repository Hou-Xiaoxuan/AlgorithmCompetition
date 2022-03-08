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
// 应该是权值线段树的模板题
// 然后就WA哭到现在
// 多组能把我卡掉就tm离谱
const int N=1e6+5;
int tree[(N<<1)];//保存权值
void update(int p,int l,int r,int v,int op=1)//op==1或-1,插入或删除 
{
	tree[p]+=op;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(v<=mid)update(p<<1,l,mid,v,op);
	else update(p<<1|1,mid+1,r,v,op); 
}
 
int Kminth(int p,int l,int r,int rank)//k小值 
{
	if(l==r)return l;
	int mid=(l+r)>>1;
	if(tree[p<<1]>=rank)return Kminth(p<<1,l,mid,rank);//左子k小 
	return Kminth(p<<1|1,mid+1,r,rank-tree[p<<1]);//右子(k-左num)小 
} 
// void update(int nod,int l,int r,int pos)//修改pos位置的数出现的次数
// {
//     if(l==r) tree[nod]++;
//     else
//     {
//         int mid=(l+r)>>1;
//         if(pos<=mid) update(nod<<1,l,mid,pos);
//         else update(nod<<1|1,mid+1,r,pos);
//         tree[nod]=tree[nod<<1]+tree[(nod<<1)+1]; 
//     }
// }

// int query(int nod,int l,int r,int pos)//查询一个值出现的总次数，功能可以被区间查询覆盖
// {
//     if(l==r) return tree[nod];
//     else
//     {
//         int mid=(l+r)>>1;
//         if(pos<=mid) return query(nod<<1,l,mid,pos);
//         else return query(nod<<1|1,mid+1,r,pos);
//     }
// }

// int query(int nod,int l,int r,int ql,int qr)
// {
//     if(l>=ql and r<=qr) return tree[nod];

//     int mid=(l+r)>>1;
//     int rt=0;
//     if(ql<=mid) rt+=query(nod<<1,l,mid,ql,qr);
//     if(qr>mid) rt+=query(nod<<1|1,mid+1,r,ql,qr);
//     return rt;
// }
// //此前内容与线段树几乎完全相同（废话，本来就是线段树嘛），下一个是独特的：查询第k大的数
// int kmaxth(int nod,int l,int r,int k)
// {
//     if(l==r) return l;

//     int mid=(l+r)>>1;
//     if(tree[nod<<1|1]>=k)//右边超过k个数，说明答案再右边
//         return kmaxth(nod<<1|1,mid+1,r,k);
//     else//答案再左子树。现在要查询左边第k-tree[nod<<1|1]个数了，因为少了右边的几个数，排名变了
//         return kmaxth(nod<<1,l,mid,k-tree[nod<<1|1]);
// }

// int kminth(int nod,int l,int r,int k)//查询第k小的版本
// {
//     if(l==r) return l;

//     int mid=(l+r)>>1;
//     if(tree[nod<<1]>=k)
//         return kminth(nod<<1,l,mid,k);
//     else
//         return kminth(nod<<1|1,mid+1,r,k-tree[nod<<1]);
// }

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int n,m;
    // while(cin>>n>>m)
    // {
       cin >> n >> m;
        memset(tree,0,sizeof(tree));
        vector<LL> a(n+1);
        vector<pair<LL,LL> > b(m+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        // 离散化
        vector<LL> sca(a);
        sort(sca.begin()+1,sca.end());
        sca.erase(unique(sca.begin()+1,sca.end()),sca.end());
        int cnt=sca.size()-1;
        unordered_map <LL,LL> ma;
        for(int i=1;i<=cnt;i++) ma[sca[i]]=i;

        // 读入询问
        for(int i=1;i<=m;i++){
            cin>>b[i].first;
            b[i].second=i;
        }
        sort(b.begin()+1,b.end());
        int ct=1;
        vector<LL> ans(m+1);
        for(int i=1;i<=m;i++)
        {
            while(tree[1]<b[i].first)
                update(1,1,cnt,ma[a[ct++]]);
            ans[b[i].second]=sca[Kminth(1,1,cnt,b[i].second)];
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<endl;

        // vector<LL>  height(n+1);
        // vector<LL> sca(n+1);
        // vector<pair<LL,LL> > query(m+1);
        // vector<LL> ans(m+1);
        // for(int i=1;i<=n;i++) cin>>height[i];
        // for(int i=1;i<=m;i++){
        //     cin>>query[i].first;
        //     query[i].second=i;
        // }
        // sort(query.begin()+1,query.end());
        // for(int i=1;i<=n;i++) sca[i]=height[i];
        // sort(sca.begin()+1,sca.end());
        // sca.erase(unique(sca.begin()+1,sca.end()),sca.end());
        // for(int i=1;i<=n;i++)
        //     height[i]=lower_bound(sca.begin()+1,sca.end(),height[i])-sca.begin();
        // for(int i=1;i<=m;i++)
        // {
        //     while(tree[1]<query[i].first)
        //         update(1,1,sca.size()-1,height[tree[1]+1]);
        //     ans[query[i].second]=sca[Kminth(1,1,sca.size()-1,query[i].second)];
        // }
        // for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
    // }
    return 0;
}
