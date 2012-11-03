#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <map>
#include <string>

template <typename Resource, std::string directory>
class ResourceManager : private std::map<std::string, Resource>
{
    public:
        ~ResourceManager();

        bool has(const std::string& name);
        Resource& get(const std::string& name);

        void add(const std::string& name, const Resource& resource);
        bool load(const std::string& name, const std::string& filename = std::string());

    private:
        typedef std::map<std::string, Resource> map;
};

#include <ResourceManager.inl>

#endif // RESOURCEMANAGER_HPP
