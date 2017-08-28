/**
 * @mainpage Example for the ServerSocket library
 * @section intro_sec What is this example about
 * A simple server in the Internet domain using TCP The port number is passed as an argument.\n
 * To test the server it is recommended to use telnet for non ssl servers and openssl s_cleant for ssl sockets.\n
 * The exact commands for these are "telnet 127.0.0.1 2500" and "openssl s_client -host 127.0.0.0 -port 2500" respectively.
 */
#include <iostream>
#include <string.h>
#include "TestImplementation.h"

using namespace std;

void commandLineInterfaceHandler(WelcomingSocket<TestImplementation>& socket);
/**
 * @brief      Displays CLI help message.
 */
void printHelp();

int main(int argc, char *argv[])
{
	// Configure the port used for incoming connections
	static int port = 2500;
	// If user inserted another port via the command line use then use that one.
	if(argc == 2){
		port = atoi(argv[1]);
	}
	static WelcomingSocket<TestImplementation> socket(port, true);
	// Command line user interface part.
	commandLineInterfaceHandler(socket);
	return 0; 
}

void commandLineInterfaceHandler(WelcomingSocket<TestImplementation>& socket){
	bool running = true;
	string inputCLI;
	cout << "Welcome the the server socket example program.\n"
	"Enter \"help\" to display help message." << endl;
	while(running){
		cout << ":> " << flush;
		getline(cin, inputCLI);
		if(inputCLI == ""){

		}
		else if(inputCLI == "help"){
			printHelp();
		}
		else if(inputCLI == "quit" || inputCLI == "q"){
			cout << "Closing...";
			cout.flush();
			running = false;
		}
		else if(inputCLI == "ls"){
			socket.printConnections();
		}
		else if(inputCLI == "clear"){
			cout << "\e[1;1H\e[2J" << endl;
		}
		else if(inputCLI == "kill"){
			int socketfd;
			do{
				cout << "Please specify the socket number you want to kill.\n:> ";
				cout.flush();
				cin.clear();
				cin >> socketfd;
				cin.get();
			}while(cin.good() == false);
			socket.kill(socketfd);
		}
		else{
			cout << "Invalid command \"" << inputCLI << "\"\n";
			printHelp();
		}
	}
	cout << "done" << endl;
}

void printHelp(){
	cout << "Available commands are:\n\n"

	"help : Prints this help message.\n"
	"quit : Quits the server and closes the clients.\n"
	"ls   : List current connections and there statuses.\n"
	"kill : Kill specific connection." << endl;
}
