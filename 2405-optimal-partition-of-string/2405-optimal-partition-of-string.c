#include <string.h>
int partitionString(char * s){
    
    int len = strlen(s);
    int count=0;
    for(int i=0; i<len; i++){
        bool arr[123] = {0};
        while(i < len){
            if(arr[s[i]]){
                i--;
                break;
            } 
            else {
                arr[s[i]] = true;
                i++;
            }
        }
        count++;
    }
    return count;
    
    

}
