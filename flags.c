/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jschille <jschille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 20:09:25 by jschille          #+#    #+#             */
/*   Updated: 2019/06/05 21:06:18 by jschille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_param(char *str, int *flag)
{
	int i;
	int	delta;

	i = 0;
	while (str[++i])
	{
		delta = 1 << (str[i] - 'a');
		*flag |= delta;
	}
}

int		set_flags(int argc, char **argv)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	if (argv[1][j] == '-' && argv[1][j + 1] >= 'a' && argv[1][j + 1] <= 'z')
		set_param(argv[1], &flag);
	else
		return (-1);
	return (flag);
}

int		get_flag(int flag, int ch)
{
	int		delta;

	delta = 1 << ch;
	return (flag & delta >> ch);
}
