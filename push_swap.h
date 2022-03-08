/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smhah <smhah@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:03:36 by smhah             #+#    #+#             */
/*   Updated: 2021/11/08 15:41:52 by smhah            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

void	*g_pointer[4000];
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
int		check_double_number(char **tab);
int		is_not_digit(char *str);
int		check_is_digit(char **tab);
int		is_sorted(char **tab);
int		check_max_min_int(char **tab);
int		ft_strcmpr(char *s1, char *s2);
int		ft_strlen(const char *str);
char	*ft_strdup(const char *s);
char	*ft_strcpy(char *s1, char *s2);
int		ft_strcmpr(char *s1, char *s2);
void	*m_malloc(size_t n, int indicator);
void	to_free(int count);
void	delete_top_value(char ***tab);
char	*ft_itoa(int n);
void	swap_nb(char **a, char **b);
void	push_b(char ***stack_index, char ***stack_b, int size);
void	push_a(char ***stack_index, char ***stack_b, int size);
void	swap_a(char ***stack_index);
void	rotaate_a(char ***stack_index, int size);
void	rotate_reeverse_a(char ***stack_index, int size);
void	sorting_data(char ***stack_sorted, int size);
void	copy_stack_origine(char ***stack_sorted,
			char ***stack_origine, int size);
void	compare_sort_nb_stacks(char ***stack_sorted,
			char **stack_origine, char ***stack_index, int size);
int		ft_calcule_bits(int c);
void	empty_b(char ***stack_b, int size);
char	*top_value(char **tab);
void	ft_sort_binary(char ***stack_index,
			int size, int i, char ***stack_b);
void	ft_sort(int size, char ***stack_index);
void	ft_sort_three_case(int size, char ***stack_index);
void	search_zero_push(int size, char ***stack_index, char ***stack_b);
void	search_one_push(int size, char ***stack_index, char ***stack_b);
void	search_zero_one_push(int size, char ***stack_index, char ***stack_b);
void	case_one(char ***stack_index);
void	case_two(char ***stack_index, int size);
void	case_three(char ***stack_index, int size);
void	case_four(char ***stack_index, int size);
char	*ft_strdup_1(const char *s);
void	new_delete_top_value(char ***tab, int size);

#endif