/*
 * File: CProcessor.cpp
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

#include "../include/CProcessor.h"
#include <ostream>
#include <iostream>
#include <intrin.h>

q1::CProcessor::CProcessor()
{
	m_stBrand = getBrand();
	m_wArchitecture = getArchitectureAsWord();
	m_stArchitecture = getArchitecture();
	m_dwType = getTypeAsDword();
	m_stType = getType();
	m_dwCore = getCores();
}

q1::CProcessor::~CProcessor()
{
}

std::string& q1::CProcessor::brand()
{
	return m_stBrand;
}

std::string& q1::CProcessor::architecture()
{
	return m_stArchitecture;
}

std::string& q1::CProcessor::type()
{
	return m_stType;
}

DWORD& q1::CProcessor::cores()
{
	return m_dwCore;
}

std::string q1::CProcessor::getBrand()
{
	int CPUInfo[4] = { -1 };
	unsigned   nExIds, i = 0;
	char brand[0x40];
	__cpuid(CPUInfo, 0x80000000);

	nExIds = CPUInfo[0];
	for (i = 0x80000000; i <= nExIds; ++i)
	{
		__cpuid(CPUInfo, i);

		if (i == 0x80000002)
			memcpy(brand, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000003)
			memcpy(brand + 16, CPUInfo, sizeof(CPUInfo));
		else if (i == 0x80000004)
			memcpy(brand + 32, CPUInfo, sizeof(CPUInfo));
	}

	return brand;
}

WORD q1::CProcessor::getArchitectureAsWord()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	return sysInfo.wProcessorArchitecture;
}

std::string q1::CProcessor::getArchitecture()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	switch (sysInfo.wProcessorArchitecture)
	{
	case PROCESSOR_ARCHITECTURE_INTEL:
		return "x86";
		break;
	case PROCESSOR_ARCHITECTURE_AMD64:
		return "x64 (AMD or Intel)";
		break;
	case PROCESSOR_ARCHITECTURE_ARM:
		return "ARM";
		break;
	case PROCESSOR_ARCHITECTURE_ARM64:
		return "ARM64";
		break;
	case PROCESSOR_ARCHITECTURE_IA64:
		return "Intel Itanium-based";
		break;
	default:
		return "Unknown architecture.";
		break;
	}
}

DWORD q1::CProcessor::getTypeAsDword()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	return sysInfo.dwProcessorType;
}

std::string q1::CProcessor::getType()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	switch (sysInfo.dwProcessorType)
	{
	case PROCESSOR_INTEL_386:
		return "Intel 386 processor";
		break;
	case PROCESSOR_INTEL_486:
		return "Intel 486 Processor";
		break;
	case PROCESSOR_INTEL_PENTIUM:
		return "Intel Pentium Processor";
		break;
	case PROCESSOR_INTEL_IA64:
		return "Intel IA64 Processor";
		break;
	case PROCESSOR_AMD_X8664:
		return "AMD X8664 Processor";
		break;
	default:
		return "Unknown";
		break;
	}
}

DWORD q1::CProcessor::getCores()
{
	SYSTEM_INFO sysInfo;
	GetSystemInfo(&sysInfo);

	return sysInfo.dwNumberOfProcessors;
}
