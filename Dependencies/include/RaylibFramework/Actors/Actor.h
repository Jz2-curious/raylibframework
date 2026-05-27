#pragma once

#include <memory>
#include <vector>
#include <RaylibFramework/RaylibFramework.h>
#include <RaylibFramework/Actors/ActorComponent.h>

using std::shared_ptr;
using std::unique_ptr;
using std::vector;

class ActorTransform;

/**
 * @brief Represents an object in the world, composed of modular ActorComponents.
 *
 * An Actor owns its transform and a collection of components. Components are
 * added and removed at runtime, and can be queried by type.
 */
class DLL Actor
{
	friend class GameInstance;

public:
	/**
	 * @brief Constructs an Actor with a default transform at the origin.
	 *
	 * Creates and owns an ActorTransform initialised to location (0, 0),
	 * rotation 0, and scale (1, 1).
	 */


public:
	/**
	 * @brief Returns a non-owning reference to this Actor's transform.
	 * @return A weak_ptr to the ActorTransform; lock() before use.
	 */


	/**
	 * @brief Constructs and attaches a new component to this Actor.
	 *
	 * The Actor takes sole ownership of the created component.
	 *
	 * @tparam COMPONENT The component type to create. Must derive from ActorComponent.
	 * @tparam ARGS      Constructor argument types, deduced automatically.
	 * @param  args      Arguments forwarded to the COMPONENT constructor.
	 * @return           A non-owning pointer to the newly added component.
	 */


	/**
	 * @brief Detaches and destroys a component belonging to this Actor.
	 * @param toRemove A non-owning pointer identifying the component to remove.
	 *                 No-ops if the pointer is not found in the component list.
	 */


	/**
	 * @brief Returns the first component of type T attached to this Actor.
	 * @tparam T The component type to search for. Must derive from ActorComponent.
	 * @return   A non-owning pointer to the first matching component, or nullptr if none found.
	 */


	/**
	 * @brief Returns all components of type T attached to this Actor.
	 * @tparam T The component type to search for. Must derive from ActorComponent.
	 * @return   A vector of non-owning pointers to all matching components; empty if none found.
	 */


private:
	/** @brief The transform representing this Actor's position, rotation, and scale in the world. */


	/** @brief The collection of components owned by this Actor. */


private:
	/**
	 * @brief Advances all components owned by this Actor by one frame.
	 *
	 * Called each frame by GameInstance. Iterates over all attached components
	 * and calls Tick() on each.
	 *
	 * @param dt Elapsed time in seconds since the last frame.
	 */


	/**
	 * @brief Renders all components owned by this Actor.
	 *
	 * Called each frame by GameInstance, after all Tick() calls have completed.
	 * Iterates over all attached components and calls Render() on each.
	 */


};

#include "Actor.inl"