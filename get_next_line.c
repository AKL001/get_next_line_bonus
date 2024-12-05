#include "get_next_line.h"


static char *ft_read_file(int fd, char *buffer)
{
    char *new_buff;
    char *tmp;
    int byte_read;

    if (!buffer)
        buffer = ft_strdup("");  // Initialize buffer as an empty string if NULL

    new_buff = (char *)malloc(BUFFER_SIZE + 1);  // Allocate memory for new_buff
    if (!new_buff)
        return NULL;

    byte_read = 1;
    while (byte_read > 0)
    {
        byte_read = read(fd, new_buff, BUFFER_SIZE);  // Read from file
        if (byte_read == -1)
        {
            free(new_buff);
            return NULL;  // Return NULL if read fails
        }

        new_buff[byte_read] = '\0';  // Ensure new_buff is null-terminated

        tmp = ft_strjoin(buffer, new_buff);  // Join the buffer and new_buff
        if (!tmp)  // Check for memory allocation failure
        {
            free(buffer);
            free(new_buff);
            return NULL;
        }
        free(buffer);  // Free old buffer
        buffer = tmp;  // Set buffer to the new joined string

        if (ft_strchr(buffer, '\n'))  // Check if newline is found
            break;
    }

    free(new_buff);  // Free new_buff after use
    return buffer;  // Return the concatenated buffer
}

static char *ft_get_line(char *buffer)
{
    int i = 0;
    char *line;

    if (!buffer || !*buffer)
        return NULL;

    while (buffer[i] && buffer[i] != '\n')  // Find the index of the first newline
        i++;

    if (buffer[i] == '\n')
        i++;  // Include the newline character in the line

    line = ft_substr(buffer, 0, i);  // Extract the line from buffer
    return line;
}

static int ft_next_line(char *buffer)
{
    int i = 0;

    if (!buffer || !*buffer)
        return -1;

    while (buffer[i] && buffer[i] != '\n')  // Find the index of the first newline
        i++;

    if (buffer[i] == '\n')
        return i;  // Return the position of the newline
    return -1;
}
char *get_next_line(int fd)
{
    static char *buffer;
    char  *line;
    int   len;

    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return NULL;

    buffer = ft_read_file(fd, buffer);
    if (!buffer)
        return NULL;

    line = ft_get_line(buffer);
    if (!line)
    {
        free(buffer);
        buffer = NULL;
        return NULL;
    }

    len = ft_next_line(buffer);
    if (len >= 0)
        ft_memmove(buffer, buffer + len + 1, ft_strlen(buffer + len + 1) + 1);  // safer copy
    return line;
}
