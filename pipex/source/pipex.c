/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkurukul <thilinaetoro4575@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:38:50 by tkurukul          #+#    #+#             */
/*   Updated: 2025/02/26 22:56:37 by tkurukul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// int	if_alpha(char str)
// {
// 	if (str >= 65 && str <= 90
// 		|| str >= 97 && str <=122)
// 		return (1);
// 	return (0);
// }
// int	if_word(char *str, int i)
// {
// 	while(str)
// 	{
// 		if (if_alpha(str[i]) == 1)
// 			return (1);
// 		else
// 			i++;
// 	}
// 	return (0);
// }

// char	**count_words(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str)
// 	{
// 		if (str[i] == 32)
// 		{
// 			if (i != 0 && if_alpha(str[i - 1]) == 1
// 			&& if_word(str, i))
// 				count++;
// 			while (str[i] == 32)
// 				i++;
// 		}
// 		else
// 			i++;
// 	}
// 	return (count + 1);
// }
char	**matrix_creation(char *str)
{
	char	**matrix;

	matrix = ft_split(str, 32);
	if (!matrix)
		return (NULL);
}

int	child_one(char **av, int *fd)
{
	char	*str;
	char	**matrix;
	int		file;

	file = open_file(av[1], 0);
	if (file == 0)
		return (0);
	in_out_1(fd, file);
	str = ft_strdup(av[2]);
	matrix = matrix_creation(str);
	if (!matrix)
		return (0);
	free(str);
	close_fd(fd);

}
void	in_out_1(int *pipefd, int fd)
{
	if (dup2(fd, 0) == -1 || dup2(pipefd[1], 1) == -1)
		perror("FAILED DUP2 1:");
	close(fd);
	close(pipefd[1]);
}
void	in_out_2(int *pipefd, int fd)
{
	if (dup2(pipefd[0], 0) == -1 || dup2(fd, 1) == -1)
		perror("FAILED DUP2 2:");
	close(fd);
	close(pipefd[1]);
}

int	child_two(char **av, int *fd)
{
	char	*str;
	char	**matrix;
	int		file;

	file = open_file(av[4], 1);
	if (file == 0)
		return (0);
	in_out_2(fd, file);
	str = ft_strdup(av[3]);
	matrix = matrix_creation(str);
	if (!matrix)
		return (0);
	free(str);
	dup2(fd[0], 0);
	close_fd(fd);
}
int	open_file(char *str, int flag)
{
	int	fd;

	if (flag == 0)
		fd = open(str, O_RDONLY);
	else if (flag == 1)
		fd = open(str, O_RDWR | O_TRUNC);
	if (fd == -1)
		return (0);
	return (fd);
}
void	close_fd(int *ar)
{
	if (ar[0])
		close(ar[0]);
	if (ar[1])
		close(ar[1]);
}

void	failure_command(int *fd, char *str)
{
	close_fd(fd);
	ft_printf("command not found: %s", str);
	exit(1);
}

void	failure(int fd, char *str)
{
	perror(str);
	exit(1);
}

void	process(char **matrix)
{
	execve()
}
void	wait_for_process(int pid1, int pid2)
{
	int		status;

	if (waitpid(pid1, &status, 0) == -1
		|| waitpid(pid2, &status, 0) == -1)
	{
		perror("FAILED TO WAIT:");
		exit(1);
	}
}
int	main(int ac, char **av)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (ac == 5)
	{
		if (pipe(pipefd) == -1)
			return (perror("PIPE FAILED:"), 0);
		pid1 = fork();
		if (pid1 == -1)
			failure(pipefd, "FORK FAILED:");
		if (pid1 == 0)
			child_one(av, pipefd);
		pid2 = fork();
		if (pid2 == -1)
			failure(pipefd, "FORK FAILED:");
		if (pid2 == 0)
			child_two(av, pipefd);
		close_fd(pipefd);
		wait_for_process(pid1, pid2);
	}
	else
		return(perror("INCORRECT INPUT FOR PROGRAM:"), 1);
	return (0);
}
