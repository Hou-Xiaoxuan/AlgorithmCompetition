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
//博弈论，题解：https://www.cnblogs.com/qingjiuling/p/11535957.html
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
        int sum1,sum2,cnt1,cnt2;
        sum1=sum2=cnt1=cnt2=0;
        vector<char> a(n+1);
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n/2;i++)
        {
            if(a[i]=='?') cnt1++;
            else sum1+=a[i]-'0';
        }
        for(int i=n/2+1;i<=n;i++)
        {
            if(a[i]=='?') cnt2++;
            else sum2+=a[i]-'0';
        }
        // 开始烧脑了
        if(sum1==sum2){
            if(cnt1==cnt2) cout<<"Bicarp"<<endl;
            else cout<<"Monocarp"<<endl;
            continue;      
        }

        if(sum1>sum2)
            swap(sum1,sum2),swap(cnt1,cnt2);
        // 保证sum1<sum2
        int sub=sum2-sum1;
        if(cnt1<cnt2) cout<<"Monocarp"<<endl;//本来就小，还没有空位，肯定GG
        else
        {
            int tree=cnt1-cnt2;//有空位的话，就看插值是否是9的num/2倍（因为后手只能保证和为9，其他的都不能控制）
            if(sub*2==9*tree) cout<<"Bicarp"<<endl;//the number of ? is even 
            else cout<<"Monocarp"<<endl;
        }
    }
    return 0;
}
