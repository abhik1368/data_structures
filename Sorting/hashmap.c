#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
 
typedef struct hashNode {
    char data[256];
    struct hashNode *next;
} node;
 
 
// computes hashcode & mods it with hash table length to get an index.
int Index(char* data) {
    int sum = 0, i = 0, size = strlen(data);
    while (i < size) {
        //printf("%d\n",(int)(*data));
        sum += (int)(*data);
        data++;
        i++;
        printf("%d\n", sum);
    }
    return (sum%1001)%100;
}
 
void main()
{
       char s[256];
       node *hash[100];
       node *link;
       int index, i;
       for (i = 0; i < 100; i++)
        hash[i] = NULL;
 
       // Add string names the Loop until null string or quit
       while (1) {
        printf("Add a data or type \"quit\" to end.\n");
        printf("Input: ");
        gets(s);
        if (strlen(s) == 0) break;
        if (!strcmp(s, "quit")) break;
        index = Index(s);
        printf("Index: %d\n", index);
        link = (node*)malloc(sizeof(node));
        // copy string s in link->data
        strcpy(link->data, s);
        // old head becomes next of link, which is the new head.
        link->next = hash[index];
        hash[index] = link;
 
       }
 
    // Print hash table
    for (i = 0; i < 100; i++) {
        link = hash[i];
        while (link) {
            printf("Index %d: %s\n", i,link->data);
            link = link->next;
        }
    }
 
}
