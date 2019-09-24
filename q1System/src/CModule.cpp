/*
 * File: CMemory.cpp
 * Location: src/
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

#include "../include/CModule.h"

#include <comdef.h>

q1::CModule::CModule(DWORD dwProcessId, const char* szModuleName)
{
	m_dwProcessId = dwProcessId;
	m_szModuleName = szModuleName;
	m_uintModulePointer = CModule::findModulePtr(dwProcessId, szModuleName);
}

DWORD q1::CModule::processId()
{
	return m_dwProcessId;
}

const char* q1::CModule::moduleName()
{
	return m_szModuleName;
}

uintptr_t q1::CModule::modulePointer()
{
	return m_uintModulePointer;
}

bool q1::CModule::hasFound()
{
	return m_uintModulePointer != 0;
}

uintptr_t q1::CModule::findModulePtr(DWORD dwProcessId, const char* szModuleName)
{
	uintptr_t ModuleBaseAddress = 0;
	HANDLE hProcessesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, dwProcessId);
	if (hProcessesSnapshot != INVALID_HANDLE_VALUE)
	{
		MODULEENTRY32 ModuleEntry32;
		ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
		if (Module32First(hProcessesSnapshot, &ModuleEntry32))
		{
			do
			{
				_bstr_t bStr(ModuleEntry32.szModule);

				if (strcmp(bStr, szModuleName) == 0)
				{
					ModuleBaseAddress = reinterpret_cast<uintptr_t>(ModuleEntry32.modBaseAddr);
					break;
				}
			} while (Module32Next(hProcessesSnapshot, &ModuleEntry32));
		}
		CloseHandle(hProcessesSnapshot);
	}
	return ModuleBaseAddress;
}
