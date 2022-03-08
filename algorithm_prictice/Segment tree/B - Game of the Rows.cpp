//到都是这道题不简单，还是我的成都太差？
//现在竟然还有些控制不知先去看小说，太差劲了。
//啊啊啊啊啊啊啊
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int row[5],rest[5];
bool solve(int m)
{
	while (m--)
	{
		int x; scanf("%d", &x);
		while (x > 2)
		{
			if (row[4])
				row[4]--, x -= 4;
			else if (row[2])
				row[2]--, x -= 2;
			else {
				printf("NO\n");
				return false;
			}
		}
		if (x>0)
			rest[x]++;
		
	}
	return true;
}
int main()
{
	//freopen("C:/Users/94726/Desktop/in.txt", "r", stdin);
	int n, m; 
	while (scanf("%d %d", &n, &m) != EOF)
	{
		memset(rest, 0, sizeof(rest));
		memset(row, 0, sizeof(row));
		row[2] = n << 1; row[4] = n;
		if (solve(m) == false)
			continue;
		while (rest[2]--)
		{
			if (row[4])
				row[4]--, row[1]++;
			else if (row[2])
				row[2]--;
			else
				rest[1] += 2;
		}
		if (rest[1] <= row[1]+row[2] + row[4] * 2)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}