#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring>

int main() {
    int pipefd[2]; // pipefd[0]用于读，pipefd[1]用于写
    pid_t pid;
    char buffer[1024];

    // 创建管道
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // 创建子进程
    pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) { // 子进程
        close(pipefd[1]); // 关闭写端，子进程只读
        
        // 从管道读取数据
        ssize_t count = read(pipefd[0], buffer, sizeof(buffer));
        if (count == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        
        std::cout << "Child process received: " << buffer << std::endl;
        
        close(pipefd[0]); // 关闭读端
        exit(EXIT_SUCCESS);
    } else { // 父进程
        close(pipefd[0]); // 关闭读端，父进程只写
        
        const char* message = "Hello from parent process!";
        
        // 向管道写入数据
        if (write(pipefd[1], message, strlen(message) + 1) == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }
        
        std::cout << "Parent process sent message." << std::endl;
        
        close(pipefd[1]); // 关闭写端
        
        // 等待子进程结束
        wait(nullptr);
    }

    return 0;
}