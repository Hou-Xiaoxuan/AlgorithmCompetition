﻿#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

//权值线段树模板
//线段树学完都已经9个月了，我还是不太会线段树啊
//**没有找到题目实验，暂时不知道模板对不对
#include<iostream>
using namespace std;

const int N=1e5+5;
int tree[(N<<2)];//保存权值
// 已检验
void update(int nod,int l,int r,int pos)//修改pos位置的数出现的次数
{
    if(l==r) tree[nod]++;
    else
    {
        int mid=(l+r)>>1;
        if(pos<=mid) update(nod<<1,l,mid,pos);
        else update(nod<<1|1,mid+1,r,pos);
        tree[nod]=tree[nod<<1]+tree[(nod<<1)+1]; 
    }
}

int query(int nod,int l,int r,int pos)//查询一个值出现的总次数，功能可以被区间查询覆盖
{
    if(l==r) return tree[nod];
    else
    {
        int mid=(l+r)>>1;
        if(pos<=mid) return query(nod<<1,l,mid,pos);
        else return query(nod<<1|1,mid+1,r,pos);
    }
}
// 已检验
int query(int nod,int l,int r,int ql,int qr)
{
    if(l>=ql and r<=qr) return tree[nod];

    int mid=(l+r)>>1;
    int rt=0;
    if(ql<=mid) rt+=query(nod<<1,l,mid,ql,qr);
    if(qr>mid) rt+=query(nod<<1|1,mid+1,r,ql,qr);
    return rt;
}
//此前内容与线段树几乎完全相同（废话，本来就是线段树嘛），下一个是独特的：查询第k大的数
int kmaxth(int nod,int l,int r,int k)
{
    if(l==r) return l;

    int mid=(l+r)>>1;
    if(tree[nod<<1|1]>=k)//右边超过k个数，说明答案再右边
        return kmaxth(nod<<1|1,mid+1,r,k);
    else//答案再左子树。现在要查询左边第k-tree[nod<<1|1]个数了，因为少了右边的几个数，排名变了
        return kmaxth(nod<<1,l,mid,k-tree[nod<<1|1]);
}

int kminth(int nod,int l,int r,int k)//查询第k小的版本
{
    if(l==r) return l;
    int mid=(l+r)>>1;
    if(tree[nod<<1]>=k)
        return kminth(nod<<1,l,mid,k);
    else
        return kminth(nod<<1|1,mid+1,r,k-tree[nod<<1]);
}
int main()
{
    IOS;
    #ifdef _DEBU
    freopen("D:\\CODE\\algorithm_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_prictice\\in.txt","r",stdin); 
    #endif
    // 貌似还要离散化：

    int n;cin>>n;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b.begin()+1,b.end());
    int m=unique(b.begin()+1,b.end())-b.begin()-1;
    map<int,int> ma;
    for(int i=1;i<=m;i++)
        ma[b[i]]=i;
    
    for(int i=1;i<=n;i++)
    {
        update(1,1,n,ma[a[i]]);
        if(i&1)
        {
            int st=kmaxth(1,1,n,i/2+1);
            cout<<b[st]<<endl;
        }
    }
    return 0;
}