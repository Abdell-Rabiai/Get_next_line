#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include "get_next_line_utils.c"

char *get_next_line(int fd, size_t buffer_size);

#endif