#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<int,int>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;

// A了，挺签到的
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;
    cin>>t;
    int n,m,a,b;
    while(t--)
    {
        cin>>n>>m>>a>>b;//a-犯人 b-警察
        vector<int> fire(m+1);
        for(int i=1;i<=m;i++) cin>>fire[i];
        sort(fire.begin(),fire.end());
        int time,len;//总时间和两人的间隔
        time = a<b?a-1:n-a;
        len=abs(a-b)-1;
        //最多放置len个鞭炮就必须要开始跑了
        //小偷能跑的最短时间就是time，他绝对会让自己跑到墙的位置，否则之前的放置没有意义。最长时间是len+time
        //而只要放置鞭炮，肯定是放置的越早越好。因此在警察走到自己隔壁的之前，他可以一直放鞭炮。

        int cnt=min(m,len);//放置的鞭炮的数量
        /*忽然觉得是不是有一点问题……感觉可能二分地去判断第一个扔出的鞭炮最好*/
        auto f = [&](const int x)->bool
        {
            //检验x是否是正确答案
            // 扔出第1个时,len+time后就会被抓
            if(x>cnt) return false;
            for(int i=1;i<=x;i++)
            {
                if(fire[x-i+1]<=time+len-i+1) continue;//第i个放置的有time+len+1的时间来爆炸
                else return false;
            }
            return true;
        };
        int ans=0;
        int l=0,r=cnt;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(f(mid)==true){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        cout<<ans<<endl;
        fire.clear();
    }
    return 0;
}
