#include<bits/stdc++.h>
using namespace std;
//уп
const int inf=2147483647;
int main()
{
    int n;cin>>n;
    int a=-inf,b=inf;
    int t;
    while(n--){
        cin>>t;
        a=max(t,a);
        b=min(t,b);
    }
    cout<<a-b<<endl;
    return 0;
}