#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
#define  m_k make_pair
#define   P  pair<int,int>
#define I (#ifdef  _DEBUG)
#define E #endif
typedef long long LL;
typedef unsigned long long ULL;
const int inf=0x3f3f3f3f;
double f1[105][105][105],f2[105][105][105],f3[105][105][105];
int main()
{
    IOS;
    #ifdef _DEBUG
    freopen("D:\\CODE\\code_prictice\\out.txt","w",stdout);
    freopen("D:\\CODE\\code_prictice\\in.txt","r",stdin);  
    #endif
    int a,b,c;
    while(cin>>a>>b>>c)
    {
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));
        memset(f3,0,sizeof(f3));
        for(int i=1;i<=a;i++) f1[i][0][0]=1;
        for(int i=1;i<=b;i++) f2[0][i][0]=1;
        for(int i=1;i<=c;i++) f3[0][0][i]=1;

        for(int i=0;i<=a;i++)
        for(int j=0;j<=b;j++)
        for(int k=0;k<=c;k++)
        {
            double p1=0,p2=0,p3=0;
            if(i and i+j+k>=2) {
                p1=2.0*i*k/(double(i+j+k)*(i+k+j-1));
            #ifdef _DEBUG
                cout<<"i-1:"<<i<<" "<<j<<" "<<k<<" "<<p1<<endl; 
            #endif
                f1[i][j][k]+=p1*f1[i-1][j][k];
                f2[i][j][k]+=p1*f2[i-1][j][k];
                f3[i][j][k]+=p1*f3[i-1][j][k];
            }
            
            if(j and i+j+k>=2) {
                p2=2.0*i*j/(double(i+j+k)*(i+k+j-1));
            #ifdef _DUBGE
                cout<<"j-1:"<<i<<" "<<j<<" "<<k<<" "<<p2<<endl;
            #endif
                f1[i][j][k]+=p2*f1[i][j-1][k];
                f2[i][j][k]+=p2*f2[i][j-1][k];
                f3[i][j][k]+=p2*f3[i][j-1][k];
            }
            if(k and i+j+k>=2) {
                p3=2.0*j*k/(double(i+j+k)*(i+k+j-1));
            #ifdef _DEBUG
            cout<<"k-1:"<<i<<" "<<j<<" "<<k<<" "<<p3<<endl;
            #endif
                f1[i][j][k]+=p3*f1[i][j][k-1];
                f2[i][j][k]+=p3*f2[i][j][k-1];
                f3[i][j][k]+=p3*f3[i][j][k-1];
            }
            if(p1+p2+p3>0){
                f1[i][j][k]/=(p1+p2+p3);
                f2[i][j][k]/=(p1+p2+p3);
                f3[i][j][k]/=(p1+p2+p3);
            }
        }
        printf("%.12f %.12f %.12f\n",f1[a][b][c],f2[a][b][c],f3[a][b][c]);
        cout<<endl;
    }

    return 0;
}