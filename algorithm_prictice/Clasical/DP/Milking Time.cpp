#include<bits/stdc++.h>
using namespace std;
//对拍后AC，思路正确。
//坑1：从0开始的情况 坑2：左开右毕（其实解决了左开右闭，也就不会有1了
//并非最佳思路，最佳为m^2的思路，空间常数小
/*
    大概思路：排序后：
    for(int i=1;i<=m;i++)//i必须放进去
        for(int j=1;j<i;j++){前面能与i共存的，加一遍
            if(i.end>j.start)
                f[i]=max(f[i],f[j]+j.value);
        }
    for(1……m) max(f[i])=ans;
*/
struct num{
    int t;
    int v;
    num(int tt,int vv):t(tt),v(vv){};
    bool operator<(num a){
        return t<a.v;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m,r;
    
    while(cin>>n>>m>>r)
    {
        //for(int i=0;i<=n;i++) f[i]=0;
        vector<int>f(n+r+2);
        vector<vector<num> > ma(n+r+2);
        for(int i=1;i<=m;i++){
            int a,b,c;  
            cin>>a>>b>>c;
            //a++;b++;
            num tmp(b+r-a,c);//竟然是左开右闭的……
            ma[b+r].push_back(tmp);
        }
        int ans=0;
        for(int i=1;i<=n+r+1;i++)//枚举结束时间i
        {
            for(int j=0;j<ma[i].size();j++)
                if(i-ma[i][j].t>=0){
                    f[i]=max(f[i],f[i-ma[i][j].t]+ma[i][j].v);
            }
           f[i]=max(f[i],f[i-1]);
        }
        
        for(int i=1;i<=n+r+1;i++) ans=max(ans,f[i]);
        cout<<ans<<endl;
    }

    return 0;
}