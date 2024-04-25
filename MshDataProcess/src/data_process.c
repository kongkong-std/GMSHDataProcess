#include "main.h"
#define MAX_SIZE 1024

void ElementDataProcess(const char *path, const char *dst)
{
    FILE *fp = NULL;
    if ((fp = fopen(path, "rb")) == NULL)
    {
        fprintf(stderr, "Cannot open file - \"%s\"\n", path);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_SIZE];
    int ele_block = 0, ele_number = 0;

    fgets(buffer, MAX_SIZE, fp);
    sscanf(buffer, "%d%d", &ele_block, &ele_number);

    Element *element_data = NULL;
    if ((element_data = (Element *)malloc(ele_number * sizeof(Element))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed - \"element_data\"\n");
        exit(EXIT_FAILURE);
    }

    int cnt_ele_id = 0;
    for (int index = 0; index < ele_block; ++index)
    {
        fgets(buffer, MAX_SIZE, fp);
        int ele_dim_block = 0, cnt_ele_block = 0;
        sscanf(buffer, "%d%*d%*d%d", &ele_dim_block, &cnt_ele_block);
        for (int index_i = 0; index_i < cnt_ele_block; ++index_i)
        {
            fgets(buffer, MAX_SIZE, fp);
            switch (ele_dim_block)
            {
            case 0:
                sscanf(buffer, "%d%d", &((element_data + cnt_ele_id)->id),
                       &((element_data + cnt_ele_id)->node_1));
                (element_data + cnt_ele_id)->node_2 = 0;
                (element_data + cnt_ele_id)->node_3 = 0;
                ++cnt_ele_id;
                break;

            case 1:
                sscanf(buffer, "%d%d%d", &((element_data + cnt_ele_id)->id),
                       &((element_data + cnt_ele_id)->node_1),
                       &((element_data + cnt_ele_id)->node_2));
                (element_data + cnt_ele_id)->node_3 = 0;
                ++cnt_ele_id;
                break;

            case 2:
                sscanf(buffer, "%d%d%d%d", &((element_data + cnt_ele_id)->id),
                       &((element_data + cnt_ele_id)->node_1),
                       &((element_data + cnt_ele_id)->node_2),
                       &((element_data + cnt_ele_id)->node_3));
                ++cnt_ele_id;
                break;
            }
        }
    }

    fclose(fp);

    if ((fp = fopen(dst, "wb")) == NULL)
    {
        fprintf(stderr, "Cannot open file - \"%s\"\n", dst);
        exit(EXIT_FAILURE);
    }

    for (int index = 0; index < ele_number; ++index)
    {
        fprintf(fp, "%d\t%d\t%d\t%d\n", element_data[index].id,
                element_data[index].node_1,
                element_data[index].node_2,
                element_data[index].node_3);
    }

    fclose(fp);

    //  free memory
    free(element_data);
}

void NodeDataProcess(const char *path, const char *dst)
{
    FILE *fp = NULL;
    if ((fp = fopen(path, "rb")) == NULL)
    {
        fprintf(stderr, "Cannot open file - \"%s\"\n", path);
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_SIZE];
    int node_block = 0, node_number = 0;

    fgets(buffer, MAX_SIZE, fp);
    sscanf(buffer, "%d%d", &node_block, &node_number);

    Node *node_data = NULL;
    if ((node_data = (Node *)malloc(node_number * sizeof(Node))) == NULL)
    {
        fprintf(stderr, "Memory allocation failed - \"node_data\"\n");
        exit(EXIT_FAILURE);
    }

    int cnt_node_id = 0, cnt_node_coor = 0;
    for (int index = 0; index < node_block; ++index)
    {
        fgets(buffer, MAX_SIZE, fp);
        int cnt_node_block = 0;
        sscanf(buffer, "%*d%*d%*d%d", &cnt_node_block);
        for (int index_i = 0; index_i < cnt_node_block; ++index_i)
        {
            fgets(buffer, MAX_SIZE, fp);
            sscanf(buffer, "%d", &((node_data + cnt_node_id)->id));
            ++cnt_node_id;
        }
        for (int index_i = 0; index_i < cnt_node_block; ++index_i)
        {
            fgets(buffer, MAX_SIZE, fp);
            sscanf(buffer, "%lf%lf%lf", &((node_data + cnt_node_coor)->x),
                   &((node_data + cnt_node_coor)->y),
                   &((node_data + cnt_node_coor)->z));
            ++cnt_node_coor;
        }
    }

    fclose(fp);

    if ((fp = fopen(dst, "wb")) == NULL)
    {
        fprintf(stderr, "Cannot open file - \"%s\"\n", dst);
        exit(EXIT_FAILURE);
    }

    for (int index = 0; index < node_number; ++index)
    {
        fprintf(fp, "%d\t%021.16le\t%021.16le\t%021.16le\n", node_data[index].id,
                node_data[index].x,
                node_data[index].y,
                node_data[index].z);
    }

    fclose(fp);

    // free memory
    free(node_data);
}