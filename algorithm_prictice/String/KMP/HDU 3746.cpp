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
// kmp的严重变形……如果不是kmp专题，真的不敢保证能做出来
// kmp[i]是最长的前缀匹配，去掉这一部分的话就是最长的独一无二部分
// 再也不想从0开始存字符串了
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    
    string p;
    int t;cin>>t;
    while(t--)
    {
        cin>>p;
        int len=p.size();
        vector<int> kmp(len*2+5);
       
        int j=-1;
        kmp[0]=-1;
        int minn=inf;//最小循环节
        for(int i=1;i<len;i++)
        {
            while(j>=0 and p[j+1]!=p[i]) j=kmp[j];
            if(p[j+1]==p[i]) j++;
            kmp[i]=j;
        }
        minn=len-kmp[len-1]-1;
        if(len%minn==0 and minn*2<=len) cout<<0<<endl;
        else cout<<(minn-len%minn)<<endl;
        // 不必这么麻烦，可以直接求最小循环节
        // int k=kmp[len-1];
        // for(int i=k+1;i<len-k-1;i++)
        // {
        //     p.push_back(p[i]);
        // }
        // int len2=len+len-k-1-k-1;
        // // cout<<p<<" "<<len2<<endl;
        // for(int i=len;i<len2;i++)
        // {
        //     while(j>=0 and p[j+1]!=p[i]) j=kmp[j];
        //     if(p[j+1]==p[i]) j++;
        //     kmp[i]=j;
        //     if((i+1)%(i-kmp[i])==0 and (i-kmp[i])*2<=i+1){
        //         cout<<i-len+1<<endl;
        //         break;
        //     }
        // }
        
    }
    return 0;
}