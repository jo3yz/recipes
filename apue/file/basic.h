//
// Created by joey on 3/31/20.
//

#ifndef APUE_BASIC_H
#define APUE_BASIC_H

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void checkSetSeek()
{
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1)
        std::cout<<"cannot seek"<<std::endl;
    else
        std::cout<<"seek ok"<<std::endl;
}

void testForkFd()
{
    int fd;
    if((fd = creat("test.file", S_IRUSR | S_IWUSR | S_IRGRP)) < 0)
        perror("create error");
    if(fork() == 0)
    {
        std::cout<<"child process fd: "<<fd<<std::endl;
        lseek(fd, 10, SEEK_CUR);
        char buf[] = "abcdefg";
        write(fd, buf, sizeof buf);
    }
    else
    {
        std::cout<<"parent process fd: "<<fd<<std::endl;
        lseek(fd, 10, SEEK_CUR);
        char buf[] = "abcdefg";
        write(fd, buf, sizeof buf);
    }

    close(fd);

    // test conclusion: fd copy by fork() or dup() share item in system file table
    // that is to say, they share offset/file status(wrx)/v node pointer
}

void testDup()
{
    int fd;
    if((fd = creat("test.file", S_IRUSR | S_IWUSR | S_IRGRP)) < 0)
        perror("create error");

    std::cout<<"orginal fd: "<<fd<<std::endl;
    lseek(fd, 0, SEEK_CUR);
    char buf1[] = "abcdefg";
    write(fd, buf1, sizeof buf1);

    int fd_copy = dup(fd);
    std::cout<<"orginal fd: "<<fd<<std::endl;
    char buf2[] = "1234567";
    lseek(fd_copy, 0, SEEK_CUR);
    write(fd_copy, buf2, sizeof buf2);

    // check with "od -c test.file"
}


void printFileType(int argc, char **argv)
{
    struct stat buf;
    std::string ptr{};
    for(int i = 1; i < argc; ++i)
    {
        std::cout<<argv[i]<<":";
        if(lstat(argv[i], &buf) < 0)
        {
            perror("lstat error");
            continue;
        }

        if(S_ISREG(buf.st_mode))
            ptr = "regular";
        else if(S_ISDIR(buf.st_mode))
            ptr = "directory";
        else if(S_ISSOCK(buf.st_mode))
            ptr = "socket";
        else
            ptr = "unknown";

        std::cout<<ptr<<std::endl;
    }
}

#endif //APUE_BASIC_H
