#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_p make_pair
#define   P  pair<double,double>
#define x first
#define y second 
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
// 补题：要判断是否可以组成三角形
double sss(pair<double,double>a,pair<double,double>b,pair<double,double> p)
{
    return (a.first-p.first)*(b.second-p.second)-(a.second-p.second)*(b.first-p.first);
}

string castMagic(vector<vector<int>> &triangle, vector<int> &point) {

    pair<double,double> a=make_pair(triangle[0][0],triangle[0][1]);
    pair<double,double> b=make_pair(triangle[1][0],triangle[1][1]);
    pair<double,double> c=make_pair(triangle[2][0],triangle[2][1]);
    pair<double,double> p=make_pair(point[0],point[1]);

    if(b.first*a.second==b.second*a.first and b.first*c.second==b.second*c.first) return "No";
    double ba=sss(a,b,p);
    double bb=sss(b,c,p);
    double bc=sss(c,a,p); 
    if(ba>=0 and bb>=0 and bc>=0 or ba<=0 and bc<=0 and bb<=0) return "Yes";
    else return "No";
}

int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\algorithm_contest\\out.txt","w",stdout);
    freopen("D:\\CODE\\algorithm_contest\\in.txt","r",stdin);  
    #endif
    int cnt=1e9-1;
    vector< vector<int> > t={{2,0},{0,0},{1,1}};
    vector<int> a={2,1};
    cout<<castMagic(t,a)<<endl;
   
    return 0;
}