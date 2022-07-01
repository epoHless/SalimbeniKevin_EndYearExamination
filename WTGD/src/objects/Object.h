#ifndef OBJECT_H
#define OBJECT_H

#include <pch.h>

namespace WTGD
{
	class WTGD_API Object
	{
	public:
		/// <summary>
		/// Default Object Constructor
		/// </summary>
		/// <param name="name">This object name</param>
		/// <param name="is_active">Is the object enabled from the beginning?</param>
		Object(const std::string name, bool is_active = true);

		/// <summary>
		/// Enable this object
		/// </summary>
		void enable() { is_active = true; }
		/// <summary>
		/// Disable this object
		/// </summary>
		void disable() { is_active = false; }
		/// <summary>
		/// Get this Object name
		/// </summary>
		/// <returns></returns>
		std::string get_name()const { return name; }

	protected:
		std::string name;
		bool is_active;
	};
}

#endif OBJECT_H

