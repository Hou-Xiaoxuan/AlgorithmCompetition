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

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int L,b,f;
    while(cin>>L>>b>>f)
    {
        int n;cin>>n;
        vector<P> pos(n+1);//车辆起始与终点位置
        vector<P> que;//储存当前车的队列
        for(int k=1;k<=n;k++)
        {
            int op,a;
            cin>>op>>a;
            if(op==2)//l~r只可能停一辆车，因此标签唯一
            {
                auto st=find(que.begin(),que.end(),pos[a]);
                que.erase(st);
            }
            else
            {
                int l=0;//车尾坐标
                // 是首辆车
                if(que.empty())
                {
                    if(l+a<=L){
                        pos[k]=P(l,l+a);
                        que.push_back(P(l,l+a));
                        cout<<l<<endl;
                    }
                    else cout<<-1<<endl;
                    continue;

                }
                bool flag=false;
                // 判断能不能插到在这辆车后边
                for(int i=0;i<(int)que.size();i++)
                    if(l+a+f<=que[i].x){//保证这辆车在自己前面f处
                        flag=true;
                        pos[k]=P(l,l+a);
                        que.insert(que.begin()+i,P(l,l+a));
                        break;
                    }
                    else{
                        l=que[i].y+b;//保证距离前一辆车b
                        continue;
                    }
                if(l+a<=L){//判断能不能停到最后面
                    flag=true;
                    pos[k]=P(l,l+a);
                    que.push_back(P(l,l+a));
                }
                if(flag==true) cout<<pos[k].x<<endl;
                else cout<<-1<<endl;
            }
        }

    }

    return 0;
}
