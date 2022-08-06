/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byan <byan@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:42:59 by byan              #+#    #+#             */
/*   Updated: 2022/04/24 19:01:30 by byan             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_index(char *repo)
{
	int	i;

	i = 0;
	while (repo[i] != '\n' && repo[i] != 0)
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	size1;
	size_t	size2;
	char	*new;

	if (!s2)
		return (NULL);
	size1 = ft_strlen((char *)s1);
	size2 = ft_strlen((char *)s2);
	new = (char *)malloc(size1 + size2 + 1);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < size1)
		new[i] = s1[i];
	while (i < size1 + size2)
	{
		new[i] = s2[i - size1];
		i++;
	}
	new[i] = 0;
	free((char *)s1);
	return (new);
}

char	*init_read(int fd, char *repo)
{
	int		bytes_read;
	char	*line_read;

	bytes_read = 1;
	repo = malloc_repo(repo);
	line_read = (char *)malloc(BUFFER_SIZE + 1);
	while (bytes_read > 0)
	{
		bytes_read = read(fd, line_read, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		line_read[bytes_read] = '\0';
		repo = ft_gnl_strjoin(repo, line_read);
		if (ft_strchr(line_read, '\n'))
			break ;
	}
	free(line_read);
	if (!*repo)
	{
		free(repo);
		return (NULL);
	}
	return (repo);
}

char	*make_next_line(char *repo, int end_index)
{
	char	*temp;
	int		index;

	index = ft_strlen(repo) - end_index;
	temp = (char *)malloc(index + 1);
	ft_strlcpy(temp, repo + end_index + 1, index + 1);
	free(repo);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*repo[OPEN_MAX];
	char		*return_line;
	int			end_index;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	repo[fd] = init_read(fd, repo[fd]);
	if (!repo[fd] || !*repo[fd])
	{
		free(repo[fd]);
		return (NULL);
	}
	end_index = find_index(repo[fd]);
	return_line = (char *)malloc(end_index + 2);
	ft_strlcpy(return_line, repo[fd], end_index + 2);
	repo[fd] = make_next_line(repo[fd], end_index);
	return (return_line);
}
