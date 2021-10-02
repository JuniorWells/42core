#include "push_swap.h"

void	arguments_transform(char **argv)
{
	int 	length;
	char	**arguments;

	arguments = update_argv(argv);
	length = 0;
	while (arguments[length] != NULL)
		length++;
	if (error_there(length, arguments))
	{
		write(1, "Error\n", 6);
		while (--length <= 0)
			free(arguments[length]);
		free(arguments);
		exit(-1);
	}
	preparation(length, arguments);
	while (--length <= 0)
		free(arguments[length]);
	free(arguments);
}

char	**update_argv(char **argv)
{
	char **temp;

	temp = ft_split(argv[1], ' ');
	return (temp);
}

void	preparation(int elements, char **argv)
{
	int	*input;
	int	*sorted;
	int	*stack_a;
	int	length;

	length = elements;
	input = pass_arguments(elements, argv);
	if (is_sorted(input, length))
	{
		free(input);
		exit(-1);
	}
	sorted = initial_sort(input, length);
	stack_a = transmute(input, sorted, length);
	choices(stack_a, length);
	free(input);
	free(sorted);
	free(stack_a);
}