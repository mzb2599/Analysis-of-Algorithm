#include<stdio.h>
#include<conio.h>
#include<string.h>
char x[20], y[20], c[20][20], d[10][10];
void display(char d[10][10],char x[],int i,int j)
{
    if(i==0||j==0)
	return;
    else
    {
	if (d[i][j]=='d')
	{
	    display(d, x, i - 1, j - 1);
	    printf("%c", x[i - 1]);
	}
	else if (d[i][j]=='u')
	{
	    display(d, x, i - 1, j);
	}
	else
	    display(d, x, i, j - 1);
    }

}
void Lcs(char x[],char y[])
{
    int m, n, j, i;
    m = strlen(x);
    n = strlen(y);
    for (  i = 0; i <= m; i++)
    {
	c[i][0] = 0;
    }
    for (  j = 0; j <= n; j++)
    {
	c[0][j] = 0;
    }
    for (  i = 1; i <= m; i++)
    for ( j = 1; j <= n; j++)
    if (x[i-1]==y[j-1])
    {
	c[i][j] = c[i - 1][j - 1] + 1;
	d[i][j] = 'd';
    }
    else if (c[i-1][j]>=c[i][j-1])
    {
	c[i][j]=c[i-1][j];
	d[i][j] = 'u';
    }
    else
    {
	c[i][j] = c[i][j - 1];
	d[i][j] = 'l';
    }
    display(d,x,m,n);
}
void main()
{
    char a[20],b[20];
    printf("String 1:");
    gets(a);
    printf("String 2:");
    gets(b);
    Lcs(a, b);
    printf(" ");
    printf(" is the longest common subsequence.");
    getch();
}