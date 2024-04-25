#include "main.h"

int main(int argc, char **argv)
{
    char *path_node = NULL, *path_ele = NULL;
    char *dst_node = NULL, *dst_ele = NULL;
    for (int index = 0; index < argc; ++index)
    {
        if (strstr("-path_node", argv[index]))
        {
            path_node = argv[index + 1];
        }
        if (strstr("-path_ele", argv[index]))
        {
            path_ele = argv[index + 1];
        }
        if (strstr("-dst_node", argv[index]))
        {
            dst_node = argv[index + 1];
        }
        if (strstr("-dst_ele", argv[index]))
        {
            dst_ele = argv[index + 1];
        }
    }

    NodeDataProcess(path_node, dst_node);
    ElementDataProcess(path_ele, dst_ele);

    return 0;
}

// command
/*
 * ./app_exe -path_node ../input/NodeData.txt -dst_node NodeData.dat
 * ./app_exe -path_ele ../input/ElementData.txt -dst_ele ElementData.dat
 * ./app_exe -path_node ../input/NodeData.txt -dst_node NodeData.dat 
 *           -path_ele ../input/ElementData.txt -dst_ele ElementData.dat
 */