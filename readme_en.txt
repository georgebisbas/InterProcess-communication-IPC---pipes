THMMY-AUTH
OPERATING SYSTEMS PORJECT 2016
Electrical and Computer Engineering Dept.
Aristotle Univeristy of Thessaloniki

MPISMPAS GEORGIOS AEM7941
ΜΠΙΣΜΠΑΣ ΓΕΩΡΓΙΟΣ ΑΕΜ7941

Implementing 2 source codes in .c .
One for client and one for server.
Code implemented for an echo server,
using named pipes.

Brief description.
Every program by using 
mkfifo(pipe_address, 0666);
και
npipe = open(pipe_address, O_RDWR);
creates and opens (gains access) to a named pipe which is used in common from 2 terminals.




Implementation enviroment:
Programming Language: C
Operating System: OS Ubuntu 14.04 LTS.


HOW TO:

- Build:
make all

- Run
Terminal 1
 ./client7941    
Terminal 2
./server7941

- You will be asked for a username. Use names without blank spaces.
- Type your message and send it by pressing ENTER
- Your message will be displayed in Server Terminal.
- By typing exit "exit" either in client or server you can disconnect from the IPC.
*"exit" (lower case);
*"EXIT" accepted as message.

For an questions, or whatever : 
gbisbas@hotmail.com

