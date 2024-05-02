#include <stdio.h>
#include <string.h>

int check_a(char c[], int len) {
    if(len == 0 || len != 1)
        return 0;
    else if(c[0] != 'a')
        return 0;
    return 1;
}

int check_abb(char c[], int len) {

        if (c[0] != 'a') {
            return 0;
        }
        else if (c[1] != 'b') {
            return 0;
        }
        else if (c[2] != 'b') {
            return 0;
        }
    if(len == 0 || len !=3)
        return 0;
    return 1;
}

int check_a_star_b_plus(char c[], int len) {
        int  i,a_count = 0, b_count = 0;
        int valid = 1;
        for(i=0; i<len; i++){
            if(c[i] == 'a'){
                a_count++;
            }
            else break;
        }
        if(i==len){
            valid = 0;
            return 0;
        }
        for(int j=i; j<len; j++){
            if(c[j] == 'b'){
                b_count++;
            }
            else{
                valid = 0;
                return 0;
            }
        }
        if(len == 0)
            return 0;

    return 1;
        // if (valid && b_count > 0) {
        //     printf("String '%s' matches the regular expression 'a*b+'.\n", c);
        // } else {
        //     printf("String '%s' does not match the regular expression 'a*b+'.\n", c);
        // }
}

int main() {
    char c[200];
    printf("Enter the String: \n");

    while (fgets(c, sizeof(c), stdin) != NULL) {

        c[strcspn(c, "\n")] = '\0';
        int len = strlen(c);

        if (check_a(c, len)) {
            printf("String '%s' matches the regular expression 'a'.\n", c);
        } else if (check_abb(c, len)) {
            printf("String '%s' matches the regular expression 'abb'.\n", c);
        } else if (check_a_star_b_plus(c, len)) {
            printf("String '%s' matches the regular expression 'a*b+'.\n", c);
        } else {
            printf("String '%s' does not match any of the regular expressions.\n", c);
        }
        
    }

    return 0;
}
