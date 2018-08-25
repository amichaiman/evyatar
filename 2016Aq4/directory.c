

#include <string.h>
#include <stdlib.h>
#include "direcory.h"

DirectoryPointer createDir(char *name) {
    DirectoryPointer newDirectory = (DirectoryPointer) malloc (sizeof(Directory));

    newDirectory->directoryName = (char*) malloc ((strlen(name)+1)* sizeof(char));
    strcpy(newDirectory->directoryName, name);

    newDirectory->fileList = linkedListCreate();

     return newDirectory;
}

DirectoryPointer destroyDir(DirectoryPointer dir) {
    linkedListFree(dir->fileList);
    free(dir->directoryName);
    return dir;
}

int addFileDescriptor(DirectoryPointer dir, FileDescriptor file) {
    int success = linkedListAdd(dir->fileList, file);

    return success;
}

int removeFileDescriptor(DirectoryPointer dir, FileDescriptor file) {
    int success = linkedListRemove(dir->fileList, file);

    return success;
}

void print(DirectoryPointer dir) {
    printf("file name: %s\n", dir->directoryName);
    linkedListPrintAll(dir->fileList);
}

