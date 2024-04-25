#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024

int main(int argc, char **argv)
{
    char *path_msh = NULL;
    int flag_node = 0, flag_ele = 0;
    for (int index = 0; index < argc; ++index)
    {
        if (strstr("-path_msh", argv[index]))
        {
            path_msh = argv[index + 1];
        }
        if (strstr("-enable_node", argv[index]))
        {
            flag_node = 1;
        }
        if (strstr("-enable_ele", argv[index]))
        {
            flag_ele = 1;
        }
    }

    FILE *fp = NULL;
    if ((fp = fopen(path_msh, "rb")) == NULL)
    {
        fprintf(stderr, "Cannot open file \"%s\"!\n", path_msh);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_SIZE];
    int flag_node_data = 0, flag_ele_data = 0;
    while(!feof(fp))
    {
        fgets(buffer, MAX_SIZE, fp);
        if(flag_node == 1)
        {
            if(strstr(buffer, "$Nodes"))
            {
                flag_node_data = 1;
                continue;
            }
            if(strstr(buffer, "$EndNodes"))
            {
                flag_node_data = 0;
                continue;
            }
            if(flag_node_data == 1)
            {
                printf("%s", buffer);
            }
        }
        else if(flag_ele == 1)
        {
            if(strstr(buffer, "$Elements"))
            {
                flag_ele_data = 1;
                continue;
            }
            if(strstr(buffer, "$EndElements"))
            {
                flag_ele_data = 0;
                continue;
            }
            if(flag_ele_data == 1)
            {
                printf("%s", buffer);
            }
        }
    }

    fclose(fp);

    return 0;
}