//求面积公式+极角排序+皮克定理
//#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstdio>
#include<vector>
using namespace std;

class point
{
public:
    int x,y;
    point(int a=0,int b=0):x(a),y(b){};
    friend double dot(point &a,point &b){
        return a.x*b.x+b.y*a.y;
    }//点积
    friend double det(point &a,point &b){
        return a.x*b.y-b.x*a.y;
    }//叉积
};
int gcd(int x, int y){
    return (!y) ? x : gcd( y, x % y );
}
int aabs(int x){
    return x>0?x:-x;
}
int main()
{
    int T;cin>>T;
    for(int i=1;i<=T;i++)
    {
        int n;cin>>n;
        vector<point> nod(n+1);
        int x,y;
        int s=0,tree=0;
        double S=0;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            s+=gcd(aabs(x),aabs(y));
            nod[i].x=x+nod[i-1].x;
            nod[i].y=y+nod[i-1].y;
        }
        for(int i=1;i<=n;i++){
            S+= det(nod[i-1],nod[i])/2;//不可取绝对值，因为存在“负面积”；
           // cout<<":"<<det(nod[i-1],nod[i])/2<<endl;
        }
        tree=S-s/2+1;
        cout<<"Scenario #"<<i<<":"<<endl;
        cout<<tree<<" "<<s<<" "<<fixed<<setprecision(1)<<fabs(S)<<endl<<endl;
    }
    return 0;
}
