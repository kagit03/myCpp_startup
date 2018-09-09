/* ------------------------ Client implementation -----------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include <arpa/inet.h>
#include<unistd.h>

#define PORT 9002

int main (int argc, char** argv){
	
	//struct sockaddr_in address;
	struct sockaddr_in serv_addr;
	int socket_fd, valread;
	char buffer[1024] = {0};
	char *hello = "Hello from Mangal client";

	//1. CREATE SOCKET FD
	// here 3rd argument 0 = TCP
	if ((socket_fd=socket(AF_INET, SOCK_STREAM, 0)) < 0){
		perror("socket client error\n");
		exit (1);
	}

	memset(&serv_addr, 0, sizeof(serv_addr));

	serv_addr.sin_family= AF_INET;
	serv_addr.sin_port = htons(PORT);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
		
	//2. CONNECT TO SERVER SOCKET
	
	if (connect(socket_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0){
		perror("connection failed \n");
	}
	//send(socket_fd, hello, strlen(hello), 0);
	//printf("hello message sent\n");
	//valread = read(socket_fd,buffer, 1024);
	recv(socket_fd, &buffer, sizeof(buffer), 0);
	printf("%s\n", buffer);

	return 0;
}
