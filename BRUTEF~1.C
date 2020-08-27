#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <string.h>
char s1[10], s2[10];
int S;
int brute(int n, int m)
{
    int i, j;
    for (i = 0; i <= n - m; i++)
    {
        j = 0;
        while (j < n && s1[i + j] == s2[j])
        {
            j++;
            printf("while loop %d\t%d\n", i, j);
        }
        if (j == n)
        { //printf("if %d",i);
            return i;
        }
    }
    return -1;
}
int main()
{
    int m, n;
    printf("Enter the first string: ");
    gets(s1);
    printf("Enter the second string: ");
    gets(s2);
    n = strlen(s1);
    m = strlen(s2);
    //printf("%s\t%s", s1, s2);
    S = brute(n, m);
    if (S != -1)
        printf("String found at %d", S + 1);
    else
        printf("String not found")
    return 0;
}