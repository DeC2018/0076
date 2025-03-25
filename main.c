#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    int* alpha = calloc(52, sizeof(int));
    int* alphaCopy = calloc(52, sizeof(int));
    for (int i = 0; i < n; i++) {
        (t[i] >= 'a') ? alpha[t[i] - 'a']++ : alpha[t[i] - 'A' + 26]++;
    }

    int min = INT_MAX;
    int l = -1, r;
    int match = 0;
    int a_idx = -1;
    int r_key, l_key;

    for (r = 0; r < m; r++) {
        r_key = (s[r] >= 'a') ? s[r] - 'a' : s[r] - 'A' + 26;

        if (alpha[r_key] > 0) {
            if (l == -1)
                l = r;
            alphaCopy[r_key]++;
            if (alphaCopy[r_key] <= alpha[r_key]) {
                match++;
                if (match == n) {
                    l_key = (s[l] >= 'a') ? s[l] - 'a' : s[l] - 'A' + 26;
                    while (match == n || alpha[l_key] == 0) {
                        if (alpha[l_key] > 0) {
                            alphaCopy[l_key]--;
                            if (alphaCopy[l_key] < alpha[l_key]) {
                                if ((r - l + 1) < min) {
                                    min = r - l + 1;
                                    a_idx = l;
                                }
                                match--;
                            }
                        }
                        l++;
                        if (l < m)
                            l_key = (s[l] >= 'a') ? s[l] - 'a' : s[l] - 'A' + 26;
                        else
                            break;
                    }
                }
            }
        }
    }

    if (a_idx == -1) {
        free(alpha);
        free(alphaCopy);
        return NULL; // Return NULL if no valid substring is found
    }

    char* ans = malloc((min + 1) * sizeof(char));
    ans[min] = '\0';
    strncpy(ans, &s[a_idx], min);
    
    free(alpha);
    free(alphaCopy);
    return ans;
}

int main() {
    // Test case 1
    char* s1 = "ADOBECODEBANC";
    char* t1 = "ABC";
    printf("Input: s = \"%s\", t = \"%s\"\n", s1, t1);
    char* result1 = minWindow(s1, t1);
    if (result1) {
        printf("Output: \"%s\"\n", result1);
        free(result1);
    } else {
        printf("Output: \"\"\n");
    }

    // Test case 2
    char* s2 = "a";
    char* t2 = "a";
    printf("Input: s = \"%s\", t = \"%s\"\n", s2, t2);
    char* result2 = minWindow(s2, t2);
    if (result2) {
        printf("Output: \"%s\"\n", result2);
        free(result2);
    } else {
        printf("Output: \"\"\n");
    }

    // Test case 3
    char* s3 = "a";
    char* t3 = "aa";
    printf("Input: s = \"%s\", t = \"%s\"\n", s3, t3);
    char* result3 = minWindow(s3, t3);
    if (result3) {
        printf("Output: \"%s\"\n", result3);
        free(result3);
    } else {
        printf("Output: \"\"\n");
    }

    return 0;
}
