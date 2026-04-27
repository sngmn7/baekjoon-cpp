#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;
int N, M, K; // 격자크기, 나무 갯수, 몇년후
int board[12][12];//처음 양분값, 초기값 5.
int new_board[12][12]; // 겨울에 추가할 양분 저장할 board
vector<int> trees[12][12]; //이렇게 하면 각각의 보드에 vector값이 들어가게됨. 나무의 나이들을 저장해야하므로.

int dr[] = {-1,-1,-1,0,0,1,1,1}; //방향 또 틀림 시발
int dc[] = {-1,0,1,1,-1,-1,0,1};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin >> new_board[i][j]; // 겨울에 추가 할 양분값
        }
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            board[i][j] = 5; // 현재 양분값
        }
    }
    for(int i=0; i<M; i++){
        int x, y, age;
        cin >> x >> y >> age; //현재 나무의 위치, 나이 받아옴 x가 r, y가 c임.
        trees[x][y].push_back(age);
        //sort(trees[x][y].begin(), trees[x][y].end()); //오름차순으로 나이 정렬

    } //모든 나무의 위치를 받아옴.


    for(int w=0; w < K; w++){

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                sort(trees[i][j].begin(), trees[i][j].end()); //오름차순으로 나이 정렬

                vector<int> live_trees;//새로 업데이트한 나무 값. 그냥 벡터로 받아도 됨.
                int dead_tree = 0; // 여름에 양분으로 변할 나무 값 받아놓음
                if(trees[i][j].size() != 0){ // size로 봐야함 trees[i][j] !=0 하니까 안되네?
                    

                    for(int a = 0; a < trees[i][j].size() ; a++){ //봄 로직, 나이 어린애부터 받아옴
                        
                        int age = trees[i][j][a]; //지금 칸에 있는 첫번째 나무의 age를 받아온다

                        if(board[i][j] < age){ //얘는 죽이되, 양분에는 + 해줘야됨. 하지만 봄이 지난 후에 + 해줘야됨.
                            dead_tree += age/2;
                        } 
                        else{
                            board[i][j] = board[i][j] - age;
                            age++;
                            live_trees.push_back(age); //업데이트 한 age를 넣는다.
                        }
                    }
                    trees[i][j] = live_trees;
                    board[i][j] += dead_tree;
                }
                else continue;
            }
        }
    

        for(int i=1; i<=N; i++){ //가을
            for(int j=1; j<=N; j++){
                for(int a = 0; a < trees[i][j].size() ; a++){
                    if(trees[i][j][a] % 5 == 0){//5의 배수
                        for(int k = 0; k<8; k++){
                            int nr = i + dr[k];
                            int nc = j + dc[k];
                            if(nr < 1 || nr > N || nc < 1 || nc >N) continue;

                            trees[nr][nc].push_back(1); //1살 짜리 나무 추가, 다른 칸에 영향 줌. 동시에 일어나는건 항상 주의해야돼
                        }
                    }
                }
            }
        } 
        
        vector<pair<int, int>> birth_list; 

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                for (int a = 0; a < (int)trees[i][j].size(); a++) {
                    if (trees[i][j][a] % 5 == 0) { 
                        for (int k = 0; k < 8; k++) {
                            int nr = i + dr[k];
                            int nc = j + dc[k];
                            if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
                            
                            birth_list.push_back(make_pair(nr, nc));
                        }
                    }
                }
            }
        }

        // auto 대신 명시적 타입을 사용한 순회
        for (int i = 0; i < (int)birth_list.size(); i++) {
            int r = birth_list[i].first;
            int c = birth_list[i].second;
            trees[r][c].push_back(1);
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                board[i][j] += new_board[i][j]; // 현재 양분값
            }
        }
        
    }

    int ans = 0;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            ans += trees[i][j].size(); // 현재 나무값 ++
        }
    }
    
    cout << ans << "\n";
    
    return 0;
}