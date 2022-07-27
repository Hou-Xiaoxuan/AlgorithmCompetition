/*
 * @Author: linxuan
 * @Date: 2022-07-12 19:12:26
 * @Description: 时间不够没能交
 * @FilePath: /Algorithm/algorithm_contest_2022/BUAA-MT/H.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <ctype.h>
int H[205][205];
int color[205][105];
// 一个队列
typedef struct{
    int x, y;
    struct Node *next;
} Node;
typedef struct
{
    int size;
    Node *head;
    Node *tail;
} Queue;
void push(Queue *que, int x, int y)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    if(que->size == 0)
    {
        que->head = node;
        que->tail = node;
    }
    else
    {
        que->tail->next = node;
        que->tail = node;
    }
    que->size++;
}
Node pop(Queue *que)
{
    Node *node = que->head;
    que->head = que->head->next;
    que->size--;
    Node ret = *node;
    free(node);
    return ret;
}
bool empty(Queue *que)
{
    return que->size == 0;
}
int min(int a, int b){
    return a < b ? a : b;
}
// vis
bool vis[205][205];
int n, m;
void fillborder()
{
    // bfs将边界的0标记
    Queue que;
    que.size = 0;
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; i++){
        push(&que, i, 0);
        push(&que, i, m+1);
    }
    for(int i=1; i<=m; i++){
        push(&que, 0, i);
        push(&que, n+1, i);
    }
    while(!empty(&que))
    {
        Node node = pop(&que);
        int x = node.x, y = node.y;
        if(vis[x][y]) continue;
        vis[x][y] = 1;
        // 越界或不为0
        if(x < 0 || x > n + 1 || y < 0 || y > m + 1 || H[x][y] != 0) continue;
        color[x][y] = -1;
        push(&que, x-1, y);
        push(&que, x+1, y);
        push(&que, x, y-1);
        push(&que, x, y+1);
    }
}
void fill(int x, int y, int h)
{
    memset(vis, 0, sizeof(vis));
    Queue que;
    que.size = 0;
    push(&que, x, y);
    if(color[x][y] == -1 || h == 0) return;
    else color[x][y] = h;
    while(empty(&que) == false)
    {
        Node node = pop(&que);
        int x = node.x;
        int y = node.y;
        if(vis[x][y] == true) continue;
        vis[x][y] = true;
        // 遍历周围4各点
        if(x-1 >= 0 && H[x-1][y] < h && color[x-1][y] != -1){
            if(color[x-1][y] == 0) color[x-1][y] = h;
            else color[x-1][y] = min(h, color[x-1][y]);
            push(&que, x-1, y);
        }
        if(x+1 <= n && H[x+1][y] < h && color[x+1][y] != -1){
            if(color[x+1][y] == 0) color[x+1][y] = h;
            else color[x+1][y] = min(h, color[x+1][y]);
            push(&que, x+1, y);
        }
        if(y-1 >= 0 && H[x][y-1] < h && color[x][y-1] != -1){
            if(color[x][y-1] == 0) color[x][y-1] = h;
            else color[x][y-1] = min(h, color[x][y-1]);
            push(&que, x, y-1);
        }
        if(y+1 <= m && H[x][y+1] < h && color[x][y+1] != -1){
            if(color[x][y+1] == 0) color[x][y+1] = h;
            else color[x][y+1] = min(h, color[x][y+1]);
            push(&que, x, y+1);
        }
    }
}
int main()
{
    # ifdef _DEBUG
    freopen("in.txt", "r", stdin);
    # endif

    scanf("%d %d", &n, &m);
    memset(H, 0, sizeof(H));
    memset(color, 0, sizeof(color));
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d", &H[i][j]);
        }
    }
    fillborder();
    for(int i=1; i<=n ;i++)
    {
        for(int j=1; j<=m; j++)
        {
            fill(i, j, H[i][j]);
        }
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(color[i][j] != -1)
            {
                ans+= color[i][j] - H[i][j];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
