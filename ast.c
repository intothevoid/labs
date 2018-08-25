#include <stdio.h>
#include <stdlib.h>

typedef struct ast_node_t
{
	char* tag;
	char* content;
	int child_count;
	struct ast_node_t** children;	
} ast_node_t;

ast_node_t* ROOT;

void add_node(ast_node_t* parent, char* tag, char* content)
{
	ast_node_t* new_node = (ast_node_t *)malloc(sizeof(ast_node_t));
	new_node->tag = tag;
	new_node->content = content;
	new_node->child_count = 0;

	*parent->children = new_node;
	parent->child_count++;
	parent->children++;
}

void print_nodes(ast_node_t* node)
{
	if(node)
	{
		printf("tag: %s\n", node->tag);
		printf("content: %s\n", node->content);
		printf("child_count: %s\n", node->child_count);

		// Print children of this child node
		while(*node->children++)
			print_nodes(*node->children);
	}
}

void delete_nodes(ast_node_t* root)
{
	ast_node_t* node = *root->children;

	if(node && node->children)
	{
		// Print children of this child node
		delete_nodes(*node->children++);

		// Next child
		root->children++;
	}

	if(node)
		free(node);
}

int main(int argc, char** argv)
{
	// Create a root node
	ROOT = (ast_node_t *)malloc(sizeof(ast_node_t));
	if(!ROOT)
		printf("Critical error - Failed to allocate space for root node. Exiting.\n");

	printf("Simple implementation of an AST in C\n");
	int choice = 3; // Exit
	char tag[10];
	char content[10];

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
				printf("Enter tag:");
				scanf("%s",&tag);
				printf("Enter content:");
				scanf("%s",&content);
				add_node(ROOT, tag, content);
				break;
			case 2:
				print_nodes(ROOT);
				break;
			default:
				printf("Invalid choice.\n");
			case 3:
				return 0;
		}
	}
	return 0;
}