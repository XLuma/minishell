/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasselin <gasselin@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 15:03:49 by gasselin          #+#    #+#             */
/*   Updated: 2021/10/21 15:12:54 by gasselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	verify_quotes(const char *str)
{
	int	squote;
	int	dquote;
	int	i;

	squote = 0;
	dquote = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == 39)
			squote++;
		if (str[i] == 34)
			dquote++;
		i++;
	}
	if (squote % 2 != 0 || dquote % 2 != 0)
	{
		print_error(NULL, NULL, QUOTES, SYNTAX_ERR);
		return (0);
	}
	return (1);
}