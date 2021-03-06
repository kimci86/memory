#ifndef RESOURCES_RESOURCEMANAGER_HPP
#define RESOURCES_RESOURCEMANAGER_HPP

#include <map>
#include <string>

namespace Resources
{

template <typename Resource>
class ResourceManager : private std::map<std::string, Resource>
{
    public:
        ResourceManager(const std::string& directory);
        ~ResourceManager();

        bool has(const std::string& name);
        Resource& get(const std::string& name);

        void add(const std::string& name, const Resource& resource);
        bool load(const std::string& name, const std::string& filename = std::string());

    private:
        typedef std::map<std::string, Resource> map;

        std::string m_directory;
};

} // namespace Resources

#include <Resources/ResourceManager.inl>

#endif // RESOURCES_RESOURCEMANAGER_HPP
