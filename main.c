#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char* minWindow(char* s, char* t) {
    int m = strlen(s);
    int n = strlen(t);

    int* alpha = calloc(128, sizeof(int));
    int* alphaCopy = calloc(128, sizeof(int));
    for (int i = 0; i < n; i++) {
        alpha[t[i]]++;
    }

    int min = INT_MAX;
    int l = 0, r = 0;
    int match = 0;
    int bestLeft = -1;

    while (r < m) {
        if (alpha[s[r]] > 0) {
            alphaCopy[s[r]]++;
            if (alphaCopy[s[r]] <= alpha[s[r]]) {
                match++;
            }
        }

        while (match == n) {
            if (r - l + 1 < min) {
                min = r - l + 1;
                bestLeft = l;
            }
            if (alpha[s[l]] > 0) {
                alphaCopy[s[l]]--;
                if (alphaCopy[s[l]] < alpha[s[l]]) {
                    match--;
                }
            }
            l++;
        }
        r++;
    }

    if (bestLeft == -1) {
        return "";
    }

    char* ans = malloc((min + 1) * sizeof(char));
    strncpy(ans, &s[bestLeft], min);
    ans[min] = '\0';
    return ans;
}

int main() {
    char s1[] = "ADOBECODEBANC";
    char t1[] = "ABC";
    printf("Input: s = \"%s\", t = \"%s\"\n", s1, t1);
    printf("Output: \"%s\"\n", minWindow(s1, t1));

    char s2[] = "a";
    char t2[] = "a";
    printf("Input: s = \"%s\", t = \"%s\"\n", s2, t2);
    printf("Output: \"%s\"\n", minWindow(s2, t2));

    char s3[] = "a";
    char t3[] = "aa";
    printf("Input: s = \"%s\", t = \"%s\"\n", s3, t3);
    printf("Output: \"%s\"\n", minWindow(s3, t3));

    return 0;
}
