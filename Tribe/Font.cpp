#include "TribePCH.h"
#include <SDL2/SDL_ttf.h>
#include "Font.h"

TTF_Font* Font::GetFont() const {
	return m_pFont;
}

Font::Font(const std::string& fullPath, unsigned int size) 
	: m_pFont(nullptr)
	, m_Size(size)
{
	m_pFont = TTF_OpenFont(fullPath.c_str(), size);
	if (!m_pFont) 
		throw std::runtime_error(std::string("Failed to load font: ") + SDL_GetError());
}

Font::~Font()
{
	TTF_CloseFont(m_pFont);
	
}
