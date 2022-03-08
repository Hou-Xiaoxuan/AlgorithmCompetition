//权值线段树模板
//线段树学完都已经9个月了，我还是不太会线段树啊

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int tree[(N<<1)];//保存权值
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
    if(tree[nod<<=1]>k)
        return kminth(nod<<1,l,mid,k);
    else
        return kminth(nod<<1|1,mid+1,r,k-tree[nod<<1]);
}
