typedef struct edge {
    int dst;
    int time;
    struct edge *p_next;
} EDGE;

EDGE *p_src[100];
bool visited[100];
int node_time[100]; /* Store minimal distance from k to specific node */

void dfs(int current, int time) {
    
    EDGE *p_hdr;

    /* Ignore the the path which required more time travel */
    if (time >= node_time[current]) {
        return;
    }
    
    /* Update the spent time from k to specific node */
    node_time[current] = time;
    visited[current] = true;
    
    p_hdr = p_src[current];

    /* Visit all the neighbooring nodes */
    while (p_hdr) {
        dfs(p_hdr->dst, time + p_hdr->time);
        p_hdr = p_hdr->p_next;
    }
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){

    /*
     *  Input:
     *      n: n nodes
     *      times[i] = (src, dst, time)
     *      k: send signel from node k
     */
    EDGE *p_tmp;
    int cnt = 0;
    int max = INT_MIN;
    
    /* Reset data */
    for (int i = 0; i <= n; i ++) {
        visited[i] = false;
        node_time[i] = INT_MAX;
        p_src[i] = NULL;
    }

    /* Convert array to list */
    for (int i = 0; i < timesSize; i++) {
        p_tmp = (EDGE *)malloc(sizeof(EDGE));
        p_tmp->dst = times[i][1];
        p_tmp->time = times[i][2];
        p_tmp->p_next = p_src[times[i][0]];
        p_src[times[i][0]] = p_tmp;
    }
    
    /*
     *  Algorithm:
     *      (1) Using DFS method, scan the shortest time from k to each node
     *          - Store the visited node in table
     -          - Store the shortest spending time for visiting nodes from k in table
     *      (2) Find out the maximum spending time from k to specific node
     *          - Also check if we visited all the nodes
     *
     *      (3) Return -1 if we cannot visit call the nodes from k.
     *          Otherwise, return the maximum spending time for visiting specific node from k.
     */
    
    /* Maesure the minimal siganl transsmting time required from k to each nodes */
    dfs(k, 0);
    
    max = INT_MIN;

    /* Check if all the nodes have been visited and get the maximum distace to nodes*/
    for (int i = 1; i <= n; i++) {
        
        /* how many nodes we have visted */
        if (visited[i]) cnt++;
        
        /* The maximum spending time form k to specific node */
        if (node_time[i] > max) max = node_time[i];
        
        /* Release memory */
        while (p_src[i]) {
            p_tmp = p_src[i];
            p_src[i] = p_src[i]->p_next;
            free(p_tmp);
        }
    }

    /*
     *  Output:
     *      return the time from k to farest node
     *      return -1 if it's impossible to access all the nodes from k
     */
    
    return (cnt == n) ? max : -1;
}