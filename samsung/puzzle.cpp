#include <stdio.h>

extern void move(int mode);

#define MOD 1000003
#define PNUM 190000
int hash_board[MOD] = {0,};
bool initialized = 0;
int ans_puzzle = 12345678;
unsigned long long path[MOD] = {0}; //0123만 저장 8바이트 ->64비트 30*2 = 60비트 필요 (00, 01, 10, 11)
//path가 이미 방문한곳이면 다시 계산할 필요없음 모든경로 = 181440개
int mov[][4] = {{10000000,100000},{100000000,1000000,10000},{10000000,1000},
                {100000000,10000,100},{10,1000,100000,10000000},{1,10000,1000000},
                {100,100000},{1,100,10000},{10,1000}};
int zero[][4] ={{1,3}, {0,2,4}, {1,5}, {0,4,6}, {7,5,3,1},{8,4,2},{7, 3},{8,6,4},{7,5}};
int mov_direct[][4] = {{3,1}, {2, 3, 1}, {2, 1}, {0, 3, 1}, {1, 3, 2,0}, {1, 2, 0}, {3, 0}, {3,2,0}, {2, 0}};
int m_size[9] = {2, 3, 2, 3, 4, 3, 2, 3 , 2};
int deci[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10, 1};
int reverse_m[4] = {1, 0, 3, 2};

int board[PNUM];
int zero_index[PNUM];
int board_hash[PNUM];

int find_zero(int ans_puzzle){
    int i=8;
    while(ans_puzzle){
        if(ans_puzzle%10 == 0){
            return i;
        }
        ans_puzzle/=10;
        i--;
    }
    return i;
}

void init_hash(){
    for(int i=0; i<MOD; i++){
        hash_board[i] =0;
        path[i] =0;
    }
}

void init(){
    init_hash();
    int q_num =0;
    //미리 계산해놓은 path
    int h = ans_puzzle%MOD;
    hash_board[h] = ans_puzzle;
    // path[h] 에 경로 쌓아나가야함
    int cur_puzzle;
    board[q_num] = ans_puzzle;
    zero_index[q_num] = find_zero(ans_puzzle);
    board_hash[q_num++] = h;
    int index=0;
    while(index<q_num){ //bfs
        cur_puzzle = board[index];
        int z_index = zero_index[index];
        unsigned long long cur_path = path[board_hash[index]];
        index++;
        for(int i=0; i<m_size[z_index]; i++){
            int tmp = cur_puzzle/mov[z_index][i] %10;
            int next_puzzle = cur_puzzle + tmp*deci[z_index] - tmp*mov[z_index][i];
            //next_puzzle있으면 넘어가고 없으면 푸쉬
            h = next_puzzle%MOD;
            //현재 퍼즐 어떻게 움직여서 왔는지 이전 움직임 정보 필요 
            while(hash_board[h]!=next_puzzle && hash_board[h]!= 0){//값이 다음퍼즐이 아니거나 0이 아닌경우
                h = (h+1)%MOD;
            }
            if(hash_board[h]==0){
                hash_board[h] = next_puzzle;
                board[q_num] = next_puzzle;
                board_hash[q_num] = h;
                zero_index[q_num++] = zero[z_index][i];
                path[h] = (cur_path << 2) + mov_direct[z_index][i];
            }
        }
    }

}

int p_move(int board){
    int h = board%MOD;

    while(hash_board[h]!= board){
        h = (h+1)%MOD;
    }
    unsigned long long answer = path[h];
    if(path[h] == 0){
        move(reverse_m[0]);
    }
    while(answer!=0){
        int mov = answer%4;
        move(reverse_m[mov]);
        answer = (answer>>2);
    }
}

void test(const int puzzle[3][3], const int target_puzzle[3][3]) {
    int target = (target_puzzle[0][0]*100000000 + target_puzzle[0][1]*10000000 + target_puzzle[0][2]*1000000
                + target_puzzle[1][0]*100000 + target_puzzle[1][1]*10000 + target_puzzle[1][2]*1000
                + target_puzzle[2][0]*100 + target_puzzle[2][1]*10 +target_puzzle[2][2]);
    if(target != ans_puzzle){
        ans_puzzle = target;
        initialized = 0;
    }
    if (initialized == 0){
        init();
        initialized = 1;
    }
    int board = (puzzle[0][0]*100000000 + puzzle[0][1]*10000000 + puzzle[0][2]*1000000
                + puzzle[1][0]*100000 + puzzle[1][1]*10000 + puzzle[1][2]*1000
                + puzzle[2][0]*100 + puzzle[2][1]*10 +puzzle[2][2]);
    while(board != ans_puzzle){
        p_move(board);
        board = (puzzle[0][0]*100000000 + puzzle[0][1]*10000000 + puzzle[0][2]*1000000
                + puzzle[1][0]*100000 + puzzle[1][1]*10000 + puzzle[1][2]*1000
                + puzzle[2][0]*100 + puzzle[2][1]*10 +puzzle[2][2]);
    }
}
