#include "../libft/libft.h"

typedef struct		s_hash
{
	char			*cmd;
	char			*path;
	struct s_hash	*next;
}				       	t_hash;

int hash_table(char *cmd, t_hash *hash)
{
    int i;
    int nbrhash;

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
			t_hash tmp = hash[nbrhash];
			tmp.next = NULL;

			ft_putendl(hash[nbrhash].cmd);
		  hash[nbrhash].next = &tmp;
    }
		else
		{
			t_hash tmp1 = *hash[nbrhash].next;
      while (tmp1.next != NULL)
				tmp1 = *tmp1.next;
			tmp1.cmd = ft_strdup(cmd);
			ft_putendl(hash[nbrhash].cmd);

		   hash[nbrhash].next = &tmp1;
			 ft_putnbr(nbrhash);
			 ft_putendl(tmp1.cmd);
    }
    return(nbrhash);
}

int main()
{
  int i;
  t_hash *hash;
	hash = malloc(sizeof (t_hash) * 1000);
	i= 0;
  ft_memset(hash, 0, sizeof(hash));

  i = hash_table("abc", hash);
  i = hash_table("cba", hash);
	// ft_putnbr(i);
	ft_putendl(hash[i].cmd);
	ft_putendl(hash[i].next->cmd);
	//ft_putnbr(i);
	//i = 0;
	//while(i < 630)
	//{
		// ft_putendl(hash[0]->cmd);
		// ft_putendl(hash[0]->cmd);
		//ft_putnbr(i);
		//ft_putendl(hash[i].next->cmd);

		// if (hash[i].next != NULL)
		// 	{
		// 		ft_putendl("LOLOLO");
    //
		// 	//	t_hash *tmp = hash[i].next;
		// 		while (hash[i].next != NULL) {
		// 			ft_putendl("++++");
		// 			ft_putendl(hash[i].next->cmd);
		// 			ft_putendl("++++");
		// 			hash[i].next = hash[i].next->next;
		// 		}
		// 	}
		// i++;
//	}
  return (0);
}
