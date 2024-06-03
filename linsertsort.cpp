#include<iostream>
using namespace std;
template<typename T>
class sort
{
public:
    T a[50];
    int i,j,n,key;
    void is()
    {
        cout<<"enter size"<<endl;
        cin>>n;
        cout<<"enter ele"<<endl;
        for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0 && a[j]>key)
            {
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
        }
        cout<<"sorted"<<endl;
        for(i=0;i<n;i++)
        {
            cout<<a[i]<<"\t";
        }
        cout<<endl;
    }
};
int main()
{
     sort<int>s1;
    sort<char>s2;
    cout<<"int:"<<endl;
    s1.is();
    cout<<"char:"<<endl;
    s2.is();
    return 0;
}
