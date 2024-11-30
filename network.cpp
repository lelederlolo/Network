#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std ;

const char* host = "0.0.0.0" ;
int port = 7000 ;

int main(){
    int sock_fd ,new_fd ;
    socklen_t addrlen ;
    struct sockaddr_in my_addr, clinet_addr ;
    int status ;
    char indata[1024] = {0} ,outdata[1024] = {0} ;
    int on = 1 ;

    //create a socket 
    sock_fd = socket(AF_INET ,SOCK_STREAM ,0) ;
    if(sock_fd == -1){
        perror("Socket creation failed") ;
        exit(1) ;
    }

}