//#include <iostream>
//#include <string>
//
//
//using namespace std;
//bool palindrom(string str)
//{
//    int i =0;
//    int end = str.length()-1;
//    while(i<=end)
//    {
//        if(str[i]==str[end])
//        {
//            i++;
//            end--;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int palindrom_length(string str,int length,int era_num)
//{
//    string str1 = str;
//    bool palin = false;
//    for(int i =1;i<length-era_num;i++)//1~10
//    {
//        str1 = str1.erase(i,era_num);
//        palin = palindrom(str1);
//        if(palin)
//        {
//            break;
//        }
//        str1 = str;
//    }
//    if(palin)
//    {
//        return length-era_num;
//    }
//    else
//    {
//        if(length==era_num+1)
//        {
//            return 0;
//        }
//        else
//        {
//            return palindrom_length(str,length,era_num+1);
//        }
//
//    }
//}
//int main(void)
//{
//    int N;
//    string str;
//    cin>>N;
//    for(int i =0;i<N;i++)
//    {
//        cin>>str;
//        if(palindrom(str))//만약 그 자체로 회문이면
//        {
//            cout<<str.length()<<endl;
//        }
//        else if(str[0]!=str[str.length()-1])
//        {
//            cout<<0<<endl;
//        }
//        else
//        {
//            cout<<palindrom_length(str,str.length(),1)<<endl;
//        }
//    }
//}