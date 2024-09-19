#include <stdlib.h>
#include "graphs.h"

/**
 * graph_create - Creates a graph and initializes its content.
 *
 * Return: A pointer to the allocated graph_t structure, or NULL on failure.
 */
graph_t *graph_create(void)
{
	graph_t *new_graph;

	new_graph = malloc(sizeof(graph_t));
	if (!new_graph)
		return NULL;

	new_graph->nb_vertices = 0;

	new_graph->vertices = NULL;

	return new_graph;
}
