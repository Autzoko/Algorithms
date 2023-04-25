/*
题目描述
动物王国中有三类动物 A,B,C，这三类动物的食物链构成了有趣的环形。A 吃 B，B
吃 C，C 吃 A。
现有 N 个动物，以 1 － N 编号。每个动物都是 A,B,C 中的一种，但是我们并不知道
它到底是哪一种。
有人用两种说法对这 N 个动物所构成的食物链关系进行描述：
第一种说法是“1 X Y”，表示 X 和 Y 是同类。
第二种说法是“2 X Y”，表示 X 吃 Y 。
此人对 N 个动物，用上述两种说法，一句接一句地说出 K 句话，这 K 句话有的是真
的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
• 当前的话与前面的某些真的话冲突，就是假话
• 当前的话中 X 或 Y 比 N 大，就是假话
• 当前的话表示 X 吃 X，就是假话
你的任务是根据给定的 N 和 K 句话，输出假话的总数。
输入格式
从 http://eat.in 中输入数据
第一行两个整数，N，K，表示有 N 个动物，K 句话。
第二行开始每行一句话（按照题目要求，见样例）
输出格式
输出到 eat.out 中
一行，一个整数，表示假话的总数。
*/

#include <cstdio>
#include <cctype>

int fa[150005], rank[150005];

int read()
{
    int ans = 0;
    char c = getchar();
    while(!isdigit(c))
        c = getchar();
    while(!isdigit(c))
    {
        ans = (ans << 3) + (ans << 1) + c - '0';
        c = getchar();
    }
    return ans;
}

int find(int a)
{
    return (fa[a] == a) ? a : (fa[a] = find(fa[a]));
}

int query(int a, int b)
{
    return find(a) == find(b);
}

void merge(int a, int b)
{
    int x = find(a), y = find(b);
    if(rank[x] >= rank[y])
        fa[y] = x;
    else
        fa[x] = y;
    if(rank[x] == rank[y] && x != y)
        rank[x]++;
}

void init(int n)
{
    for(int i = 1; i <= n; i++)
    {
        rank[i] = 1;
        fa[i] = i;
    }
}

int main()
{
    int n = read(), m = read(), ans = 0;
    init(n * 3);
    for(int i = 0; i < m; i++)
    {
        int opr, x, y;
        scanf("%d%d%d", &opr, &x, &y);

        if(x > n || y > n)
            ans++;
        else if(opr == 1)
        {
            if(query(x, y + n) || query(x, y + 2 * n))
                ans++;
            else
            {
                merge(x, y);
                merge(x + n, y + n);
                merge(x + 2 * n, y + 2 * n);
            }
        }
        else if(opr == 2)
        {
            if(query(x, y) || query(x, y + 2 * n))
                ans++;
            else
            {
                merge(x, y + n);
                merge(x + n, y + 2 * n);
                merge(x + 2 * n, y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
