#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "bitmap/bitmap.h"
#include "shape/shape.h"
#include "shape/shapefactory.h"
#include "shape/shapetypes.h"
#include "scanline.h"

namespace geometrize
{

/**
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class State
{
public:
    /**
     * @brief Creates a new state.
     * @param shapeTypes The types of geometric primitive to select.
     * @param alpha The color alpha of the geometric shape.
     * @param width The width of the bitmap.
     * @param height The height of the bitmap.
     */
    State(const shapes::ShapeTypes shapeTypes, const std::uint32_t alpha, const std::uint32_t width, const std::uint32_t height);

    ~State() = default;
    geometrize::State(const geometrize::State& other);
    geometrize::State& operator=(const geometrize::State& other);

    /**
     * @brief Calculates a measure of the improvement drawing the primitive to the current bitmap will have.
     * The lower the energy, the better. The score is cached, set it to < 0 to recalculate it.
     * @return The energy measure.
     */
    float calculateEnergy(const geometrize::Bitmap& target, const geometrize::Bitmap& current, geometrize::Bitmap& buffer);

    /**
     * @brief mutate Modifies the current state in a random fashion.
     * @return The old state - in case we want to go back to the old state.
     */
    geometrize::State mutate();

    float m_score; ///< The score of the state, a measure of the improvement applying the state to the current bitmap will have.
    std::uint32_t m_alpha; ///< The alpha of the shape.
    std::shared_ptr<geometrize::Shape> m_shape; ///< The geometric primitive owned by the state. // TODO watch memory leaks!!!!!!!!!!!!!!!!!!!!!!!!!!
};

}