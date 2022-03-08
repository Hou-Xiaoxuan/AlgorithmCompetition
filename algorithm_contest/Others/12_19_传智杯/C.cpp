/*
 * @Author: LinXuan
 * @Date: 2021-12-19 15:54:18
 * @Description: 
 * @LastEditors: LinXuan
 * @LastEditTime: 2021-12-19 16:15:23
 * @FilePath: /Algorithm/algorithm_contest/Others/12_19_传智杯/C.cpp
 */
# ifndef _USE_MATH_DEFINES
# define _USE_MATH_DEFINES
# endif
# include<bits/stdc++.h>
# define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
# define  m_p make_pair
# define x first
# define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using LD=long double;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

const int N=4000;
struct trreeArray
{
    //区间查询，单点修改
    int a[N],c[N];
    int lowbit(int x){
        return x&(-x);
    }
    void update(int x,int n,int value){//x位增加value
        a[x]+=value;
        while(x<=n){
            c[x]+=value;
            x+=lowbit(x);
        }
    }
    int get_sum(int x){//求出前x位的和
        int ans=0;
        while(x>0){
            ans+=c[x];
            x-=lowbit(x);
        }
        return ans;
    }
};
trreeArray tree[1005];
int main()
{
    IOS;
    # ifdef _DEBUG
    freopen("in.txt","r",stdin);  
    # endif
    int n, k;
    cin>>n>>k;
    while(k--)
    {
        int op;
        cin>>op;
        if(op == 1)
        {
            
        }
        else
        {
            int x, l, r;
            cin>>x>>l>>r;
            // 查询多少个字段 x 在取值范围内
            int ans = 0;
            for(int i=1; i<=n; i++)
            {
                if(tree[i].get_sum(x) >0 and tree[i].get_sum(1005) - tree[i].get_sum(x-1) > 0)
                    ans ++;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
