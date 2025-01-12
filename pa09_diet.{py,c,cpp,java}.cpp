//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <climits>
//using namespace std;
//
//struct Food
//{
//public:
//    int pro;//단백질
//    int fat;//지방
//    int carbohy;//탄수화물
//    int vi;//비타민
//    int price;//가격
//};
//vector<Food> food_gather;
//int save[51];
//bool Access[51];
//int mp = 0;//최소 단백질
//int mf = 0;//최소 지방
//int ms = 0;//최소 탄수화물
//int mv = 0;//최소 비타민
//int money = INT_MAX;
//int foodNum = 0;
//int solution_len = 0;
//int answer[51];
//void find_min(int num1,int num2);
//void cal(int num1);
//void find_min(int num1,int num2)
//{
//    for(int i = num1;i<=foodNum;i++)
//    {
//        if(!Access[i])
//        {
//            Access[i] = true;
//            save[num2] = i;
//            cal(num2);
//            find_min(save[num2],num2+1);
//            Access[i] = false;
//        }
//    }
//    return;
//}
//void cal(int num1)
//{
//    int pro_sum= 0;
//    int fat_sum = 0;
//    int car_sum = 0;
//    int vi_sum = 0;
//    int pri_sum = 0;
//    for(int i = 1 ;i<=num1;i++)
//    {
//        pro_sum += food_gather.at(save[i]).pro;
//        fat_sum += food_gather.at(save[i]).fat;
//        vi_sum += food_gather.at(save[i]).vi;
//        car_sum += food_gather.at(save[i]).carbohy;
//        pri_sum += food_gather.at(save[i]).price;
//    }
//    if(pro_sum>=mp&&fat_sum>=mf&&vi_sum>=mv&&car_sum>=ms) //만약 모든 수치가 최솟값보다 클때
//    {
//        if(money > pri_sum) // 돈이 더 작다면
//        {
//            money = pri_sum;
//            for(int i = 1;i<=num1;i++)
//            {
//                answer[i] = save[i];
//            }
//            solution_len = num1;
//        }
//        else if(money == pri_sum) //액수는 같다묜
//        {
//            int result1 = pro_sum+fat_sum+vi_sum+car_sum; // 영양치의 총합계산
//            int result2 = 0;
//            for(int i = 1;i<=num1;i++)
//            {
//                result2 += food_gather.at(save[i]).pro;
//                result2 += food_gather.at(save[i]).carbohy;
//                result2 += food_gather.at(save[i]).vi;
//                result2 += food_gather.at(save[i]).fat;
//            }
//            if(result1 > result2) // 영양치의 총합이 크다면 교환한다.
//            {
//                money = pri_sum;
//                for(int i = 1;i<=num1;i++)
//                {
//                    answer[i] = save[i];
//                }
//                solution_len = num1;
//            }
//            else {return;}
//        }
//    }
//}
//int main(void)
//{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//
//    cin>>foodNum;//음식의 수
//    cin>>mp>>mf>>ms>>mv;
//    for(int i =1;i<=foodNum+1;i++)
//    {
//        Access[i] = false;
//    }
//    Food Null_food;
//    food_gather.push_back(Null_food);
//
//    for(int i =1;i<=foodNum;i++)
//    {
//        int p,f,s,v,n;
//        cin>>p>>f>>s>>v>>n;
//        Food food;
//        food.pro = p;
//        food.fat = f;
//        food.carbohy = s;
//        food.vi = v;
//        food.price = n;
//        food_gather.push_back(food);
//    }
//
//    find_min(1,1);
//    if(solution_len>0){
//        for(int i = 1;i<=solution_len;i++)
//        {
//            cout<<answer[i]<<" ";
//        }
//    }
//    else cout<<0<<endl;
//    return 0;
//}