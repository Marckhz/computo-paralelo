#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORTNUMBER  7777

void main(void)
{
    char buf[10];
    int s, n, ns, len;
    struct sockaddr_in name;

    /* Create the socket. */
    s = socket(AF_INET, SOCK_STREAM, 0);

    /* Create the address of the server. */
    name.sin_family = AF_INET;
    name.sin_port = htons(PORTNUMBER);
    name.sin_addr.s_addr = htons(INADDR_ANY); /* Use the wildcard address.*/
    len = sizeof(struct sockaddr_in);
    
    /* Bind the socket to the address. */
   if( bind(s, (struct sockaddr *) &name, len))
		printf("bind error");

    /* Listen for connections.  */
    listen(s, 5);

    /* Accept a connection.  */
    while(1){
    	ns = accept(s, (struct sockaddr *) &name, &len);
	int pid  = fork();
	

    /* Read from the socket until end-of-file and
     * print what we get on the standard output.  */
    	if(pid == 0){
		printf("Connection from : %s\n",inet_ntoa(name.sin_addr));
    
    		while ((n = recv(ns, buf, sizeof(buf), 0)) > 0)
        		write(1, buf, n);
		}
    	}
    close(ns);
    close(s);
    exit(0);
}
