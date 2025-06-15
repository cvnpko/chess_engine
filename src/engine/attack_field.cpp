#include "engine/attack_field.hpp"

namespace engine
{
        AttackField::AttackField()
        {
            whiteCount = 0;
            blackCount = 0;
            whiteMatVal = 0;
            blackMatVal = 0;
            pinned = false;
        }
        AttackField::AttackField(Figure firstFigure)
        {
            whiteCount = 0;
            blackCount = 0;
            whiteMatVal = 0;
            blackMatVal = 0;
            pinned = false;
            upCount(firstFigure.getColor());
            addMat(firstFigure);
        }
        void AttackField::upCount(FigureColor color)
        {
            if(color == FigureColor::WHITE)
                whiteCount++;
            else blackCount++;
        }

        void AttackField::lowerCount(FigureColor color)
        {
            if(color == FigureColor::WHITE)
                whiteCount--;
            else blackCount--;
        }

        int AttackField::getCount(FigureColor color)
        {
            if(color == FigureColor::WHITE)
                return whiteCount;
            else return blackCount;
        }
        void AttackField::addMat(Figure figure)
        {
            if(figure.getColor() == FigureColor::WHITE)
                whiteMatVal += figure.getFigureValue();
            else
                blackMatVal += figure.getFigureValue();
        }
        int AttackField::getMat(FigureColor color)
        {
            if(color == FigureColor::WHITE)
                return whiteMatVal;
            else return blackMatVal;
        }
        void AttackField::resetField()
        {
            whiteCount = 0;
            blackCount = 0;
            whiteMatVal = 0;
            blackMatVal = 0;
            pinned = false;
        }

        bool AttackField::getPinned() const
        {
            return pinned;
        }
        void AttackField::setPinned(bool pin)
        {
            pinned= pin;
        }

}