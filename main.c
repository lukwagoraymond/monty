#include "monty.h"

/**
* Global data - collection of monty data variables
*/
var_t data;

/*
* main -    Controls Program flow
* @argc:    Argument Count
* @argv:    Argument List
* Return:   Return Nothing
*/

int main (int argc, char **argv)
{
    stack_t *head = NULL; /* for tokenised list */
    size_t buffer_size = 0;
    char **tokens = NULL; /* for tokenised list */

    memset((void *) &data, 0, sizeof(data));

    if (argc != 2)
    {
        error_1(1);
    }

    var_t.filename = argv[1]
    var_t.fp = fopen(var_t.filename, r+);
    if (var_t.fp == NULL)
    {
        error_1(2);
    }

    while ((getline(&var_t.buffer, &buffer_size, var_t.fp)) != 1)
    {
        var_t.line_number++;
        tokens = //tokenize(var_t.buffer) /* result is a top of list */
        if (tokens)
        {
            call(tokens, &head);
            free(tokens);
        }
    }
    free(var_t.buffer);
    free_dlistint(head);
    fclose(var_t.fp);

    return (0);
}
