#include<bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define P pair<int,int>
#define x first
#define y second
typedef long long LL;
const int inf=0x3f3f3f3f;
// 写完没有交，曲荣升已经A掉了

int n,h,H;
int get_pos(int t){
    t%=(2*H);
    return min(t,2*H-t);
}
int get_dir(int t){
    t%=(2*H);
    if(t<H) return 1;
    else return -1;
}
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
        
        
        scanf("%d %d %d",&n,&h,&H);
        vector<int> a(n+5),c(n+5),ans(n+5);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans[i]=inf;
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&c[i]);
        
        for(int i=1;i<=n;i++)
        {
            int tim=a[i];
            if(get_pos(tim)<=h)//第一次向上
            {
                tim+=c[i];
                int pos=get_pos(tim);
                if(pos<=h) ans[i]=tim;
                else
                {
                    if(get_dir(tim)==1) tim+=2*H-h-pos;
                    else tim+=pos-h;
                    tim+=c[i];
                    if(get_pos(tim)<=h) ans[i]=tim;
                    else ans[i]=inf;
                }
            }
            else
            {
                int pos=get_pos(tim);
                if(get_dir(tim)==1) tim+=2*H-h-pos;
                else tim+=pos-h;

                tim+=c[i];
                if(get_pos(tim)<=h) ans[i]=tim;
                else ans[i]=inf;
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