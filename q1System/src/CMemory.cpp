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

#include <iostream>

#include "../include/CMemory.h"

q1::CMemory::CMemory(const std::wstring& wstrProcessName, const wchar_t* szModuleName)
{
	m_Process = CProcess(wstrProcessName);
	m_Module = CModule(m_Process.processId(), szModuleName);
	m_hProcess = OpenProcess(PROCESS_ALL_ACCESS, 0, m_Process.processId());
}

q1::CMemory::~CMemory()
{
	CloseHandle(m_hProcess);
}

q1::CProcess& q1::CMemory::process()
{
	return m_Process;
}

q1::CModule& q1::CMemory::module()
{
	return m_Module;
}

uintptr_t q1::CMemory::readPointerFromModule(uintptr_t& uintAddr)
{
	uintptr_t value;
	ReadProcessMemory(m_hProcess,reinterpret_cast<LPCVOID>(m_Module.modulePointer() + uintAddr),&value,sizeof(uintptr_t),nullptr);
	return value;
}
