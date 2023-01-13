#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  struct node *start;
  int length;
} list;

typedef struct node {
  struct node *prev;
  int contents;
  struct node *next;

} node;

struct node *new_node(node *prev_val, int conts, node *next_val) {
  node *node_addr = malloc(sizeof(node));
  node_addr->contents = conts;
  node_addr->prev = prev_val;
  node_addr->next = next_val;
  if (prev_val != NULL) {
    prev_val->next = node_addr;
  }
  return (node_addr);
}

int count_elements(node *list) {
  int count = 1;
  while (list->next != NULL) {
    count++;
    list = list->next;
  }
  return count;
}

void print_elements(node *list, int count) {
  printf("%i ", list->contents);
  for (int i = 0; i < count; i++) {
    printf("%i ", list->next->contents);
    list = list->next;
  }
}

void del_node(node *node) {
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
}

void add_node(node *list, int conts) {
  struct node *dest = list;
  while (1) {
    if (dest->next == NULL) {
      new_node(dest, conts, NULL);
      break;
    } else {
      dest = dest->next;
    }
  }
}

int main(void) {
  struct node *list = new_node(NULL, 3, NULL);
  add_node(list, 6);
  add_node(list, 8);
  del_node(list->next);
  print_elements(list, 1);
}
