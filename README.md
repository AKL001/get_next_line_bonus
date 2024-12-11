# 📜 get_next_line  

**get_next_line** is a 42 project aimed at creating a function that reads a line from a file descriptor (one line at a time). It teaches efficient memory handling, file operations, and the use of static variables to preserve state across function calls.  

---

## 🧠 What You'll Learn  
- **Static Variables**: Manage state between function calls for multiple file descriptors.  
- **Memory Management**: Allocate, resize, and free memory to avoid leaks.  
- **File Handling**: Work with file descriptors using `read()` and handle errors gracefully.  

---

## ⚙️ How to Use  

### Clone the Repository  
```bash
git clone https://github.com/AKL001/get_next_line_bonus.git
cd get_next_line_bonus
```
### Example Code
**Create a main.c file:**
```bash
#include "get_next_line.h"
int main(void)
{
    // change example.txt with the file you want to read from
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```
#### 🔧 Compilation and Execution
**Compile and run the code with the following command:**
```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c -o gnl && ./gnl
```
### 💧 Checking for Memory Leaks with Valgrind:
*🔍 Keep your code leak-free by regularly checking with Valgrind*
**To check your program for memory leaks, use the following command:**
```
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./gnl
```
---

## 🛠️ Project Status  

This project is part of the 42 curriculum and serves as a foundation for mastering file handling and memory management in C. Contributions, suggestions, and feedback are welcome!  

---

## 📬 Contact  

Feel free to reach out if you have any questions or need assistance:  

- **Email**: akarimlabib@gmail.com  
- **GitHub**: [AKL001](https://github.com/AKL001)  

---
