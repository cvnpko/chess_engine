#include "engine/board.hpp"
#include <iostream>
#define fi first
#define se second
namespace engine
{
    Board::Board() : isSelected(false), boardSide(BoardSide::WHITE),
                     currentTurn(FigureColor::WHITE)
    {
        boardGrid[0][0] = Figure(FigureType::ROOK, FigureColor::BLACK);
        boardGrid[0][7] = Figure(FigureType::ROOK, FigureColor::BLACK);
        boardGrid[7][0] = Figure(FigureType::ROOK, FigureColor::WHITE);
        boardGrid[7][7] = Figure(FigureType::ROOK, FigureColor::WHITE);
        boardGrid[0][1] = Figure(FigureType::KNIGHT, FigureColor::BLACK);
        boardGrid[0][6] = Figure(FigureType::KNIGHT, FigureColor::BLACK);
        boardGrid[7][1] = Figure(FigureType::KNIGHT, FigureColor::WHITE);
        boardGrid[7][6] = Figure(FigureType::KNIGHT, FigureColor::WHITE);
        boardGrid[0][2] = Figure(FigureType::BISHOP, FigureColor::BLACK);
        boardGrid[0][5] = Figure(FigureType::BISHOP, FigureColor::BLACK);
        boardGrid[7][2] = Figure(FigureType::BISHOP, FigureColor::WHITE);
        boardGrid[7][5] = Figure(FigureType::BISHOP, FigureColor::WHITE);
        boardGrid[0][4] = Figure(FigureType::KING, FigureColor::BLACK);
        boardGrid[0][3] = Figure(FigureType::QUEEN, FigureColor::BLACK);
        boardGrid[7][4] = Figure(FigureType::KING, FigureColor::WHITE);
        boardGrid[7][3] = Figure(FigureType::QUEEN, FigureColor::WHITE);
        for (int i = 0; i < 8; i++)
        {
            boardGrid[1][i] = Figure(FigureType::PAWN, FigureColor::BLACK);
            boardGrid[6][i] = Figure(FigureType::PAWN, FigureColor::WHITE);
        }
        for (int i = 2; i < 6; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                boardGrid[i][j] = Figure();
            }
        }
        createAttackBoard();
        updateAttackBoard();
    }
    BoardSide Board::getBoardSide() const
    {
        return boardSide;
    }
    FigureColor Board::getCurrentTurn() const
    {
        return currentTurn;
    }
    bool Board::getIsSelected() const
    {
        return isSelected;
    }
    int Board::getSelectedRow() const
    {
        return selectedRow;
    }
    int Board::getSelectedCol() const
    {
        return selectedCol;
    }
    void Board::setBoardSide(BoardSide newSide)
    {
        if (newSide != boardSide)
        {
            Board::changeBoardSide();
            boardSide = newSide;
        }
    }
    void Board::deselect()
    {
        if (isSelected)
        {
            isSelected = false;
            boardGrid[selectedRow][selectedCol].setSelected(false);
        }
    }
    void Board::select(int x, int y)
    {
        if (isSelected)
        {
            boardGrid[selectedRow][selectedCol].setSelected(false);
        }
        isSelected = true;
        boardGrid[x][y].setSelected(true);
        selectedRow = x;
        selectedCol = y;
    }
    void Board::changeBoardSide()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                Figure tempFig = boardGrid[i][j];
                boardGrid[i][j] = boardGrid[7 - i][j];
                boardGrid[7 - i][j] = tempFig;
            }
        }
    }
    Figure &Board::getFigure(int x, int y)
    {
        return boardGrid[x][y];
    }

    

    std::pair<int, int> Board::getEp()
    {
        return ep;
    }

    FigureColor Board::getEpColor()
    {
        return epcolor;
    }

    void Board::setEp(std::pair<int, int> newEp, FigureColor epCol)
    {
        ep = newEp;
        epcolor = epCol;
    }

    void Board::createAttackBoard()
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                attackBoard[i][j] = AttackField();
                Figure t = (Figure)boardGrid[i][j];
                if(t.getType() == FigureType::KING)
                {
                    if(t.getColor() == FigureColor::WHITE)
                    {
                        whiteKingPos = std::make_pair(i, j);
                    }
                    else
                    {
                        blackKingPos = std::make_pair(i, j);
                    }
                }
            }
        }
    }

    static std::pair<int,int> findNextPinnable(int i, int j, int vi, int vj, FigureColor kingColor, FigureType pinner, Figure (&board)[8][8])
    {
        FigureColor enemyColor = kingColor == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE;
        bool foundPinnable = false;
        std::pair<int, int> pinnablePos;
        while(i + vi< 8 && i + vi >= 0 && j + vj < 8 && j + vj>= 0)
        {
            i += vi;
            j += vj;

            Figure curr = board[i][j];
            if(curr.getColor() == FigureColor::NONE) continue;
            else if(curr.getColor() == kingColor)
            {
                if(!foundPinnable) 
                {   
                    foundPinnable = true;
                    pinnablePos = std::make_pair(i, j);
                }
                else break;
            }
            else 
            {
                if(curr.getType() == pinner || curr.getType() == FigureType::QUEEN)
                {
                    if(foundPinnable)
                        return pinnablePos;
                }
            }
        }
        return std::make_pair(-1, -1);
    }

    static void setPins(std::pair<int, int> kingPos, FigureColor kingColor, Figure (&board)[8][8], AttackField (&attackBoard)[8][8])
    {
        std::pair<int, int> pinCheck;
        //VERTICAL

        //up
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, -1, 0, kingColor, FigureType::ROOK, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true); 

        //down
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, 1, 0, kingColor, FigureType::ROOK, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true);

        //left
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, 0, -1, kingColor, FigureType::ROOK, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true);

        //right
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, 0, 1, kingColor, FigureType::ROOK, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true);

        //DIAGONAL

        //upleft
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, -1, -1, kingColor, FigureType::BISHOP, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true); 

        //upright
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, -1, 1, kingColor, FigureType::BISHOP, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true);

        //downleft
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, 1, -1, kingColor, FigureType::BISHOP, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true);

        //downright
        pinCheck = findNextPinnable(kingPos.fi, kingPos.se, 1, 1, kingColor, FigureType::BISHOP, board);
        if(pinCheck.fi != -1) attackBoard[pinCheck.fi][pinCheck.se].setPinned(true);
    }

    static int abs(int a)
    {
        return a < 0 ? -a : a;
    }

    static std::pair<int, int> pinDirection(std::pair<int, int> kingPos, std::pair<int, int> pinPos)
    {
        //pin direction moves from pinned piece to the king
        //so if king (3, 6) has a pawn pinned to him on (2, 5)
        //the result is is -1, -1 making it top left of him, just like the coordinate system
        std::pair<int,int> temp;
        temp.fi = (pinPos.fi - kingPos.fi)/abs(pinPos.fi - kingPos.fi);
        temp.se = (pinPos.se - kingPos.se)/abs(pinPos.se - kingPos.se);
        return temp;
    }

    static FigureColor reverseColor(FigureColor color)
    {
        if(color == FigureColor::NONE) return FigureColor::NONE;
        else return color == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE;
    }


    static void moveUntilFigure(int i, int j, int vi, int vj, Figure *figure, Figure (&board)[8][8], AttackField (&attackBoard)[8][8])
    {
        while(i + vi < 8 && i + vi >= 0  && j + vj < 8 && j + vj >= 0 && board[i + vi][j + vj].getColor() == FigureColor::NONE)
        {
            i += vi; j += vj;
            attackBoard[i][j].upCount((*figure).getColor());
            attackBoard[i][j].addMat((*figure));
            (*figure).pushValidMove(std::make_pair(i, j));
        }

        if(i < 8 && i >= 0 && j < 8 && j >= 0)
        {
            attackBoard[i][j].upCount((*figure).getColor());
            attackBoard[i][j].addMat((*figure));
        }
    }

    static void knightMove(int i, int j, int vi, int vj, Figure *figure, Figure (&board)[8][8], AttackField (&attackBoard)[8][8])
    {
        if(i + vi < 8 && i + vi >= 0  && j + vj < 8 && j + vj >= 0 )
        {
            i += vi; j += vj;
            attackBoard[i][j].upCount((*figure).getColor());
            attackBoard[i][j].addMat((*figure));
            if(board[i][j].getColor() != (*figure).getColor())
                (*figure).pushValidMove(std::make_pair(i, j));
        }
    }

    void Board::updateAttackBoard()
    {
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                attackBoard[i][j].setPinned(false);
            }
        }
        //set pins
        setPins(whiteKingPos, FigureColor::WHITE, boardGrid, attackBoard);
        setPins(blackKingPos, FigureColor::BLACK, boardGrid, attackBoard);
        
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                if(attackBoard[i][j].getPinned()) std::cout<< "1 ";
                else std::cout << "0 ";
            }
            std::cout <<'\n';
        }

        //
        for(int i = 0; i < 8; i++)
        {
            for(int j = 0; j < 8; j++)
            {
                Figure curr = boardGrid[i][j];
                curr.resetValidMoves();
                FigureColor currcol = curr.getColor();
                switch (curr.getType())
                {
                    case FigureType::PAWN:
                    {
                        int vi = currcol == FigureColor::WHITE ? -1 : 1;
                        //pawnSide *= boardSide TO ADD LATER!!! won't work when flipped otherwise
                        
                        if(attackBoard[i][j].getPinned())
                        {
                            std::pair<int,int> direction;
                            if(currcol == FigureColor::WHITE)
                            {
                                direction = pinDirection(whiteKingPos, std::make_pair(i, j));
                            }
                            else direction = pinDirection(blackKingPos, std::make_pair(i, j));
                            //horizontal pin means no moves, this is when i = 0;
                            //vertical pin
                            //in both cases of a vertical pin the pawn is movable just like normal
                            //except it doesn't have the option to enpassant 
                            if(direction.se == 0 && boardGrid[i + vi][j].getType() == FigureType::NONE)
                            {
                                curr.pushValidMove(std::make_pair(i + vi, j));
                                if(!boardGrid[i][j].getMoved() && boardGrid[i + 2 * vi][j].getType() == FigureType::NONE)
                                {
                                    curr.pushValidMove(std::make_pair(i + 2 * vi, j));
                                }
                            }
                            //diagonal backwards pin also means no moves
                            //diagonal front pins allow them to capture in that diagonal
                            else if(direction.fi == vi && direction.se != 0)
                            {
                                //normal taking while pinned
                                if(direction.se == -1 && boardGrid[i + vi][j - 1].getColor() == reverseColor(currcol))
                                {
                                    curr.pushValidMove(std::make_pair(i + vi, j - 1));
                                }
                                else if (direction.se == 1 && boardGrid[i + vi][j + 1].getColor() == reverseColor(currcol))
                                {
                                    curr.pushValidMove(std::make_pair(i + vi, j + 1));
                                }
                                //en passant while pinned
                                else if(direction.se == -1 && i == getEp().fi && j - 1 == getEp().se)
                                {
                                    curr.pushValidMove(std::make_pair(i + vi, j - 1));
                                }
                                else if(direction.fi == 1 && i == getEp().fi && j + 1 == getEp().se)
                                {
                                    curr.pushValidMove(std::make_pair(i + vi, j + 1));
                                }
                            }
                        }
                        else
                        {
                            //moving forward
                            if(boardGrid[i + vi][j].getType() == FigureType::NONE)
                            {
                                curr.pushValidMove(std::make_pair(i + vi, j));
                                if(!boardGrid[i][j].getMoved() && boardGrid[i + 2 * vi][j].getType() == FigureType::NONE)
                                {
                                    curr.pushValidMove(std::make_pair(i + 2 * vi, j));
                                }
                            }
                            //taking left
                            if(j > 0 && boardGrid[i + vi][j - 1].getColor() != currcol)
                            {
                                if(boardGrid[i + vi][j - 1].getColor() != FigureColor::NONE)
                                {
                                    curr.pushValidMove(std::make_pair(i + vi, j - 1));
                                }
                            }
                            //taking right
                            if(j < 7 && boardGrid[i + vi][j + 1].getColor() != currcol)
                            {
                                if(boardGrid[i + vi][j + 1].getColor() != FigureColor::NONE)
                                {
                                    curr.pushValidMove(std::make_pair(i + vi, j + 1));
                                }
                            }
                            //en passant
                            if(i == getEp().fi && (getEp().se - 1 == j || getEp().se + 1 == j))
                            {
                                curr.pushValidMove(std::make_pair(getEp().fi + vi, getEp().se));
                            }
                        }

                        if(j > 0)
                        {
                            attackBoard[i + vi][j - 1].upCount(currcol);
                            attackBoard[i + vi][j - 1].addMat(curr); 
                        }
                        if(j < 7)
                        {
                            attackBoard[i + vi][j + 1].upCount(currcol);
                            attackBoard[i + vi][j + 1].addMat(curr); 
                        }
                        break;
                    }
                    case FigureType::ROOK:
                    {
                        if(attackBoard[i][j].getPinned())
                        {
                            std::pair<int, int> direction; 
                            if(currcol == FigureColor::WHITE)
                            {
                                direction = pinDirection(whiteKingPos, std::make_pair(i, j));
                            }
                            else direction = pinDirection(blackKingPos, std::make_pair(i, j));
                            //if pinned diagonally, a rook cannot move
                            
                            if(direction.fi == 0 || direction.se == 0)
                            {
                                moveUntilFigure(i, j, direction.fi, direction.se, &curr, boardGrid, attackBoard);
                            }
                        }
                        else
                        {
                            //upwards
                            moveUntilFigure(i, j, -1, 0, &curr, boardGrid, attackBoard);
                            
                            //downwards
                            moveUntilFigure(i, j, 1, 0, &curr, boardGrid, attackBoard);
                            
                            //left
                            moveUntilFigure(i, j, 0, -1, &curr, boardGrid, attackBoard);
                            
                            //right
                            moveUntilFigure(i, j, 0, 1, &curr, boardGrid, attackBoard);
                        }
                        break;
                    }
                    case FigureType::KNIGHT:
                    {
                        //a knight cannot ever move while pinned
                        if(!attackBoard[i][j].getPinned())
                        {
                            knightMove(i, j, -2, -1, &curr, boardGrid, attackBoard);
                            knightMove(i, j, -2, 1, &curr, boardGrid, attackBoard);
                            knightMove(i, j, 2, -1, &curr, boardGrid, attackBoard);
                            knightMove(i, j, 2, 1, &curr, boardGrid, attackBoard);
                            knightMove(i, j, 1, -2, &curr, boardGrid, attackBoard);
                            knightMove(i, j, -1, -2, &curr, boardGrid, attackBoard);
                            knightMove(i, j, 1, 2, &curr, boardGrid, attackBoard);
                            knightMove(i, j, -1, 2, &curr, boardGrid, attackBoard);
                        }
                        break;
                    }
                    case FigureType::BISHOP:
                    {
                        if(attackBoard[i][j].getPinned())
                        {
                            std::pair<int, int> direction; 
                            if(currcol == FigureColor::WHITE)
                            {
                                direction = pinDirection(whiteKingPos, std::make_pair(i, j));
                            }
                            else direction = pinDirection(blackKingPos, std::make_pair(i, j));
                            //if pinned horizontally or vertically, a bishop cannot move
                            if(direction.fi != 0 && direction.se != 0)
                            {
                                moveUntilFigure(i, j, direction.fi, direction.se, &curr, boardGrid, attackBoard);
                            } 
                            
                        }
                        else
                        {
                            
                            //up left
                            moveUntilFigure(i, j, -1, -1, &curr, boardGrid, attackBoard);
                            
                            //up right
                            moveUntilFigure(i, j, -1, 1, &curr, boardGrid, attackBoard);
                            
                            //down left
                            moveUntilFigure(i, j, 1, -1, &curr, boardGrid, attackBoard);
                            
                            //dwon right
                            moveUntilFigure(i, j, -1, 1, &curr, boardGrid, attackBoard);
                        }
                        break;
                    }
                    case FigureType::QUEEN:
                    {

                        if(attackBoard[i][j].getPinned())
                        {
                            std::pair<int, int> direction; 
                            if(currcol == FigureColor::WHITE)
                            {
                                direction = pinDirection(whiteKingPos, std::make_pair(i, j));
                            }
                            else direction = pinDirection(blackKingPos, std::make_pair(i, j));
                            //if pinned a queen can always take the pinning piece
                            moveUntilFigure(i, j, direction.fi, direction.se, &curr, boardGrid, attackBoard);
                            
                        }
                        else
                        {
                            //upwards
                            moveUntilFigure(i, j, -1, 0, &curr, boardGrid, attackBoard);
                            
                            //downwards
                            moveUntilFigure(i, j, 1, 0, &curr, boardGrid, attackBoard);
                            
                            //left
                            moveUntilFigure(i, j, 0, -1, &curr, boardGrid, attackBoard);
                            
                            //right
                            moveUntilFigure(i, j, 0, 1, &curr, boardGrid, attackBoard);
                            //up left
                            moveUntilFigure(i, j, -1, -1, &curr, boardGrid, attackBoard);
                            
                            //up right
                            moveUntilFigure(i, j, -1, 1, &curr, boardGrid, attackBoard);
                            
                            //down left
                            moveUntilFigure(i, j, 1, -1, &curr, boardGrid, attackBoard);
                            
                            //dwon right
                            moveUntilFigure(i, j, -1, 1, &curr, boardGrid, attackBoard);
                        }
                        break;
                    }
                    case FigureType::KING:
                    {
                        break;
                    }
                    default:
                    {

                    }
                    
                }
                boardGrid[i][j] = curr;
                if(curr.getType() != FigureType::NONE)
                    curr.printValidMoves();
            }
        }
        
         
    
    }
    bool Board::validMove(int xStart, int yStart, int xEnd, int yEnd)
    {
        std::pair<int, int> newMove = std::make_pair(xEnd, yEnd);
        return boardGrid[xStart][yStart].validMove(newMove);
    }
    void Board::update(int xStart, int yStart, int xEnd, int yEnd)
    {
        boardGrid[xEnd][yEnd] = boardGrid[xStart][yStart];
        boardGrid[xStart][yStart] = Figure();
        currentTurn = currentTurn == FigureColor::WHITE ? FigureColor::BLACK : FigureColor::WHITE;
    }

    int Board::getControl(FigureColor color)
    {
        return 0; //temp
    }

}