#pragma once

#include <cstdint>

#include "shape.h"
#include "../util.h"

namespace geometrize
{

/**
 * @brief The RotatedEllipse class represents a rotated ellipse.
 * @author Sam Twidale (http://samcodes.co.uk/)
 */
class RotatedEllipse : public Shape
{
public:
    /**
     * @brief RotatedEllipse Creates a new rotated ellipse.
     * @param xBound xBound	The x-bound of the whole canvas.
     * @param yBound yBound	The y-bound of the whole canvas.
     */
    RotatedEllipse(const std::uint32_t xBound, const std::uint32_t yBound) : m_xBound(xBound), m_yBound(yBound)
    {
        // TODO
    }

    virtual Shape* clone() const
    {
        return new RotatedEllipse(m_xBound, m_yBound); // TODO
    }

    virtual std::vector<Scanline> rasterize() const override
    {
        std::vector<Scanline> lines;
        return lines; // TODO
    }

    virtual void mutate() override
    {
        // TODO
    }

    virtual shapes::ShapeTypes getType() const override
    {
        return shapes::ShapeTypes::ROTATED_ELLIPSE;
    }

    virtual std::vector<std::int32_t> getShapeData() const override
    {
        return {};
    }

private:
    const std::uint32_t m_xBound; ///< The x-bound of the whole canvas.
    const std::uint32_t m_yBound; ///< The y-bound of the whole canvas.
};

}
