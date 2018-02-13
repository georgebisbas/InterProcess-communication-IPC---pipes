THMMY-AUTH
OPERATING SYSTEMS PORJECT 2016
Electrical and Computer Engineering Dept.
Aristotle Univeristy of Thessaloniki

MPISMPAS GEORGIOS AEM7941
ΜΠΙΣΜΠΑΣ ΓΕΩΡΓΙΟΣ ΑΕΜ7941

Υλοποιήση 2 προγραμμάτων σε .c .
Ενα για τον client και ένα για τον server.
Υλοποιήθηκε κώδικας για την δημιουργία ενός echo server,
με την χρήση named pipes.

Σύνοψη υλοποίησης.Κάθε πρόγραμμα μέσω των εντολών
mkfifo(pipe_address, 0666);
και
npipe = open(pipe_address, O_RDWR);
δημιουργεί και ανοίγει (αποκτά πρόσβαση) το named pipe που χρησιμποιείται από κοινού από τα δύο(2) τερματικά.
Εν συνεχεία "τακτοποιεί" την "υποδοχή" των users, και ακολούθως δημιουργείται μέσω fork() μια διαδικασία παιδί σε κάθε terminal για την ενδοεπικοινωνία.
Ακολούθως μέσω εντολών read, write, buffer, fflush χειριζόμαστε ανάλογα
το περιεχόμενο των pipes ανάλογα με το τι θέλουμε να κάνουμε σε κάθε περίπτωση...
O client γράφει στο pipe και ο server αναπαράγει το μήνυμα.Ο server επίσης μπορεί να γράψει αλλά το περιεχόμενο που καταγράφει αγνοείται.


Περιβάλλον υλοποίησης:
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

- Σε κάθε πρόγραμμα θα σας ζητηθεί ένα username.Χρησιμοποιήστε ονόματα χωρίς κενά.
- Πληκτρολογήστε το μήνυμα σας και αποστείλατε το με το πάτημα του ENTER
- Το αποσταλθέν μήνυμα θα εμφανιστεί στο Terminal του server.
- Με την πληκτρολόγηση "exit" είτε στον client είτε στον server μπορέιτε να αποσυνδεθείτε από την ενδοεπικοινωνία.
*"exit" (lower case);
*"EXIT" accepted as message.

Για οποιαδήποτε έλλειψη,απαραίτητη προσθήκη και οτιδήποτε θεωρείτε ασαφές ή που να χρήζει επεξήγησης μην διστάσετε να επικοινωνήσετε στο 
gbisbas@hotmail.com

