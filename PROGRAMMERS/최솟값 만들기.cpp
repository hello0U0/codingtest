#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    sort(A.begin(),A.end());
    sort(B.begin(),B.end(),greater<>());
    for(int i=0;i<A.size();i++){
        answer += A[i]*B[i];
    }
    return answer;
}

/*
numeric inner_product사용하기
#include<numeric>

answer = inner_product(A.begin(),A.end(),B.begin(),0);

*/