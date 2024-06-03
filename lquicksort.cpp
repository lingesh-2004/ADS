#include<iostream>
using namespace std;

int partition(int arr[],int start,int end)
{
    int pivot=arr[start];
    int count=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=pivot)
        {
            count++;
        }
    }

       int pi=start+count;
        swap(arr[pi],arr[start]);
        int i=start,j=end;
        while(i<pi && j>pi)
        {
            while(arr[i]<=pivot)
            {
                i++;
            }
            while(arr[j]>pivot)
            {
                j--;
            }
            if(i<pi && j>pi)
            {
                swap(arr[i++],arr[j--]);
            }
        }

         return pi;

}

void qs(int arr[],int start, int end)
{
    if (start>=end)
        return;
    int p=partition(arr,start,end);
    qs(arr,start,p-1);
    qs(arr,p+1,end);
}
int main()
{
    int n,arr[50],i;
     cout<<"enter size"<<endl;
        cin>>n;
        cout<<"enter ele"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        qs(arr,0,n-1);
        cout<<"sorted"<<endl;
         for(i=0;i<n;i++)
        {
            cout<<arr[i]<<"\t";
        }
        return 0;
}
