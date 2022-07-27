/*
 * @Author: linxuan
 * @Date: 2022-07-12 19:12:26
 * @Description: 排个序后，暴力可能可以 未知逻辑错误
 * @FilePath: /Algorithm/algorithm_contest_2022/BUAA-MT/F.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
typedef struct{
    int x;
    int y;
} Look;
int cmp(const void *a, const void *b) // 以维度增序、二维降序排序
{
    Look *aa = (Look *)a;
    Look *bb = (Look *)b;
    if(aa->x == bb->x) return bb->y - aa->y;
    else return aa->x - bb->x;
}
int a[10000 + 5];
Look pairs[10000 + 5];

int fill(int l, int r, int w){
    for(int i=l; i<=r; i++)
        a[i] = w;
}

int min(int x, int y){if(x>y) return y; else return x;}
int main()
{
    # ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    # endif

    int n, h, m;
    scanf("%d %d %d", &n, &h, &m);
    for(int i=1; i<=n; i++) a[i] = h;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b) {
            pairs[i].x = b;
            pairs[i].y = a;
        } else{
            pairs[i].x = a;
            pairs[i].y = b;
        }
    }
    qsort(pairs, m, sizeof(Look), cmp);
    for(int i=1; i<=m; i++)
    {
        // 跳过重复
        if(i > 1 && pairs[i].x == pairs[i-1].x && pairs[i].y == pairs[i-1].y) continue;

        int l = pairs[i].x, r = pairs[i].y;

        fill(l+1, r-1, min(a[l], a[r]) - 1);
        
    }
    for(int i=1; i<=n; i++){
        printf("%d\n", a[i]);
    }
    return 0;
}
