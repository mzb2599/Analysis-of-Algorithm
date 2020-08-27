#include<stdio.h>
#include<conio.h>
int size, u, v, adj[10][10], i, j, cost[10][10], dist[10];
void sssp()
{
    int k;
    for ( i = 1; i <= size; i++)
    {
        dist[i] = cost[v][i];
    }
    for ( k = 2; k <= size; k++)
        for ( u = 1; u <= size; u++)
        for ( i = 1; i <= size; i++)
        {
           if(adj[i][u]==1)
            {
                if(dist[u]>dist[i]+cost[i][u])
                {
                    dist[u] = dist[i] + cost[i][u];
                }
            }
        }
    for ( i = 1; i <= size; i++)
    {
        printf("Distance from 1 to %d is %d\n", i, dist[i]);
    }
}
void main()
{
    int i, j;
    printf("Enter the size : ");
    scanf("%d", &size);
    printf("Enter the path if there is enter 1 or enter 0\n");
    for (i = 1; i <= size; i++)
    {
        for (j = 1; j <= size; j++)
        {
            printf("Enter the adjacency matrix for i,j %d %d:", i, j);
            scanf("%d", &adj[i][j]);
        }
    } 
    for (  i = 1; i <= size; i++)
    {
         for (  j = 1; j <= size; j++)
         {
             cost[i][j] = 100;
         }
    }
    printf("Enter the weight :");
    for (  i = 1; i <= size; i++)
    {
         for (  j = 1; j <=  size; j++)
         {
              if (adj[i][j]==1)
              {
                  printf("From %d to %d", i, j);
                  scanf("%d", &cost[i][j]);
              }
              
         }
    }
    printf("Enter the source :");
    scanf("%d", &v);
    printf("Enter the destination : ");
    scanf("%d", &u);
    sssp();
}