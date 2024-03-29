/*
 * File: CModule.h
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

#ifndef __C_MODULE_H__
#define __C_MODULE_H__

#include <windows.h>
#include <cstdint>
#include <tlhelp32.h>

namespace q1
{
	/**
	 * Handles the modules inside a CProcess
	 * 
	 * @Author Qu1oX
	 * @since 1.0
	 * @version 1.0
	 */
	class CModule
	{
	public:
		/**
		 * Default constructor
		 */
		CModule() = default;

		/**
		 * Creates an instance of CModule
		 * 
		 * @param dwProcessId Process id to search in
		 * @param szModuleName Module to search
		 */
		CModule(DWORD dwProcessId, const wchar_t* szModuleName);

		/**
		 * Getter of m_dwProcessId
		 * @returns The current value of m_dwProcessId
		 */
		DWORD processId();

		/**
		 * Getter of m_szModuleName
		 * @returns The current value of m_szModuleName
		 */
		const wchar_t* moduleName();

		/**
		 * Getter of m_uintModulePointer
		 * @returns The current value of m_uintModulePointer
		 */
		uintptr_t modulePointer();

		/**
		 * Checks if the module was found or not
		 * @returns true if m_uintModulePointer is not 0 otherwise false
		 */
		bool hasFound();

		/**
		 * Find the pointer to a module <br>
		 * Should be in the format: "module.dll"
		 * 
		 * @param dwProcessId Process id to search in
		 * @param szModuleName Module to search
		 * 
		 * @returns The pointer to the module as uintptr_t
		 */
		static uintptr_t findModulePtr(DWORD dwProcessId, const wchar_t* szModuleName);

	private:

		/** process id */
		DWORD		m_dwProcessId;

		/** module name */
		const wchar_t* m_szModuleName;

		/** module pointer */
		uintptr_t	m_uintModulePointer;
	};
}

#endif