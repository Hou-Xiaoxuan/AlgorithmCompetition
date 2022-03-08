#include<bits/stdc++.h>
using namespace std;
//zhe dou bu hui TLE?
int main()
{
    int t;  cin>>t;
    while(t--)
    {
        int x; cin>>x;
        int a=-1,b;
        for(int m=1;m<=x/2 and a==-1;m++)
        {
            if((x-m)%m==0)
            {
                int n=x-m;
                int t=sqrt(n)+1;
                for(int i=1;i*m<t and a==-1;i++)
                    if(n%(i*m)==0)
                        a=i*m,b=n/(i*m);
            }    
        }
        cout<<a<<" "<<b<<endl;
    }



    return 0;
}