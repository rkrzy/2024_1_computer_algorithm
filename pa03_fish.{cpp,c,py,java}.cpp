//#include <iostream>
//
//using namespace std;
//void Printing(int num)
//{
//    if(num == 1)
//    {
//        cout<<"one"<<endl;
//    }
//    else if(num == 2)
//    {
//        cout<<"two"<<endl;
//    }
//    else
//    {
//        cout<<"over"<<endl;
//    }
//}
//void Reverse(int * arr,int Start_Point,int End_Point)
//{
//    int temp = 0;
//    while (Start_Point<=End_Point)
//    {
//        temp = arr[Start_Point];
//        arr[Start_Point] = arr[End_Point]*-1;
//        arr[End_Point] = temp*-1;
//        Start_Point++;
//        End_Point--;
//    }
//}
//bool One_can(int  arr[],int Start_Point, int End_Point)
//{
//    for(int i = Start_Point;i<=End_Point;i++)
//    {
//        if(arr[i]<0)
//        {
//            int num = arr[i]*-1;
//            int num2 = arr[num];
//            if(num2>0)
//            {
//                return false;
//            }
//            else
//            {
//                num2 = num2 * -1;
//                if(num2 != i)
//                {
//                    return false;
//                }
//            }
//        }
//        else if(arr[i] != i)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool Two_can(int arr[], int Start_Point, int End_Point)
//{
//    for(int i = Start_Point;i<=End_Point;i++)
//    {
//        Reverse(arr,i,End_Point);
//        if(One_can(arr,Start_Point,End_Point))
//        {
//            return true;
//        }
//        Reverse(arr,i,End_Point);
//    }
//    for(int i = End_Point;i>Start_Point;i--)
//    {
//        Reverse(arr,Start_Point,i);
//        if(One_can(arr,Start_Point,End_Point))
//        {
//            return true;
//        }
//        Reverse(arr,Start_Point,i);
//    }
//    return false;
//}
//int main() {
//    int k = 0;
//    cin>>k;
//    int Fish[k+1];
//    int answer = 0;
//    for(int j = 0; j<5;j++)
//    {
//        for(int a = 1;a<=k;a++)
//        {
//            cin>>Fish[a];
//        }
//        for(int i =1;i<=k;i++)
//        {
//            if(Fish[i] != i)
//            {
//                int Start_Point = i;
//                int End_Point = 0;
//                for(;i<=k;i++)
//                {
//                    if(Fish[i] == i)
//                    {
//                        End_Point = i-1;
//                        break;
//                    }
//                }
//                if(i>k)
//                {
//                    End_Point = k;
//                }
//                if(One_can(Fish,Start_Point,End_Point))
//                {
//                    answer += 1;
//                }
//                else if(Two_can(Fish,Start_Point,End_Point))
//                {
//                    answer += 2;
//                }
//                else
//                {
//                    answer = 3;
//                    break;
//                }
//            }
//            if(answer >= 3)
//            {
//                break;
//            }
//        }
//        Printing(answer);
//        answer = 0;
//    }
//    return 0;
//}
