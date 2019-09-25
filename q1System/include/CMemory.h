/*
 * File: CMemory.h
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

#ifndef __C_MEMORY_H__
#define __C_MEMORY_H__

#include <windows.h>

#include "CProcess.h"
#include "CModule.h"

namespace q1
{
	/**
	 * Handles memory information
	 *
	 * @Author Qu1oX
	 * @since 1.0
	 * @version 1.0
	 */
	class CMemory
	{
	public:
		/**
		 * Default constructor
		 */
		CMemory() = default;

		/**
		 * Creates an instance of CMemory
		 * 
		 * @param wstrProcessName Process to read from or write into
		 * @param szModuleName Module to read from or write into
		 */
		CMemory(const std::wstring& wstrProcessName, const wchar_t* szModuleName);

		/**
		 * Destroys the instance <br>
		 * Closes the HANDLE
		 */
		~CMemory();

		/**
		 * Getter of the CProcess object
		 * @returns Ref to the CProcess object
		 */
		CProcess& process();

		/**
		 * Getter of the CModule object
		 * @returns Ref to the CModule object
		 */
		CModule& module();

		/**
		 * Read the the value of a pointer based on the address of the module
		 * @returns The pointer
		 */
		uintptr_t readPointerFromModule(uintptr_t& uintAddr);

		/**
		 * Reads process memory
		 * @returns The value
		 */
		template<class T>
		T read(uintptr_t* uintAddr)
		{
			T value;
			ReadProcessMemory(m_hProcess,reinterpret_cast<LPCVOID>(uintAddr),&value,sizeof(T),nullptr);
			return value;
		}

		/**
		 * Reads process memory
		 * @returns The value
		 */
		template<class T>
		T read(uintptr_t uintAddr)
		{
			T value;
			ReadProcessMemory(m_hProcess, reinterpret_cast<LPCVOID>(uintAddr), &value, sizeof(T), nullptr);
			return value;
		}

		/**
		 * Writes process memory
		 */
		template<class T>
		void write(uintptr_t* uintAddr, T* value)
		{
			WriteProcessMemory(m_hProcess, reinterpret_cast<LPCVOID>(uintAddr), value, sizeof(T), nullptr);
		}

		/**
		 * Writes process memory
		 */
		template<class T>
		void write(uintptr_t uintAddr, T* value)
		{
			WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(uintAddr), &value, sizeof(T), nullptr);
		}

		/**
		 * Writes process memory
		 */
		template<class T>
		void write(uintptr_t uintAddr, T value)
		{
			WriteProcessMemory(m_hProcess, reinterpret_cast<LPVOID>(uintAddr), &value, sizeof(T), nullptr);
		}

	private:

		/** Process handle */
		HANDLE		m_hProcess;

		/** CProcess object */
		CProcess	m_Process;

		/** CModule object */
		CModule		m_Module;

	};
}

#endif
