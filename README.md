# ServerSocketExample

A simple server in the Internet domain using TCP. 
This is an example implementation on how to use the SimpleSocketServer to serve multible connections.

# How to install
1. Download this repository using `git clone git@github.com:overlord1123/ServerSocketExample.git`
2. Cd into the repository `cd ServerSocketExample/`
3. Download its SimpleSocketModule gitmodule by using `git submodule init && git submodule update` in the repository
4. Compile using `make`
5. Start server by running the compiled binary `./prog`.
You can specify another port by entering it as argument. For example when using port 1200 `./prog 1200`
