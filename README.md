   
                                              _                   _                    
                                        __ _ / | ___  _   _  ___ | |_   ___  _ __ ___  
                                       / _` || |/ __|| | | |/ __|| __| / _ \| '_ ` _ \ 
                                      | (_| || |\__ \| |_| |\__ \| |_ |  __/| | | | | |
                                       \__, ||_||___/ \__, ||___/ \__| \___||_| |_| |_|
                                          |_|         |___/                            

# q1System [![q1System](https://img.shields.io/badge/Cpp-System-blue?style=flat-square&logo=c%2B%2B&logoColor=White)](https://github.com/Qu1oX/q1System) [![q1System](https://img.shields.io/github/license/qu1ox/q1System?style=flat-square)](https://github.com/Qu1oX/q1System) [![q1System](https://img.shields.io/github/v/release/qu1ox/q1System?label=stable&style=flat-square)](https://github.com/Qu1oX/q1System) [![q1System](https://img.shields.io/github/v/release/qu1ox/q1System?include_prereleases&label=beta&style=flat-square)](https://github.com/Qu1oX/q1System)
> Simplified C++ System Library

## Features
### MemoryManager 
> Allows to read from and write into the memory of a process

#### How to read and write

      q1::CMemory acClient(L"ac_client.exe", L"ac_client.exe");
      
      uintptr_t localplayerPtr = acClient.readPointerFromModule(0x00109B74);
      int32_t healthValue = acClient.read<int32_t>(localplayerPtr + 0xF8);
      acClient.write<int32_t>(localplayerPtr + 0xF8, 999);