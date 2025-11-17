/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngulam <ngulam@student.42lehavre.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 09:37:19 by ngulam            #+#    #+#             */
/*   Updated: 2025/11/17 17:18:02 by ngulam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s);
int		ft_newline(char	*str);


static	char	*ft_line(char **line, int fd)
{
	int		r;
	char	*buffer;

	r = 1;
	while (r > 0)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
		{
			free(buffer);
			return (NULL);
		}
		r = read(fd, buffer, BUFFER_SIZE);
		*line = ft_strjoin(*line, buffer);
		if (ft_strchr(buffer, '\n'))
			return (ft_strchr(buffer, '\n'));
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*last;

	if (!last)
		line = "";
	else
		line = last;
	last = ft_line(&line, fd);
	return (line);
}

int	main(void)
{
	int fd = open("helloworld.txt", O_RDONLY);
	int r = 1;
	while(r)
		r = printf("%s",get_next_line(fd));
    close(fd);
}