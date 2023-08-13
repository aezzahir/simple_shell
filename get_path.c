#include "main.h"



char *get_path(const char *command) {
    char *path, *path_copy, *path_token, *file_path;
    int command_len, token_len;
    struct stat buffer;

    path = getenv("PATH");

    if (path) {
        _strcpy(path_copy, path);
        command_len = _strlen(command);
        path_token = strtok(path_copy, ":");

        while (path_token) {
            token_len = _strlen(path_token);
            file_path = (char *)malloc(command_len + token_len + 2); 
            if (!file_path) {
                perror("Error allocating memory");
                free(path_copy);
                return NULL;
            }
            _strcpy(file_path, path_token);
            _strcat(file_path, "/");
            _strcat(file_path, command);
            
            if (stat(file_path, &buffer) == 0) { 
                free(path_copy);
                return file_path;
            } else {
                free(file_path);
                path_token = strtok(NULL, ":");
            }
        }
        free(path_copy);
        if (stat(command, &buffer) == 0) {
            return command;
        }
        return NULL;
    }

    return NULL;
}


