#include <string>
#include <vector>
using namespace std;

vector<int> cal_one(int num){
    vector<int> answer(2,0);
    while(num > 0){
        answer[num % 2]++;
        num /= 2;
    }
    return answer;
}

vector<int> solution(string s) {
    vector<int> answer(2,0);    //[이진변환횟수, 제거한 0의 수]
    //1이면 끝
    if(!s.compare("1")) return answer;
    // 최초엔 string에서 계산
    int num = 0;    //1의 개수
    for(auto c : s){
        if(c == '1') num++;
        else answer[1]++;
    }
    answer[0]++;
    
    //1만 남을 때까지
    while(num != 1){
        //0과 1의 개수 구함
        vector<int> now_cnt = cal_one(num);
        //0은 두번째에 더함
        answer[1] += now_cnt[0];
        //회차 기록
        answer[0]++;
        //다음 수는 1의 개수
        num = now_cnt[1];
    }
    
    return answer;
}