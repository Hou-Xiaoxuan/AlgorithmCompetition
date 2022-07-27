/*
 * @Author: linxuan
 * @Date: 2022-07-12 19:12:26
 * @Description: 并查集
 * @FilePath: /Algorithm/algorithm_contest_2022/BUAA-MT/D.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>

// 并查集
int fa[200000+5];
int get_father(int x)
{
    if (fa[x] == x) return x;
    else{
        fa[x] = get_father(fa[x]);
        return fa[x];
    }
}
int unio(int x, int y)
{
    int a = get_father(x);
    int b = get_father(y);
    fa[a] = b;
    if(a==b) return false;
    else return true;
}
int main()
{
    # ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    # endif
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++){
        fa[i] = i;
    }
    while(m--)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if(op==1) // 加边
        {
            unio(x, y);

        } else if(op==2) // 询问
        {
            int a = get_father(x);
            int b = get_father(y);
            if(a==b) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
