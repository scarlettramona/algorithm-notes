bool canTravelTo(std::vector<std::vector<bool>>& gameMatrix,
                 int fromRow, int fromColumn,
                 int toRow,   int toColumn)
{
    int numRows = gameMatrix.size();
    if (numRows == 0) return false;
    int numCols = gameMatrix[0].size();

    // anything outside of [0, numRows-1] x [0, numCols-1] is invalid so bail
    if (fromRow < 0 || fromRow >= numRows ||
        fromColumn < 0 || fromColumn >= numCols ||
        toRow   < 0 || toRow   >= numRows ||
        toColumn< 0 || toColumn>= numCols)
        return false;

    // number of spots we're going to move  
    int dr = toRow   - fromRow; // (positve = down negative = up)
    int dc = toColumn- fromColumn; // (positive = right, negative = left)

    // single moves: just check target is water
    if ((dr == -1 && dc ==  0) ||  // Up 1
        (dr ==  1 && dc ==  0) ||  // Down 1
        (dr ==  0 && dc == -1) ||  // Left 1
        (dr ==  0 && dc ==  1))    // Right 1
    {
        return gameMatrix[toRow][toColumn];
    }

    // right 2: check both intermediate and target cells
    if (dr == 0 && dc == 2) {
        // intermediate cell (fromRow, fromColumn+1)
        return gameMatrix[fromRow][fromColumn + 1]
            && gameMatrix[toRow]  [toColumn];
    }

    // anything else is none of our buisness
    return false;
}
