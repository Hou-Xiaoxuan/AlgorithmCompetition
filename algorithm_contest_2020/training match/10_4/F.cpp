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
char str[int(2e6)+5];
const char harbin[]="harbin";
bool vis[256];
bool can[6][256];
// 不知道为什么没过的假算法
// bool dfs(int k)
// {
//     if(k==6){
//         for(auto i:harbin)
//             if(vis[i]==false) return false;
//         return true;
//     }
//     bool flag=false;
//     for(auto i:harbin)
//     {
//         if(can[k][i] and vis[i]==false)
//         {
//             vis[i]=true;
//             flag=dfs(k+1);
//             if(flag) return true;
//             vis[i]=false;
//         }
//     }
//     return false;
// }
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    int t;cin>>t;
    while(t--)
    {
        memset(can,0,sizeof(can));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<6;i++)
        {
            cin>>str;
            int len=strlen(str);
            for(int j=0;j<len;j++)
            {
                char ch=str[j];
                can[i][int(ch)]=true;
            }
        }

        // if(dfs(0)) cout<<"Yes"<<endl;
        // else cout<<"No"<<endl;
        char ord[6]={'a','b','h','j','n','r'};
        bool kk=false;
        while(1)
        {
            bool flag=true;
            for(int i=0;i<6;i++)
                if(!can[i][ord[i]]==true) flag=false;
            if(flag==true){
                cout<<"Yes";
                kk=true;
                break;
            }
            else if(!next_permutation(ord,ord+6))
                break;
        }
        if(kk==false) cout<<"No"<<endl;
    }
    return 0;
}