/*
 * File: CProcessor.h
 * Location: include/
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

#ifndef __C_PROCESSOR_H__
#define __C_PROCESSOR_H__

#include <string>
#include <windows.h>

namespace q1
{
	/**
	 * Data storage of the system CPU / Processor information <br>
	 * Functions to get this information
	 *
	 * @author Qu1oX
	 * @since 1.0
	 * @version 1.0
	 */
	class CProcessor
	{
	public:

		/**
		 * Creates an instance of CProcess and fills it's fields
		 */
		CProcessor();

		/**
		 * Destorys the object
		 */
		~CProcessor();

		/**
		 * Getter of m_stBrand
		 * @returns The current value of m_stBrand
		 */
		std::string& brand();

		/**
		 * Getter of m_stArchitecture
		 * @returns The current value of m_stArchitecture
		 */
		std::string& architecture();

		/**
		 * Getter of m_stType
		 * @returns The current value of m_stType
		 */
		std::string& type();

		/**
		 * Getter of m_dwCore
		 * @returns The current value of m_dwCore
		 */
		DWORD& cores();

		/**
		 * Gets the processor brand and name
		 * @returns The processor brand and name
		 */
		static std::string getBrand();

		/**
		 * Gets the processor architecture as a WORD <br>
		 * https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
		 * @returns The processor architecture
		 */
		static WORD getArchitectureAsWord();

		/**
		 * Gets the processor architecture
		 * @returns The processor architecture
		 */
		static std::string getArchitecture();

		/**
		 * Gets the processor architecture as a WORD <br>
		 * https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/ns-sysinfoapi-system_info
		 * @returns The processor architecture
		 */
		static DWORD getTypeAsDword();

		/**
		 * Gets the processor architecture type
		 * @returns The processor architecture type
		 */
		static std::string getType();

		/**
		 * Gets the processor number of cores
		 * @returns The processor number of cores
		 */
		static DWORD getCores();

	private:

		/** Processor brand name */
		std::string m_stBrand;

		/** Processor Architecture as WORD */
		WORD m_wArchitecture;

		/** Processor Architecture as string */
		std::string m_stArchitecture;

		/** Processor type as DWORD */
		DWORD m_dwType;

		/** Processor type as string */
		std::string m_stType;

		/** Number of cores */
		DWORD m_dwCore;
	};
}

#endif
