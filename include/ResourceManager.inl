#include "Console.hpp"

template <typename Resource, std::string directory>
ResourceManager<Resource, directory>::~ResourceManager()
{
    for(typename map::iterator ite = begin(); ite != end(); ++ite)
        log() << "Removed " << ite->first << std::endl;
}

template <typename Resource, std::string directory>
bool ResourceManager<Resource, directory>::has(const std::string& name)
{
    return map::find(name) != map::end();
}

template <typename Resource, std::string directory>
Resource& ResourceManager<Resource, directory>::get(const std::string& name)
{
    return (*this)[name];
}

template <typename Resource, std::string directory>
void ResourceManager<Resource, directory>::add(const std::string& name, const Resource& resource)
{
    log() << (has(name) ? "Replaced " : "Added ") << name << std::endl;
    get(name) = resource;
}

template <typename Resource, std::string directory>
bool ResourceManager<Resource, directory>::load(const std::string& name, const std::string& filename)
{
    Resource resource;
    if(!resource.loadFromFile(std::string("data/") + directory + "/" + (filename != std::string() ? filename : name)))
    {
        err() << "Can not load " << name << std::endl;
        return false;
    }
    else
    {
        add(name, resource);
        return true;
    }
}
