/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: inhkim <inhkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 06:13:21 by inhkim            #+#    #+#             */
/*   Updated: 2023/03/14 06:25:41 by inhkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	temp_idx;
	int	idx;

	temp_idx = -1;
	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			temp_idx = idx;
		idx++;
	}
	if ((char)c == 0)
		return ((char *)(s + idx));
	if (temp_idx != -1)
		return ((char *)(s + temp_idx));
	return (0);
}
