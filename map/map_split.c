/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:45:11 by fel-maac          #+#    #+#             */
/*   Updated: 2021/12/12 11:45:22 by fel-maac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	count_strs(char const *s, char c)
{
	int	strs;
	int	check;
	int	i;

	strs = 0;
	check = 0;
	i = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			check = 0;
		else if (check == 0)
		{
			check = 1;
			strs++;
		}
		i++;
	}
	return (strs);
}

static int	strs_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**free_arr(char **arr_strs, int j)
{
	while (j-- > 0)
		free((void *)arr_strs[j]);
	free(arr_strs);
	return (NULL);
}

static char	**allocate(char const *s, char **arr_strs, char c, int strs_count)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] != '\0' && j < strs_count)
	{
		k = 0;
		while (s[i] == c)
			i++;
		arr_strs[j] = (char *)malloc(sizeof(char) * strs_len(s, c, i) + 1);
		if (arr_strs[j] == NULL)
			return (free_arr(arr_strs, j));
		while (s[i] != '\0' && s[i] != c)
			arr_strs[j][k++] = s[i++];
		arr_strs[j][k] = '\0';
		j++;
	}
	arr_strs[j] = 0;
	return (arr_strs);
}

char	**ft_split(char const *s, char c)
{
	char	**arr_strs;
	int		strs;

	if (s == NULL)
		return (NULL);
	strs = count_strs(s, c);
	arr_strs = (char **)malloc(sizeof(char *) * (strs + 1));
	if (arr_strs == NULL)
		return (NULL);
	arr_strs = allocate(s, arr_strs, c, strs);
	return (arr_strs);
}
