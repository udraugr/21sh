/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 19:14:59 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/05 17:21:46 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void	ft_change_var_env(t_vector **env, char *key, char *value)
{
	char	*line;
	char	*half;

	half = ft_strjoin(key, "=");
	line = ft_strjoin(half, value);
	ft_setenv(line, env);
	ft_strdel(&half);
	ft_strdel(&line);
}

static void	ft_change_dir(char *path, t_vector **env)
{
	char	*pwd;
	char	*new_pwd;

	pwd = 0;
	new_pwd = 0;
	if (*path && (pwd = ft_memalloc(STDMES))
			&& (new_pwd = ft_memalloc(STDMES)))
	{
		if (file_check(path, FOLD, X_OK, path))
		{
			if (!(pwd = getcwd(pwd, STDMES)))
				return ;
			ft_change_var_env(env, "OLDPWD", pwd);
			chdir(path);
			if (!(new_pwd = getcwd(new_pwd, STDMES)))
			{
				ft_strdel(&pwd);
				return ;
			}
			ft_change_var_env(env, "PWD", new_pwd);
		}
	}
	ft_strdel(&pwd);
	ft_strdel(&new_pwd);
}

void		ft_cd(char *param, t_vector **env)
{
	char		**arr_param;
	char		*next_dir;
	int			numb_par;

	arr_param = ft_strsplit(param, ' ');
	ft_ungrab_arr(arr_param);
	if ((numb_par = ft_arrlen(arr_param)) < 3)
	{
		if (numb_par == 1)
			next_dir = ft_take_value_env("HOME", env);
		else if (numb_par == 2 && ft_strequ(arr_param[1], "-"))
			next_dir = ft_take_value_env("OLDPWD", env);
		else
			next_dir = ft_strdup(arr_param[1]);
		ft_change_dir(next_dir, env);
		ft_strdel(&next_dir);
	}
	else
		write(2, "cd: too many arguments\n", 23);
	ft_del_arr(&arr_param);
}
