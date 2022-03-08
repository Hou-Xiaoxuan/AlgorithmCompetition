#include<bits/stdc++.h>
using namespace std;
#define  m_k make_pair
#define   P  pair<int,int>
#define  V vector
typedef long long LL;
typedef unsigned long long ULL;
//补题：题解放在了怎么从第1个得到第k个
//事实上，若a>b,则a变化得到的一定>b变化得到的

int main()
{
    int k;cin>>k;
    if(k<=9){
        cout<<k<<endl;
        return 0;
    }
    queue<LL> que;
    for(int i=1;i<=9;i++) que.push(i);
    LL current;
    for(int i=1;i<=k;i++)
    {
        current=que.front();//第k次取出来的就是第k个
        que.pop();
        int tail=current%10;
        if(tail>0) que.push(current*10+tail-1);
        que.push(current*10+tail);
        if(tail<9) que.push(current*10+tail+1);
    }

    cout<<current<<endl;
    return 0;
}
/*
int f[15][15];
void get(int st,int t,int k,queue<int> &s)
{
    if(t==0) return;
    
    {
        if(st==0)
        {
            if(k<f[t][0]){
                s.push(0);
                get(0,t-1,k,s);
                return;
            }
            else{
                k-=f[t][0];
                s.push(1);
                get(1,t-1,k,s);
                return;
            }

        }
        else
        {
            for(int i=st-1;i<=st+1;i++)
            {
                if(f[t][i]<k) k-=f[t][i];
                else{
                    s.push(i);
                    get(i,t-1,k,s);
                    return;
                }
            }
        }    
    }
    
}
int main()
{
    //i位数，首位是j
    int cnt[15];
    for(int i=0;i<=9;i++) f[1][i]=1;
    cnt[1]=9;
    for(int i=2;i<=13;i++)
    {
        cnt[i]=0;
        for(int j=0;j<=9;j++)
        {
            if(j==0) f[i][j]=f[i-1][0]+f[i-1][1];
            else if(j==9) f[i][j]=f[i-1][9]+f[i-1][8];
            else f[i][j]=f[i-1][j]+f[i-1][j-1]+f[i-1][j+1];
            cnt[i]+=f[i][j];
        }
    }
    int k;
    while(cin>>k)
    {
        queue<int> ans;
        int t=1;
        while(k-cnt[t]>0){
            k-=cnt[t];
            t++;
        }
        //t位数的第k个
        for(int i=1;i<=9;i++)
        {
            if(f[t][i]<k) k-=f[t][i];
            else{
                ans.push(i);
                get(i,t-1,k,ans);
                break;
            }
        }
        
        while(!ans.empty()){
             cout<<ans.front();
             ans.pop();
        }
        cout<<endl;
    }
    return 0;
}
*/