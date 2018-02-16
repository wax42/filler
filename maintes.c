
#include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int		ft_openfile(char *files)
{
	int	fd;

	fd = open(files, O_RDONLY);
	return (fd);
}

int main()
{
	char *line;
	int ret;
	int fd;

	fd = ft_openfile("pute");
	ret = 1;
	while (ret != 0)
	{
		ft_putstr("gnl");
		ft_putnbr(ret = get_next_line(0, &line));
		free(line);
		ft_putendl(line);
		ft_putstr("jsp ?");
	}
	pause();
}
