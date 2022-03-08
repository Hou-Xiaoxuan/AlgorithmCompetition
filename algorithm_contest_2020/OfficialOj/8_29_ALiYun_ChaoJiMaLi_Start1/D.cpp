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

int solotion(string & s)
{
    long long ans=0;
    
    for(int i=0;i<s.size();i++)
    {
        int l=i,r=i+1;
        long long num=0;
        bool conti=true;
        while(l>=0 and r<s.size())
        {
            num++;
            if(s[l]==s[r])
            {
                if(conti==true)
                    ans+=num*2;
                else
                    ans+=num; 
            }
            else
            {
                conti=false;
                num=0;
            }
            l--;r++;
        }

        l=r=i;
        num=0;
        conti=true;
        while(l>=0 and r<s.size())
        {
            num++;
            if(s[l]==s[r])
            {
                if(conti==true)
                    ans+=num*2-1;
                else  
                    ans+=num;
            }
            else
            {
                conti=false;
                num=0;
            }    
            l--;r++;     
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
    
    
    return 0;
}