#ifndef MAIN_H_
#define MAIN_H_

// header file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct
typedef struct node
{
    /* data */
    int id;
    double x, y, z;
} Node;

typedef struct element
{
    int id;
    int node_1, node_2, node_3;
} Element;

// function prototype
void NodeDataProcess(const char *, const char *);
void ElementDataProcess(const char *, const char *);

#endif