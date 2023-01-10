#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

struct node *init_list(int contents) {
  struct node *init = malloc(sizeof(node));
  init->contents = 0;
  init->next = NULL;
  return init;
}

int pretty_print(struct node* starting_node){
        struct node *cur_node = starting_node;
        while(cur_node != NULL){
                if(cur_node->next == NULL){
                printf("%i -> NULL", cur_node->contents);
                break;
                }
                printf("%i -> ", cur_node->contents);
                cur_node = cur_node->next;
        }
        return 0;
}

int add_node(int contents, struct node *prev) {
  while (prev->next != NULL) {
    prev = prev->next;
  }
  prev->next = malloc(sizeof(node));
  prev->next->contents = contents;
  prev->next->next = NULL;
  return 0;
};


