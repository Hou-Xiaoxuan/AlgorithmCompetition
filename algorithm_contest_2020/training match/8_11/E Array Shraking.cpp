#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
//#include<bits/stdc++.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<cstring>
#include<cstdio>
#include<queue>
#include<stack>
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
        vector<int> a(n);
        for(int i=0;i<n;i++) cin>>a[i];

        bool flag=true;
        while(flag==true)
        {
            flag=false;
            for(int i=0;i<n;i++)
            {
                int cnt=1;
                while(i+cnt<n and a[i]==a[i+cnt]) cnt++;
                if(cnt==1) continue;

                // if(cnt%2==0)
                // {
                //     for(int j=i;j<=i+cnt-1 and j<n;j+=2){
                //         a[j]++;
                //         a.erase(a.begin()+j+1);
                //         n--;
                //     }
                //     flag=true;
                // }
                // else
                {
                    if(i-1>0 and a[i-1]==a[i]+1){
                        a[i]++;
                        a.erase(a.begin()+i+1);
                        n--;
                    }
                    else if(i+cnt<n and a[i+cnt]==a[i+cnt-1]+1){
                        a[i+cnt-1]++;
                        a.erase(a.begin()+i+cnt-2);
                        n--;
                    }
                    else{
                        a[i]++;
                        a.erase(a.begin()+i+1);
                        n--;
                    }
                    flag=true;
                }
            }
        }
        cout<<a.size()<<endl;
    }
    return 0;
}