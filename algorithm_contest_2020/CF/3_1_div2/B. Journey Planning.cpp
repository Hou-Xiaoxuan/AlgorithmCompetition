#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
long long count(vector<int>& b)
{
    long long cnt=0;
    for(int i=0;i<b.size();i++)
        cnt+=b[i];
    return cnt;
}
int main()
{
    int n; 
    while(cin>>n)
    {
        vector<int> a(n+1);
        map<int,vector<int> >cnt;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]-=i;
            cnt[a[i]].push_back(i);
        }
        
        map<int,vector<int> >::iterator i;
        long long ans=0;
        for(i=cnt.begin();i!=cnt.end();i++){
            long long temp=LL(i->first)*LL(i->second.size())+count(i->second);//需要防止爆精度
            //cout<<int(i->first)<<" "<<i->second.size()<<" "<<temp<<endl;
            if(temp>ans) ans=temp;
        }
       cout<<ans<<endl;
    }
    return 0;
}