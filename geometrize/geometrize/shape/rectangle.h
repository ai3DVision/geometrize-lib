#pragma once

#include <cstdint>
#include <memory>

#include "shape.h"

namespace geometrize
{

/**
 * @brief The Rectangle class represents a rectangle.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class Rectangle : public Shape
{
public:
    /**
     * @brief Rectangle Creates a new rectangle.
     * @param xBound xBound	The x-bound of the whole canvas.
     * @param yBound yBound	The y-bound of the whole canvas.
     */
    Rectangle(const std::uint32_t xBound, const std::uint32_t yBound);

    virtual std::shared_ptr<geometrize::Shape> clone() const;
    virtual std::vector<Scanline> rasterize() const override;
    virtual void mutate() override;
    virtual geometrize::shapes::ShapeTypes getType() const override;
    virtual std::vector<std::int32_t> getShapeData() const override;

private:
    const std::uint32_t m_xBound; ///< The x-bound of the whole canvas.
    const std::uint32_t m_yBound; ///< The y-bound of the whole canvas.

    std::uint32_t m_x1; ///< Left coordinate.
    std::uint32_t m_y1; ///< Top coordinate.
    std::uint32_t m_x2; ///< Right coordinate.
    std::uint32_t m_y2; ///< Bottom coordinate.
};

}