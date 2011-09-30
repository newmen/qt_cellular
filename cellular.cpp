#include "cellular.h"

Cellular::Cellular(int size_x, int size_y) : size_x(size_x), size_y(size_y), curr_state_index(0) {
	for (int i = 0; i < 2; ++i) {
		cells[i] = new int*[size_x];
        for (int x = 0; x < size_x; ++x) cells[i][x] = new int[size_y];
	}

    firstInit();
}

Cellular::~Cellular() {
	for (int i = 0; i < 2; ++i) {
		for (int x = 0; x < size_x; ++x) delete[] cells[i][x];
		delete[] cells[i];
	}
}

void Cellular::zerofile() {
    for (int x = 0; x < size_x; ++x) {
        for (int y = 0; y < size_y; ++y) {
            cells[curr_state_index][x][y] = 0;
        }
    }
}

void Cellular::firstInit() {
    zerofile();
    cells[curr_state_index][1][1] = 1;
    cells[curr_state_index][3][1] = 1;
    cells[curr_state_index][2][2] = 1;
    cells[curr_state_index][3][2] = 1;
    cells[curr_state_index][2][3] = 1;
}

void Cellular::next() {
	int next_state_index = (curr_state_index == 0) ? 1 : 0;
	
	for (int x = 0; x < size_x; ++x) {
		for (int y = 0; y < size_y; ++y) {
			cells[next_state_index][x][y] = getNextState(x, y);
		}
	}
	
	curr_state_index = next_state_index;
}

int Cellular::getNextState(int x, int y) const {
	int set_nums = 0;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			if (i == 0 && j == 0) continue;
			
			int real_x = x + i, real_y = y + j;
			if (real_x < 0) real_x = size_x - 1;
			else if (real_x == size_x) real_x = 0;
			if (real_y < 0) real_y = size_y - 1;
			else if (real_y == size_y) real_y = 0;
			
			if (cells[curr_state_index][real_x][real_y] == 1) ++set_nums;
		}
	}
	return getStateByNums(cells[curr_state_index][x][y], set_nums);
}

int Cellular::getStateByNums(int curr_state, int nums) const {
	if (curr_state == 0) {
		if (nums == 3) return 1;
        else return curr_state;
	} else {
		if (nums == 2 || nums == 3) return 1;
		else return 0;
	}
}

