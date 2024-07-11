#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/model/Model.hpp>
#include <stdio.h>

Screen2View::Screen2View() : tickCounter(0)
{
}

void Screen2View::setupScreen()
{
    Screen2ViewBase::setupScreen();

	touchgfx::Unicode::snprintf(cpuTextAreaBuffer, CPUTEXTAREA_SIZE, "%d", presenter->getCpuUsage());
	touchgfx::Unicode::snprintf(memoryTextAreaBuffer, MEMORYTEXTAREA_SIZE, "%d", presenter->getMemoryUsage());
	touchgfx::Unicode::snprintf(gpuTextAreaBuffer, GPUTEXTAREA_SIZE, "%d", presenter->getGpuUsage());

	cpuTextArea.invalidate();
	memoryTextArea.invalidate();
	gpuTextArea.invalidate();

    uint8_t cpu[Model::USAGE_ARRAY_NUM];
	uint8_t memory[Model::USAGE_ARRAY_NUM];
	uint8_t gpu[Model::USAGE_ARRAY_NUM];
	presenter->getEachUsage(cpu, memory, gpu);

	// 取得した各種 usage データを流し込む
	for (int i = 0; i < Model::USAGE_ARRAY_NUM; i++) {
//		printf("(cpu, memory, gpu)=(%d, %d, %d)\n", cpu[i], memory[i], gpu[i]);
		cpuDynamicGraph.addDataPoint(cpu[i]);
		memoryDynamicGraph.addDataPoint(memory[i]);
		gpuDynamicGraph.addDataPoint(gpu[i]);
	}
}

void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
}

void Screen2View::handleTickEvent()
{
	tickCounter++;

	if (tickCounter > 60) {
		touchgfx::Unicode::snprintf(cpuTextAreaBuffer, CPUTEXTAREA_SIZE, "%d", presenter->getCpuUsage());
		touchgfx::Unicode::snprintf(memoryTextAreaBuffer, MEMORYTEXTAREA_SIZE, "%d", presenter->getMemoryUsage());
		touchgfx::Unicode::snprintf(gpuTextAreaBuffer, GPUTEXTAREA_SIZE, "%d", presenter->getGpuUsage());

		cpuTextArea.invalidate();
		memoryTextArea.invalidate();
		gpuTextArea.invalidate();

		cpuDynamicGraph.addDataPoint(presenter->getCpuUsage());
		memoryDynamicGraph.addDataPoint(presenter->getMemoryUsage());
		gpuDynamicGraph.addDataPoint(presenter->getGpuUsage());

		tickCounter = 0;
	}
}
