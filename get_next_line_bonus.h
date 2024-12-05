#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd);

char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

char	*ft_memcpy(char *dest,const char *src, size_t n);

char	*ft_strdup(const char *s1);

void	*ft_memmove(void *dest, const void *src, size_t n);

char	*ft_strjoin(char const *s1, char const *s2);


#endif
