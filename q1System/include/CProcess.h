/*
 * File: CProcess.h
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

#ifndef __C_PROCESS_H__
#define __C_PROCESS_H__

#include <string>
#include <windows.h>
#include <tlhelp32.h>

namespace q1
{
	/**
	 * Handles the everything related to a Process <br>
	 * 
	 * @Author Qu1oX
	 * @since 1.0
	 * @version 1.0
	 */
	class CProcess
	{
	public:
		/**
		 * Creates an instance of CProcess <br>
		 * And searches it's id.
		 * @param processName WideString with a process in it. <br> 
		 *		Should be in the format "process.exe"
		 */
		CProcess(const std::wstring& processName);

		/**
		 * Getter of the process name
		 * @returns The current process name as a wide string
		 */
		std::wstring&	processName();

		/**
		 * Getter of the process id
		 * @returns The current process id of the process name
		 */
		DWORD&			processId();

		/**
		 * Checks if the process was found
		 * @returns true if the process id is not 0 otherwise false
		 */
		bool			hasFound();

		/**
		 * Searches for the process id of the process given to the method. 
		 * @param processName WideString with a process in it. <br> 
		 *		Should be in the format "process.exe"
		 *	@returns The process id if process was found otherwise 0
		 */
		static DWORD findProcessId(const std::wstring& processName);

	private:
		/** Process name */
		std::wstring	m_ProcessName;
		/** Process id */
		DWORD			m_dwProcessId;
	};
}

#endif