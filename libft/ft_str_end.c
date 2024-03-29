#include "libft.h"

int	ft_str_end(const char *str, const char *end)
{
	int	len1;
	int	len2;

	len1 = 0;
	len2 = 0;
	while (str[len1])
		len1++;
	while (end[len2])
		len2++;
	if (len1 < len2)
		return (0);
	while (0 < len2)
	{
		len1--;
		len2--;
		if (str[len1] != end[len2])
			return (0);
	}
	return (1);
}
