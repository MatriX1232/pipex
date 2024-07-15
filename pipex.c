/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msolinsk <msolinsk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:43:47 by msolinsk          #+#    #+#             */
/*   Updated: 2024/07/15 02:26:54 by msolinsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_command(char *cmd, char **envp)
{
	char	**argv;

	argv = (char **) malloc(4 * sizeof(char *));
	if (!argv)
		return ;
	argv[0] = ft_strdup("/bin/sh");
	argv[1] = ft_strdup("-c");
	argv[2] = cmd;
	argv[3] = NULL;

	execve("/bin/sh", argv, envp);
	perror("execive");
	free(argv[0]);
	free(argv[1]);
	free(argv);
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char **envp)
{
	if (argc != 5)
		ft_print_error("Bad number of arguments!\n");

	(void)argv;
	/*
	char	*infile = argv[1];
	char	*cmd1 = argv[2];
	char	*cmd2 = argv[3];
	char	*outfile = argv[4];
	*/

	exec_command("cat -e infile", envp);

	return (0);
}
