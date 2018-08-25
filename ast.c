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
	return 0;
}