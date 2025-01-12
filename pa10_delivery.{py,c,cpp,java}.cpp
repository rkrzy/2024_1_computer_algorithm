//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <climits>
//using namespace std;
//struct order{
//public:
//    int state;
//    int x;
//    int y;
//};
//vector<order> location;
//
//int save[21];
//int sequence[21];
//int length[21];
//int N = 0;
//int capacity = 2;
//int number_of_object = 0;
//
//int answer = INT_MAX;
//void find_min(int num1);
//bool promising(int num1);
//int manhattan_distance(order order1, order order2)
//{
//    return abs(order1.x - order2.x)+abs(order1.y - order2.y);
//}
//void find_min(int num1)
//{
//    if(num1 > N*2)
//    {
//        int result = 0;
//        for(int i = 0 ;i<N*2;i++)
//        {
//            result = result + manhattan_distance(location.at(save[i]),location.at(save[i+1]));
//        }
//        if(result < answer)//만약 더 최적화된 답안이면 답을 변경한다.
//        {
//            answer = result;
//            for(int i= 0;i<=N*2;i++)
//            {
//                sequence[i] = save[i];
//            }
//
//            return;
//        }
//        else if(result == answer)
//        {
//            for(int j = 0 ;j<=num1;j++)
//            {
//                if(location.at(save[j]).state<location.at(sequence[j]).state)
//                {
//                    for(int a = 0;a<=num1;a++)
//                    {
//                        sequence[a] = save[a];
//                    }
//                    break;
//                }
//                else if(location.at(save[j]).state>location.at(sequence[j]).state)
//                {
//                    break;
//                }
//            }
//        }
//    }
//    bool bol = true;
//    for(int i = 1;i<=N*2;i++)
//    {
//        if(find(save,save+num1,i) == save+num1) // 만약 중복되는 값이 없다면
//        {
//            save[num1] = i;
//            if(bol)
//            {
//                length[num1] = manhattan_distance(location.at(save[num1]),location.at(save[num1-1]));
//                bol = false;
//            }
//            if(promising(num1))
//            {
//                find_min(num1+1);
//            }
//        }
//    }
//}
//bool promising(int num1)
//{
//    int save1[num1+1];
//    for(int i = 1;i<=num1;i++)
//    {
//        save1[i] = save[i];
//    }
//    bool can = true;
//    vector<int> storage;
//    for (int i = 1; i <= num1; i++) {
//        if (location.at(save[i]).state > 0) //주문한 음식을 수령하는곳
//        {
//            storage.push_back(location.at(save[i]).state);
//        } else if (location.at(save[i]).state < 0)//가방에 있는 음식을 배달을 완료했음
//        {
//            if (storage.size() == 0) {
//                return false;
//            }
//            for(int j =0;j<storage.size();j++)
//            {
//                if(storage.at(j)== location.at(save[i]).state*-1)
//                {
//                    storage.erase(remove(storage.begin(),storage.end(),location.at(save[i]).state*-1),storage.end());
//                    can = true;
//                }
//                else
//                {
//                    can = false;
//                }
//            }
//        }
//        else
//        {
//            return false;
//        }
//        if (storage.size() > capacity||!can)//가방에 넣을수 있는 양을 초과했을때, 가방에 없는 물건을 사용했을때.
//        {//이 순서는 더 탐색을 안해도 괜찮다.
//            return false;
//        }
//    }
//    return true;
//}
//bool cmp(order o1,order o2)
//{
//    return o1.state<o2.state;
//}
//int main()
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//    int order_x,order_y;
//    int dest_x,dest_y;
//    int order_state = 1;
//    int dest_state = -1;
//    for(int i =0;i <= 20;i++)
//    {
//        save[i] = 0;
//    }
//    cin>>N;
//    order start;
//    start.state = 0;
//    start.x = 500;
//    start.y = 500;
//    location.push_back(start);
//    for(int i = 0;i<N;i++)
//    {
//        cin>>order_x>>order_y;
//        cin>>dest_x>>dest_y;
//        order Order;
//        order Dest;
//        Order.x = order_x;
//        Order.y = order_y;
//        Order.state = order_state;
//        Dest.x = dest_x;
//        Dest.y = dest_y;
//        Dest.state = dest_state;
//        order_state++;
//        dest_state--;
//        location.push_back(Order);
//        location.push_back(Dest);
//    }
//    sort(location.begin()+1,location.end(), cmp);
//    reverse(location.begin()+1,location.end());
//    reverse(location.begin()+1,location.begin()+order_state);
//
//
//    find_min(1);
//    for(int i = 1;i<=N*2;i++)
//    {
//        cout<<location.at(sequence[i]).state<<" ";
//    }
//    cout<<endl;
//    cout<<answer;
//}