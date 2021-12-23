/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchimb <tarchimb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:44:39 by tarchimb          #+#    #+#             */
/*   Updated: 2021/12/23 11:04:32 by tarchimb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	start;
	int	end;

	start = 0;
	end = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
	{
		i++;
		start++;
	}
	if (s1[i] == '\0')
	{
		return (ft_strdup(""));
	}
	i = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i--]))
		end++;
	return (ft_substr(s1, start, (ft_strlen(s1) - (start + end))));
}
