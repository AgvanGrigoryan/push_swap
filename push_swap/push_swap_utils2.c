/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aggrigor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 17:50:36 by aggrigor          #+#    #+#             */
/*   Updated: 2024/02/19 14:16:37 by aggrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	s_len;
	unsigned int	substr_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		substr_len = 0;
	else
	{
		substr_len = s_len;
		if (len < s_len)
			substr_len = len;
	}
	substr = (char *)malloc(substr_len + 1);
	if (substr == NULL)
		return (NULL);
	s += start;
	substr[substr_len] = '\0';
	while (substr_len--)
		substr[substr_len] = s[substr_len];
	return (substr);
}

static size_t	count_words(char const *s)
{
	unsigned int	words_count;
	unsigned int	i;

	words_count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i] && !ft_isspace(s[i]))
			words_count++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (words_count);
}

static void	free_prev_words(char **words, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		free(words[i++]);
}

static int	separate_words(char const *s, size_t words_count, char **words)
{
	size_t		word_num;
	int			word_start;
	int			i;

	i = 0;
	word_num = 0;
	while (s[i] && word_num < words_count)
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		word_start = i;
		while (s[i] && !ft_isspace(s[i]))
			i++;
		words[word_num] = ft_substr(s + word_start, 0, i - word_start);
		if (words[word_num] == NULL)
		{
			free_prev_words(words, word_num);
			return (0);
		}
		word_num++;
	}
	words[word_num] = NULL;
	return (1);
}

char	**ft_split(char const *s)
{
	size_t		words_count;
	char		**words;

	if (s == NULL)
		return (NULL);
	words_count = count_words(s);
	words = (char **)malloc((words_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	if (!separate_words(s, words_count, words))
		return (NULL);
	return (words);
}
