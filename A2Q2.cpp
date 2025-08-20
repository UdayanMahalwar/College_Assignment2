#include<iostream>
using namespace std;
int main()
{
    int arr[7]={64,34,25,12,22,11,90};
        for(int i=0;i<=6;i++)
        {
            for(int j=0;j<6;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    for(int i=0;i<=6;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    
    
    return 0;
}