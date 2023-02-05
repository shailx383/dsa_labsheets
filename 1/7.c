#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* substr(char* str, int start, int end){
    int len = strlen(str);
    char*res = (char*)malloc((end -start)*sizeof(char));
    int ctr = 0;
    for (int i = start; i < end+1; i++){
        res[ctr] = str[i];
        ctr++;
    }
    res[ctr] = '\0';
    return res;
}

int in(char*main, char c){
    int flag = 0;
    for (int i = 0; i < strlen(main); i++){
        if (c == main[i]){
            flag = 1;
            break;
        }
    }
    return flag;
}

bool isSubset(char*main, char*sub){
    int flag = 1;
    for(int i = 0; i < strlen(sub); i++){
        if (in(main, sub[i]) != 1){
            flag = 0;
            break;
        }
    }
    return flag;
}

int main(){
    char s[100];
    char w[100];
    scanf("%[^\n]s", s);
    scanf("%s", w);
    if (strlen(w) > strlen(s)){
        printf("NO WINDOW");
    }
    else{
        for (int window_size = strlen(s); window_size >= strlen(w); window_size--){
            
        }
    }    
    return 0;
}
    
