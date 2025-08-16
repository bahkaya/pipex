/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bahkaya <bahkaya@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 22:27:43 by bahkaya           #+#    #+#             */
/*   Updated: 2025/08/03 22:27:43 by bahkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
// Just testing the functions that are allowed
// av[2] == "ls -la" 'daki "ls" bulmak için yapıldı ama split zaten bana bunu veriyor yinede dursun /usr/bin/---ls--  "ls -la"'daki "ls" bulmak için
/*size_t	ft_blank_is_found(char *av)
{
	size_t i;

	i = 0;
	while(av[i] != ' ' && av[i] != '\0')
		i++;
	return (i);
}*/
// "ls" "filename" "Null" vermek için ama ls -la da patlıyor
/*char	**ft_exc(char const **command_to_exc)
{
	size_t	i;
	size_t	str_len;
	size_t	k;
	char	**exc;

	k = 0;
	i = 1;
	str_len = 0;
	exc = malloc(sizeof(char *) * 2 + 1);
	if (!exc)
		return (NULL);
	while (k < 2)
	{
		str_len = ft_strlen(command_to_exc[i]);
		exc[k] = ft_substr(command_to_exc[i], 0, str_len);
		i--;
		k++;
	}
	exc[k] = NULL;
	return (exc);
}*/
static size_t	ft_str_len(char const *s, size_t start, char c)
{
	size_t	len;

	len = 0;
	while (s[start] != c && s[start] != '\0')
	{
		len++;
		start++;
	}
	return (len);
}

static char	**ft_put_str(char const *s, char c, char **str)
{
	size_t	i;
	size_t	k;
	size_t	str_len;

	i = 0;
	k = 0;
	str_len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
		{
			str_len = ft_str_len(s, i, c);
			str[k] = ft_substr(s, i, str_len);
			k++;
			i += str_len;
		}
	}
	str[k] = NULL;
	return (str);
}

static size_t	arr_len(char const *s, char c)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			return (len);
		while (s[i] != c && s[i] != '\0')
			i++;
		len++;
	}
	return (len);
}
// ALLAHIM BU NE AMQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
char	**ft_exc_update(char const **command_to_exc, int ac)
{
	size_t	arr_len_size;
	size_t	i;
	char	**arg_list;

	arr_len_size = 0;
	i = 0;
	while (i < ac)
	{
		arr_len_size += arr_len(command_to_exc[i], ' ');
		i++;
	}
	arg_list = malloc (sizeof(char *) * arr_len_size + 1);
	if (!arg_list)
		return (NULL);
	i = 0;
	// while (i < ac) --- pipe için şuanlık gerek yok
	printf("%s\n", command_to_exc[1]);
	arg_list = ft_put_str(command_to_exc[1], ' ', arg_list);
	arg_list[2] = ft_strdup(command_to_exc[0]);
	arg_list[3] = NULL;
	return (arg_list);
}
char	*ft_command_location(char const **av)
{

	char	*path;
	char	*path_location;
	char	**command;
	// Gerek yok ama yinede dursun split yaptığımız için command[0] path location'a gönderilebilir  size_t	av_substr_len;
	// av_substr_len = ft_blank_is_found(av[1]);

	path = "/usr/bin/";
	command = ft_split(av[0], ' ');
	path_location = ft_strjoin(path, command[0]);
	return (path_location);
}
// parse için ft_split Example av[2] == "ls -la veya ls -l" char **parse = ft_split(av[2], ' ') böylelikle char **parse = {"ls", "-l"}
// ./pipex infile -- infile pipex dosyaları içinde olsa yeterli mi ? yoksa infile aramam mı gerekiyor ??
// Commandler "ls -l -a" olabilir mi bunu handlelamamız gerekiyor mu ?
// Yoksa commandler "ls -la" mı olmak zorunda ?
int main(int ac, char const **av)
{
	char *path;
	char **command_to_exc;

	command_to_exc = ft_exc_update(&av[1], ac - 1); // right now I am giving the argument size however this needs to be updated if you want to do the bonus which can be done
	path = ft_command_location(&av[2]);
	execve(path, command_to_exc, NULL);
	// execve(path_location, command, NULL);
	return 0;
}
