#include <napi.h>
#include <windows.h>
#include <string.h>

#include "../SharedMemory.h"

Napi::FunctionReference SharedMemory::constructor;

Napi::Object SharedMemory::Init(Napi::Env env, Napi::Object exports)
{
    Napi::HandleScope scope(env);


    exports.Set(Napi::String::New(env, "setMemory"), Napi::Function::New(env, SetMemory));
    exports.Set(Napi::String::New(env, "getMemory"), Napi::Function::New(env, GetMemory));
    exports.Set(Napi::String::New(env, "removeMemory"), Napi::Function::New(env, RemoveMemory));
    exports.Set(Napi::String::New(env, "removeAll"), Napi::Function::New(env, RemoveAll));

    return exports;
}
