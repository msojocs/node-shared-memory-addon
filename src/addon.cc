#include <napi.h>
#include "SharedMemory.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "setMemory"), Napi::Function::New(env, SetMemory));
    exports.Set(Napi::String::New(env, "getMemory"), Napi::Function::New(env, GetMemory));
    exports.Set(Napi::String::New(env, "removeMemory"), Napi::Function::New(env, RemoveMemory));
    exports.Set(Napi::String::New(env, "removeAll"), Napi::Function::New(env, RemoveAll));

    return exports;
}

NODE_API_MODULE(SharedMemory, InitAll)