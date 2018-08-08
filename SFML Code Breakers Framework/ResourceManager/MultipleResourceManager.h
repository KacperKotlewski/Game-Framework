#pragma once

#include <memory>
#include <unordered_map>
#include <string>


template<typename Resource>
class MultipleResourceManager
{
	using conString = const std::string&;
public:
	MultipleResourceManager(conString folder, conString extension)
	:	m_folder("Resource/"+folder+"/")
	,	m_extension("."+extension)
	{

	}

	static std::shared_ptr<Resource> Use(const std::string& resourceName)
	{
		conString resourcePathAndName = m_folder + resourceName + m_extension;
		const auto i = resourcePtrs.find(resourcePathAndName);
		if (i != resourcePtrs.end())
		{
			return i->second;
		}
		else
		{
			auto ptrResource = std::make_shared<Resource>();
			ptrResource->loadFromFile(resourcePathAndName);
			resourcePtrs.insert({ resourcePathAndName, ptrResource });
			return ptrResource;
		}
	}
	static void ClearMemoryFromNotUsableSource()
	{
		for (auto i = resourcePtrs.begin(); i != resourcePtrs.end(); )
		{
			if (i->second.unique())
			{
				i = resourcePtrs.erase(i);
			}
			else
			{
				++i;
			}
		}
	}

private:
	static std::unordered_map<std::string, std::shared_ptr<Resource>> resourcePtrs;

	std::string m_folder;
	std::string m_extension;
};

template<typename Resource>
std::unordered_map<std::string, std::shared_ptr<Resource>> MultipleResourceManager::resourcePtrs;

