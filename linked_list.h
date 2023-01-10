typedef struct node {
  int contents;
  struct node *next;
} node;

struct node *init_list(int contents);

int pretty_print(struct node *starting_node);

int add_node(int contents, struct node *prev);
