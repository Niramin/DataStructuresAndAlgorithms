#include <iostream>
using namespace std;
//Time Complexity,    
//                O( n^2 )
int* insertionSort(int a[])
{
    int l=10;
    int j=0;
    for(j=1;j<l;j++)
    {
        int key=a[j];
        //Insert a[j] into sorted sequence a[0..j-1]
        int i=j-1;
        while(i>=0&&a[i]>key)
        {
            a[i+1]=a[i];
            i=i-1;

        }
        a[i+1]=key;
    }
    return a;
}

int main()
{
    int a[10]={1,2,4,5,7,9,34,-9,6,4};
    int *b=insertionSort(a);
    for(int i=0;i<10;i++)
    {
        cout<<*(b+i)<<" ";
    }


    return 0;
}
