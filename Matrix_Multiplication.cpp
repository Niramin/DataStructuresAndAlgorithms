#include <iostream>
using namespace std;

int main()
{
    int A[3][2]=
    {   {1,2},
        {3,4},
        {5,6}
        };
    int B[2][3]=
    {
        {1,2,3},
        {4,5,6},
    };
    int R[3][3]={0};
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    for(int k=0;k<2;k++)
    {
        R[i][j]=R[i][j]+(A[i][k]*B[k][j]);

    }
    
    for(int i=0;i<3;i++)
    {
    for(int j=0;j<3;j++)
    {
        cout<<R[i][j]<<" ";
    }
    cout<<endl;
    }


    return 0;

}
