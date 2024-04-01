# Mini Talk

Mini Talk is a simple client-server communication program written in C. It allows the exchange of messages between a client and a server using signals.

## Features

- Send messages from the client to the server
- Receive messages on the server from the client
- Basic error handling
- Simple and easy-to-understand codebase

## How to Use

### Building

To build the project, simply run `make` in the root directory of the project. This will compile the `server.c` and `client.c` files along with any dependencies.
make

### Running

First, start the server by running:
./server

Then it will give you a SERVER_PID Number:
i.e. 73327

Then, start the client by providing the server's process ID (PID) and the message to send:
./client [SERVER_PID] [MESSAGE]

Replace [SERVER_PID] with the process ID of the server and [MESSAGE] with the message you want to send.
./client 73327 "Hello, Deia!"
