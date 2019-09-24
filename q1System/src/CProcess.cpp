/*
 * File: CProcess.cpp
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

#include "../include/CProcess.h"

q1::CProcess::CProcess(const std::wstring& processName)
{
	m_wstrProcessName = processName;
	m_dwProcessId = CProcess::findProcessId(processName);
}

std::wstring& q1::CProcess::processName()
{
	return m_wstrProcessName;
}

DWORD& q1::CProcess::processId()
{
	return m_dwProcessId;
}

bool q1::CProcess::hasFound()
{
	return m_dwProcessId != 0;
}

DWORD q1::CProcess::findProcessId(const std::wstring& wstrProcessName)
{
	PROCESSENTRY32 processInfo;
	processInfo.dwSize = sizeof(processInfo);

	HANDLE hProcessesSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	if (hProcessesSnapshot == INVALID_HANDLE_VALUE)
		return 0;

	Process32First(hProcessesSnapshot, &processInfo);
	if (!wstrProcessName.compare(processInfo.szExeFile))
	{
		CloseHandle(hProcessesSnapshot);
		return processInfo.th32ProcessID;
	}

	while (Process32Next(hProcessesSnapshot, &processInfo))
	{
		if (!wstrProcessName.compare(processInfo.szExeFile))
		{
			CloseHandle(hProcessesSnapshot);
			return processInfo.th32ProcessID;
		}
	}

	CloseHandle(hProcessesSnapshot);
	return 0;
}
