#include "../convertor.h"
#include <sstream>

void map2string(std::map<std::string, MemoryNode> & src, std::string & ret)
{
    std::stringstream ss;
    for (auto i = src.begin(); i != src.end(); i++)
    {
        MemoryNode node = i->second;
        ss << i->first << "," << node.length << std::endl;
    }
    ret = ss.str();
    
}
void string2map(std::string & src, std::map<std::string, MemoryNode> & ret)
{
    int start = 0;
    std::string key;
    for (int i = 0; i < src.length(); i++)
    {
        if (src[i] == ',')
        {
            std::string str(&src[start], i - start);
            key = str;
            start = i;
        }
        else if (src[i] == '\n')
        {
            std::string str(&src[start], i - start);
            long size;
            sscanf(str.data(), "%ld", &size);
            MemoryNode node;
            node.length = size;
            ret.emplace(key, node);
        }
    }
}