#include <stdio.h>

typedef struct ast_node_t
{
	char* tag;
	char* content;
	int child_count;
	struct ast_node_t** children;	
} ast_node_t;

int main(int argc, char** argv)
{

	printf("Simple implementation of an AST in C\n");
	int choice = 3; // Exit

	while(1)
	{
		printf("============================\n");
		printf("Please choose an operation -\n");
		printf("1. Add node\n");
		printf("2. Print all nodes\n");
		printf("3. Exit\n");
		printf("============================\n\n");

		scanf("%d", &choice);

		switch(choice)
		{
			case 1:
				printf("Add Node\n");
				break;
			case 2:
				printf("Print All Nodes\n");
				break;
			default:
				printf("Invalid choice.\n");
			case 3:
				return 0;
		}
	}
	return 0;
}