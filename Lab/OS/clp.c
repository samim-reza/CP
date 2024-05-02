#include<stdio.h>
#include<string.h>

int main(){
    int a=0, b=0,c;
    char str[100];
    char token[100];
    fgets(str, sizeof(str), stdin);
    while(str[a]!='\0'){
        if(str[a]=='{' || str[a]=='(' || str[a]=='['){
            token[b]='4';
            b++;
        }
        if(str[a]=='}' || str[a]==')' || str[a]==']'){
            token[b]='5';
            b++;
        }
        if(isdigit(str[a])){
            while(isdigit(str[a])){
                a++;
            }
            a--;
            token[b]='6';
            b++;
        }
        if(str[a]=='+' || str[a]=='-' || str[a]=='*' || str[a]=='/' || str[a]=='%' || str[a]=='^'){
            token[b]='7';
            b++;
        }
        a++;
        token[b]='\0';
        b=0;
    }

    while(token[b]!='\0'){
        if(token[b]=='6' && token[b+1]=='7' && token[b+2]=='6' || token[b]=='4' && token[b+1]=='6' && token[b+2]=='5'){
            
            token[b]='6';
            c=b+1;
            while(token[c]!='\0'){
                token[c]=token[c+2];
                c++;
            }
        token[c]='\0';
        b=0;
        }
        else{
            b++;

        }
    }
    int d;
    d=strcmp(token,"6");

    if(d==0){
        printf("Valid Expression\n");
    }
    else{
        printf("Invalid Expression\n");
    }
}