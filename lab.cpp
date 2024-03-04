#include <stdio.h>
#include<string.h>

int main()
{
    char input[200];
    char comment[200];
    int index = 0;
    printf("input: ");
    scanf("%[^\n]%*c", input);
    for(int i=0; i<strlen(input); i++){
        if(input[i]=='/' && input[i+1]=='/'){
            for(int j=i; j<strlen(input)-2; j++){
                comment[index++] = input[j+2];
            }
            break;
        }
    }
    printf("comment: %s\n", comment);
    printf("Number of characters in comment: %d\n", strlen(comment));
}
