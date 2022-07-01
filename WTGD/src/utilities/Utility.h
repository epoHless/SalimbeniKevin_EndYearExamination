#ifndef UTILITY_H
#define UTILITY_H

#include <pch.h>
#include <objects/gameobjects/Gameobject.h>

namespace WTGD
{
	struct WTGD_API Utility
	{
	public:

		/// <summary>
		/// Returns a vector with pointers to GameObject (s) with the given tag
		/// </summary>
		[[nodiscard]] static std::vector<GameObject*> get_gameobjects_by_tag(std::vector<GameObject*> objects, std::string tag)
		{
			std::vector<GameObject*> output;
			if (objects.size() == 0) return output;

			for (GameObject* obj : objects)
			{
				if (obj->get_tag() == tag)
				{
					output.push_back(obj);
				}
			}
			return output;
		}

		/// <summary>
		/// Returns a vector with pointers to GameObject (s) with the given class (derived included as of for now)
		/// </summary>
		template<class T, class = GameObject>
		static std::vector<T*> get_gameobjects_by_class(std::vector<GameObject*> objects)
		{
			std::vector<T*> output;
			if (objects.size() == 0) return output;

			for (GameObject* obj : objects)
			{
				const auto val = dynamic_cast<T*>(obj);

				if (val)
				{
					output.push_back(val);
				}
			}

			return output;
		}
	};
}


#endif