/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfoote <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:17:58 by gfoote            #+#    #+#             */
/*   Updated: 2019/07/25 17:18:00 by gfoote           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsft.h"

void	ft_strdl2(char **tmp)
{
	ft_strdl(tmp);
	free(tmp);
}

int		type_check(char c)
{
	if (c == 'b' || c == 'c')
		return (1);
	return (0);
}

void	ft_parse_null(t_curr *new)
{
	new->rights = NULL;
	new->links = 0;
	new->user = NULL;
	new->groop = NULL;
	new->size = 0;
	new->maj = -1;
	new->s_total = 0;
	new->print_date = 0;
}

char	*formatdate(char **str, int check)
{
	char	*result;
	int		i;
	int		j;
	int		k;

	result = (char *)malloc(sizeof(char) * 13);
	i = 0;
	j = 1;
	while (i < 10)
	{
		k = 0;
		while (str[j][k] && i < 12)
			result[i++] = str[j][k++];
		j++;
		if (ft_strlen(str[2]) == 1 && j == 2)
			result[i++] = ' ';
		if (i < 8)
			result[i++] = ' ';
		if (check == 1 && i == 7 && j++ == 3)
			result[i++] = ' ';
	}
	result[i] = '\0';
	return (result);
}

int		*ft_fill_date(char **time)
{
	int	*result;

	result = (int *)malloc(sizeof(int) * 3);
	result[0] = ft_atoi(time[4]);
	result[2] = ft_atoi(time[2]);
	if (ft_strequ(time[1], "Jan") || ft_strequ(time[1], "Feb"))
		result[1] = ft_strequ(time[1], "Jan") ? 1 : 2;
	else if (ft_strequ(time[1], "Mar") || ft_strequ(time[1], "Apr"))
		result[1] = ft_strequ(time[1], "Mar") ? 3 : 4;
	else if (ft_strequ(time[1], "May") || ft_strequ(time[1], "Jun"))
		result[1] = ft_strequ(time[1], "May") ? 5 : 6;
	else if (ft_strequ(time[1], "Jul"))
		result[1] = 7;
	else if (ft_strequ(time[1], "Aug"))
		result[1] = 8;
	else if (ft_strequ(time[1], "Sept"))
		result[1] = 9;
	else if (ft_strequ(time[1], "Oct"))
		result[1] = 10;
	else if (ft_strequ(time[1], "Nov"))
		result[1] = 11;
	else
		result[1] = 12;
	return (result);
}
