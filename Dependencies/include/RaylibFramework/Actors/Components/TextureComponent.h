#pragma once

#include <memory>
#include <string>
#include <raylib/raylib.h>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/Actors/ActorComponent.h>
#include <RaylibFramework/Maths/Vec2.h>

using std::shared_ptr;
using std::string;

class TextureResource;

/**
 * @brief An ActorComponent that renders a texture at the owning Actor's transform.
 *
 * TextureComponent loads a texture from the ResourceManager on creation and
 * draws a configurable UV region of it each frame, tinted and offset by a
 * specified origin. Attach to an Actor via Actor::AddComponent<TextureComponent>().
 */
class DLL TextureComponent : public ActorComponent
{
public:
	/**
	 * @brief Constructs a TextureComponent with the given texture path.
	 *
	 * The texture is not loaded until OnCreated() is called by the Actor.
	 *
	 * @param path The resource identifier used to retrieve the texture from ResourceManager.
	 */

public:
	/**
	 * @brief Sets the origin point used as the pivot when rendering the texture.
	 *
	 * The origin is in texture-local space; { 0, 0 } is the top-left corner.
	 *
	 * @param newOrigin The new origin point in pixels.
	 */

	/**
	 * @brief Sets the tint colour applied to the texture when rendering.
	 *
	 * Defaults to WHITE, which renders the texture unmodified.
	 *
	 * @param newTint The new tint colour.
	 */

	/**
	 * @brief Sets the UV rectangle defining which region of the texture to draw.
	 *
	 * Useful for rendering a sub-region or a sprite from a texture atlas.
	 *
	 * @param newUVRect The source rectangle in texture-space pixels.
	 */

protected:
	/**
	 * @brief Resolves the texture from ResourceManager and initialises the UV rect.
	 *
	 * Called once by the owning Actor when this component is first attached.
	 */

	/**
	 * @brief Draws the texture region at the owning Actor's world transform.
	 *
	 * Called each frame by the owning Actor within an active
	 * BeginFrame()/EndFrame() block.
	 */

private:
	/** @brief The loaded texture resource used for rendering. */


	/** @brief The resource identifier used to retrieve the texture on creation. */


	/** @brief The region of the texture to draw, in texture-space pixels. */


	/** @brief The pivot point used when positioning and rotating the texture. */


	/** @brief The tint colour blended with the texture during rendering. */


};