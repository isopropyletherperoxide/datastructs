// implementation of Linked Lists in C 
#include "linked_list.h"

#include <stdio.h>
#include <stdlib.h>

struct node *init_list(int contents) {
  struct node *init = malloc(sizeof(node));
  init->contents = contents;
  init->next = NULL;
  return init;
}

int pretty_print(struct node *starting_node) {
  struct node *cur_node = starting_node;
  while (cur_node != NULL) {
    if (cur_node->next == NULL) {
      printf("%i -> \e[1;32mNULL\e[0m\n", cur_node->contents);
      break;
    }
    printf("%i -> ", cur_node->contents);
    cur_node = cur_node->next;
  }
  return 0;
}

int delete_node(struct node *list) { // pops off node from end of list
  while (list->next->next != NULL) {
    list = list->next;
  }
  free(list->next);
  list->next = NULL;
  return 0;
}

int add_node(int contents, struct node *prev) { // appends node to end of list
  while (prev->next != NULL) {
    prev = prev->next;
  }
  prev->next = malloc(sizeof(node));
  prev->next->contents = contents;
  prev->next->next = NULL;
  return 0;
};
