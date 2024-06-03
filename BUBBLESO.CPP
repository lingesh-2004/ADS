#include<iostream.h>
#include<conio.h>
int main()
{
int a[50],n,i,j,temp;
clrscr();
cout<<"Enter the size of the array:";
cin>>n;
cout<<"Enter the array elements\n";
for(i=0;i<n;i++)
{
cin>>a[i];
}
cout<<"The array elements in ascending order\n";
for(i=0;i<n;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
for(i=0;i<n;i++)
{
cout<<a[i]<<"\t";
}
getch();
return 0;
}