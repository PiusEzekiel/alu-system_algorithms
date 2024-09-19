#include <stdlib.h>
#include <string.h>
#include "graphs.h"

/**
 * graph_add_edge - Adds an edge between two vertices in a graph.
 *
 * @graph: Pointer to the graph.
 * @src: String identifying the source vertex.
 * @dest: String identifying the destination vertex.
 * @type: Type of edge (UNIDIRECTIONAL or BIDIRECTIONAL).
 *
 * Return: 1 on success, or 0 on failure.
 */

int graph_add_edge(graph_t *graph, const char *src, const char *dest, edge_type_t type)
{
	vertex_t *src_vertex = NULL;
	vertex_t *dest_vertex = NULL;
	edge_t *new_edge;

	for (int i = 0; i < graph->num_vertices; i++)
	{
		if (strcmp(graph->vertices[i]->str, src) == 0)
			src_vertex = graph->vertices[i];
		if (strcmp(graph->vertices[i]->str, dest) == 0)
			dest_vertex = graph->vertices[i];
	}

	if (!src_vertex || !dest_vertex)
		return (0);

	new_edge = malloc(sizeof(edge_t));
	if (!new_edge)
		return (0);

	new_edge->dest = dest_vertex;
	new_edge->next = src_vertex->edges;
	src_vertex->edges = new_edge;

	if (type == BIDIRECTIONAL)
	{
		edge_t *reverse_edge = malloc(sizeof(edge_t));
		if (!reverse_edge)
		{
			free(new_edge);
			return (0);
		}
		
		reverse_edge->dest = src_vertex;
		reverse_edge->next = dest_vertex->edges;
		dest_vertex->edges = reverse_edge;
	}

	return (1);
}
