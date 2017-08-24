
#include "TestImplementation.h"

TestImplementation::TestImplementation(int isocketfd, bool usesSsl):Connection(isocketfd, usesSsl){}
void TestImplementation::dataHandler(char *inputData, size_t size){
	// Add incoming data to input buffer.
	for (unsigned int i = 0; i < size; ++i){
		inputConsideration[inputIndex++] = inputData[i];
		// If a '\n' character is received then the input data is checked.
		if(inputData[i] == '\n'){
			inputConsideration[inputIndex] = 0;
			inputIndex = 0;
			std::cout << "Received from socket nr " << socketfd << " : " << inputConsideration;
			if(strncmp(inputConsideration, "quit", 4) == 0){
				// Instruct thread that is receiving the data to stop.
				keepRunning = false;
				static constexpr char quitMsg[] = "Goodbye!\n";
				// Send a friendly goodbye message to the connected client.
				write(quitMsg, sizeof(quitMsg));
				break;
			}
		}
	}
}
