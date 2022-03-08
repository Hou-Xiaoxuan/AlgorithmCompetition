#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
const int N=1000<<2;
class TREE
{
public:
    int tree[N+5];
    int cov[N+5];
    void putdown(int nod,int l,int r)
    {
        if (cov[nod]) {
            int mid = l + r >> 1;
            tree[nod << 1] += cov[nod] * (mid - l + 1);
            tree[nod << 1 | 1] += cov[nod] * (r - mid);
            cov[nod << 1 | 1] += cov[nod];
            cov[nod << 1] += cov[nod];
            cov[nod] = 0;
        }
    }
    void change(int nod, int l, int r, int ql, int qr, int y)
    {
        if (ql <= l and qr >= r) {
            tree[nod] += (r - l + 1) * y;/*(红色)这里写成了l-r+1！！（红色）*/
            cov[nod] += y;
            return;
        }
        putdown(nod, l, r);
        int mid = l + r >> 1;
        if(ql<=mid)
            change(nod << 1, l, mid, ql, qr, y);
        if(qr>mid)
            change(nod << 1 | 1, mid + 1, r, ql, qr, y);
        tree[nod] = tree[nod << 1] + tree[nod << 1 | 1];
    }
    long long ask(int nod, int l, int r, int ql, int qr)
    {
        if (ql <= l and qr >= r) return tree[nod];
        putdown(nod, l, r);
        long long ans = 0;
        int mid = l + r >> 1;
        if (ql <= mid)
            ans += ask(nod << 1, l, mid, ql, qr);
        if (qr > mid)
            ans += ask(nod << 1 | 1, mid + 1, r, ql, qr);
        
        return ans;
    }
};

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        vector<TREE> a(n+1);
        char ch;
        while(k--)
        {
            cin>>ch;
            if(ch=='A'){
                int x1,x2,y1,y2;
                cin>>x1>>y1>>x2>>y2;
                for(int i=y1;i<=y2;i++)
                    a[i].change(1,1,m,x1,x2,1);
            }
            else{
                int x,y;
                cin>>x>>y;
                int tmp=a[x].ask(1,1,m,y,y);
                if(tmp&1) cout<<"I want five star!"<<endl;
                else cout<<"I want five star next time!"<<endl;
            }
        }
    }
    return 0;
}