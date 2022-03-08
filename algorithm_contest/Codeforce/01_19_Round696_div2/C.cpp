#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define x first
#define y second 
using namespace std;
using LL=long long;
using ULL=unsigned long long;
using P=pair<int,int>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;

// 补题了！最终要的一点，每次必须选择当前的最大值，否则最大值就不可能被消除了。
int main()
{
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    int t;
    const int N=1e6;
    vector<int> num(N+5,0);
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        vector<int> a((n<<1)|1);
        for(int i=1;i<=n*2;i++){
            cin>>a[i];
            num[a[i]]++;
        }
        sort(a.begin(),a.end());
        vector<int> ans;//储存配对信息;
        for(int x=1;x<n*2;x++)
        {
            // 枚举与最大值结合的数字x;
            int target=a[2*n];
            ans.push_back(a[x]); num[a[x]]--;
            ans.push_back(a[2*n]); num[a[2*n]]--;
            for(int k=2*n-1;k>=1;k--)
            {
                if(num[a[k]]<=0) continue;
                ans.push_back(a[k]); num[a[k]]--;
                if(num[target-a[k]]<=0) break;
                ans.push_back(target-a[k]); num[target-a[k]]--;
                target=max(a[k],target-a[k]);
            }
            if(ans.size()==n*2){
                // 得到结果了
                break;
            }
            else{
                for(auto val:ans) num[val]++;
                ans.clear();
            }
        }
        if(ans.size()==2*n)
        {
            cout<<"YES"<<endl;
            cout<<ans[0]+ans[1]<<endl;
            for(int i=0;i<ans.size();i++)
                cout<<ans[i]<<" \n"[i&1];
        }
        else{
            cout<<"NO"<<endl;
            for(auto val:ans) num[val]++;
            for(auto val:a) num[val]--;
        }

    }
    return 0;
}
