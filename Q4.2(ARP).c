#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#include <net/if_arp.h>
#include <net/ethernet.h>

#include <arpa/inet.h>

#include <netinet/in.h>
#include <netinet/if_ether.h>


int main(int argc, char *argv[]) {
    struct sockaddr_in sin = {0};
    struct arpreq myarp = {{0}};
    unsigned char *ptr;
    int sd;

    // Check if the correct number of command line arguments is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    sin.sin_family = AF_INET;

    // Convert the provided IP address string to network format and check its validity
    if (inet_aton(argv[1], &sin.sin_addr) == 0) {
        fprintf(stderr, "IP address entered '%s' is not valid\n", argv[1]);
        return 1;
    }

    memcpy(&myarp.arp_pa, &sin, sizeof(myarp.arp_pa));

    // Create a socket
    sd = socket(AF_INET, SOCK_DGRAM, 0);

    // Use ioctl to fetch ARP information
    if (ioctl(sd, SIOCGARP, &myarp) == 1) {
        printf("No entry in ARP cache for '%s'\n", argv[1]);
        close(sd);
        return 1;
    }

    ptr = &myarp.arp_pa.sa_data[0];

    // Print the retrieved MAC address
    printf("MAC Address for '%s': %02x:%02x:%02x:%02x:%02x:%02x\n",
           argv[1], *ptr, *(ptr + 1), *(ptr + 2), *(ptr + 3), *(ptr + 4), *(ptr + 5));

    // Close the socket
    close(sd);

    return 0;
}
// output
// ./a.out 172.47.29.06
// MAC Address for '172.47.29.06': 00:00:ac:2f:1d:06
