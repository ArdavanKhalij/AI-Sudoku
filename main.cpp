//
//  main.cpp
//  AI Sudoku
//
//  Created by Ardavan.A Khalij on 12/26/19.
//  Copyright © 2019 Ardavan.A Khalij. All rights reserved.
//

#include <iostream>

using namespace std;
  
#define UNASSIGNED 0
#define N 9

void get(int gride[N][N]);
bool FindUnassignedLocation(int grid[N][N], int &row, int &col);
bool isSafe(int grid[N][N], int row, int col, int num);
  
bool SolveSudoku(int grid[N][N]){
    int row, col;
    if(!FindUnassignedLocation(grid, row, col))
    return true;
    for(int num=1;num<=9;num++){
        if(isSafe(grid, row, col, num)){
            grid[row][col]=num;
            if(SolveSudoku(grid))
                return true;
            grid[row][col]=UNASSIGNED;
        }
    }
    return false;
}
bool FindUnassignedLocation(int grid[N][N],int &row, int &col){
    for(row=0;row<N;row++)
        for(col=0;col<N;col++)
            if(grid[row][col]==UNASSIGNED)
                return true;
    return false;
}
bool UsedInRow(int grid[N][N], int row, int num){
    for(int col=0;col<N;col++)
        if(grid[row][col]==num)
            return true;
    return false;
}
bool UsedInCol(int grid[N][N], int col, int num){
    for(int row=0;row<N;row++)
        if(grid[row][col]==num)
            return true;
    return false;
}
bool UsedInBox(int grid[N][N], int boxStartRow,int boxStartCol, int num){
    for(int row=0;row<3;row++)
        for(int col=0;col<3;col++)
            if(grid[row+boxStartRow][col+boxStartCol]==num)
                return true;
    return false;
}
bool isSafe(int grid[N][N], int row, int col, int num){
    return !UsedInRow(grid, row, num) &&
           !UsedInCol(grid, col, num) &&
           !UsedInBox(grid, row - row % 3 ,col - col % 3, num) &&
            grid[row][col] == UNASSIGNED;
}
void printGrid(int grid[9][9]){
    for(int row=0;row<9;row++){
        cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
        cout<<"| ";
        for(int col=0;col<9;col++)
            cout<<grid[row][col]<<" | ";
        cout<<endl;
    }
    cout<<"+---+---+---+---+---+---+---+---+---+"<<endl;
}
int main(){
    int gride[N][N];
    get(gride);
    if(SolveSudoku(gride)==true){
        printGrid(gride);
    }
    else{
        cout<<"No solution exists";
    }
    return 0;
}
void get(int gride[N][N]){
    for(int i=0;i<N;i++){
        cout<<"Enter line "<<i<<" : "<<endl<<endl;
        for(int j=0;j<N;j++){
            cin>>gride[i][j];
        }
        cout<<endl;
    }
}
