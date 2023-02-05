#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char* reverse_word(char* str){
    char* new_str = (char*)malloc(strlen(str) * sizeof(char));
    int ctr = 0;
    for (int i = strlen(str) - 1; i >=0; i--){
        new_str[ctr] = str[i];
        ctr++;
    }
    new_str[ctr] = '\0';
    return new_str;
}

bool isPalindrome(char* str){
    char* rev = reverse_word(str);
    if (strcmp(str, rev) == 0) return true;
    else return false;
}


int main(){
    char str[1000];
	char *ptr = str;
	scanf("%[^\n]s", str);
	int len = strlen(str);
	char words[1000][1000];
	int wordcount = 0, lettercount = 0;
	for (int i = 0; i < len; i++)
	{
		if (*ptr != ' ')
		{
			words[wordcount][lettercount] = *ptr;
			lettercount++;
		}
		else
		{
			words[wordcount][lettercount] = '\0';
			wordcount++;
			lettercount = 0;
		}
		ptr++;
	}
    wordcount++;
    char palindromes[1000][1000];
    int flag = 0;
    for (int i = 0; i < wordcount; i++){
        if (isPalindrome(words[i])){
            flag = 1;
        }
        else flag = 0;
    }
    if (flag == 1){
        int no_of_pals = 0;
        for (int i = 0; i < wordcount; i++){
            printf("%s ", reverse_word(words[i]));
            if (isPalindrome(words[i])){
                for (int j = 0; j < strlen(words[i]); j++){
                    palindromes[no_of_pals][j] = words[i][j];
                }
                no_of_pals++;
            }
        }
        printf("\n");
        for (int i = 0; i < no_of_pals; i++){
            printf("%s ", palindromes[i]);
        }
    }
    else printf("NO PALINDROMES");
}