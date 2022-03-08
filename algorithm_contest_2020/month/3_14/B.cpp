#include<bits/stdc++.h>
using namespace std;
//被你坑惨了，时间卡的那么紧
bool cmp(pair<int,int> &a,pair<int,int>&b){
    if(a.first==b.first)
        return a.second<b.second;
    return a.first<b.first;
}
const int N=2e5+5;
pair<int,int> a[N];
bool vis[N];
int main()
{
    int n;
    //ios_base::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    while(scanf("%d",&n)!=EOF)
    {
        //memset(vis,0,sizeof(vis));
        //for(int i=1;i<=n;i++)
           
            //cin>>a[i].first>>a[i].second;
        //sort(a+1,a+n+1,cmp);
        int r1=-1,r2=-1;
        bool flag=true;
        for(int i=1;i<=n;i++)
        { 
            scanf("%d %d",&a[i].first,&a[i].second);
            /*if(a[i].first>r1 and a[i].first>r2){
                if(r1-a[i].first<r2-a[i].first) r1=a[i].second;
                else r2=a[i].second;
            }*/
            if(a[i].first>r1) r1=a[i].second;
            else if(a[i].first>r2) r2=a[i].second;
            else flag=false;
        }
        if(flag)    printf("yes\n");//cout<<"yes"<<endl;
        else    printf("no\n");     //cout<<"no"<<endl;
    }
    return 0;
}

/*
 
*/