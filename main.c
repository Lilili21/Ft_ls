#include "lsft.h"

void giv_me(t_q **qu, t_curr **ad)
{
	*qu = (t_q*)malloc(sizeof(t_q));
	*ad = (t_curr*)malloc(sizeof(t_curr));
	(*ad)->user = (char*)malloc(sizeof(char) * 1000);
	(*qu)->abspath = (char*)malloc(sizeof(char) * 1000);
}


void fef()
{
	char *a;

	a = ft_strjoin("a", "ok");

	ft_putendl(a);
	
}

int main()
{
	t_q *tmp;
	t_curr *t;

	giv_me(&tmp, &t);
	exit(0);
}

/*

int		main(int ac, char **av)
{
	DIR *d;
	struct dirent *rd;

	if (!(d = opendir(av[1])))
	{
		ft_putendl_fd("bla", 2);
		perror("sukaneotkrit");
		ft_putnbr(errno);
		exit(1);
	}
	else
	{
		while ((rd = readdir(d)))
		{
			ft_putstr(rd->d_name);
			ft_putnbr(rd->d_type);
			write(1, "\n", 1);
		}
	}
	if (closedir(d))
		perror("blane close");
	
}
*/