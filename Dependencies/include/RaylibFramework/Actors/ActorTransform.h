#pragma once

#include <RaylibFramework/RaylibFramework.h>

/** @brief Callback invoked when the children list of an ActorTransform changes. */



/**
 * @brief Manages the 2D location, rotation, and scale of an Actor.
 *
 * Internally stores the transform as a 3D Matrix (via raymath) used in
 * a 2D context. Supports a parent-child hierarchy; when a parent transform
 * changes, its children are updated accordingly.
 *
 * Construction and destruction are private; instances are created and
 * owned exclusively by Actor via the friend declaration.
 *
 * Copy and move construction and assignment are deleted; an ActorTransform
 * must not be duplicated or transferred.
 */
class DLL ActorTransform
{
	/**
	 * @brief An empty token type used to restrict construction to trusted callers.
	 *
	 * Passed as the first argument to the public constructor in place of a private
	 * constructor. Since PrivateKey itself is private, only friends and members of
	 * this class can instantiate it, achieving the same effect.
	 */

public:

	/**
	 * @brief Constructs a default ActorTransform at the origin.
	 *
	 * Private; instances are created exclusively by Actor.
	 * Initialises location to (0, 0), rotation to 0, and scale to (1, 1).
	 */

	/** @brief Copy construction is disabled; an ActorTransform must not be duplicated. */

	/** @brief Move construction is disabled; an ActorTransform must not be transferred. */

public:

	/**
	 * @brief Returns the current world location.
	 * @return The translation component of the transform as a Vector2.
	 */

	/**
	 * @brief Returns the current rotation angle.
	 * @return The rotation in radians, extracted from the transform matrix.
	 */

	/**
	 * @brief Returns the current scale.
	 * @return The scale component of the transform as a Vector2.
	 */

	/**
	 * @brief Returns the world-space transform, composed with all parent transforms.
	 *
	 * Traverses the parent chain and multiplies each local transform together,
	 * returning the final matrix representing this transform in world space.
	 *
	 * @return The world-space transformation matrix.
	 */

	/**
	 * @brief Returns a reference to the local transformation matrix.
	 *
	 * The local matrix represents this transform relative to its parent.
	 * Modifying the returned reference directly bypasses the decompose/compose
	 * cycle of the individual setters.
	 *
	 * @return A reference to the local transformation matrix.
	 */

	/**
	 * @brief Returns the Actor that owns this transform.
	 * @return A pointer to the owning Actor.
	 */

	/**
	 * @brief Sets the parent of this transform.
	 *
	 * Attaches this transform as a child of @p newParent, removing it from
	 * its current parent if one exists. Passing nullptr detaches this transform
	 * from its current parent, making it a root transform.
	 *
	 * Any registered ChildListChange callbacks on the affected parents are
	 * invoked after the hierarchy is updated.
	 *
	 * @param newParent The transform to attach to, or nullptr to detach.
	 */

	/**
	 * @brief Returns the direct children of this transform.
	 * @return A copy of the list of child ActorTransform pointers.
	 */


public:

	/** @brief Copy assignment is disabled; an ActorTransform must not be duplicated. */


	/** @brief Move assignment is disabled; an ActorTransform must not be transferred. */


private:

	/** @brief The Actor that owns and is represented by this transform. */


	/** @brief The parent transform, or nullptr if this is a root transform. */


	/** @brief The direct children of this transform in the hierarchy. */


	/**
	 * @brief Callbacks invoked when the children list changes.
	 *
	 * Registered listeners are called whenever a child is added to or
	 * removed from this transform via SetParent().
	 */


	/** @brief A 3D transformation matrix used to encode a 2D transform (location, rotation, scale). */


private:

	/**
	 * @brief Flushes all pending parent/child relationship changes queued by SetParent().
	 *
	 * SetParent() defers modifications to the child list to avoid mutating it
	 * mid-iteration. This function executes each queued change in order and
	 * then clears the queue. Should be called once per frame, before any
	 * traversal of the transform hierarchy.
	 */


};