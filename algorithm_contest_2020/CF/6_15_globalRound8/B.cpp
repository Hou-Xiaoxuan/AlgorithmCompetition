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
//???????????
inline LL cont(vector<int> & s)
{
    LL cnt=1;
    for(int i=1;i<=10;i++)
        cnt*=s[i];
    return cnt;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_contest\\in.txt","r",stdin);  
    #endif
    
    LL k;
    char str[]=" codeforces";
    while(cin>>k)
    {
        vector<int> s(11);
        for(int i=1;i<=10;i++) s[i]=1;
        LL sum=cont(s);
        int m=1;
        while(sum<k){
            s[m++]++;
            if(m>10) m=1;
            sum=cont(s);
        }
        for(int i=1;i<=10;i++)
            for(int j=1;j<=s[i];j++)
                cout<<str[i];
        cout<<endl;
    }
    return 0;
}