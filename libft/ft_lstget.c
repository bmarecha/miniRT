#include "libft.h"

void	*ft_lstget(t_list *lst, int i)
{
	t_list	*p;

	p = lst;
	if (p == NULL)
		return (NULL);
	while (p->next && i--)
	{
		p = p->next;
	}
	if (i > 0)
		return (NULL);
	return (p->content);
}
