//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//#include <utility>
//using namespace std;
//
//int RK_chance = 0;
//int KMP_chance = 0;
//int BM_chance = 0;
//const long long MOD = 100000007;
//
//void RK_algorithm(string text, string pattern) {
//    int text_length = text.length();
//    int pattern_length = pattern.length();
//
//    long long pattern_hash = 0;
//    long long text_hash = 0;
//    long long power = 1;
//
//    for (int i = 0; i < pattern_length; i++) {
//        // 이 구간을 이용해서 비교하는 문자열의 hash값을 구한다
//        pattern_hash = (pattern_hash * 2 + (pattern[i] - 'A')) % MOD;
//        //이 구간을 이용해서 비교당하는 문자열의 hash값을 구해준다
//        text_hash = (text_hash * 2 + (text[i] - 'A')) % MOD;
//        if (i > 0) power = (power * 2) % MOD; // 자리의 최댓값을 구해준다
//    }
//
//    for (int i = 0; i <= text_length - pattern_length; i++) {
//        RK_chance++;
//        if (pattern_hash == text_hash) {//원래라면 같을때 문자열도 같은지 확인을 해줘야 한다.
//            RK_chance += pattern_length;
//            break;//만약 해쉬값이 같다면 함수를 종료해준다.
//        }
//        if (i < text_length - pattern_length) {
//            text_hash = (text_hash - (text[i] - 'A') * power) * 2 + (text[i + pattern_length] - 'A');
//            text_hash = (text_hash % MOD + MOD) % MOD;
//        }
//    }
//}
//
//void failure_function(string str, int* arr) {
//    arr[0] = -1;
//    int k = -1;
//    for (int j = 1; j < str.length(); j++) {//패턴의 실패함수를 구하는 구간
//        while (k >= 0 && str[j] != str[k + 1]) k = arr[k];
//        if (str[j] == str[k + 1]) k++;
//        arr[j] = k;
//    }
//}
//
//void KMP_algorithm(string text, string pattern) {
//    int i = 0, j = 0;
//    int text_length = text.length();
//    int pattern_length = pattern.length();
//
//    int fail_num[pattern_length];
//    failure_function(pattern, fail_num);
//
//    while (i < text_length && j < pattern_length) {
//        KMP_chance++;
//        if (text[i] == pattern[j]) //만약 패턴문자와 텍스트의 문자가 동일하다면 다음으로 넘어간다.
//        {
//            i++;
//            j++;
//        } else if (j == 0)//만약 문자는 다른데 패턴의 비교 부분이 첫번째라면 문자열 비교는 다음부터 진행한다,
//        {
//            i++;
//        } else {
//            j = fail_num[j - 1] + 1;
//        }
//        if (j == pattern_length) // 만약 패턴이 텍스트안에 존재한다면 종료한다.
//        {
//            break;
//        }
//    }
//}
//
//void Bad_Char_Heuristic(string pattern, int* badchar) {
//    int pattern_length = pattern.length();
//    for (int i = 0; i < 256; i++) {
//        badchar[i] = -1;
//    }
//    for (int i = 0; i < pattern_length; i++) {
//        badchar[pattern[i]] = i;
//    }
//}
//
//void BM_algorithm(string text, string pattern) {
//    int badchar[256];
//    Bad_Char_Heuristic(pattern, badchar);
//    int pattern_length = pattern.length();
//    int text_length = text.length();
//
//    int i = 0;
//    while (i <= text_length - pattern_length) {
//        int j = pattern_length - 1;
//        while (j >= 0 && pattern[j] == text[i + j]) {
//            BM_chance++;
//            j--;
//        }
//        if (j < 0) {
//            break;
//        } else {
//            BM_chance++;
//            i += max(1, j - badchar[text[i + j]]);
//        }
//    }
//}
//
//bool comp(pair<string, int> a, pair<string, int> b) {
//    return a.second < b.second;
//}
//
//int main() {
//    int n, m;
//    string pattern, text = "";
//    vector<pair<string, int>> save;
//    cin >> n;
//    for (int i = 0; i < n; i++) {
//        string pat;
//        cin >> pat;
//        pattern += pat;
//    }
//    cin >> m;
//    for (int i = 0; i < m; i++) {
//        string str;
//        cin >> str;
//        text += str;
//    }
//
//    KMP_algorithm(text, pattern);
//    RK_algorithm(text, pattern);
//    BM_algorithm(text, pattern);
//
//    save.push_back(make_pair("KMP", KMP_chance));
//    save.push_back(make_pair("BM", BM_chance));
//    save.push_back(make_pair("RK", RK_chance));
//    sort(save.begin(), save.end(), comp);
//
//    for (int i = 0; i < 3; i++) {
//        if (i < 2 && save[i].second == save[i + 1].second) {
//            cout << "0 ";
//        } else if (i >= 1 && save[i].second == save[i - 1].second) {
//            cout << "0 ";
//        } else {
//            cout << save[i].first << " ";
//        }
//    }
//}
