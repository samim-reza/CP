#include <stdio.h>

int main() {
    char c[2000];
    int i = 0;
    int count = 0;
    int line_count = 1;
    printf("Enter the code with comments: \n");

    while (fgets(c, sizeof(c), stdin) != NULL) {
        i = 0;
        while (c[i] != '\0') {
            if (c[i] == '/' && c[i + 1] == '/') {
                printf("Single-line comment found at line %d: ", line_count);
                i = i + 2;
                while (c[i] != '\0' && c[i] != '\n') {
                    count++;
                    putchar(c[i]);
                    i++;
                }
                putchar('\n');
            }
            else if (c[i] == '/' && c[i + 1] == '*') {
                printf("Multi-line comment found starting at line %d: ", line_count);
                i = i + 2;
                while (!(c[i] == '*' && c[i + 1] == '/') && c[i] != '\0') {
                    count++;
                    putchar(c[i]);
                    if (c[i] == '\n') {
                        line_count++;
                    }
                    i++;
                }
                if (c[i] == '*' && c[i + 1] == '/') {
                    putchar('*');
                    putchar('/');
                    count += 2;
                }
                putchar('\n');
            }
            else {
                i++;
            }
        }

        line_count++;
    }
    printf("The number of letters in the comments is: %d\n", count);

    return 0;
}
