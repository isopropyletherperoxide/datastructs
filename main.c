#include "linked_list.h"

int main(int argc, char *argv[])
{
        struct node *list = init_list(1);
        add_node(7, list);
        add_node(3, list);
        add_node(8, list);
        pretty_print(list);
        return 0;
}
