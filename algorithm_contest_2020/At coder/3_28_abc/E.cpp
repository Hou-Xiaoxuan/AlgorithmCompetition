#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;
#define k_p make_pair
const int inf=0x3f3f3f3f;
bool cmp(int a,int b){return a>b;}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int x,y,ia,ib,ic;
    while(cin>>x>>y>>ia>>ib>>ic)
    {
        vector<int> a(ia+1),b(ib+1),c(ic+1);
        a[0]=b[0]=c[0]=inf;
        for(int i=1;i<=ia;i++) cin>>a[i];
        for(int i=1;i<=ib;i++) cin>>b[i];
        for(int i=1;i<=ic;i++) cin>>c[i];
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end(),cmp);
        sort(c.begin(),c.end(),cmp);
        vector<int> ans(x+y+1);
        for(int i=1;i<=x;i++)
            ans[i]=a[i];
        for(int i=1;i<=y;i++)
            ans[i+x]=b[i];
        sort(ans.begin(),ans.end());
        for(int i=1;i<=ic;i++){
            if(ans[i]<c[i])
                ans[i]=c[i];
            else break;
        }
        LL res=0;
        for(int i=1;i<=x+y;i++)
            res+=ans[i];
        cout<<res<<endl;
    }
    return 0;
}
