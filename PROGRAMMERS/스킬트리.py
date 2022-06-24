#include <string>
#include <vector>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int end=skill.size();       #스킬트리 개수
    vector<int> alpha(26,0);
    int skill_idx=1;
    for(int i=0;i<end;i++){         #스킬트리를 따라서
        int now_node=skill[i]-'A';  #스킬명을 A=0, B=1....
        alpha[now_node]=skill_idx;  #현재 스킬에 index부여
        skill_idx++;
    }
    
    for(int i=0;i<skill_trees.size();i++){
        string now_skill = skill_trees[i];
        int index=1;    #현재 배울 수 있는 스킬 index
        bool isok=true; #스킬트리 가능한가.
        for(int j=0;j<now_skill.size();j++){
           int now_node=now_skill[j]-'A';
               
            if(!alpha[now_node]) continue;  #스킬트리랑 무관하면 패스
            if(alpha[now_node]==index){ #현재 배울 수 있는 스킬이면 ok.
                index++;                #다음에 배울 수 있는 스킬 open
            }
            else{               #현재 배울 수 없는 스킬이면
                isok=false;     #스킬트리 불가
                break;          #더 볼 것도 없다.
            }
            if(index==end) break;       #스킬트리 끝까지 왔으면 끝
        }
        answer+=isok;       #스킬트리 가능이면 +1, 아니면 +0
    }
    
    return answer;
}