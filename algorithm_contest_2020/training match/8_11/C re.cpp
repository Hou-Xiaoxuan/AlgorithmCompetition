#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
// 复习线段树
// 题解链接：https://www.iteye.com/blog/simone-chou-2077070
// 数据范围1^16,建4棵线段树来表示数据的每一位。这样位运算就方便表示了
// // wocao,戏界错误找了两个小时，字符级别的错误
//  RE，放弃了，找不到哪里有问题
const int N=1e6+5;
int tree[5][4*N];
int cov_xor[5][4*N],cov_oth[5][4*N];//xor[i]是否状态相反过一次，oth代表是否杯覆盖(&1 and |1都不变，&0 and |1 全变0 or 全变1，^1 全部相反，^0不变)
int a[N];
int k,L,R,res;
//  op=1,全变0 op=2,全变1，op=3,相反
void putdown(int nod,int l,int r)
{
    int mid=(l+r)>>1;
    if(cov_oth[k][nod]!=-1)
    {
        tree[k][nod<<1]=(mid-l+1)*cov_oth[k][nod];
        tree[k][nod<<1|1]=(r-mid)*cov_oth[k][nod];
        cov_oth[k][nod<<1]=cov_oth[k][nod<<1|1]=cov_oth[k][nod];
        cov_xor[k][nod<<1]=cov_xor[k][nod<<1|1]=0;
        cov_oth[k][nod]=-1;
    }
    if(cov_xor[k][nod])
    {
        cov_xor[k][nod]=0;
        tree[k][nod<<1]=mid-l+1-tree[k][nod<<1];
        tree[k][nod<<1|1]=r-mid-tree[k][nod<<1|1];
        
        // 下方标记
        if(cov_oth[k][nod<<1]!=-1)    cov_oth[k][nod<<1]^=1;
        else cov_xor[k][nod<<1]^=1;
        if(cov_oth[k][nod<<1|1]!=-1)   cov_oth[k][nod<<1|1]^=1;
        else cov_xor[k][nod<<1|1]^=1;
    }
}
void build(int k,int nod,int l,int r)
{
    int mid=(l+r)>>1;
    cov_oth[k][nod]=-1;//没有杯覆盖
    cov_xor[k][nod]=0;//没有相反
    if(l==r)
    {
        tree[k][nod]=(a[l]>>k)&1;
        return;
    }
    
    build(k,nod<<1,l,mid);
    build(k,nod<<1|1,mid+1,r);
    tree[k][nod]=tree[k][nod<<1]+tree[k][nod<<1|1];
}
void update(int nod,int l,int r,int op)
{
    int mid=(l+r)>>l;
    if(L>r or R<l) return;
    if(L<=l and R>=r)
    {
        if(op==1)//全部置零
        {
            tree[k][nod]=0;
            cov_oth[k][nod]=0;
            cov_xor[k][nod]=0;//不用管了
        }
        else if(op==2)//全部置1
        {
            tree[k][nod]=r-l+1;
            cov_oth[k][nod]=1;
            cov_xor[k][nod]=0;
        }
        else if(op==3)
        {
            tree[k][nod]=r-l+1-tree[k][nod];
            if(cov_oth[k][nod]!=-1)//如果被覆盖过
                cov_oth[k][nod]^=1;//取相反覆盖就可以了
            else cov_xor[k][nod]^=1;//标记覆盖 
        }
        return;
    }
        putdown(nod,l,r);
        update(nod<<1,l,mid,op);
        update(nod<<1|1,mid+1,r,op);
        tree[k][nod]=tree[k][nod<<1]+tree[k][nod<<1|1];
}
// int sum(int k,int nod,int l,int r,int L,int R)
// {
//     int mid=(l+r)>>1;
//     if(L>r or R<l) return 0;
//     if(L<=l and R>=r)
//     {
//         return tree[k][nod];
//     }
//     putdown(k,nod,l,r);
//     int tmp=sum(k,nod<<1,l,mid,L,R)+sum(k,nod<<1|1,mid+1,r,L,R);
//     return tmp;
// }
void sum(int nod,int l,int r)
{
    int mid=(l+r)>>1;
    if(L>r or R<l) return;
    if(L<=l and R>=r)
    {
        res+=tree[k][nod];
        return;
    }
    putdown(nod,l,r);
    sum(nod<<1,l,mid);
    sum(nod<<1|1,mid+1,r);
}
int main()
{
    // IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;
    // cin>>t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        //cin>>n>>m;
        for(int i=1;i<=n;i++)
            scanf("%d",a+i); //cin>>a[i];
        for(int i=0;i<4;i++)
            build(i,1,1,n);
        char s[10];
        while(m--)
        {
            scanf("%s",s);
            if(s[0]=='S')
            {
                int L,R;
                scanf("%d %d",&L,&R);
                ++L,++R;
                int ans=0;
                for(k=0;k<4;k++)
                {
                    // int tmp=sum(i,1,1,n,L,R);
                    // // cout<<tmp<<" -";
                    // ans+=tmp*(1<<i);
                    res=0;
                    sum(1,1,n);
                    ans+=(res*(1<<k));
                }
                printf("%d\n",ans);
            }
            else if(s[0]=='A')
            {
                int op,L,R;
                scanf("%d %d %d",&op,&L,&R);
                ++L,++R;
                for(k=0;k<4;k++)
                    if(((op>>k)&1)==0)//全部取0
                        update(1,1,n,1);
            }
            else if(s[0]=='O')
            {
                int op,L,R;
                scanf("%d %d %d",&op,&L,&R);
                ++L,++R;
                for(int i=0;i<4;i++)
                    if(((op>>i)&1)==1)// 全部取1
                        update(1,1,n,2);
            }
            else if(s[0]=='X')
            {
                int op,L,R;
                scanf("%d %d %d",&op,&L,&R);
                ++L,++R;
                // 取反
                for(int i=0;i<4;i++)
                    if(((op>>i)&1)==1)
                        update(1,1,n,3);
            }

        }
    }
   
    return 0;
}

