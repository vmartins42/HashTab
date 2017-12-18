/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmartins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:17:05 by vmartins          #+#    #+#             */
/*   Updated: 2017/12/18 14:23:45 by vmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

typedef struct			s_hash
{
	char			*cmd;
	char			*path;
	struct s_hash	*next;
}				       	t_hash;

t_hash					*ft_new_maillon(char *cmd)
{
	t_hash *new;

	if ((new = (t_hash *)malloc(sizeof(t_hash))) == NULL)
		return (NULL);
	new->cmd = ft_strdup(cmd);
	new->path = NULL;
	new->next = NULL;
	return (new);
}

int						hash_table(char *cmd, t_hash *hash)
{
	int		i;
	int		nbrhash;
	t_hash	*tmp;

	i = 0;
	nbrhash = 0;
	while (cmd[i] != '\0')
	{
		nbrhash += cmd[i];
		i++;
	}
	nbrhash %= 1000;
	if (hash[nbrhash].cmd == NULL)
	{
		hash[nbrhash].cmd = ft_strdup(cmd);
		hash[nbrhash].next = NULL;
	}
	else if (hash[nbrhash].cmd != NULL)
	{
		tmp = &hash[nbrhash];
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_new_maillon(cmd);
	}
	return (nbrhash);
}

int						main(void)
{
	int		i;
	int		j;
	t_hash	*hash;

	i = 0;
	j = 0;
	hash = malloc(sizeof(t_hash) * 1000);
	ft_memset(hash, 0, sizeof(hash));
	i = hash_table("cba", hash);
	i = hash_table("abc", hash);
	i = hash_table("cba", hash);
	i = hash_table("abc", hash);
	i = hash_table("bca", hash);
	i = hash_table("acb", hash);
	i = hash_table("toto", hash);
	while (j < 1000)
	{
		if (hash[j].cmd != NULL)
		{
			ft_putendl("NEW");
			ft_putendl(hash[j].cmd);
			if (hash[j].next != NULL)
			{
				ft_putendl("COLLISSION");
				while (hash[j].next)
				{
					hash[j] = *hash[j].next;
					ft_putendl(hash[j].cmd);
				}
			}
		}
		j++;
	}
	return (0);
}
