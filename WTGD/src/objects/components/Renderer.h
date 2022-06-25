#ifndef RENDERER_H
#define RENDERER_H

#ifdef DLL_EXPORT
#define RENDERER_API __declspec(dllexport)
#else
#define RENDERER_API __declspec(dllimport)
#endif 

#include "Component.h"
#include <SFML/Graphics.hpp>

namespace WTGD
{
	class RENDERER_API Renderer : public Component
	{
		friend class LoopManager;
	public:
		/// <summary>
		/// Defualt Renderer Constructor
		/// </summary>
		Renderer();
		explicit Renderer(std::string texture_path);
		~Renderer() override;
		/// <summary>
		/// Sets the object's texture
		/// </summary>
		/// <param name="texture_path"></param>
		void set_texture(std::string texture_path);

	private:
		sf::Texture* texture;

	};
}

#endif