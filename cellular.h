#ifndef CELLULAR_H
#define CELLULAR_H

#define STATES_NUM 3

class Cellular
{
public:
    explicit Cellular(int size_x, int size_y);
    virtual ~Cellular();

    void save();
    void restore();

    void next();
    int sizeX() const { return size_x; }
    int sizeY() const { return size_y; }
    int cell(int x, int y) const { return cells[curr_state_index][x][y]; }

    void invertCell(int x, int y) {
        int state = cells[curr_state_index][x][y];
        cells[curr_state_index][x][y] = (state == 0) ? 1 : 0;
    }

private:
    void copyCells(int to_state, int from_state);

    void zerofile();
    void firstInit();

    int getNextState(int x, int y) const;
    int getStateByNums(int curr_state, int nums) const;

    int size_x, size_y;

    int** cells[STATES_NUM];
    int curr_state_index;
};

#endif // CELLULAR_H
