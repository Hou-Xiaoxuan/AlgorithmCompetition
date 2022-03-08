#include<bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define P pair<int,int>
#define x first
#define y second
typedef long long LL;
const int inf=0x3f3f3f3f;
// WA代码，可能是读错题了
int main()
{
    #ifdef _DEBUG
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,h,H;
        // cin>>n>>h>>H;
        scanf("%d %d %d",&n,&h,&H);
        vector<int> a(n+5),c(n+5),ans(n+5);
        for(int i=1;i<=n;i++){
            // cin>>a[i];
            scanf("%d",&a[i]);
            ans[i]=inf;
        }
        for(int i=1;i<=n;i++) //cin>>c[i];
            scanf("%d",&c[i]);
        
        for(int i=1;i<=n;i++)
        {
            if(a[i]%(2*H)>h or a[i]%(2*H)<2*H-h)//等到平台向下的时候跳
            {
                int tmp=a[i]+2*H-h-a[i]%(2*H);//准备起跳的时刻
                if(tmp%(2*H)<=h or tmp%(2*H)>=2*H-h) ans[i]=tmp+c[i];
            }
            else//立刻跳
            {
                int tmp=a[i];
                if(tmp%(2*H)<=h or tmp%(2*H)>=2*H-h) ans[i]=tmp+c[i];
            }
        }
        int minn=inf,id;
        for(int i=1;i<=n;i++)
        {
            if(ans[i]<minn){
                minn=ans[i];
                id=i;
            }
        }
        // cout<<id<<endl;
        printf("%d\n",id);
    }

    return 0;
}