#include "../libft/libft.h"

typedef struct		s_hash
{
	char			*cmd;
	char			*path;
	struct s_hash	*next;
}				       	t_hash;

int hash_table(char *cmd, t_hash hash[1000])
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
    ft_putnbr(nbrhash);
    if (hash[nbrhash].cmd == NULL)
    {
      ft_putendl("je rentre ici");
      hash[nbrhash].cmd = ft_strdup(cmd);
    }
    else
    {
      ft_putendl("je rentre la");
      while(hash[nbrhash].next != NULL)
        hash[nbrhash] = *hash[nbrhash].next;
      hash[nbrhash].cmd = ft_strdup(cmd);
    }
    return(nbrhash);
}

int main()
{
  int i;
  t_hash hash[1000];

  ft_memset(hash, 0, sizeof(hash));
  i = hash_table("banane", hash);
  i = hash_table("bnanae", hash);
  return (0);
}
