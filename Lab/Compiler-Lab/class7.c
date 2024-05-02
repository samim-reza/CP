#include <stdio.h>
#include <string.h>

#define nonTerminal s[i]>='A' && s[i]<='Z'
#define terminal s[i]>='a' && s[i]<='z'

char S[10] = "Aa", A[10]="aaB", B[10]="bbb", C[10]="aaD", D[10]="bbd";
char T[100];
int treeIndex = 0;

void expand(char s[], int length){
    for(int i=0; i<length; i++){
        if(nonTerminal){
            if(s[i]=='A'){
                T[treeIndex++] = 'A';
                expand(A,strlen(A));
                treeIndex--;
            }
            else if(s[i]=='B'){
                T[treeIndex++] = 'B';
                expand(B,strlen(B));
                treeIndex--;
            }
            else if(s[i]=='C'){
                T[treeIndex++] = 'C';
                expand(C,strlen(C));
                treeIndex--;
            }
            else if(s[i]=='D'){
                T[treeIndex++] = 'D';
                expand(D,strlen(D));
                treeIndex--;
            }
        }
        else if(terminal){
            T[treeIndex++] = s[i];
        }
    }
}

int main()
{
    expand(S, strlen(S));

    for(int i=0; i<treeIndex; i++)
    {
        printf("%c",T[i]);
    }
    printf("\n");
}