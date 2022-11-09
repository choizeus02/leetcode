int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    
    int max=0;
    int count=0;
    
    
    for(int i=0;i<gridSize; i++){
        for(int j=0;j<gridColSize[i];j++){
            if (grid[i][j]==1){
                countArea(grid, gridSize, gridColSize,i,j,&count);
                if(max < count)
                    max = count;
            }
            count=0;

        }
    }
    
    return max;
    
    
    
}

void countArea(int** grid, int gridSize, int *gridColSize,int m, int n,int *count) {
     
    if (m < 0 || n < 0 || m >= gridSize || n >= gridColSize[0]) 
        return;
    
    
    if (grid[m][n] == 1) {
        (*count)++;
        grid[m][n]=0;
        
        countArea(grid, gridSize, gridColSize, m-1, n, count);
        countArea(grid, gridSize, gridColSize, m+1, n, count);
        countArea(grid, gridSize, gridColSize, m, n-1, count);
        countArea(grid, gridSize, gridColSize, m, n+1, count);
        
    }
    
    
}