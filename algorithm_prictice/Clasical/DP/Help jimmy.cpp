#include<bits/stdc++.h>
using namespace std;
//递归，递归，以递归的思路来做
struct num{
    int x,y;
    int h;
    bool operator<(num a){
        return h<a.h;
    }
};
int main()
{

    int T;cin>>T;
    const int N=20005;
    while(T--)
    {
        int n,X,h,H;
        cin>>n>>X>>h>>H;
        vector<num> nod(n+2),time(n+2);
        for(int i=1;i<=n;i++)
            cin>>nod[i].x>>nod[i].y>>nod[i].h;
        nod[0].x=-N,nod[0].y=N,nod[0].h=0;
        nod[n+1].x=nod[n+1].y=X,nod[n+1].h=h;
        sort(nod.begin(),nod.end());
        /*DP*/
        for(int i=1;i<=n+1;i++)
        {
            int now,j;
            //caculate the left
            now=nod[i].x;
            for( j=i-1;j>=1;j--)
                if(nod[j].x<=now and nod[j].y>=now)
                    break;
            if(j<1){
                if(nod[i].h<=H)
                    time[i].x=nod[i].h;
                else
                    time[i].x=N;                
            }
            else{
                if(nod[i].h-nod[j].h<=H)
                    time[i].x=min(time[j].x+now-nod[j].x,time[j].y+nod[j].y-now)+nod[i].h-nod[j].h;
                else
                    time[i].x=N;               
            }
            //caculate the right
            now=nod[i].y;
            for( j=i-1;j>=1;j--)
                if(nod[j].x<=now and nod[j].y>=now)
                    break;
            if(j<1){
                if(nod[i].h<=H)
                    time[i].y=nod[i].h;
                else
                    time[i].y=N;                
            }
            else{
                if(nod[i].h-nod[j].h<=H)
                    time[i].y=min(time[j].x+now-nod[j].x,time[j].y+nod[j].y-now)+nod[i].h-nod[j].h;
                else
                    time[i].y=N;               
            }
        }
        cout<<time[n+1].x<<endl;
    }
    return 0;
}