#include "get_next_line.h"

int main(void) {
    int fd = open("test.txt", O_RDONLY);
    char *line;
    /* 
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }*/
    
    line = get_next_line(fd);
    printf("%s",line);
    line = get_next_line(fd);
    printf("%s",line);
    
    close(fd);
    return 0;
}
