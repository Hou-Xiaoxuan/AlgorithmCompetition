#include<bits/stdc++.h>
using namespace std;
const int N=200005;//How full I am!
char s[N];
int ans[27],a[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;cin>>T;
    while(T--)
    {   memset(ans,0,sizeof(ans));
        int n,m;cin>>n>>m;
        cin>>(s+1);
        for(int i=1;i<=m;i++) cin>>a[i];
        sort(a+1,a+1+m);
        a[0]=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=a[i-1]+1;j<=a[i];j++)
                ans[s[j]-'a'+1]+=m+2-i;
        }
        for(int i=a[m]+1;i<=n;i++) ans[s[i]-'a'+1]++;
        for(int i=1;i<=26;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }





    return 0;
}