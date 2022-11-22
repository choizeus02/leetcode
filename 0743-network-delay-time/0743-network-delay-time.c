typedef struct edge {
    int dst;
    int time;
    struct edge *p_next;
} EDGE;

EDGE *p_src[100];
bool visited[100];
int node_time[100]; 

void dfs(int current, int time) {
    
    EDGE *p_hdr;

    
    if (time >= node_time[current]) {
        return;
    }
    
    node_time[current] = time;
    visited[current] = true;
    
    p_hdr = p_src[current];

    while (p_hdr) {
        dfs(p_hdr->dst, time + p_hdr->time);
        p_hdr = p_hdr->p_next;
    }
}

int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){

    EDGE *p_tmp;
    int cnt = 0;
    int max = INT_MIN;
    
    for (int i = 0; i <= n; i ++) {
        visited[i] = false;
        node_time[i] = INT_MAX;
        p_src[i] = NULL;
    }

    for (int i = 0; i < timesSize; i++) {
        p_tmp = (EDGE *)malloc(sizeof(EDGE));
        p_tmp->dst = times[i][1];
        p_tmp->time = times[i][2];
        p_tmp->p_next = p_src[times[i][0]];
        p_src[times[i][0]] = p_tmp;
    }
   
    dfs(k, 0);
    
    max = INT_MIN;


    for (int i = 1; i <= n; i++) {
        
        
        if (visited[i]) cnt++;
        
        
        if (node_time[i] > max) max = node_time[i];
        
        while (p_src[i]) {
            p_tmp = p_src[i];
            p_src[i] = p_src[i]->p_next;
            free(p_tmp);
        }
    }

    return (cnt == n) ? max : -1;
}