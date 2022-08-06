/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 13:32:45 by byan              #+#    #+#             */
/*   Updated: 2022/07/11 17:00:24 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_err(char *message)
{
	printf("Error\n");
	printf("%s", message);
	exit(1);
}

char	*ft_strdup_no_nl(char *s)
{
	char	*temp;
	int		len;
	int		i;

	temp = NULL;
	len = ft_strlen(s);
	i = 0;
	temp = malloc(len + 1);
	if (!(temp))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		temp[i] = s[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

int	ft_strlcpy_no_nl(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
		return (src_len);
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin_no_nl(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	new_mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_no_nl(s2));
	else if (s2 == NULL)
		return (ft_strdup_no_nl(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len);
	if (!(new_mem))
		return (NULL);
	ft_strlcpy_no_nl(new_mem, s1, s1_len + 1);
	ft_strlcpy_no_nl(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_mem);
}
