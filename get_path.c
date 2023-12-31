#include "main.h"

/**
 * get_path - Retrieves the path of a command.
 * @command: The command name
 * Return: Pointer to the full path of the command, or NULL if not found
 */
char *get_path(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length, path_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_length = _strlen(path) + 1;
		path_copy = malloc(sizeof(char) * path_length);
		if (!path_copy)
			return (NULL);
		_strcpy(path_copy, path);
		command_length = _strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			if (!file_path)
			{
				free(path_copy);
				return (NULL);
			}
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			free(file_path);
			path_token = strtok(NULL, ":");
		}
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (_strdup(command));
	}
	return (NULL);
}

