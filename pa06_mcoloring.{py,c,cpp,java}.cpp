//#include <iostream>
//#include <algorithm>
//using namespace std;
//int n;//노드의 수
//int m;//색의 수
//bool exist = true;
//int result = 0;
//int chance = 0;
//bool promising(int num,int ** arr,int * v_color)
//{
//    int j;
//    bool flag;
//    flag = true;
//    j = 1;
//    while(j<num && flag)
//    {
//        if(arr[num][j] && v_color[num] == v_color[j] )//색깔이 같은데 인접하다면
//        {
//            flag = false;
//        }
//        j++;
//    }
//    return flag;
//}
//bool composition(int * v_color) //모든 색깔을 다 포함하고 있는지 확인한다.
//{
//    bool flag = false;
//    for(int i =1;i<=m;i++)
//    {
//        for(int j = 1;j<=n;j++)
//        {
//            if(v_color[j] == i)
//            {
//                flag = true;
//                break;
//            }
//            else
//            {
//                flag = false;
//            }
//        }
//        if(flag == false)
//        {
//            return false;
//        }
//    }
//    return flag;
//}
//void m_coloring(int num,int **arr,int * v_color)
//{
//    int color;
//    if(promising(num,arr,v_color))//정해진 조건을 지키고 있다면
//        if(num==n){//색을 다 사용함.
////            for(int i = 1;i<=n;i++)
////            {
////                cout<<v_color[i];
////            }
//            if(composition(v_color))
//            {
//                result++;
//            }
//
//            //cout<<endl;
//        }
//        else
//        {
//            for(color = 1;color <=m;color++)
//            {
//                v_color[num+1] = color; //다음거에 색을 넣고 다시 실행한다.
//                m_coloring(num+1,arr,v_color);//만약 했던 값이 조건을 만족하지 못하면 다음 색깔을 넣고 다시 실행한다.
//                chance++;
//            }
//        }
//}
//int main(void)
//{
//
//    cin>>n>>m;
//    int ** arr = new int* [n+1];
//    for(int i = 1;i<=n;i++)
//    {
//        arr[i] = new int[n+1];
//    }
//    int * v_color = new int[n+1];
//    for(int i =1;i<=n;i++) //노드 인접여부 입력받기
//    {
//        for(int j = 1;j<=n;j++)
//        {
//            cin>>arr[i][j];
//        }
//    }
//    m_coloring(0,arr,v_color);
//    if(result ==0)
//    {
//        cout<<"no";
//    }
//    else
//    {
//        cout<<result<<endl;
//        cout<<chance;
//    }
//}