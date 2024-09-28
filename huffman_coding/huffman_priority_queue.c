#include "heap.h"
#include "huffman.h"

/**
 * huffman_priority_queue - Creates a priority queue (min-heap)
 * for Huffman coding
 * @data: An array of characters
 * @freq: An array of associated frequencies
 * @size: The size of the data and freq arrays
 *
 * Return: A pointer to the created min-heap (priority queue),
 * or NULL on failure
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
       	heap_t *heap;
	binary_tree_node_t *node;
	symbol_t *symbol;
	size_t i;

	heap = heap_create();
	if (!heap)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		symbol = symbol_create(data[i], freq[i]);
		if (!symbol)
		{
			heap_destroy(heap);
			return (NULL);
		}

		node = binary_tree_node(NULL, symbol);
		if (!node)
		{
			free(symbol);
			heap_destroy(heap);
			return (NULL);
		}

		if (heap_insert(heap, node) == NULL)
		{
			free(symbol);
			free(node);
			heap_destroy(heap)
			return (NULL);
		}
	}
	
	return (heap);
}
