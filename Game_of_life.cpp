/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
*/
class Solution {
public: void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int live = 0;
                
                for(int k = -1; k <= 1; k++) {
                    for(int l = -1; l <= 1; l++) {
                        int x = i + k, y = j + l;
                        
                        if(x < 0 || y < 0 || x == m || y == n || x == i && y == j) 
                            continue;
                        if(board[x][y] != 0 && board[x][y] != 2) 
                            live++;
                    }
                }
                
                if(board[i][j] == 0) {
                    if(live == 3) board[i][j] = 2;
                } else {
                    if(live < 2 || live > 3) board[i][j] = -1;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == -1) {
                    board[i][j] = 0;
                } else if(board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
    }
 
};

