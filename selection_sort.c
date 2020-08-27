#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10],n,i,j,largest,pos;
    printf("Enter the number of elements");
    scanf("%d",&n);
    printf("Enter the elements");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //Sorting
    for(j=n-1;j>=1;j--)
    {
        largest=a[0];
        pos=0;
        for(i=0;i<=j;i++)
        {
            if(a[i]>largest)
            {
                largest=a[i];
                pos=i;
            }
        }
        a[pos]=a[j];
        a[j]=largest;
    }
    for(i=0;i<n;i++)
    {
         printf("%d\n",a[i]);
    }
}