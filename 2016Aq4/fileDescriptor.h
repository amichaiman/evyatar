#ifndef EVYATAR_FILEDESCRIPTOR_H
#define EVYATAR_FILEDESCRIPTOR_H

#include <stdio.h>

typedef enum{
    false,
    true
} bool;

typedef struct fileDescriptor* FileDescriptor;

FILE* createFile(char *fileName);
bool deleteFile(FileDescriptor fileDescriptor);
bool openFile(FileDescriptor fileDescriptor, char *mode);
bool closeFile(FileDescriptor fileDescriptor);
char readChar(FileDescriptor fileDescriptor);
bool writeChar(FileDescriptor fileDescriptor, char toWrite);
char* getFileName(FileDescriptor fileDescriptor);
FileDescriptor* copyFile(FileDescriptor fileDescriptor);
bool isSame(FileDescriptor fileDescriptor1, FileDescriptor fileDescriptor2);


#endif //EVYATAR_FILEDESCRIPTOR_H
