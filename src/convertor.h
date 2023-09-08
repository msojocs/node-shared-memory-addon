#ifndef __CONVERTOR_H__
#define __CONVERTOR_H__

#include <string>
#include <map>
#include "./SharedMemory.h"

void map2string(std::map<std::string, MemoryNode> &, std::string &);
void string2map(std::string &, std::map<std::string, MemoryNode> &);

#endif