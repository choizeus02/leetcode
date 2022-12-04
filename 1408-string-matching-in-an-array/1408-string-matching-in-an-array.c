/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** stringMatching(char ** words, int wordsSize, int* returnSize){
    char **a = malloc(sizeof(char *[wordsSize])), **w = words;
    int k = 0;
    for (int i = 0 ; i < wordsSize ; i++)
        for (int j = i + 1, x, y ; j < wordsSize ; j++)
                if (w[j] && w[i] && ((x = !!strstr(w[i], w[j])) || (y = !!strstr(w[j], w[i])))) {
                    a[k++] = x ? w[j] : w[i];
                    x ? w[j] = NULL : (w[i] = NULL);
                }
    return *returnSize = k, a;
}