/*
 * File: entry.cpp
 * Location: /
 * Author: Qu1oX
 *
 * This file is part of {{ q1System }}.
 *
 * MIT License
 * Copyright (c) 2019 Qu1oX
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER	LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <CProcess.h>
#include <CModule.h>
#include <CMemory.h>

#pragma comment(lib, "q1System")

/**
 * Entry point of the program. Just to show some features of the lib
 */
int main()
{
	uintptr_t localplayer = 0x00109B74;
	uintptr_t health = 0xF8;

	q1::CMemory acClient(L"ac_client.exe", L"ac_client.exe");

	std::cout << "Process " << acClient.process().processId() << std::endl;
	std::cout << "Module " << acClient.module().moduleName() << std::endl;
	std::cout << "Pointer " << std::hex << "0x"<< acClient.module().modulePointer() << std::endl;

	std::cout << "-----------------------------" << std::endl;

	uintptr_t localplayerPtr = acClient.readPointerFromModule(localplayer);
	std::cout << "local: " << localplayerPtr << std::endl;

	int32_t healthValue = acClient.read<int32_t>(localplayerPtr + health);
	std::cout << "health: " << healthValue << std::endl;

	acClient.write(localplayerPtr + health, 1337);

	return 0;
}