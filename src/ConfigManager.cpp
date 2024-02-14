#include "ConfigManager.h"
#include <fstream>

ConfigManager::ConfigManager()
{
}

ConfigManager::~ConfigManager()
{
}

template <typename T>
T ConfigManager::LoadConfig(const std::string& path)
{
    std::ifstream ifs(path.c_str());
    Json::Value obj;
    ifs.open(path);

    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs;
    if(!parseFromStream(builder, ifs, &obj, &errs))
    {
        return T();
    }

    T config;
    config = obj;
    return config;
}

template <typename T>
void ConfigManager::SaveConfig(const std::string &path, const T &object)
{
    Json::Value obj;
    obj = object;
    std::ofstream ofs(path);
    Json::StyledWriter writer;
    ofs << writer.write(obj);
}