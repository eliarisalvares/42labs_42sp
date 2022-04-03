/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cli.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/02/27 20:19:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_H
# define CLI_H

# include <stdio.h> /*   usada para printf(), size_t e *FILE    */
# include <string.h> /*           usada para strncmp           */
# include <stdlib.h> /*   usada para manipulação de memória   */
# include <unistd.h> /* usada para read(), fopen(), fclose() */
# define BUFFER_SIZE 1

/*........struct que substitui o ponteiro *save do projeto original.........*/
typedef struct s_save
{
	int				fd;
	char			all_data[BUFFER_SIZE + 1];
	int				read_bytes;
	char			*line;
}	t_save;

/*.............................main.c functions...............................*/

/**
 * @brief Limpa o terminal ("clear"), checa se o arquivo de logs existe para
 * evitar Segmentation Faults e mantém a aplicação funcionando enquanto não
 * houver uma terminação pelo usuário (crtl + c).
*/
int			ft_request(void);

/**
 * @brief Essa função rece o conteúdo do arquivo de logs, os exibe no terminal e
 * adiciona o número de requisições e um separador após todas as linhas de cada
 * requisição serem processadas.
 */
int			ft_print_logs(FILE *log_file, int id);

/**
 * @brief Essa função abre, lê e fecha o arquivo de logs "log.txt" ao receber o
 * comando "logs" através do terminal.
 */
void		ft_read_logs(char *all_data);

/*.........................get_next_line.c functions..........................*/

size_t		ft_get_line(char *all_data);
void		ft_read_and_save(t_save *save);
int			ft_save(char *line, char *all_data);
char		*get_next_line(int fd);

#endif
