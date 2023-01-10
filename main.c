#include "linked_list.h"


// todo: structure DSL

int main(int argc, char *argv[])
{
        struct node *list = init_list(1);
        add_node(7, list);
        add_node(3, list);
        add_node(8, list);
        add_node(3, list);
        delete_node(list);
        pretty_print(list);
        return 0;
}
