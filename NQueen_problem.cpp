#include<bits/stdc++.h>
int board[11][11];
bool isPossible(int n,int row,int col)
{
    //Column wise Checking
    for(int i=row-1;i>=0;i--)
    {
        if(board[i][col]==1)
        {
            return false;
        }
    }
    
    //UpperLEft Diagonal
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
    
     for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++)
    {
        if(board[i][j]==1)
        {
            return false;
        }
    }
  return true;
}

void NQueenHelper(int n,int row)
{
    if(row==n)
    {
        //Print the board;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<board[i][j]<<" ";
            }
          //cout<<endl;
        }
     //cout<<endl;
        cout<<endl;
        return;
    }
    
    //Checck if the queen can be place din the board
    //Return to the next Small Problem
    //Initialize the n=board to be zero for the next;
    for(int j=0;j<n;j++)
    {
        if(isPossible(n,row,j))
        {
            board[row][j]=1;
            NQueenHelper(n,row+1);
            board[row][j]=0;
            
        }
        
      }
    return;
}


void placeNQueens(int n){

    memset(board,0,11*11*sizeof(int));
    
    NQueenHelper(n,0);
    

}

