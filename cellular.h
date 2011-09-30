#ifndef CELLULAR_H
#define CELLULAR_H

class Cellular
{
public:
    Cellular(int size_x, int size_y);
	virtual ~Cellular();
	
	void next();
	int sizeX() const { return size_x; }
	int sizeY() const { return size_y; }
    int cell(int x, int y) const { return cells[curr_state_index][x][y]; }
    
private:
    void zerofile();
    void firstInit();

	int getNextState(int x, int y) const;
	int getStateByNums(int curr_state, int nums) const;

	int size_x, size_y;

	int** cells[2];
	int curr_state_index;
};

#endif // CELLULAR_H
