/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/02/27 22:56:58 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cli.h"

int	ft_print_logs(FILE *log_file, int request)
{
	char	data[300];
	int		line;

	line = 1;
	printf("\n");
	while (fgets(data, 350, log_file))
	{
		printf("%s", data);
		if (line == 9)
		{
			printf("Number of Requests: %d\n", request + 1);
			printf("~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~o~\n");
			line = 1;
			fgets(data, 350, log_file);
			request++;
		}
		else
			line++;
	}
	return (request);
}

void	ft_read_logs(char	*data)
{
	FILE	*log_file;

	if (data)
	{
		if (strncmp(data, "logs", 4) == 0)
		{
			log_file = fopen("../API/log.txt", "r");
			ft_print_logs(log_file, 0);
			fclose(log_file);
		}
		else if ((strncmp(data, "close", 5) == 0))
		{
			free(data);
			exit(0);
		}
		free(data);
	}
}

int	ft_request(void)
{
	char		*data;

	if (access("../API/log.txt", F_OK) == -1)
		printf("Error! No logs yet!\n");
	else
	{
		system("clear");
		while (1)
		{
			data = get_next_line(0);
			ft_read_logs(data);
		}
	}
	return (0);
}

int	main(void)
{
	ft_request();
	return (0);
}
