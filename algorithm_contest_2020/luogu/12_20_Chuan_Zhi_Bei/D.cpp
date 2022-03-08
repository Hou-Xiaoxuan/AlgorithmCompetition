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

    int n;
    while(cin>>n)
    {
        vector<string> lis;
        string com,file;
        while(n--)
        {
            cin>>com;
            if(com=="ls")
            {
                for(auto &st:lis)
                {
                    cout<<st<<endl;
                }
            }
            else
            {
                cin>>file;
                if(com=="touch")
                {
                   auto index=find(lis.begin(),lis.end(),file);
                   if(index==lis.end())
                   {
                       lis.push_back(file);
                   }
                }
                else if(com=="rename")
                {
                    auto index=find(lis.begin(),lis.end(),file);
                    if(index!=lis.end())
                    {
                        cin>>file;
                        *index=file;
                    }
                }
                else if(com=="rm")
                {
                    auto index=find(lis.begin(),lis.end(),file);
                    if(index!=lis.end())
                        lis.erase(index);
                }
            }
        }
    }
    return 0;
}
