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

int maxLcsplenth(string &str)
{
    if(str.length()==0) return 0;
    int len=str.length()*2+1;
    vector<int> p(len+5);
    vector<char> s(len+5);
    int index=0;
    for(int i=1;i<=len;i++)
        s[i]=(i&1)?'#':str[index++];
    
    int C=-1,R=-1;
    int ans=0;
    for(int i=1;i<=len;i++)
    {
        p[i]=i>R?1:min(R-i,p[2*C-i]);
        while(i+p[i]<=len and i-p[i]>=1)
        {
            if(s[i+p[i]]==s[i-p[i]]) p[i]++;
            else break;
        }

        if(i+p[i]>R){
            R=i+p[i];
            C=i;
        }
        ans=max(ans,p[i]-1);
    }
    return ans;
}