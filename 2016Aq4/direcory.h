//
// Created by amichai on 25/08/18.
//

#ifndef EVYATAR_DIRECORY_H
#define EVYATAR_DIRECORY_H
#include "fileDescriptor.h"
#include "linkedlist.h"

typedef struct{
    LinkedList *fileList;
    char *directoryName;
} *DirectoryPointer, Directory;

DirectoryPointer createDir(char *name);
DirectoryPointer destroyDir(DirectoryPointer dir);
int addFileDescriptor(DirectoryPointer dir, FileDescriptor file);
int removeFileDescriptor(DirectoryPointer dir, FileDescriptor file);
void print(DirectoryPointer dir);

#endif //EVYATAR_DIRECORY_H
