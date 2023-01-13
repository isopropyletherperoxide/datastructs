// binary tree project

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node *add_to_list(struct node *parent, int);
void iterate_over_tree(struct node *start);
bool is_terminal(struct node *node);

struct node {
  int value;
  struct node *children[];
};

int main(void) {
  struct node *new_node, *node1, *node2, *node3;
  new_node = add_to_list(NULL, 20);
  node1 = add_to_list(new_node, 10);
  node2 = add_to_list(new_node, 20);
  node3 = add_to_list(node2, 10);
  printf("%i", is_terminal(node1));
  iterate_over_tree(new_node);
}

bool is_terminal(struct node *node) {
  for (int n = 0; n < 2; n++)
    if (node->children[n] == NULL) {
      return (1);
    }
  return (0);
}

struct node *delete (struct node *node, struct node *parent) {
  if (is_terminal(node)) {
    free(node);
    return (NULL);
  } else {
    printf("Cannot Delete Non-Terminal Node!");
  }
  return(node);
}

void iterate_over_tree(struct node *start) {
  printf("%i \n", start->value);
  for (int i = 0; i < 2; i++) {
    if (start->children[i] != NULL) {
      iterate_over_tree(start->children[i]);
    }
  }
}

struct node *add_to_list(struct node *parent, int n) {
  struct node *new_node;

  new_node = malloc(sizeof(struct node));
  if (new_node == NULL) {
    printf("Error: malloc failed in add_to_list\n");
    exit(EXIT_FAILURE);
  }
  new_node->value = n;
  new_node->children[0] = NULL;
  new_node->children[1] = NULL;
  if (parent == NULL) {
    return new_node;
  }
  if (parent->children[0] == NULL) {
    parent->children[0] = new_node;
  } else if (parent->children[1] == NULL) {
    parent->children[1] = new_node;
  } else {
    printf("Node Already Full!\n");
    return NULL;
  }
  return new_node;
}
