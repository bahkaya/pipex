/*// ALLAHIM BU NE AMQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQQ
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
	arg_list = ft_put_str(command_to_exc[1], ' ', arg_list);
	arg_list[2] = ft_strdup(command_to_exc[0]);
	arg_list[3] = NULL;
	return (arg_list);
}*/

/*char	*ft_command_location(char *av, char **envp)
{
	size_t i;
	size_t k;
	size_t start;
	size_t access_id;
	char *path;
	char *path_loca;
	char *dir;

	access_id = 0;
	start = 0;
	k = 0;
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH", ft_strlen(envp[i])))
		{
			if (ft_strnstr(envp[i], ":", ft_strlen(envp[i])))
			{
				path = ft_strnstr(envp[i], "/", ft_strlen(envp[i]));
				while (path[k] != ':')
				{
					if (path[k] == ':' || path[k] != '\0')
					{
						path_loca = ft_substr(dir, start, k - 1);
						path = ft_strjoin(path_loca, av);
						access_id = access(path, F_OK);
						if (access_id == -1)
						{
							free(path_loca);
							free(path);
						}
						else if(access_id == 0)
						{
							free(path_loca);
							return (path);
						}
						start = k + 2;
					}
					k++;
				}
				return (path);
			}
		}
		i++;
	}
	return (path);
}*/