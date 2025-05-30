#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	index;

	src_length = ft_strlen(src);
	if (dstsize == 0)
		return (src_length);
	index = 0;
	while (src[index] && index < dstsize - 1)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
	return (src_length);
}

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*copy;

	length = 0;
	length = ft_strlen(s1);
	copy = (char *)malloc(sizeof(char) * (length + 1));
	if (copy == NULL)
		return (NULL);
	ft_strlcpy(copy, s1, length + 1);
	return (copy);
}
