#include <bits/stdc++.h>
#define fast_io                                                                \
    ios::sync_with_stdio(false);                                               \
    cin.tie(0)
using namespace std;
using LL = long long;
using P = pair<int, int>;
const int inf = 0x3f3f3f3f;
const int N = (int)1e5 + 5;
const int M = (int)1e5 + 5;
const int mod = (int)1e9 + 7;
const double esp = 1e-8;
// 这一遍是能过的，之前的都过不了
//------------------------------
LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
};
struct node //分数a/b
{
    node(LL aa = 0, LL bb = 1) : a(aa), b(bb) {
        div();
    };
    LL a;
    LL b;
    void div() {
        LL d = gcd(a, b);
        a /= d;
        b /= d;
    }
    bool operator<(const node &s) const {
        return a * s.b - b * s.a < 0;
    }
    bool operator==(const node &s) const {
        return a == s.a && b == s.b;
    }
    node operator*(const node &s) const {
        node st(a * s.a, b * s.b);
        return st;
    }
    node operator-(const node &s) const {
        node st(a * s.b - b * s.a, b * s.b);
        return st;
    }
    node operator+(const node &s) const {
        node st(a * s.b + b * s.a, b * s.b);
        return st;
    }
};
struct Node {
    node k;
    node b;
} l[N];
vector<int> vec;
int main()
{

    
    LL t, n;
    LL a, b, c, d;
    LL ans;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        LL num = 0;
        vector<int>().swap(vec);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d %d", &a, &b, &c, &d);
            if (c == a) {
                vec.push_back(c);
            } else {
                l[num].k.a = b - d;
                l[num].k.b = a - c;
                l[num].k.div();
                l[num].b = l[num].k * node(-1, 1) * node(a, 1) + node(b, 1);
                ++num;
            }
        }
        sort(l, l + num, [](const Node &a, const Node &b) {
            if (a.k == b.k)
                return a.b < b.b;
            return a.k < b.k;
        });
        sort(vec.begin(), vec.end());
        LL cnt = 1;
        ans = num * (num - 1) / 2;
        ans += num * (vec.size());
        for (int i = 1; i < vec.size(); ++i) {
            if (vec[i] != vec[i - 1])
                ans += cnt * (cnt - 1) / 2, cnt = 1;
            else
                ++cnt;
        }
        ans += cnt * (cnt - 1) / 2, cnt = 1;
        for (int i = 1; i < num; ++i) {
            if (l[i - 1].k == l[i].k) {
                LL flag = 1;
                cnt = 1;
                for (i; i < num && l[i - 1].k == l[i].k; ++i) {
                    cnt++;
                    if (l[i - 1].b == l[i].b)
                        flag++;
                    else
                        ans += flag * (flag - 1) / 2, flag = 1;
                }
                ans += flag * (flag - 1) / 2, flag = 1;
                ans -= cnt * (cnt - 1) / 2;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}