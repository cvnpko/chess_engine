#ifndef ENGINE_ATTACK_FIELD_HPP
#define ENGINE_ATTACK_FIELD_HPP

#include "engine/figure.hpp"

namespace engine
{

    class AttackField
    {
        public:
        AttackField();
        AttackField(Figure firstFigure);
        void resetField();
        void upCount(FigureColor color);
        int getCount(FigureColor color);
        void addMat(Figure figure);
        int getMat(FigureColor color);
        void lowerCount(FigureColor color);

        bool getPinned() const;
        void setPinned();

        private:
        int whiteMatVal; //could be used for eval algorithm for trading pieces
        int whiteCount;

        int blackMatVal;
        int blackCount;

        bool pinned;

    };

}

#endif