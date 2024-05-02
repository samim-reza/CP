#include <stdio.h>
#include <string.h>

int main() {
    char c[200];
    printf("Enter the String: \n");
    int id = 1;
    while (fgets(c, sizeof(c), stdin) != NULL && c[0] != '\n') {
        c[strcspn(c, "\n")] = '\0';
        int len = strlen(c);
        for (int i = 0; i < len; i++) {
            if (c[i] == '+') {
                if (c[i + 1] == '+') {
                    printf("<increment,>\n");
                    i++;
                } else {
                    printf("<add,>\n");
                }
            } else if (c[i] == '-') {
                if (c[i + 1] == '-') {
                    printf("<decrement,>\n");
                    i++;
                } else {
                    printf("<subtract,>\n");
                }
            } else if (c[i] == '*') {
                printf("<multiplication,>\n");
            } else if (c[i] == '/') {
                printf("<division,>\n");
            } else if (c[i] == '%') {
                printf("<modulus,>\n");
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
            } else if (c[i] == '=') {
                if (c[i + 1] == '=') {
                    printf("<equal,>\n");
                    i++;
                } else {
                    printf("<assign,>\n");
                }
            } else if (c[i] == '!') {
                if (c[i + 1] == '=') {
                    printf("<ne,>\n");
                    i++;
                }
            } else if (c[i] == '&') {
                if (c[i + 1] == '&') {
                    printf("<logical_and,>\n");
                    i++;
                } else {
                    printf("<bitwise_and,>\n");
                }
            } else if (c[i] == '|') {
                if (c[i + 1] == '|') {
                    printf("<logical_or,>\n");
                    i++;
                } else {
                    printf("<bitwise_or,>\n");
                }
            }else if ((c[i] >= '0' && c[i] <= '9') || (c[i] == '.' && (c[i+1] >= '0' && c[i+1] <= '9'))) {
                printf("<num,>\n");
                while ((c[i] >= '0' && c[i] <= '9') || c[i] == '.') {
                    i++;
                }
                i--;
            } else if ((c[i] >= 'a' && c[i] <= 'z') || (c[i] >= 'A' && c[i] <= 'Z')) {
                int j = i;
                while ((c[j] >= 'a' && c[j] <= 'z') || (c[j] >= 'A' && c[j] <= 'Z')) {
                    j++;
                }
                printf("<id,%d>\n", id++);
                i = j - 1;
            }
        }
    }

    return 0;
}
