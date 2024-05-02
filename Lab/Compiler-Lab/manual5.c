#include <stdio.h>
#include <string.h>

int main() {
    char c[200];
    printf("Enter the String: \n");
    int id = 1, token;
    while (fgets(c, sizeof(c), stdin) != NULL) {

        c[strcspn(c, "\n")] = '\0';
        int len = strlen(c);
        for (int i = 0; i < len; i++) {
            if (c[i] == '+' && c[i + 1] == '+') {
                printf("<increment,>\n");
                i++;
            } else if (c[i] == '-' && c[i + 1] == '-') {
                printf("<decrement,>\n");
                i++;
            } else if (c[i] == '+') {
                printf("<add,>\n");
                i++;
            } else if (c[i] >= '0' && c[i] <= '9') {
                printf("<num,>\n");
            } else if (c[i] == '*') {
                printf("<Multiplication,>\n");
            } else if (c[i] == '-') {
                printf("<subtract,>\n");
            } else if (c[i] == '>') {
                if (c[i + 1] == '=') {
                    printf("<gte,>\n");
                    i++;
                } else {
                    printf("<gt,>\n");
                }
            } else if (c[i] == '<') {
                if (c[i + 1] == '=') {
                    printf("<lte,>\n");
                    i++;
                } else {
                    printf("<lt,>\n");
                }
            } else if (c[i] == '/') {
                printf("<div,>\n");
            }else if (c[i] == '=') {
                printf("<assign,>\n");
            } else if (c[i] == '!') {
                if (c[i + 1] == '=') {
                    printf("<ne,>\n");
                    i++;
                }
            } else if (c[i] == '=') {
                if (c[i + 1] == '=') {
                    printf("<equal,>\n");
                    i++;
                }
            } else if (c[i] != ' ') {
                int j = i;
                while (c[j] >='a' && c[j] <= 'z') {
                    j++;
                }
                printf("<id,%d>\n", id++);
                i = j - 1;
            }
        }
    }

    return 0;
}
