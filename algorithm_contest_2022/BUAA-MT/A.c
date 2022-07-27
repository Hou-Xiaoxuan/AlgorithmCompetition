/*
 * @Author: linxuan
 * @Date: 2022-07-12 19:12:26
 * @Description: file content
 * @FilePath: /Algorithm/algorithm_contest_2022/BUAA-MT/A.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
int a[200000+5];
int main()
{
    # ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    # endif
    
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &a[i]);
        }
        int cnt[2] = {0, 0};
        for(int i=1; i<=n; i++)
        {
            int l=i*2 , r=i*2+1;
            if((l>n || a[i] >= a[l]) && (r>n || a[i] >= a[r]))
            {
                cnt[0]++;
            }
            if((l>n || a[i] <= a[l]) && (r>n || a[i] <= a[r]))
            {
                cnt[1]++;
            }
        }
        if(cnt[0] == n ){
            printf("Max heap\n");
        } else if(cnt[1] == n){
            printf("Min heap\n");
        } else{
            printf("Not a heap!\n");
        }
    }
    return 0;
}
