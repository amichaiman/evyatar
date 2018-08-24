#include <stdio.h>
#include <string.h>

#define MAX_WORD_LEN 20

void foo(FILE *pFILE);

int readWord(FILE *f, long pos, char *buf);

int isInVocabulary(char *word, FILE *f);

int speller(FILE* source, FILE* vocabulary);

int main(){
    FILE *file;
    FILE *voc;
    file = fopen("foo.txt", "r");
    voc = fopen("voc.txt", "r");

    printf("%d\n", speller(file,voc));

    return 0;
}


int readWord(FILE *f, long pos, char *buf){
    fseek(f,pos,SEEK_SET);

    return fscanf(f, "%s", buf) == -1 ? -1 : (int) strlen(buf);
}

int searchWord(FILE *f, char *word){
    int count = 0;
    int wordLen;
    char buf[MAX_WORD_LEN];

    rewind(f);

    while (readWord(f,ftell(f), buf) != -1){
        if (strcmp(buf,word) == 0){
            count++;
        }
    }

    return count;
}

int speller(FILE* source, FILE* vocabulary){
    int count = 0;
    char buf[MAX_WORD_LEN];

    while(readWord(source, ftell(source), buf) != -1){
        if (!isInVocabulary(buf, vocabulary)){
            count++;
        }
    }

    return count;
}

int isInVocabulary(char *word, FILE *f) {
    return searchWord(f,word) > 0;
}
