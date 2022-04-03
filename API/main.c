/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elraira- <elraira-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 10:39:55 by elraira-          #+#    #+#             */
/*   Updated: 2022/02/27 21:38:29 by elraira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "api.h"

int	callback(const struct _u_request *request, struct _u_response *response,
	void *activity_data)
{
	char	*info;

	info = ft_get_activity_info(&request->http_url[1]);
	ulfius_set_string_body_response(response, 200, info);
	ulfius_set_string_body_response(response, 200,
		"Check terminal or log.txt to see latest activity recommendations :D");
	return (U_CALLBACK_CONTINUE);
	(void)activity_data;
}

int	ft_ulfius(void)
{
	struct _u_instance	instance;

	if (ulfius_init_instance(&instance, PORT, NULL, NULL) != U_OK)
	{
		fprintf(stderr, "Error ulfius_init_instance!\n");
		return (1);
	}
	ulfius_add_endpoint_by_val(&instance, "GET", "*", NULL, 0, &callback, NULL);
	if (ulfius_start_framework(&instance) == U_OK)
	{
		printf("Framework initialized - PORT %d\n", instance.port);
		printf("Go to your browser and type 'localhost:8080'");
		getchar();
	}
	else
	{
		fprintf(stderr, "Framework error!\n");
	}
	ulfius_stop_framework(&instance);
	ulfius_clean_instance(&instance);
	return (0);
}

int	main(void)
{
	ft_ulfius();
	return (0);
}
