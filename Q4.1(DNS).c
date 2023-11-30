#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>

#include<arpa/inet.h>

#include<netdb.h>
#include<errno.h>

int main(int argc, char *argv[1]) {
if (argc != 2) {
    fprintf(stderr, "enter host name\n");
    return 1; // Exit the program with an error code
}
struct hostent *hen;
hen = gethostbyname(argv[1]);
if (hen == NULL) {
    fprintf(stderr, "host not found\n");
    return 1; // Exit the program with an error code
}
printf("Host name: %s \n", hen->h_name);
printf("IP address: %s \n", inet_ntoa(*((struct in_addr *)hen->h_addr))); // converts ipv4 address to string
return 0;
}

// output
// ./a.out google.com
// Host name: google.com 
// IP address: 74.125.197.138 
