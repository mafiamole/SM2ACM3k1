#include "client/WorkQueues.h"



WorkQueues::WorkQueues(){

}


	 std::queue<sf::Packet>& WorkQueues::packetsToSend(){
		static std::queue<sf::Packet> packetsToSend;
		return packetsToSend;
		
	}	
	 std::queue<sf::Packet>& WorkQueues::packetsToProcess(){
		static std::queue<sf::Packet> packetsToProcess;
		return packetsToProcess;
	}

	