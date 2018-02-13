/*SERVER PART
 * AUTH-THMMY
 * MPISMPAS GEORGIOS AEM7941
 * Ergasia Leitourgika sythmata.
 * InterProcess communication (IPC)
 * implemented using named pipes.
 */

#include <stdlib.h>
#include <stdio.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#define verbose(msg, ...)\
do{\
	fprintf(stdout, " - " msg "\n", ##__VA_ARGS__);\
	fflush(stdout);\
} while(0)


#define USERNAME_LENGTH 100
#define BUFFER_LENGTH 10000

char buffer[BUFFER_LENGTH];
char username[USERNAME_LENGTH];
int npipe, username_len;


int main(){

	char *pipe_address = "/tmp/chat_named_pipe";
	
	int bindex;
        pid_t pid;
	// Creating named pipe
	mkfifo(pipe_address, 0666);
	
	// Opening named pipe
	npipe = open(pipe_address, O_RDWR);
	if(npipe < 0){
		perror("Error opening named pipe");
		exit(EXIT_FAILURE);
	}

	// Initializing
	memset(username, 0, USERNAME_LENGTH);
	memset(buffer, 0, BUFFER_LENGTH);
	
	// Welcome messages
        verbose("OS SERVER WELCOMES YOU!");
        printf(" - Enter your server's name: ");
	scanf("%s", username);
	getchar();
	username_len = strlen(username);
	sprintf(buffer, " - %s: ", username);
	//verbose("You have entered O.S.PROJECT as %s. Insert your message and press ENTER to send.", username);
	verbose("Waiting for client message.... ");
        // Creating reading thread
        pid = fork();

if (pid < 0) {
	 	//failure in creating a child
	 	perror ("fork");
	 	exit(2);
	}
if (pid == 0)
	{

	char read_buf[BUFFER_LENGTH];
	int bytes_read;

	// Reading from pipe
	while(1){
		memset(read_buf, 0, BUFFER_LENGTH);
		bytes_read = read(npipe, read_buf, BUFFER_LENGTH);
                
		// If data was from itself, send it back
		if(!memcmp(read_buf, buffer, username_len + 3))
			write(npipe, read_buf, bytes_read);
		
                // Else print it out
		else{
			printf("\r%s", read_buf);
			printf(" - %s: ", username);
			fflush(stdout);
		}
		usleep(10000);
	}
}

	// Reading message from standard input
	while(1){
		//printf(" - %s: ", username);
		bindex = username_len + 5;
		while(1){
			buffer[bindex] = getchar();
			fflush(stdin); bindex++;
			if(buffer[bindex-1] == '\n')
				break;
		}
		
		// Exit command
		if(!memcmp(&buffer[username_len+5], "exit", 4))
			break;
		
		// Sending through pipe
		write(npipe, buffer, bindex);
	}
	


	if(close(npipe) < 0)
		perror("Error closing named pipe");
}


