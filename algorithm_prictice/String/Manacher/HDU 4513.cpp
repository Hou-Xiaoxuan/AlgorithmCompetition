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

// 鬼知道为什么WA，全部重写吧~
// 马拉车模板变式，要求递增
// int maxLcsplenth(const string str)
// {
//     if(str.length()==0) return 0;
//     int len=str.length()*2+1;
//     vector<int> p(len+5);
//     vector<char> s(len+5);
//     int index=0;
//     for(int i=1;i<=len;i++)
//         s[i]=(i&1)?'#':str[index++];
    
//     int id=0;
//     int ans=0;
//     for(int i=1;i<=len;i++)
//     {
//         if(id+p[id] > i)
//             p[i] = min(p[id-(i-id)], p[id]-(i-id));
//         else
//             p[i] = 1;
//         if(p[i]==0) p[i]=1; 
//         while(i+p[i]<=len and i-p[i]>=1)
//         {
//             if(s[i+p[i]]==s[i-p[i]] and s[i-p[i]]<=s[i-p[i]+2])
//                 p[i]++;
//             else break;
//         }

//         if(i+p[i]>id+p[id]){
//             id=i;
//         }
//         ans=max(ans,p[i]-1);
//     }
//     vector<int>().swap(p);
//     vector<char>().swap(s);
//     return ans;
// }
// char str[int(2e5)];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin); 
    #endif
    // 重写，鬼知道为什么过了
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        vector<int> a(n+1);
        for(int i=1;i<=n;i++) cin>>a[i];

        int len=2*n+1;
        vector<int> s(len+5),p(len+5);
        // 这里出了问题吗？？？？？
        // for(int i=1;i<=len;i++){
        //     s[i]= (i&1)==0?0:s[index++];
        // }
        // p[0]=-1;
        for(int i=1;i<=n;i++)
        {
            s[i<<1]=a[i];
            s[i<<1|1]=0;
        }
        s[1]=0;
        s[0]=-1;
        int id=0;
        int ans=-1;
        for(int i=2;i<=len;i++)
        {
            if(id+p[id]<i) p[i]=1;
            else p[i]=min(id+p[id]-i,p[2*id-i]);
            p[i]=max(p[i],1);
            while(s[i+p[i]]==s[i-p[i]] and s[i-p[i]]<=s[i-p[i]+2]) p[i]++;
            
            if(id+p[id]<i+p[i]) id=i;
            ans=max(ans,p[i]-1);

        }
        cout<<ans<<endl;
    }
    return 0;
}
