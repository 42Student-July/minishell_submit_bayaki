#include "libft.h"

t_list	*ft_xlstnew(void *content)
{
	t_list	*list;

	list = (t_list *)ft_xmalloc(sizeof(t_list));
	list->content = content;
	list->next = NULL;
	return (list);
}
