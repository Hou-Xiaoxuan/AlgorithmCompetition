#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
typedef long long LL;
const long long inf=2147483648;
int main()
{
    int n;
    while(cin>>n)
    {
        /*虽然过了，其实是因为数据里面没有0*//*
        if(n)    cout<<inf*2<<endl;
        else     cout<<(inf-1)*2<<endl;*/
        /*correct*/
        cout<<inf*2<<endl;
    }
    return 0;
}