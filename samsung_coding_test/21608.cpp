#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student{
    int id;
    int fav[4]; //좋아하는 친구는 배열로 정리하자
    int r,c;
};

/*비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.*/

vector<Student> students; //students라는 구조체를 넣는 벡터에 N*N개의 방 설정

int N;
int board[25][25];
int dr[] = {-1,1,0,0}; //상 하
int dc[] = {0,0,-1,1}; //좌 우

void seat_student(Student &s){ //&s를 해줘야 복사본 안만들고 진짜 students안에께 바뀜 그리고 이자리는 어떤 유형인지를 적어주는 자리
    //int cnt = 0;

    int max_fav = -1;    // 내가 본 칸 중 좋아하는 친구가 가장 많았던 수
    int max_empty = -1;  // 그중에서 빈칸이 가장 많았던 수
    int best_r = 0;      // 그때의 행
    int best_c = 0;      // 그때의 열

    for(int r = 1; r<=N; r++){
        for(int c = 1; c<=N; c++){
            if(board[r][c] != 0) continue;
            
            int f_cnt = 0; // 이 칸 주변의 친구 수
            int e_cnt = 0; // 이 칸 주변의 빈칸 수 

            for (int d=0; d<4; d++){
                int nr = r + dr[d];
                int nc = c + dc[d];
                if(nr < 1 || nr > N ||nc < 1 || nc > N ) continue;

                for(int k = 0; k<4; k++){
                    if(board[nr][nc] == s.fav[k]) f_cnt++;  
                }             
                if(board[nr][nc] == 0) e_cnt++;
            }

            if (f_cnt > max_fav){
                max_fav = f_cnt; max_empty = e_cnt;
                best_r = r; best_c = c;
            }
            else if(f_cnt  == max_fav){
                if(e_cnt > max_empty){ //같으면 if문 안거치고 그냥 원래대로 놔둔다 -> 알아서 행, 열이 작은 순으로 저장된거임
                    max_empty = e_cnt;
                    best_r = r; best_c = c;
                }
            }
            //board에 넣고 걔네 번호 저장? 그리고 주변의 좋아하는 친구의 수도 저장해야 나중에 cout가능
            
            
        }
    } 
    board[best_r][best_c] = s.id;

    s.r = best_r;
    s.c = best_c;
}  
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if(!(cin >> N)) return 0; //N입력 받기 with 예외 처리

    for(int i =0; i<N * N; i++){
        Student temp;
        cin >> temp.id >> temp.fav[0] >>temp.fav[1] >> temp.fav[2] >> temp.fav[3];
        students.push_back(temp);
    }

    for(int i = 0; i<N*N ; i++){
        seat_student(students[i]);
    }

    
    int total = 0;
    for(int i = 0; i<N*N; i++){
        int cnt = 0;
        for(int k = 0; k < 4; k++){
            for(int j = 0; j < 4; j++){
                int nr = students[i].r + dr[k];
                int nc = students[i].c + dc[k]; 
                if(nr < 1 || nr > N ||nc < 1 || nc > N ) continue;

                if(students[i].fav[j] ==  board[nr][nc]) cnt++;
            }
            
        }
        if(cnt == 1) total += 1;
        else if(cnt == 2) total += 10;
        else if(cnt == 3) total += 100;
        else if(cnt == 4) total += 1000;
    }

    cout << total << "\n";

    return 0;
}