#include <string>
#include <vector>
using namespace std;

int dfs(int k, int v_count, vector<bool> &visit, vector<vector<int>> &dungeons){
    int v_max=v_count;
    for(int i = 0; i<visit.size();i++){
        if(visit[i]) continue;
        //들어갈 수 있으면 들어가자
        if(dungeons[i][0] <= k){
            visit[i]=1;
            int now_v = dfs(k - dungeons[i][1],v_count+1,visit,dungeons);
            if(v_max<now_v) v_max = now_v;
            visit[i]=0;
        }
    }
    return v_max;
}

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<bool> visit(dungeons.size(),0);
    answer = dfs (k,0,visit,dungeons);
    return answer;
}