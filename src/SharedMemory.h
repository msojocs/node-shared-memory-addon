#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <napi.h>
#include <windows.h>

struct MemoryNode
{
    long length = 0;
    HANDLE map = nullptr;
    LPTSTR buf = nullptr;
};

Napi::Value SetMemory(const Napi::CallbackInfo& info);
Napi::Value GetMemory(const Napi::CallbackInfo& info);
Napi::Value RemoveMemory(const Napi::CallbackInfo& info);
Napi::Value RemoveAll(const Napi::CallbackInfo& info);
#endif