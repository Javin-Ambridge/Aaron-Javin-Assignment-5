#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "tile.h"

class View {

	public:
		void print() = 0;
		void notify(Tile pos[]) = 0;
};

#endif
