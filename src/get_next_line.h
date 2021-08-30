
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 30

typedef struct		s_list
{
	char			*remainder;
	int				fd;
	struct s_list	*next;
}					t_list;

int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *str);
char				*ft_strchr(const char *str, int ch);
char				*ft_strjoin(char const *s1, char const *s2);
t_list				*infonew(int fd, t_list **info);

#endif
