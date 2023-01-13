#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "linked_list.h"
#include "main.h"

int main(int argc, char *argv[]) {
  struct node *list = list_init_from_arg(argv[1]);
  parse_args(argc, argv, list);
  return 0;
}

struct node *list_init_from_arg(char *init) {
  if (init[0] != 'i' || strlen(init) < 2) {
    printf("\e[1;31mList must start with valid initializer!\e[0m\n");
    help();
    exit(1);
    return NULL;
  }
  int initializer = atoi(init + 1);
  printf("List initialized with %i\n", initializer);
  return init_list(initializer);
}

int parse_args(int argc, char *argv[], struct node *list) {
  for (int i = 2; i < argc; i++) {
    switch (argv[i][0]) {
    case 'a':
      if (strlen(argv[i]) < 2) {
        printf("\e[1;31mInvalid append command, appending failed!\e[0m\n");
        break;
      }
      printf("Appending Node \n");
      int new_node;
      // sscanf(argv[i], "a%d", &new_node); // old bad implementation
      new_node = atoi(argv[i] + 1);
      add_node(new_node, list);
      break;
    case 'd':
      printf("Deleting Node\n");
      delete_node(list);
      break;
    case 'p':
      printf("Prettyprinting your list! \n");
      pretty_print(list);
      break;
    case 'h':
      help();
      break;

    default:
      printf("\e[1;31m%s, Command not recognised!\e[0m\n", argv[i]);
    }
  }
  return 0;
}

void help() {
  printf("iX - initialize list with X as the contents\naX - append node with X "
         "as the contents\nd - delete last node\n"
         "p - prettyprint the linked list\nh - help \n");
}
