//Student's name 1: Danielle Agat Levi
//Student's ID 1: 313357329
//Student's name 2: Tal Luvton
//Student's ID 2: 318420601

#include "List_Tests.h"

movesList getListFromUser(){
    movesList res;
    int size,i;
    Move move;
    int rows, cols;

    makeEmptyList(&res);

    printf("Please enter the number of items to be entered:\n");
    scanf("%d", &size);

    printf("Please enter the numbers:\n");
    for(i = 0; i < size; i++){
        scanf("%d", &rows);
        scanf("%d", &cols);
        move.rows = (char)rows;
        move.cols = (char)cols;
        insertDataToEndList(&res, move);
    }
    return res;
}

movesList getList(){
    movesList res;
    int size = 5,i;
    Move move;

    makeEmptyList(&res);

    for(i = 0; i < size; i++){
        move.rows = (char)((random() % 2 * 127) - 127);
        scanf("%c", &move.rows);
        scanf("%c", &move.cols);
        insertDataToEndList(&res, move);
    }
    return res;
}


void printList(movesList lst) {
	_print_list(lst.head);
}

void _print_list(moveCell* node) {
	while (node != NULL) {
		printf("row:%d col:%d\n", node->move.rows, node->move.cols);
		node = node->next;
	}
}