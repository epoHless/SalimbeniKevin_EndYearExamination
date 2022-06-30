#ifndef RENDERER_H
#define RENDERER_H

#include <pch.h>
#include <objects/components/Component.h>

namespace WTGD
{
	class WTGD_API Renderer : public Component
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