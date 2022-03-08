#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//44722
//wtf£¡£¡why i wast such long time on this easy question??
int main()
{
    int t;cin>>t;
    while(t--)
    {
        long long n,k;cin>>n>>k;
        long long cnt=sqrt(2*k)-3;
        while(cnt*(cnt+1)/2<k) cnt++;
        long long cnt2=cnt*(cnt+1)/2-k;
        //cout<<cnt<<" "<<cnt2<<endl;//forget to delete
        for(int i=1;i<=n;i++){
            if(i==(n-cnt) or i==(n-cnt+1+cnt2)) cout<<'b';
            else cout<<'a';
        }
        cout<<endl;
    }

    return 0;
}