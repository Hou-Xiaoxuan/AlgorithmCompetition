//Finally AC
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,x,y;cin>>n>>x>>y;
        //让尽可能多的人>x+y;
        int a1=x-1,a2=y-1,b1=n-x,b2=n-y;
        int tnp;
        tnp=min(a1,max(b2-1,0));//前两次WA：b2-1可能为-1影响结果；
        a1-=tnp;
        b2-=tnp;
        tnp=min(a2,max(b1-1,0));
        a2-=tnp;
        b1-=tnp;
        int ans1=max(a1,a2);

        //让尽可能多的人<=x+y;
        int ans2=0;
        a1=x-1,a2=y-1,b1=n-x,b2=n-y;
        tnp=min(a1,b2);
        a1-=tnp; ans2+=tnp;
        tnp=min(a2,b1);
        a2-=tnp;ans2+=tnp;
        ans2+=min(a1,a2);
        
        cout<<ans1+1<<" "<<ans2+1<<endl;
    }
    return 0;

}