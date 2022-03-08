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
using P=pair<LL,LL>;
const int inf=0x3f3f3f3f;
const LL LLinf=0x3f3f3f3f3f3f3f3f;
// AC

const vector<vector<LL>> multi(const vector<vector<LL>>&a,const vector<vector<LL>>&b,const LL n=3)//矩阵相乘
{
    vector<vector<LL>> ret(n,vector<LL>(n,0));
    // k,i,j,最优locality~
    for(LL k=0;k<n;k++)
        for(LL i=0;i<n;i++)
        {
            LL tmp=a[i][k];
            for(LL j=0;j<n;j++)
                ret[i][j]+=tmp*b[k][j];
        }
    return ret;
};
void prLL(vector<LL> dot,vector<vector<LL>> Q){
    LL x=dot[0]*Q[0][0]+dot[1]*Q[1][0]+dot[2]*Q[2][0];
    LL y=dot[0]*Q[0][1]+dot[1]*Q[1][1]+dot[2]*Q[2][1];
    cout<<x<<" "<<y<<endl;
}
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("D:/CODE/algorithm_contest/in.txt","r",stdin);  
    #elif _LINUX
    freopen("/media/linxuan/储存/CODE/algorithm_contest/out.txt","w",stdout);
    freopen("/media/linxuan/储存/CODE/algorithm_contest/in.txt","r",stdin);
    #endif
    
    LL n;
    cin>>n;
    vector<vector<LL> > a(n+1,vector<LL>(3,1));
    for(LL i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
    }

    /*q次操作*/
    LL q;
    cin>>q;
    //初始化方阵 
    vector< vector<vector<LL>> > Q(q+1,vector<vector<LL>>(3,vector<LL>(3,0)));//累计的右乘
    vector<vector<LL>> ope1(3,vector<LL>(3,0)),ope2(3,vector<LL>(3,0)),\
    ope3(3,vector<LL>(3,0)),ope4(3,vector<LL>(3,0));//四种操作
    Q[0][0][0]=Q[0][1][1]=Q[0][2][2]=1;
    ope1[1][0]=ope1[2][2]=1,ope1[0][1]=-1;//顺时针
    ope2[0][1]=ope2[2][2]=1,ope2[1][0]=-1;//逆时针

    ope3[1][1]=ope3[2][2]=1,ope3[0][0]=-1;//x=p对称
    ope4[0][0]=ope4[2][2]=1,ope4[1][1]=-1;//y=p对称
    for(LL i=1;i<=q;i++)
    {
        LL lab,p;
        cin>>lab;
        if(lab==1){
            Q[i]=multi(Q[i-1],ope1);
        }
        else if(lab==2){
            Q[i]=multi(Q[i-1],ope2);
        }
        else if(lab==3){
            cin>>p;
            ope3[2][0]=2*p;
            Q[i]=multi(Q[i-1],ope3);
        }
        else if(lab==4){
            cin>>p;
            ope4[2][1]=2*p;
            Q[i]=multi(Q[i-1],ope4);
        }
    }

    /*m 次 询问*/
    LL m;
    cin>>m;
    while(m--)
    {
        LL A,B;
        cin>>A>>B;
        prLL(a[B],Q[A]);
    }
    return 0;
}
