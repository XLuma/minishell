/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:29:23 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/20 16:57:57 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

u_int32_t	ft_atoi_32(const char *s)
{
	u_int32_t	result;
	u_int32_t	minus;

	result = 0;
	minus = 1;
	while ((s[0] >= 9 && s[0] <= 13) || s[0] == 32)
		s++;
	if (s[0] == '-')
		minus = minus * -1;
	if (s[0] == '-' || s[0] == '+')
		s++;
	while (s[0] >= '0' && s[0] <= '9')
	{
		result = (result * 10) + s[0] - '0';
		s++;
	}
	return (result * minus);
}

int	is_number(const char *str)
{
	int	i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **argv)
{
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!argv[1])
		g_mini.output_code = SUCCESS;
	else if (!is_number(argv[1]))
		print_error("exit", argv[1], NUM_ERR, EXIT_ERR);
	else if (argv[2])
	{
		print_error("exit", NULL, ARGS_ERR, GEN_ERR);
		return ;
	}
	else
		g_mini.output_code = ft_atoi_32(argv[1]) % 256;
	ft_strarr_free(g_mini.env);
	ft_strarr_free(g_mini.path);
	rl_clear_history();
	exit ((int)g_mini.output_code);
}