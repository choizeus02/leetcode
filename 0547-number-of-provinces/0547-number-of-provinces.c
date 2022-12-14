void dfs(int **isConnected, bool *visited, int row, int col, int idx)
{
    if(visited[idx]) 
        return;
    visited[idx] = true;
    for(int i = 0; i < col; i++)
        if(visited[i] == false && isConnected[idx][i] == 1)
            dfs(isConnected, visited, row, col, i);
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    bool * visited = (bool *)calloc(isConnectedSize, sizeof(int));
    int count = 0;
    for(int i = 0; i < isConnectedSize; i++)
        if(visited[i] == false)
        {
            dfs(isConnected, visited, isConnectedSize, *isConnectedColSize, i);
            count++;
        }
    return count;
}