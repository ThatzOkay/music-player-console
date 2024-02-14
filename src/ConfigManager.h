
#ifdef __VITA__
#include <jsoncpp/json/json.h>
#else
#include <json/json.h>
#endif

class ConfigManager
{

public:
    ConfigManager();
    ~ConfigManager();

    template <typename T>
    T LoadConfig(const std::string& path);
    template <typename T>
    void SaveConfig(const std::string& path, const T& object);
};