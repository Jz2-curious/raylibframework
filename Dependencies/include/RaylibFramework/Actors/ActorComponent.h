#pragma once

#include <RaylibFramework/RaylibFramework.h>

class Actor;

/**
 * @brief A modular piece of behaviour or data that can be attached to an Actor.
 *
 * ActorComponent is the base class for all components. Components are owned
 * exclusively by an Actor and driven by it each frame. Override the virtual
 * event methods to implement per-component logic.
 */
class DLL ActorComponent
{
	friend Actor;

public:
	/**
	 * @brief Constructs an ActorComponent with no owning Actor.
	 *
	 * The owner is assigned by the Actor when the component is attached
	 * via Actor::AddComponent().
	 */




protected:
	/**
	 * @brief Returns the Actor that owns this component.
	 * @return A non-owning pointer to the owning Actor.
	 */


	/**
	 * @brief Called once when the owning Actor is first added to the world.
	 *
	 * Override to perform any one-time initialisation that requires the
	 * Actor to be fully constructed and present in the scene.
	 */


	/**
	 * @brief Called once per frame to update this component's logic.
	 * @param dt Elapsed time in seconds since the last frame.
	 */


	/**
	 * @brief Called once per frame to submit this component's visuals for rendering.
	 *
	 * Invoked by the owning Actor after all Tick() calls have completed,
	 * within an active BeginFrame()/EndFrame() block.
	 */


	/**
	 * @brief Called once when the owning Actor is removed from the world.
	 *
	 * Override to perform any cleanup before the component is destroyed.
	 */


private:
	/** @brief The Actor that owns and drives this component. */

};