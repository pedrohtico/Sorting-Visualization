#pragma once

#include <random>
#include <allegro5/allegro_primitives.h>

class Sort
{
public:
	Sort(int N) {
		this->N = N;
		this->array = new int[N];
		this->isSorted = false;
		this->step = 0;

		for (int i = 0; i < N; i++)
			array[i] = rand() % 600;
	}

	~Sort() {
		delete[] array;
	}

	void render() const {
		for (int i = 0; i < N; i++)
			al_draw_line(i, 599, i, 599 - array[i], al_map_rgb_f(1, 1, 1), 1);
	}

	virtual void update() = 0;

protected:
	int* array;
	int N;
	bool isSorted;
	int step;
};

