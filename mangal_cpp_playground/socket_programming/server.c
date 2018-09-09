/* ------------------------ Server impementation -----------------------*/
#include<stdio.h>
#include<unistd.h>
#include<sys/socket.h> //socket progs
#include<stdlib.h>
#include<netinet/in.h>
#include<string.h>

#define PORT 9002
int main(int argc, char** argv){

	int socket_fd, client_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);	
	char buffer[1024] = {0};
	char *hello = "Hello from Mangal server";

/*	//1A. CREATE SOCKET FD
	//int sockfd = socket(domain, type, protocol)
	//AL_INET (IPv4) SOCK_STREAM(TCP)/SOCK_DGRAM(UDP)
	if((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0 ){
		perror("socket failed");
		exit (1);
	}		

	//1B. SET SOCKET PARAMS
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = PORT;

	//2. BIND SOCKET TO PORT
	//int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
	if ((bind(socket_fd, (struct sockaddr*)&address, sizeof(address))) < 0){
		perror("Binding error");
		exit (1);
	}
	//3. LISTEN ON PORT
	//int listen(int sockfd, int backlog);
	if (listen(socket_fd, 5) < 0){
		perror("listen queue error");
		exit (1);
	}
	//4. ACCEPT CLIENT REQUEST
	//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
/*	if ((client_socket = accept(socket_fd, (struct sockaddr*) &address, \
		(socklen_t*)&addrlen)) < 0){
		perror("accept error");
		exit(1);
	}*/
	
	if ((client_socket = accept(socket_fd, NULL, NULL)) < 0){
		perror("accept error");
		exit(1);
	}
	
	//send the message
	send (client_socket, hello, strlen(hello), 0);

	//close the socket
	close(socket_fd);



/*	do{

		//4. ACCEPT CLIENT REQUEST
		//int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
		if ((client_socket = accept(socket_fd, (struct sockaddr*) &address, \
			(socklen_t*)&addrlen)) < 0){
			perror("accept error");
			exit(1);
		}else{
			//5. SEND/RECEIVE DATA	
		      	if((valread = read (client_socket, buffer, 1024))>0){
				printf("%s\n", buffer);
			}else{
				printf("Message stream error");
			}
			//send(client_socket, hello, strlen(hello), 0);
			//printf(" hello message sent\n");
		}
	}while(1);
*/
	
	return 0;
	
}
