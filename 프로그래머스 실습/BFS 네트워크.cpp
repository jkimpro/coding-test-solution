#include <string>
#include <vector>
#include <cstdio>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    bool visit[201];
    for(int i =0; i<n; i++){
        visit[i] = false;
    }
    queue <int> root;
   
    for(int i =0; i<computers.size(); i++){
        if(visit[i] == true){
            continue;
        }
        else{
            for(int j =0; j<computers[i].size(); j++){
                if(visit[j] == true || computers[i][j] == 0){
                    continue;
                }
                else{
                    root.push(j);
                    visit[j] = true;
                }
            }
            
            while(!root.empty()){
                int now = root.front();
                root.pop();
                
                for(int j =0; j<computers[now].size(); j++){
                    if(visit[j] == true || computers[now][j] == 0){ continue;}
                    else{
                        root.push(j);
                        visit[j] = true;
                    }
                }   
            }
            answer+=1;    
        }     
    }
    
    return answer;
}