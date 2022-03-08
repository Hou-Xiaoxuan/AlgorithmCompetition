#include<bits/stdc++.h>
using namespace std;
#define m_p make_pair
#define P pair<int,int>
#define x first
#define y second
typedef long long LL;
const int inf=0x3f3f3f3f;
// 签到，A过
int main()
{
    #ifdef _DEBUG
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    #endif

    int t;cin>>t;
    while(t--)
    {
        map<char,int> cnt;
        cnt['A']=0;
        cnt['B']=0;
        cnt['G']=0;
        cnt['P']=0;
        
        int n,k;cin>>k>>n;//k轮，n个人
        vector<pair<char,int> > rec(n+1);
        for(int i=0;i<n;i++){
            rec[i]=m_p('A',0);
        }
        int ans=0;
        char ch;int x;
        for(int i=0;i<k;i++)
        {
            cin>>ch>>x;
            cnt[rec[i%n].first]-=rec[i%n].second;
            cnt[ch]+=x;
            rec[i%n]=m_p(ch,x);
            for(auto i:cnt)
            {
                if(i.second==5)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}