#include<bits/stdc++.h>
using namespace std;
//我个垃圾，这他妈得掉一百分…………
//补题：什么魔鬼思路？？？连数据都不用读入
//2*m*n很大，所以，把所有点集中到一点，在遍历即可n-1 m-1 m*n不超过
int main()
{
    int n,m;cin>>n>>m;
    cout<<n-1+m-1+m*n-1<<endl;
    for(int i=1;i<n;i++) cout<<'U';
    for(int j=1;j<m;j++) cout<<'R';
    for(int i=1;i<=m;i++){
        for(int j=1;j<n;j++)
            if(i&1) cout<<'D';
            else cout<<'U';
        if(i<m) cout<<'L';
    }
    return 0;
}