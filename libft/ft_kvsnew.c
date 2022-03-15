#include "libft.h"

void	*ft_kvsnew(char *key, char *value)
{
	t_kvs	*kvs;

	kvs = (t_kvs *)ft_xmalloc(sizeof(t_kvs));
	if (kvs == NULL)
		return (NULL);
	kvs->key = ft_xstrdup(key);
	if (kvs->key == NULL)
		return (NULL);
	if (value != NULL)
	{
		kvs->value = ft_xstrdup(value);
		if (kvs->value == NULL)
		{
			free(kvs->key);
			return (NULL);
		}
	}
	else
		kvs->value = NULL;
	return ((void *)kvs);
}
