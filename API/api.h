/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/02/27 22:52:01 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef API_H
# define API_H

# define _GNU_SOURCE
# define PORT 8080

# include <stdio.h> /*  usada para printf(), size_t e *FILE */
# include <stdlib.h> /*  usada para manipulação de memória  */
# include <string.h> /*         usada para strncmp          */
# include <curl/curl.h> /*         usada para libcurl       */
# include <ulfius.h> /*         usada para ulfius           */
# include <fcntl.h> /*         usada para open()            */

/*............................curl.c functions................................*/

/**
 * @brief Essa função inicializa a sessão "libcurl" para que as informações do
 * header da Bored API sejam extraídas e adicionadas, através da função "header
 * callback()", ao arquivo de logs. A opção "CURLOPT_HEADERFUNCTION" permite o
 * tratamento da informação extraída em uma função externa.
 * @return char* o buffer da informação contida no header.
 */
char	*ft_get_header(char *pointer);

/**
 * @brief Função que recebe o conteúdo do header da requisição HTTP de tipo GET
 * ao Bored API e adiciona("appends"), a partir dela, o status HTTP ao arquivo
 * de logs. Nessa mesma função, "time()" é usada para obter e adicionar a hora
 * da requisição ao arquivo de logs.
 */
size_t	ft_header_callback(char *buffer, size_t size, size_t n, void *userdata);

/**
 * @brief Essa função inicializa uma sessão libcurl, performando uma requisição
 * à Bored API para que informações do corpo da resposta sejam extraídas e
 * então formatas (legibilidade) e adicionadas ao arquivo de logs pela função
 *ft_body_callback();
 * @return char* o buffer da informação contida no corpo.
 */
char	*ft_get_activity_info(char *activity);

/**
 * @brief Função que recebe o buffer com o conteúdo do corpo da requisição HTTP
 * de tipo GET ao Bored API, a formata, imprime no terminal e adiciona
 * ("appends") ao arquivo de logs. Ela chama a função ft_get_header para ser
 * executada em seguida.
 */
char	ft_body_callback(char *s, size_t item, size_t n, void *pointer);

/*.............................main.c functions...............................*/

/**
 * @brief Recebe as repostas da requisição HTTP da função. Exibe a mensagem no
 * navegador. Se comunica com as funções de callback da libcurl.
 */
int		callback(const struct _u_request *request, struct _u_response *response,
			void *activity_data);

/**
 * @brief inicializa o Framework ulfius. Estabelece a 8080 e o método HTTP.
 * Envia as repostas da requisição para a função callback. Encerra o Framework.
 */
int		ft_ulfius(void);

#endif
