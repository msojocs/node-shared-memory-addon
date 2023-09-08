#include "../SharedMemory.h"
#include <napi.h>
#include <iostream>
#include <map>
#include <windows.h>
#include <string.h>

using StorageData = std::map<std::string, MemoryNode>;
// StorageData memoryData;
std::string STORAGE_KEY = "wechat-storage";


Napi::Value SetMemory(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    // printf("SetMemory\n");

    if (info.Length() < 2)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString() || !info[1].IsNumber())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }

    Napi::String arg0 = info[0].As<Napi::String>().ToString();
    std::string k = arg0.Utf8Value();
    double size = info[1].As<Napi::Number>().DoubleValue();
    int mapSize = size + sizeof(long);
    auto fmap = CreateFileMapping(
        INVALID_HANDLE_VALUE, // 使用无效的句柄值，表示创建一个新的文件映射对象
        NULL,                 // 安全性属性，默认为 NULL
        PAGE_READWRITE,       // 共享内存可读可写
        0,                    // 高位文件大小
        mapSize,  // 低位文件大小，这里表示共享内存的大小为一个整数
        k.data());  // 共享内存对象的名称
    if (!fmap)
    {
        // printf("CreateFileMapping failed\n");
        return Napi::Number::New(info.Env(), 1);
    }
    else
    {
        auto buf = (LPTSTR)MapViewOfFile(fmap, FILE_MAP_ALL_ACCESS, 0, 0, mapSize);
        if (!buf)
        {
            CloseHandle(fmap); // fmap是成功的，要关闭
            return Napi::Number::New(info.Env(), 2);
        }
        *(long*)buf = size;
    }

    return Napi::Object::New(env);
}

Napi::Value GetMemory(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::String arg0 = info[0].As<Napi::String>().ToString();
    std::string k = arg0.Utf8Value();

    auto fmap = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, k.data());
    if (!fmap)
    {
        // printf("CreateFileMapping failed\n");
        return Napi::Number::New(info.Env(), 1);
    }
    else
    {
        //MemoryNode node = target->second;
        // 取得大小
        auto buf = (LPTSTR)MapViewOfFile(fmap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(long));
        if (!buf)
        {
            CloseHandle(fmap); // fmap是成功的，要关闭
            return Napi::Number::New(info.Env(), 2);
        }
        long size = *(long*)buf;
        UnmapViewOfFile(buf);

        buf = (LPTSTR)MapViewOfFile(fmap, FILE_MAP_ALL_ACCESS, 0, 0, sizeof(long) + size);
        if (!buf)
        {
            CloseHandle(fmap); // fmap是成功的，要关闭
            return Napi::Number::New(info.Env(), 2);
        }

        //// 创建一个新的ArrayBuffer，并将数据复制到其中
        Napi::ArrayBuffer arrayBuffer = Napi::ArrayBuffer::New(env, buf + sizeof(long), size);

        // 将ArrayBuffer封装到一个Napi::Value对象中，并返回给JavaScript
        return arrayBuffer;
    }

    // return memoryData[k];
}
Napi::Value RemoveMemory(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    if (info.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return env.Null();
    }

    if (!info[0].IsString())
    {
        Napi::TypeError::New(env, "Wrong arguments").ThrowAsJavaScriptException();
        return env.Null();
    }
    Napi::String arg0 = info[0].As<Napi::String>().ToString();
    std::string k = arg0.Utf8Value();

    //UnmapViewOfFile(target->second.map);
    //CloseHandle(target->second.buf);
    //(*s).erase(target);
    return env.Undefined();
}

Napi::Value RemoveAll(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    //if (storage.buf == nullptr)
    //{
    //    GetStorage(env);
    //}
    //StorageData *s = *(StorageData **)storage.buf;
    //for (auto i = s->begin(); i != s->end(); i++)
    //{
    //    UnmapViewOfFile(i->second.map);
    //    CloseHandle(i->second.buf);
    //    // memoryData.erase(i);
    //}
    //CloseStorage();
    return env.Undefined();
}
