#include "Log.hpp"

template <typename Resource>
ResourceManager<Resource>::ResourceManager(const std::string& directory)
 : m_directory(directory)
{}

template <typename Resource>
ResourceManager<Resource>::~ResourceManager()
{
    for(typename map::iterator ite = map::begin(); ite != map::end(); ++ite)
        log() << "Removed " << ite->first << std::endl;
}

template <typename Resource>
bool ResourceManager<Resource>::has(const std::string& name)
{
    return map::find(name) != map::end();
}

template <typename Resource>
Resource& ResourceManager<Resource>::get(const std::string& name)
{
    return (*this)[name];
}

template <typename Resource>
void ResourceManager<Resource>::add(const std::string& name, const Resource& resource)
{
    log() << (has(name) ? "Replaced " : "Added ") << name << std::endl;
    get(name) = resource;
}

template <typename Resource>
bool ResourceManager<Resource>::load(const std::string& name, const std::string& filename)
{
    Resource resource;
    if(!resource.loadFromFile(std::string("data/") + m_directory + "/" + (filename != std::string() ? filename : name)))
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
