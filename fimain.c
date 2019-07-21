#include "lsft.h"

void	flags_n_sort(char **av, &que, &cur);
{
	while 
}

int		ft_ls(t_q **que, t_q **lev, t_curr **cur)
{
	DIR				*d;
	struct dirent	*rd;
	char 			*av;

	av = ((*lev)->abspath != NULL ? (*lev)->abspath : (*que)->abspath);
	if (av == NULL) //finish of program
		return (0);

	if (!(d = opendir(av)))
		perror(ft_strjoin("ft_ls: ", av));
	else
		while ((rd = readdir(d))) // || rd == NULL && errno )
		{
			if (global_flags[1] == 0)

			ft_add_sorted(cur, rd); // sorted, rdy2print
	/// note, if D_TYPE == 10 (symb.link), we need info about SLINK FILE, not endfile !!!
	/// so we have to use lstat;
			if(rd->d_type == 4)
				to_que(rd->d_name, lev);
		}
	pr_cur(cur);
	//if (closedir(d))
	//	perror(0);
	return (1);
}

int		main(int ac, char **av)
{
	int		state;
	t_q		*que; //terminal que
	t_q		*lev; //for recursive
	t_curr	*cur; //print reg.files from dir or terminal ("ls file1 dir1 fil2" -->
					// file1, file2
					// dir1: 
					// ......)

	cur = NULL;
	que = NULL;
	lev = NULL;
	state = 1;
	flags_n_fsort(av, &que, &cur); //define global flags, add to que sorted argv's from terminal; 
				// if av == NULL, then av = ".";
				// add to t_curr !!! reg. files to print, then folders to que;
	pr_cur(&cur);
	while (state > 0)
		state = ft_ls(&que, &lev, &cur);
}