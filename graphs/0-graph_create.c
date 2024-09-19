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

    // Allocate memory for the graph structure
    new_graph = malloc(sizeof(graph_t));
    if (!new_graph)
        return NULL;

    // Initialize the number of vertices
    new_graph->num_vertices = 0;

    // Allocate memory for the adjacency matrix
    new_graph->adj_matrix = NULL;

    return new_graph;
}
