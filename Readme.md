Jeff Banister
bani0044

This project was written in C++
How to run project:
    client:
        1. Make sure current working directory is whereItWasPlaced/NetA2/client
        2. Call make clean to ensure project is clean
        3. Call make 
        4. Pick excutable to run
        5. Download file are stored in whereItWasPlaced/NetA2/client/src/data

    server:
        1. Make sure current working directory is whereItWasPlaced/NetA2/server
        2. Call make clean to ensure project is clean
        3. Call make
        4. Place server data into whereItWasPlaced/NetA2/server/src/data
        5. Pick excutable to run  

How to change message.h file
    client:
        1. reaplace whereItWasPlaced/NetA2/client/src/h/message.h with new message.h
        2. rebuild project
    server:   
        1. reaplace whereItWasPlaced/NetA2/server/src/h/message.h with new message.h
        2. rebuild project 

Notes:
    Each client and server have a debug and a src directory. Complied objects and excutables
    are stored in the debug directory. Source code is stored in the src directory.

    In each src directory there is a data and an h subdirectory. h directory stores h 
    files. data directory is where the program reads and writes data to. 

Class:
    server_tcp - holds the main for tcp server
    client_tcp - holds the main for tcp client
    server_udp - holds the main for udp server
    client_udp - holds the main for tcp client
    
    TcpServer - contains logic for how to connect and handle incoming requests
    UdpServer - contains logic for how to connect and handle incoming requests
    Client - contatins logic for how to connect and issue request. There is an
             udp verison and tcp verison with different code.
    
    ArgHandler - handles logic for the argument that are passed into the program
    FileWriter - handles logic for writting data into data directory
    FilePacker - reads in file data and packages it up into messages to sent accross the 
                 network
    MessageMaker - handles logic for building messages to sent to the server
    NetTime - Used to measure the clients performace
    
      
