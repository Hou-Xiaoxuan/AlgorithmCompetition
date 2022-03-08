#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
pair<int,int> a[N];
int main()
{
    int n;
    scanf("%d",&n);
    {
        int r1=-1,r2=-1;
        bool flag=true;
        for(int i=1;i<=n;i++)
        { 
            scanf("%d %d",&a[i].first,&a[i].second);
            if(a[i].first>r1) r1=a[i].second;
            else if(a[i].first>r2) r2=a[i].second;
            else flag=false;
        }
        if(flag)    printf("yes\n");
        else    printf("no\n");
    }
    return 0;
}

/*
 
*/