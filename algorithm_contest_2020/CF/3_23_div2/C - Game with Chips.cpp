#include<bits/stdc++.h>
using namespace std;
//�Ҹ�������������õ�һ�ٷ֡�������
//���⣺ʲôħ��˼·�����������ݶ����ö���
//2*m*n�ܴ����ԣ������е㼯�е�һ�㣬�ڱ�������n-1 m-1 m*n������
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