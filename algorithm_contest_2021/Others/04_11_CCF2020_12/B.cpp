#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
#define m_p make_pair
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;
// 虽然过了，但是好麻烦啊……换一个编译器真的不一定可以打出来
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt", "w", stdout);
    freopen("D:/CODE/algorithm_contest/in.txt", "r", stdin);
    #endif
    int m;
    cin >> m;
    vector<P> a(m + 1);
    for (int i = 1; i <= m; i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin() + 1, a.end());
    int num_zero = 0;
    vector<int> cnt(m + 1);//不包含自己，左边由多少个0
    vector<int> num(m+1);//1~n,小于自己有几个数字
    map<int,int> cnt_zeros,cnt_one;
    for (int i = 1; i <= m; i++)
    {
        if(a[i].second==0){
            num_zero++;
            cnt_zeros[a[i].first]++;
            cnt_one[a[i].first]+=0;
        }
        else{
            cnt_one[a[i].first]++;
            cnt_zeros[a[i].first]+=0;
        } 
    }
    int n = cnt_one.size();
    auto it1 = cnt_one.begin(), it0 = cnt_zeros.begin();
    for(int i=2;i<=n;i++)
    {
        cnt[i]=cnt[i-1]+it0->second;
        num[i]=num[i-1]+it0->second+it1->second;
        it1++, it0++;
    }
    int value=0,ans;
    it1 = cnt_one.begin(), it0 = cnt_zeros.begin();
    for(int i=1;i<=n;i++)
    {

        int tmp_value = cnt[i] + (m - num[i] - num_zero + cnt[i]);//做0+右1-自0
        // cout<<"debug "<<it0->first<<" "<<tmp_value<<endl;
        if(value<=tmp_value){
            value = tmp_value;
            ans = it0->first;
        }
        it1++,it0++;
    }
    cout<<ans<<endl;
    return 0;
}
