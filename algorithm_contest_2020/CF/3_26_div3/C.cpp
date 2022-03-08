#include<bits/stdc++.h>
using namespace std;
const int N=5e4+5;
char s[N],a[N],b[N];
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        memset(a,0,n+5);
        memset(b,0,n+5);
        cin>>(s+1);
        bool flag=false;
        a[1]=b[1]='1';
        for(int i=2;i<=n;i++)
        {
            if(s[i]=='0') a[i]=b[i]='0';
            else if(flag)
            {
                b[i]=s[i];a[i]='0';
            }
            else
            {
                if(s[i]=='2')
                    a[i]=b[i]='1';
                else if(s[i]=='1'){
                    a[i]='1';
                    b[i]='0';
                    flag=true;
                }

            }
        }
        cout<<a+1<<endl<<b+1<<endl;
    }


    return 0;
}