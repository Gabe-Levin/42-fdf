/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:21:02 by glevin            #+#    #+#             */
/*   Updated: 2024/05/26 16:37:29 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer.
*/

#include "libft.h"

typedef struct t_copy_params
{
	char		**ans;
	const char	*s;
	int			i;
	int			substr_i;
	int			str_cnt;
	int			flag;
}				t_copy_params;

static int	ft_str_cnt(const char *str, char c, int len_op)
{
	size_t	i;
	int		cnt;
	int		flag;

	i = 0;
	cnt = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == c || str[i] == '\0')
		{
			flag = 1;
			if (len_op == 1)
				return (i);
		}
		else if (str[i + 1] == '\0' && len_op == 1)
			return (i + 1);
		else if (flag == 1)
		{
			cnt++;
			flag = 0;
		}
		i++;
	}
	return (cnt);
}

static char	*ft_copy_str(t_copy_params *p, char const *s, char c)
{
	size_t	substr_len;
	size_t	j;

	j = 0;
	substr_len = ft_str_cnt(s + p->i, c, 1);
	p->ans[p->substr_i] = (char *)malloc((substr_len + 1) * sizeof(char));
	if (p->ans[p->substr_i] == NULL)
		return (NULL);
	j = 0;
	while (j < substr_len)
	{
		p->ans[p->substr_i][j] = (s + p->i)[j];
		j++;
	}
	p->ans[p->substr_i][j] = '\0';
	return (p->ans[p->substr_i]);
}

static void	free_memory(char **ans, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(ans[i]);
		i++;
	}
	free(ans);
}

char	**ft_split(char const *s, char c)
{
	t_copy_params	p;

	p.i = 0;
	p.substr_i = 0;
	p.flag = 1;
	p.str_cnt = ft_str_cnt(s, c, 0);
	p.ans = (char **)malloc((ft_str_cnt(s, c, 0) + 1) * sizeof(char *));
	if (p.ans == NULL)
		return (NULL);
	while (s[p.i])
	{
		if (s[p.i] == c)
			p.flag = 1;
		else if (s[p.i] != c && p.flag == 1)
		{
			if (ft_copy_str(&p, s, c) == NULL)
				return (free_memory(p.ans, p.substr_i), NULL);
			p.flag = 0;
			p.substr_i++;
		}
		p.i++;
	}
	p.ans[p.str_cnt] = NULL;
	return (p.ans);
}
