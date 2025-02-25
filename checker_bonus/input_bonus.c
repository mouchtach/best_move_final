/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymouchta <ymouchta@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:27:25 by ymouchta          #+#    #+#             */
/*   Updated: 2025/02/11 10:27:28 by ymouchta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	if_double_sort(int **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (*tab[i] == *tab[j])
				return (ft_free_int(&tab), ft_error(), 1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	**atoi_arg(char **str, int *count)
{
	int		i;
	long	res;
	int		**tab;

	i = 0;
	while (str[*count])
		(*count)++;
	tab = (int **)malloc(sizeof(int *) * (*count + 1));
	if (!tab)
		return (ft_free_tab_str(&str), NULL);
	while (i < *count)
	{
		tab[i] = malloc(sizeof(int));
		if (!tab[i])
			return (ft_free_tab_str(&str), ft_free_int(&tab), NULL);
		res = ft_atoi(str[i]);
		if (res > 2147483647 || res < -2147483648)
			return (ft_free_int(&tab), ft_free_tab_str(&str), ft_error(), NULL);
		*(tab[i]) = (int)res;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static int	check_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') 
				|| (str[i] == '-' || str[i] == '+') || (str[i] == ' ')))
			return (1);
		if (i == 0 && (str[i] == '-' || str[i] == '+') 
			&& !(str[i + 1] >= '0' && str[i + 1] <= '9'))
			return (1);
		if (i > 0 && (str[i] == '-' || str[i] == '+'))
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9') || str[i - 1] != ' ')
				return (1);
		}
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i++] != ' ')
			return (0);
	}
	return (1);
}

static char	*read_arg(int argc, char **argv)
{
	char	*str;
	char	*tmp;
	int		i;

	i = 1;
	tmp = NULL;
	str = NULL;
	if (argc == 1)
		return (NULL);
	while (argc > 1)
	{
		if (check_error(argv[i]) == 1 || argv[i][0] == '\0')
			return (ft_free_str(&str), ft_error(), NULL);
		tmp = ft_strdup(str);
		ft_free_str(&str);
		str = ft_strjoin(tmp, argv[i]);
		free (tmp);
		argc--;
		i++;
	}
	return (str);
}

int	**get_int_arg(int argc, char **argv, int *count)
{
	char	*str;
	char	**stack;
	int		**int_stack;

	*count = 0;
	str = read_arg(argc, argv);
	if (!str)
		return (NULL);
	stack = ft_split(str, ' ');
	if (!stack)
		return (ft_free_str(&str), NULL);
	free(str);
	int_stack = atoi_arg(stack, count);
	if (!int_stack)
		return (ft_free_tab_str(&stack), NULL);
	ft_free_tab_str(&stack);
	if (if_double_sort(int_stack) == 1)
		return (ft_free_int(&int_stack), NULL);
	return (int_stack);
}
