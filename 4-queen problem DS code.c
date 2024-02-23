#include <stdio.h>
#define board_size 4
int stack[4] = {1,1,1,1};
int ind = 4;

void push(){
    if(ind == 4){
        printf("\nOverflow");
    }
    else{
        stack[ind++] = 1;
    }
}

int pop(){
    int e = stack[ind-1];
    ind--;
    return e;
}
void refresh_stack(){
    ind = 4;
    //Time Complexity : O(n)
    for(int i = 0;i<4;i++){
        stack[i] = 1;
    }
}
int arr[board_size][board_size] = {{0,0,0,0},
                                    {0,0,0,0},
                                    {0,0,0,0},
                                    {0,0,0,0}};

void refresh_board(){
    //Time Complexity : O(n^2)
    for(int i = 0;i<board_size;i++){
        for(int j = 0;j<board_size;j++){
            arr[i][j] = 0;
        }
    }
}
int check_queen(int row,int col){
    int cond1 = 0;
    //Time Complexity : O(n)
    for(int i = row;i>-1;i--){ 
        if(arr[i][col] == 1){
            cond1 = 1;
            break;
        }
    }
    
    int cond2 = 0;
    //Time Complexity :O(n)
    for(int i = 0;i<4;i++){
        if(i == col){
            continue;
        }else{
            if(arr[row][i] == 1){
                cond2 = 1;
                break;
            }
        }
    }
    //Time Complexity : O(n)
    int cond3 = 0;
    int r = row,c = col;
    while(r>-1 && c>-1){
        if(arr[r][c] == 1){
            cond3 = 1;
            break;
        }
        c--;
        r--;
    }
    //Time Complexity : O(n)
    int cond4 = 0;
    int r1 = row,r2 = col;
    while(r1 > -1 && r2<board_size){
        if(arr[r1][r2] == 1){
            cond4 = 1;
            break;
        }
        r1--;
        r2++;
    }
    
    if(cond1 == 0 && cond2 == 0 && cond3 == 0 && cond4 == 0){
        return 0;
    }else{
        return 1;
    }
}
void print_board(int status){
    if(status == 1){
        printf("\nPassed\n");
    }else{
        printf("\nFailed\n");
    }
    //Time Complexity : O(n^2)
    for(int i = 0; i<board_size;i++){
        for(int j = 0;j<board_size;j++){
            printf("%d ",arr[i][j]);
        }printf("\n");
    }
}
int main(){
    int iter = 0;
    //Time Complexity : O(n^3)
    while(iter < 4){
        int queens_placed[4] = {1,0,0,0};
        arr[0][iter] = pop();
   for(int i = 1;i<board_size;i++){
        int placed = 0;
        int queen = pop();
       for(int j = 0;j<board_size;j++){
           if(check_queen(i,j) == 0){
               placed = 1;
               arr[i][j] = queen;
               break;
           }
           else{
               continue;
           }
       }
       if(placed == 1){
           queens_placed[i] = 1;
       }
   }
   if(queens_placed[0] == 1 && queens_placed[1] == 1 && queens_placed[2] == 1 && queens_placed[3] == 1){
       print_board(1);
   }
   else{
       print_board(0);
   }
   refresh_board();
   refresh_stack();
   iter++;
    }
    return 0;
}
