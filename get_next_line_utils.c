#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (*str)
	{
		length++;
		str++;
	}
	return (length);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;

	i = 0;
	copy = (char *)malloc(ft_strlen((char *)src) * sizeof(char) + 1);
	if (!copy)
		return (NULL);
	while (i < ft_strlen((char *)src))
	{
		copy[i] = (char)src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (s[0] == '\0')
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= start + len)
		substr = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (s[start] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	strjoin = (char *)malloc(sizeof(char)
			* (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoin)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		strjoin[i] = s1[i];
		i++;
	}
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		strjoin[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	strjoin[i] = '\0';
	free((char *)s1);
	return (strjoin);
}