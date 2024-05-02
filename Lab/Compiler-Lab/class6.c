#include <stdio.h>
#include <string.h>

#define nonTerminal s[i]>='A' && s[i]<='Z'
#define terminal s[i]>='a' && s[i]<='z'

char S[10] = "Aa", A[10]="aaB", B[10]="bbb", C[10]="aaD", D[10]="bbd";
void expand(char s[], int length){
    for(int i=0; i<length; i++){
        if(nonTerminal){
            if(s[i]=='A'){
                expand(A,strlen(A));
            }
            else if(s[i]=='B'){
                expand(B,strlen(B));
            }
            else if(s[i]=='C'){
                expand(C,strlen(C));
            }
            else if(s[i]=='D'){
                expand(D,strlen(D));
            }
        }
        else if(terminal){
            printf("%c", s[i]);
        }
    }
}

int main()
{
    expand(S, strlen(S));
    printf("\n");
}