#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdio.h>
#include <cstring>
#include "main.h"

#define RECV_PACKET_SIZE	7
#define SEND_PACKET_SIZE	4

extern UART_HandleTypeDef huart1;
extern TIM_HandleTypeDef htim3;

enum {
	COMMAND_INFO,
	COMMAND_PLAY,
	COMMAND_NEXT,
	COMMAND_PREV,
	COMMAND_VLUP,
	COMMAND_VLDN,
	COMMAND_DISP,
	COMMAND_HMI1,
	COMMAND_HMI2,
	COMMAND_TYPC
};

typedef struct Packet {
	uint8_t size;
	uint8_t version;
	uint8_t command;
	uint8_t volume;
	uint8_t cpuUsage;
	uint8_t memoryUsage;
	uint8_t gpuUsage;
} Packet;

int gUartReceived = 0;

uint8_t buffer[256];
Packet packet;

int isButtonTriggered = 0;
int isButtonReleased = 1;

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  gUartReceived = 1;
}

Model::Model() : modelListener(0),
		currentScreenIndex(0), tickCounter(0),
		isBackLightOn(true),
		systemVolume(0), cpuUsage(0), memoryUsage(0), gpuUsage(0)
{
  printf("Model Constructor\n");

  // Model まで起動したので、RED LED を消灯する (Active Low)
  HAL_GPIO_WritePin(USER_LD2_RED_GPIO_Port, USER_LD2_RED_Pin, GPIO_PIN_SET);

  // LCD Back light の PWM 開始
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);

  // シリアル受信割り込みを有効
  HAL_UART_Receive_IT(&huart1, buffer, RECV_PACKET_SIZE);

}

void Model::tick()
{
  tickCounter++;

  // USER_BUTTON 処理
  if (HAL_GPIO_ReadPin(USER_BUTTON_GPIO_Port, USER_BUTTON_Pin) == GPIO_PIN_SET) {
	  if (isButtonReleased) {
		  isButtonTriggered = 1;
		  isButtonReleased = 0;
		  printf("USERBUTTON is triggered\n");

		  setBackLightState(isBackLightOn ? false : true);
	  }
  } else {
	  if (isButtonTriggered) {
		  isButtonTriggered = 0;
		  isButtonReleased = 1;
		  printf("USERBUTTON is released\n");
	  }
  }

  if (gUartReceived) {
	memcpy(&packet, buffer, RECV_PACKET_SIZE);
	printf("size:%d, version:%d, command:%d, volume:%d, cpu:%d, memory:%d, gpu:%d\n",
			packet.size, packet.version, packet.command, packet.volume,
			packet.cpuUsage, packet.memoryUsage, packet.gpuUsage);
	switch (packet.command) {
	case COMMAND_INFO:
		systemVolume = packet.volume;
		cpuUsage = packet.cpuUsage;
		memoryUsage = packet.memoryUsage;
		gpuUsage = packet.gpuUsage;
		break;

	case COMMAND_VLUP:
	case COMMAND_VLDN:
		systemVolume = packet.volume;
		break;
	}
	gUartReceived = 0;
    HAL_UART_Receive_IT(&huart1, buffer, RECV_PACKET_SIZE);
  } else if (tickCounter > 60) {
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"INFO", SEND_PACKET_SIZE);
    tickCounter = 0;
  }
}

void Model::setBackLightState(bool isOn)
{
	if (isBackLightOn == isOn)
	{
		return;
	}

	// PWM の duty 比を変えて輝度を変える
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, isOn ? 75 : 0);

	// Active Low (BL 点灯時は LED OFF)
	HAL_GPIO_WritePin(USER_LD3_GREEN_GPIO_Port, USER_LD3_GREEN_Pin, isOn ? GPIO_PIN_SET : GPIO_PIN_RESET);

	isBackLightOn = isOn;
}

void Model::play()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"PLAY", SEND_PACKET_SIZE);
}

void Model::nextMusic()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"NEXT", SEND_PACKET_SIZE);
}

void Model::prevMusic()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"PREV", SEND_PACKET_SIZE);
}

void Model::volumeUp()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"VLUP", SEND_PACKET_SIZE);
}

void Model::volumeDown()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"VLDN", SEND_PACKET_SIZE);
}

void Model::displayPort()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"DISP", SEND_PACKET_SIZE);
}

void Model::hdmi1()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"HMI1", SEND_PACKET_SIZE);
}

void Model::hdmi2()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"HMI2", SEND_PACKET_SIZE);
}

void Model::typec()
{
	HAL_UART_Transmit_IT(&huart1, (const uint8_t*)"TYPC", SEND_PACKET_SIZE);
}
