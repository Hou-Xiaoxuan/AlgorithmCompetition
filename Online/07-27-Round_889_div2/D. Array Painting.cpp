#ifndef _USE_MATH_DEFINES
 #define _USE_MATH_DEFINES
#endif
#include <bits/stdc++.h>
#define IOS                   \
 ios::sync_with_stdio(false); \
 cin.tie(0);                  \
 cout.tie(0);
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;
using LD = long double;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const LL LLinf = 0x3f3f3f3f3f3f3f3f;
/*补题，做复杂了。能消就消地贪心就可以了*/
int main()
{
    IOS;
#ifdef _DEBUG
    // freopen("out.txt","w",stdout);
    freopen("in.txt", "r", stdin);
#endif

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    struct Seg {
        int num;
        int cnt;
    };
    vector<vector<Seg>> segs_group;
    bool have_two;
    vector<Seg> segs;
    Seg seg_now {-1, 0};
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (seg_now.num == -1)    // start
        {
            seg_now.num = a[i] > 0;
            seg_now.cnt = 1;
            have_two = a[i] == 2;
            continue;
        }

        if (seg_now.num > 0 and a[i] > 0)
        {
            if (a[i] == 2)
                have_two = true;
            seg_now.cnt++;
        }
        else if (seg_now.num == 0 and a[i] == 0)
        {
            seg_now.cnt++;
        }
        else if (seg_now.num > 0 and a[i] == 0)
        {
            if (have_two)
            {
                // 截断seg, 该seg不用加入segs, 截断segs
                ans++;
                if (not segs.empty())
                {
                    segs.back().cnt--;    // 前面的0 - 1
                    if (segs.back().cnt == 0)
                        segs.pop_back();
                }
                if (not segs.empty())
                    segs_group.push_back(segs);
                segs.clear();
            }
            else
            {
                // 截断seg，加入segs
                i--;
                segs.push_back(seg_now);
            }
            seg_now = {-1, 0};
        }
        else if (seg_now.num == 0 and a[i] > 0)
        {
            // 截断，不加入seg
            segs.push_back(seg_now);
            i--;    // 重新处理a[i]
            seg_now = {-1, 0};
        }
    }
    if (seg_now.num != -1)
        segs.push_back(seg_now);
    if (not segs.empty())
        segs_group.push_back(segs);

    for (auto &segs : segs_group)
    {
        for (int i = 0; i < segs.size(); i++)
        {
            if (segs.empty())
                continue;
            // 1 0 1 0 or 0 1 0 and 1 0 1 三种情况，处理ans
            if (segs[i].num > 0)
            {
                if (i > 0 and segs[i - 1].num == 0 and segs[i - 1].cnt > 0)
                    segs[i - 1].cnt--;
                else if (i + 1 < segs.size() and segs[i + 1].num == 0 and segs[i + 1].cnt > 0)
                    segs[i + 1].cnt--;
            }
        }
        for (auto &seg : segs)
        {
            if (seg.num == 0)
                ans += seg.cnt;
            else
                ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}