# advanced-programming
As part of my Software Engineering Apprenticeship Degree, I was given two tasks to implement in an OOP language (C++).  The tasks will exhibit principles of C++ that have been learnt over the Advanced Programming module. This project was developed on MacOS using the Clang++ compiler.

## Task 1

Task 1 creates a simple game engine that consists of two classes representing entities within the game (GameComponent & DrawableGameComponent, which has an associated position – x,y) and a controlling class (Game) that manages the entities (see Task1AssignmentBrief.txt).

### Dependencies
- **Operating System**: MacOS
- **Compiler**: Clang++ (supports C++17)
- **Development Tools**: A text editor or IDE (e.g., Visual Studio Code)

### Build Instructions
To build this program with an executable of gameEngine, use the following command:
```console
/usr/bin/clang++ -std=c++17 -arch arm64 main.cpp Game.cpp GameComponent.cpp DrawableGameComponent.cpp -o gameEngine
```

### Usage
To run the executable from the project directory, use the following command:
```console
task1/gameEngine 
```

### Example Output
Your output should look similar to:

```console
Initialising Game...
ID: 1 Updated at 10:43:48 
ID: 2 Updated at 10:43:48 
Right : X: 1, Y: 0 
ID: 1 Updated at 10:43:49 
ID: 2 Updated at 10:43:49 
Up : X: 1, Y: 1 
ID: 1 Updated at 10:43:50 
ID: 2 Updated at 10:43:50 
Right : X: 2, Y: 1 
ID: 1 Updated at 10:43:51 
ID: 2 Updated at 10:43:51 
Left : X: 1, Y: 1 
ID: 1 Updated at 10:43:52 
ID: 2 Updated at 10:43:52 
Right : X: 2, Y: 1 
Terminating game...
```

The actual results may differ as the second movement onwards is randomised. You will not get the same direction twice in a row.

## Task 2

Task 2 creates a server and a client from the same codebase, using pre-processor directives in order to decide what part of the code is run. Full breakdown of the task can be found in Task2AssignmentBrief.txt.

### Dependencies
- **Operating System**: MacOS
- **Compiler**: Clang++ (supports C++11)
- **Development Tools**: A text editor or IDE (e.g., Visual Studio Code)

### Build Instructions
To build this program with an executable of server and client, use the following commands from the task2 directory:

#### Sever
```console
clang++ -DIS_SERVER=true -std=c++11 main.cpp Server.cpp Client.cpp Comms.cpp SockException.cpp -o server
```
#### Client
```console
clang++ -std=c++11 main.cpp Client.cpp Server.cpp Comms.cpp SockException.cpp -o client 
```

### Usage
The following commands must be run in separate terminals. To run the executables from the project directory, use the following commands:

#### Server
```console
task2/server
```

#### Client
```console
task2/client
```

### Example Output

#### Server
Your output should look similar to:

```console
Server: Bound to address and port successfully!
The server has successfully started! Listening for connections...
Server: Connection established with client successfully!
```

#### Client
```console
Client: Connected to server successfully!
Connection has been established with server.
Client: Connection closed.
```
