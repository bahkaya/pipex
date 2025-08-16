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