#include<algorithm>
#include<cmath>
using namespace std;
const int N=1e6+5;
int st_max[N][20];
int st_min[N][20];
int a[N];
void initiate(int n)
{
    for(int i=1;i<=n;i++) st_max[i][0]=st_min[i][0]=a[i];
    for(int j=1;1<<j<=n;j++)
        for(int i=1;i+(1<<j)-1<=n;j++)
        {
            st_max[i][j]=max(st_max[i][j-1],st_max[i+(1<<(j-1))][j-1]);
            st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<(j-1))][j-1]);
        }
}
int search_min(int x,int y){
    int k=log(double(y-x+1))/log(2.0);
    return min(st_min[x][k],st_min[y-(1<<k)+1][k]);
}
int search_max(int x,int y){
    int k=log(double(y-x+1))/log(2.0);
    return max(st_max[x][k],st_max[y-(1<<k)+1][k]);
}