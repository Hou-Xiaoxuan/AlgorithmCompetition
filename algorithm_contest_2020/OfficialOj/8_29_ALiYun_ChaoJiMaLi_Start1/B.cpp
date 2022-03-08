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

int solution()
{
    vector<int> lengths={2,3,3,3};
    sort(lengths.begin(),lengths.end());
    int cnt=1;
    int ans=2;
    for(int i=0;i<lengths.size();i++)
    {
        if(lengths[i]==lengths[i-1]){
            cnt++;
            if(cnt==3){
                ans=0;
                break;
            }
            if(cnt==2)
            {
                ans=min(ans,1);
            }
        }
        else
        {
            cnt=1;
            for(int j=i+1;j<=lengths.size() and lengths[j]<=2*lengths[i];j++)
                if(lengths[j]==2*lengths[i])
                    ans=min(ans,1);
        }
    }
    return ans;
}

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    cout<<solution()<<endl;
    return 0;
}