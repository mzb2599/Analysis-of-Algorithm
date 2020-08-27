#include <stdio.h>
#include <conio.h>
int n, adj[10][10], weight[10][10], path[10];
void Shortpath(int s, int t)
{
    int i, dc, newdist, mindist, current;
    int dist[10],nodeset[10];
    int inf = 32768;
    int l, x;
    for (i = 0; i < n; i++)
    {
        dist[i] = inf;
        nodeset[i] = 0;
    }
    current = s;
    dist[current] = 0;
    nodeset[current] = 1;
    while (current != t)
    {
        dc = dist[current];
        for (i = 0; i <= n; i++)
        {
            if (adj[current][i] && !(nodeset[i]))
            {
                newdist = dc + weight[current][i];
                if (newdist < dist[i])
                {
                    dist[i] = newdist;
                    path[i] = current;
                }
            }
        }
        mindist = inf;
        for (i = 0; i <= n; i++)
        {
            if (!(nodeset[current]) && (dist[i] < mindist))
            {
                mindist = dist[i];
                current = i;
            }
        }
        nodeset[current] = 1;
    }
    printf("%d", dist[i]);
    l = t;
    do
    {
        x = path[l];
        printf("%d:%d", l, x);
    } while (l != 5);
}
int main()
{
    int i, s, t, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("Enter the adjacency matrix for %d,%d", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (adj[i][j] == 1)
            {
                printf("Enter the weight from %d to %d", i, j);
                scanf("%d", &weight[i][j]);
            }
        }
    }
    printf("Source: ");
    scanf("%d", &s);
    printf("Target: ");
    scanf("%d", &t);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\n", adj[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d\n", weight[i][j]);
        }
    }

    Shortpath(s, t);
    return 0;
}