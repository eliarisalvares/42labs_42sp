/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/02/27 21:36:38 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

size_t	ft_header_callback(char *buffer, size_t size, size_t n, void *userdata)
{
	time_t	curtime;
	FILE	*file_log;

	file_log = fopen("log.txt", "a");
	time(&curtime);
	fprintf(file_log, "Time Request: %s", ctime(&curtime));
	fprintf(file_log, "%s\n", buffer);
	fclose(file_log);
}

char	*ft_get_header(char *pointer)
{
	CURL				*curl;
	CURLcode			res;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL,
			"http://www.boredapi.com/api/activity/");
		curl_easy_setopt(curl, CURLOPT_HEADERFUNCTION, ft_header_callback);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

char	ft_body_callback(char *s, size_t item, size_t n, void *pointer)
{
	FILE	*file_log;

	file_log = fopen("log.txt", "a");
	fprintf(file_log, "\n\t");
	printf("\n\t");
	while (*s)
	{
		if (*s == ',')
		{
			fprintf(file_log, ",\n\t");
			printf(",\n\t");
		}
		else
		{
			fprintf(file_log, "%c", *s);
			printf("%c", *s);
		}
		s++;
	}
	printf ("\n");
	fprintf (file_log, "\n");
	fclose(file_log);
	ft_get_header(pointer);
}

char	*ft_get_activity_info(char *activity)
{
	CURL		*curl;
	CURLcode	res;

	curl = curl_easy_init();
	if (curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL,
			"http://www.boredapi.com/api/activity/");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, ft_body_callback);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	return (0);
}
