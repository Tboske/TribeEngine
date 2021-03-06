#pragma once
struct SDL_Texture;

/**
	* Simple RAII wrapper for an SDL_Texture
	*/
class Texture2D
{
public:
	explicit Texture2D(SDL_Texture* texture);
	~Texture2D();
	Texture2D(const Texture2D&) = delete;
	Texture2D(Texture2D&&) = delete;
	Texture2D& operator= (const Texture2D&) = delete;
	Texture2D& operator= (const Texture2D&&) = delete;

	// normal draw calls
	void Draw(float x, float y) const;
	void Draw(float x, float y, float width, float height) const;
	void Draw(const glm::vec3& pos) const;
	// source rect draw calls
	void Draw(const glm::vec3& pos, const SDL_Rect& srcRect, float scale);
	//background draw calls
	void DrawFillScreen() const;

private:
	SDL_Texture* m_pTexture;
};

