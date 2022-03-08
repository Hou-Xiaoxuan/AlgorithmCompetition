#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a,b;
    while(cin>>a>>b)
    {
        double l=max(double(a)*12.5,double(b)*10.0);
        double r=min(12.5*double(a+1),10.0*double(b+1));
       // cout<<l<<" "<<r<<endl;
        int ans=l;
        if(!(double(ans)*0.08>=a and double(ans)*0.1>=b))
            ans++;
        if(ans<r)
            cout<<ans<<endl;
        else cout<<-1<<endl;
    }



    return 0;
}