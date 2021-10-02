/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchaniot <kchaniot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:33:22 by kchaniot          #+#    #+#             */
/*   Updated: 2021/10/02 23:25:51 by kchaniot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

int		error_there(int argc, char **argv);
int		has_duplicates(int argc, char **argv);
int		more_than_int(int argc, char **argv);
int		more_than_digits(int argc, char **argv);
int		is_sorted(int *arr, int len);
int		find_min(int *arr, int len);
int		has_double(int len, int *input);
int		out_of_limits(int len, int *input);
int		*pass_arguments(int argc, char **argv);
int		*initial_sort(int *array, int len);
int		*transmute(int *unsorted, int *sorted, int len);
int		*handle_input_variable(char **argv, int *len);
void	free_and_out(int len, char **s);
void	free_and_in(int len, char **s);
void	error_here(int len, int *input);
void	implement(int *input, int length);
void	choices(int *stack_a, int length);
void	swap_a(int *arr);
void	swap_b(int *arr);
void	swap_both(int *arr1, int *arr2);
void	push_a(int *dest, int *src, int *len_dest, int *len_src);
void	push_b(int *dest, int *src, int *len_dest, int *len_src);
void	rotate_a(int *arr, int len);
void	rotate_b(int *arr, int len);
void	rotate_both(int *arr1, int *arr2, int len1, int len2);
void	rev_rotate_a(int *arr, int len);
void	rev_rotate_b(int *arr, int len);
void	rev_rotate_both(int *arr1, int *arr2, int len1, int len2);
void	sort_2(int *arr, int len);
void	sort_3(int *arr, int len);
void	sort_4(int *arr, int len);
void	sort_5(int *arr, int len);
void	sort_big(int *arr_a, int len_a);
void	the_final_sort(int *stack_a, int *stack_b, int len_a, int max_bits);

#endif
