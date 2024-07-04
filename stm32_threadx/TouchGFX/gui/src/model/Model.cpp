#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdio.h>
#include <cstring>
#include "main.h"

#define RECV_PACKET_SIZE	7
#define SEND_PACKET_SIZE	4

extern UART_HandleTypeDef huart1;

typedef struct Packet {
	uint8_t size;
	uint8_t version;
	uint8_t result;
	uint8_t volume;
	uint8_t cpuUsage;
	uint8_t memoryUsage;
	uint8_t gpuUsage;
} Packet;

int gUartReceived = 0;
int gIsAlreadySend = 0;

uint8_t buffer[256];
Packet packet;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  gUartReceived = 1;
}

Model::Model() : modelListener(0),
		tickCounter(0), systemVolume(0), cpuUsage(0), memoryUsage(0), gpuUsage(0)
{
  printf("Model Constructor\n");
  HAL_UART_Receive_IT(&huart1, buffer, RECV_PACKET_SIZE);
}

void Model::tick()
{
  tickCounter++;
  if (gUartReceived) {
	memcpy(&packet, buffer, RECV_PACKET_SIZE);
	printf("size:%d, version:%d, result:%d, volume:%d, cpu:%d, memory:%d, gpu:%d\n",
			packet.size, packet.version, packet.result, packet.volume,
			packet.cpuUsage, packet.memoryUsage, packet.gpuUsage);
	systemVolume = packet.volume;
	cpuUsage = packet.cpuUsage;
	memoryUsage = packet.memoryUsage;
	gpuUsage = packet.gpuUsage;
    gUartReceived = 0;
    HAL_UART_Receive_IT(&huart1, buffer, RECV_PACKET_SIZE);
  } else if (tickCounter > 30) {
	if (gIsAlreadySend) {
		gIsAlreadySend = 0;
	} else {
		HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"INFO", SEND_PACKET_SIZE);
	}
    tickCounter = 0;
  }
}

void Model::play()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"PLAY", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}

void Model::nextMusic()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"NEXT", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}

void Model::prevMusic()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"PREV", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}

void Model::volumeUp()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"VLUP", SEND_PACKET_SIZE);
	systemVolume += 2;
	if (systemVolume > 100) {
		systemVolume = 100;
	}
	gIsAlreadySend = 1;
}

void Model::volumeDown()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"VLDN", SEND_PACKET_SIZE);
	systemVolume -= 2;
	if (systemVolume > 100) {
		systemVolume = 0;
	}
	gIsAlreadySend = 1;
}

void Model::displayPort()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"DISP", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}

void Model::hdmi1()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"HMI1", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}

void Model::hdmi2()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"HMI2", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}

void Model::typec()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"TYPC", SEND_PACKET_SIZE);
	gIsAlreadySend = 1;
}
