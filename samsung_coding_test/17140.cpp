#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int r,c,k;
int A[104][104];

void sort_line(vector<int> &line){ // &써주면 그냥 모든 line이 바뀜 이 함수에서만 바뀌는게 아니라
    int cnt[101] = {0, };//몇갠지 저장할 애 이제 line에서 같은건 모아서 몇갠지 알아야 그 갯수에 따라 sort 가능
    for(int i=0; i<line.size(); i++){
        int num = line[i];
        if (num > 0 && num <=100) cnt[num]++;
    }

    vector<pair<int,int>> v;
    for (int i=1; i <= 100; i++){
        if (cnt[i] > 0){
            v.push_back(make_pair(cnt[i], i)); // 갯수 오름차순 정렬하고 같으면 갯수 같으면 오름차순 정렬.. 
        }
    }

    sort(v.begin(), v.end()); //오름차순으로 쭉 정렬

    line.clear();
    for(int i = 0; i < v.size(); i++){
        line.push_back(v[i].second);
        line.push_back(v[i].first); //line 만들었다
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> k;

    for(int i=1; i <=3; i++){
        for(int j=1; j<=3; j++){
            cin >> A[i][j]; // 일단 입력 받은 애 만들기, 인덱스 1부터 시작
        }
    }
    int time=0;//while문에 넣으면 계속 초기화됨
    int R=3, C=3; //현재 크기 저장해둘 변수

    while(time <= 100){ //몇번 반복해야 할지 모르는 경우 while문
        if(A[r][c] == k) {
            cout << time << "\n";
            return 0;
        }
        if(R >= C){
            int max_C =0;
            for(int i=1; i<=R; i++){
                vector<int> line;
                for(int j=1; j<=C; j++){
                    if(A[i][j] > 0) line.push_back(A[i][j]);
                    A[i][j] = 0;
                }
                sort_line(line);//지금 line은 벡터 상태임
                //이제 한줄 다 받은 상태. sort를 해야함
                for(int j = 0; j < line.size() && j < 100; j++){ //여기서도 100 제한둬야됨. 사실상 v에선 100제한뒀는데 line은 또 다른 개념.
                    A[i][j+1] = line[j];
                }
                int s = line.size();
                max_C = max(max_C, s); //라이브러리를 algorithm 써줘야
            }
            if(max_C > 100) max_C = 100;
            C = max_C; //들어간건 100 제한 뒀는데 사실상 size는 100보다 클 수도 있다.                
        }

        else{
            int max_R =0;
            for(int i=1; i<=C; i++){
                vector<int> line;
                for(int j=1; j<=R; j++){
                    if(A[j][i] > 0) line.push_back(A[j][i]);
                    A[j][i] = 0;
                }
                sort_line(line);//지금 line은 벡터 상태임
                //이제 한줄 다 받은 상태. sort를 해야함
                for(int j = 0; j < line.size() && j < 100; j++){ //여기서도 100 제한둬야됨. 사실상 v에선 100제한뒀는데 line은 또 다른 개념.
                    A[j+1][i] = line[j];
                }
                int s = line.size();
                max_R = max(max_R, s); //라이브러리를 algorithm 써줘야
            }
            if(max_R > 100) max_R = 100; //들어간건 100 제한 뒀는데 사실상 size는 100보다 클 수도 있다.     
            R = max_R;
        }
        time++;
    }
    cout << -1 << "\n";
}