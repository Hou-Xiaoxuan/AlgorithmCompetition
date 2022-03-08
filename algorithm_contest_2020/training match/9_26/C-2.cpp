#include <bits/stdc++.h>
#define fast_io                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const int N = (int)1e5 + 5;
const int M = (int)1e5 + 5;
const int mod = (int)1e9 + 7;
const double esp = 1e-15;//精度绝对已经道极限了……
//------------------------------
struct Node {
    double k;
    double b;
} l[N];
vector<int> vec;
int main() {
    int t, n;
    double a, b, c, d;
    ll ans;
        #ifdef _DEBUG
        freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
        freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);
        #endif
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ll num = 0;
        vector<int>().swap(vec);
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
            if (c == a) {
                vec.push_back((int)c);
            } else {
                l[num].k = (d - b) / (c - a);
                l[num].b = -l[num].k * a + b;
                ++num;
            }
        }
        sort(l, l + num, [](Node &a, Node &b) {
            if (fabs(a.k - b.k) < esp)
                return a.b < b.b;
            return a.k < b.k;
        });
        sort(vec.begin(), vec.end());
        ll cnt = 1;
        ans = num * (num - 1) / 2;
        ans += num * ll(vec.size());
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] != vec[i - 1])
                ans += cnt * (cnt - 1) / 2, cnt = 1;
            else
                ++cnt;
        }
        ans += cnt * (cnt - 1) / 2, cnt = 1;
        for (int i = 1; i < num; ++i)
        {
            if (fabs(l[i].k - l[i - 1].k) < esp)
            {
                if(fabs(l[i].b - l[i - 1].b) > esp)
                    ++cnt;
                else
                    ans -= cnt * (cnt - 1) / 2, cnt = 1;
            }
            else
                ans -= cnt * (cnt - 1) / 2, cnt = 1;
        }
        ans -= cnt * (cnt - 1) / 2, cnt = 1;
        printf("%lld\n", ans);
    }
    return 0;
}