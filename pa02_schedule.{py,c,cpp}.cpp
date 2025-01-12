#include <iostream>

using namespace std;
int main() {
    int study = 0;
    int time = 0;
    int business = 0;
    int Num_of_op = 0;

    int work_start = 0;
    int work_end = 0;
    int noise =0;
    cin>>study;
    cin>>time;
    cin>>business;
    int arr[time];
    int max[time];
    for(int i = 0 ; i<time;i++)
    {
        arr[i] = study;
    }
    for(int i =0;i<business;i++)
    {
        cin>>Num_of_op;
        for(int j = 0;j<Num_of_op;j++)
        {
            cin>>work_start>>work_end>>noise;
            for(int k = work_start;k<work_end;k++)
            {
                arr[k] += noise;
            }
        }
    }
    max[0] = arr[0];
    int max_num = arr[0];
    for(int j = 1;j<time;j++)
    {
        max[j-1] = arr[j-1];
        if(arr[j] > max_num)
        {
            max_num = arr[j];
        }
        for(int i =j;i<time;i++)
        {
            max[i] = max[i-1]+arr[i];
            if(max[i]>max_num)
            {
                max_num = max[i];
            }
        }
    }
    cout<<max_num;



}
