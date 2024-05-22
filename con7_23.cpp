#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    int stack[1000];
    int stackTop = -1;
    char* result = (char*)malloc(1000 * sizeof(char));
    int resultSize = 0;
    
    for (int i = 0; s[i]; ++i) {
        if (isdigit(s[i])) {
            int num = 0;
            while (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            stack[++stackTop] = num;
        }

        if (s[i] == '[') {
            stack[++stackTop] = resultSize;
        } else if (s[i] == ']') {
            int startIdx = stack[stackTop--];
            int repeatTimes = stack[stackTop--];
            int seqLength = resultSize - startIdx;
            for (int j = 0; j < repeatTimes - 1; ++j) {
                memcpy(result + resultSize, result + startIdx, seqLength);
                resultSize += seqLength;
            }
        } else if (isalpha(s[i])) {
            result[resultSize++] = s[i];
        }
    }

    result[resultSize] = '\0';
    return result;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        char encodedString[1000];
        scanf("%s", encodedString);
        char* decodedString = decodeString(encodedString);
        printf("%s\n", decodedString);
        free(decodedString);
    }
    return 0;
}