#include<iostream>
using namespace std;
int main()
{
int a[50],n,i,j,temp,low,mid,high,target,index;
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
cout<<endl;
cout<<"enter target"<<endl;
cin>>target;
low=0;
high=n;
while(low<=high)
{
    mid=(high+low)/2;
    if(a[mid]==target)
    {
        index=1;
        break;
    }
    else if(a[mid]<target)
    {
        low=mid+1;
    }
    else if(a[mid]>target)
    {
        high=mid-1;
    }
}
if(index==1)
{
    cout<<"ele present at index "<<mid;
}
else{
    cout<<"not found"<<endl;
}
return 0;
}
