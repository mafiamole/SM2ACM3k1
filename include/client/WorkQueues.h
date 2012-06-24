#ifndef WORK_QUEUES_H
#define WORK_QUEUES_H

#include <shared/Packets.h>
#include <queue>


class WorkQueues{
public:
	WorkQueues();

	static std::queue<sf::Packet>& packetsToSend();	
	static std::queue<sf::Packet>& packetsToProcess();
};
	

#endif