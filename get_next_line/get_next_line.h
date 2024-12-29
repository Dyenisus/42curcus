#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_reader(int fd, char	*buffer);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*get_next_line(int fd);

#endif