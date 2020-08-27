#include <stdio.h>
#include <conio.h>
float ratio[10],w[10],p[10];
void sort(int n)
{
    int i,j;
    float t, w1, p1;
    for (i = 0; i < n; i++)
    {
	w1 = w[i];
	p1 = p[i];
	ratio[i] = p1/w1;
    }
    for (i = 0; i < n; i++)
    {
	for (j = 0; j < n - i - 1; j++)
	{
	    if (ratio[j + 1] > ratio[j])
	    {
		t = ratio[j];
		ratio[j] = ratio[j + 1];
		ratio[j + 1] = t;
		t=p[j];
		p[j] = p[j + 1];
		p[j + 1] = t;
		t=w[j];
		w[j] = w[j + 1];
		w[j + 1] = t;
	    }
	}
    }

}
float Knapsack(float w[], float p[], float m, int n)
{
    float x[10];
    float max = 0;
    int cp, i;
    for (i = 0; i < n; i++)
    {
	x[i] = 0;
	cp = m;
    }
    sort(n);
    i = 0;
    while (i < n && w[i] <= cp)
    {
	x[i] = 1;
	cp = cp - w[i];
	i++;
    }
    if (i < n)
    {
	x[i] = cp / w[i];
    }
    for (i = 0; i < n; i++)
    {
	max = max + x[i] * p[i];
    }
    return max;
}
void main()
{
    int n,i;
    float capacity,max;
    printf("Enter the number of items");
    scanf("%d", &n);
    printf("Enter the max capcity of knapsack: ");
    scanf("%f", &capacity);
    for (i = 0; i < n; i++)
    {
	printf("Enter the profit: ");
	scanf("%f", &p[i]);
	printf("Enter the corresponding weight: ");
	scanf("%f", &w[i]);
    }
    max = Knapsack(w, p, capacity, n);
    printf("The max profit is : %f", max);
    getch();
}
/* 
The max profit is : 240.000000
The max profit is : 17.666666

*/