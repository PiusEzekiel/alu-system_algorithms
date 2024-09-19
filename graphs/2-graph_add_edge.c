#include "graphs.h"

vertex_t *get_vertex(graph_t *graph, const char *str);
edge_t *create_edge(vertex_t *src_vertex, vertex_t *dest_vertex,
		edge_type_t type);

/**
 * graph_add_edge - Adds an edge between two vertices in the graph.
 * @graph: Pointer to the graph.
 * @src: String value of the source vertex.
 * @dest: String value of the destination vertex.
 * @type: Type of edge (UNIDIRECTIONAL or BIDIRECTIONAL).
 *
 * Return: 1 on success, 0 on failure.
 */
int graph_add_edge(graph_t *graph, const char *src,
		const char *dest, edge_type_t type)
{
    vertex_t *src_vertex, *dest_vertex;
    edge_t *edge;

    if (graph == NULL || src == NULL || dest == NULL)
    {
        return (0);
    }

    if (type != UNIDIRECTIONAL && type != BIDIRECTIONAL)
    {
        return (0);
    }

    src_vertex = get_vertex(graph, src);
    dest_vertex = get_vertex(graph, dest);

    if (src_vertex == NULL || dest_vertex == NULL)
    {
        return (0);
    }

    edge = create_edge(src_vertex, dest_vertex, type);
    if (edge == NULL)
    {
        return (0);
    }

    src_vertex->nb_edges += 1;
    if (type == BIDIRECTIONAL)
    {
        dest_vertex->nb_edges += 1;
    }

    return (1);
}

/**
 * get_vertex - Retrieves a vertex from the graph.
 * @graph: Pointer to the graph.
 * @str: String value of the vertex.
 *
 * Return: Pointer to the vertex or NULL if not found.
 */

vertex_t *get_vertex(graph_t *graph, const char *str)
{
    vertex_t *vertex_ptr = graph->vertices;

    while (vertex_ptr)
    {
        if (strcmp(vertex_ptr->content, str) == 0)
        {
            return (vertex_ptr);
        }
        vertex_ptr = vertex_ptr->next;
    }

    return (NULL);
}
/**
 * create_edge - Creates an edge between two vertices.
 * @src_vertex: Pointer to the source vertex.
 * @dest_vertex: Pointer to the destination vertex.
 * @type: Type of edge (UNIDIRECTIONAL or BIDIRECTIONAL).
 *
 * Return: Pointer to the new edge or NULL on failure.
 */

edge_t *create_edge(vertex_t *src_vertex, vertex_t *dest_vertex, edge_type_t type)
{
    edge_t *edge = malloc(sizeof(edge_t));

    if (edge == NULL)
    {
        return (NULL);
    }

    edge->dest = dest_vertex;
    edge->next = src_vertex->edges;
    src_vertex->edges = edge;

    if (type == BIDIRECTIONAL)
    {
        edge_t *reverse_edge = malloc(sizeof(edge_t));

        if (reverse_edge == NULL)
        {
            free(edge);
            return (NULL);
        }

        reverse_edge->dest = src_vertex;
        reverse_edge->next = dest_vertex->edges;
        dest_vertex->edges = reverse_edge;
    }

    return (edge);
}
