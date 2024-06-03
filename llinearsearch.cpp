#include<iostream>
using namespace std;

int main()
{
    int n,arr[50],i,num,index;
     cout<<"enter size"<<endl;
        cin>>n;
        cout<<"enter ele"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<"enter ele to search"<<endl;
        cin>>num;
        for(i=0;i<n;i++)
        {
            if(arr[i]==num)
            {
                index=i;
                cout<<"found at index "<<i<<endl;
                break;
            }
            else
            {
                cout<<"not found"<<endl;
            }

        }
            return 0;
        }
