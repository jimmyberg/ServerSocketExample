
#ifndef TESTIMPLEMENTATION
#define TESTIMPLEMENTATION

#include "SimpleSocketServer/SocketPp.h"
/**
 * @brief      Implementation example for the Connection ABS.
 */
class TestImplementation : public Connection{
public:
	/**
	 * @brief      Constructor that now simply passes the arguments to the
	 *             connection constructor
	 *
	 * @param[in]  isocketfd  The socketfd that will be received from the accept
	 *                        socket.
	 * @param[in]  usesSsl    State if the connection needs to use SSL or not.
	 */
	TestImplementation(int isocketfd, bool usesSsl);
	/**
	 * @brief      This function will be called by the thread function when new
	 *             data has been received.
	 *
	 * @param      inputData  Pointer to the data array.
	 * @param[in]  size       The size of inputData
	 */
	void dataHandler(char *inputData, size_t size);
private:
	char inputConsideration[1024];
	unsigned int inputIndex = 0;
};

#endif
