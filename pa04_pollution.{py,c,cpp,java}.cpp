#include <iostream>

using namespace std;
void floyd2(int N, int **W,int **D,int **P)
{
    for(int i =1;i<=N;i++)
    {
        for(int j = 1;j<=N;j++)
        {
            D[i][j] = W[i][j];
            P[i][j] = 0;
        }
    }
    for(int k =1; k<= N;k++)
    {
        for(int i = 1;i<=N;i++)
        {
            for(int j = 1;j<=N;j++)
            {
                if(D[i][k]+D[k][j]<D[i][j]){
                    P[i][j] = k;
                    D[i][j] = D[i][k]+D[k][j];
                }
            }
        }
    }

}
void sorting(int * result,int N)
{
    int temp = 0;
    for(int i =1;i<=N;i++)
    {
        int Mnum = i;
        for(int j = i+1;j<=N;j++)
        {
            if(result[j]<result[Mnum]){
                Mnum = j;
            }
        }
        temp = result[Mnum];
        result[Mnum] = result[i];
        result[i] = temp;
    }
}
int main(void)
{
    int N;
    int c1,c2;
    int vertex1,vertex2,length;
    cin>>N>>c1>>c2;
    int **W = new int*[N+1];
    int **D = new int*[N+1];
    int **P = new int*[N+1];
    int result[N+1];
    int order[N+1];
    for(int i =1;i<=N;i++)
    {
        W[i] = new int[N+1];
        D[i] = new int[N+1];
        P[i] = new int[N+1];
        for(int j = 1;j<=N;j++)
        {
            W[i][j] = 10000000;
            if(i == j){
                W[i][j] = 0;
            }
        }
    }
    for(int i =0;i<N-1;i++)
    {
        cin>>vertex1>>vertex2>>length;
        W[vertex1][vertex2] = length;
        W[vertex2][vertex1] = length;
    }
    floyd2(N,W,D,P);
    for(int i = 1;i<=N;i++)
    {
        if(D[c1][i]<D[c2][i])
        {
            result[i] = D[c1][i];
        }
        else
        {
            result[i] = D[c2][i];
        }
    }
    for(int i = 1;i<=N;i++)
    {
        order[i] = result[i];
    }
    sorting(result,N);
    for(int i = 3;i<=N;i++)
    {
        for(int j = 1;j<=N;j++)
        {
            if(order[j]==result[i])
            {
                cout<<j<<endl;
                order[j] = 0;
                break;
            }
        }
    }
}