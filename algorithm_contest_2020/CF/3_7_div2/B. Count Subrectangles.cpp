#include<bits/stdc++.h>
using namespace std;
const int N=4e5+5;
//const int N=100;
//TLE
//离散化一下，不能使用map
int a[N],b[N];
vector<int> c;
vector<pair<int,int> > cntk;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n,m,k;  cin>>n>>m>>k;
    /*divide K*/
    for(int i=1;i*i<=k;i++)
        if(k%i==0){
            cntk.push_back(make_pair(i,k/i));
            c.push_back(i);
            if(i==k/i) continue;
            c.push_back(k/i);
        }
    c.push_back(0);
    int sum=c.size();
    vector<int> cnta(sum),cntb(sum);
    sort(c.begin(),c.end());
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]) a[i]+=a[i-1];
        for(int j=1;j<sum;j++){
            if(a[i]>=c[j]) cnta[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
        if(b[i]) b[i]+=b[i-1];
        for(int j=1;j<sum;j++){
            if(b[i]>=c[j]) cntb[j]++;
        }
    }
    long long ans=0;
    for(int i=1;i<sum;i++)
        ans+=cnta[i]*cntb[sum-i];
    /*{
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]) a[i]+=a[i-1];
        for(int j=0;j<cntk.size();j++){
            if(a[i]>=cntk[j].first)  cnta[cntk[j].first]++;
            if(cntk[j].first==cntk[j].second) continue;
            if(a[i]>=cntk[j].second) cnta[cntk[j].second]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        if(b[i]) b[i]+=b[i-1];
        for(int j=0;j<cntk.size();j++){
            if(b[i]>=cntk[j].first) cntb[cntk[j].first]++;
            if(cntk[j].first==cntk[j].second) continue;
            if(b[i]>=cntk[j].second) cntb[cntk[j].second]++;
        }
    }
    long long ans=0;
    for(int i=0;i<cntk.size();i++){
        ans+=cnta[cntk[i].first]*cntb[cntk[i].second];
        if(cntk[i].first==cntk[i].second) continue;//twe sides
        ans+=cnta[cntk[i].second]*cntb[cntk[i].first];
    }
     }*/
    cout<<ans<<endl;
    return 0;
}