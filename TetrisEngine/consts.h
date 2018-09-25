#ifndef CONSTS_H
#define CONSTS_H

#include "bin_macros.h"

const int NUM_SHAPES = 7;

// shape (16 bits) width (8 bits) height (8 bits)
// each of the four rows is a different rotation

const array<int32_t, 4> shape1 = {{
	B32(11001100,00000000,00000010,00000010),  // **
	B32(11001100,00000000,00000010,00000010),  // **
	B32(11001100,00000000,00000010,00000010),
 	B32(11001100,00000000,00000010,00000010)
}};

const array<int32_t, 4> shape2 = {{
	B32(10001000,10001000,00000001,00000100), // *
	B32(11110000,00000000,00000100,00000001), // *
	B32(10001000,10001000,00000001,00000100), // *
 	B32(11110000,00000000,00000100,00000001)  // *
}};

const array<int32_t, 4> shape3 = {{
	B32(11001000,10000000,00000010,00000011), // **
	B32(11100010,00000000,00000011,00000010), // *
	B32(01000100,11000000,00000010,00000011), // * 
 	B32(10001110,00000000,00000011,00000010)
}};

const array<int32_t, 4> shape4 = {{
	B32(11000100,01000000,00000010,00000011), // **
	B32(00101110,00000000,00000011,00000010), //  *
	B32(10001000,11000000,00000010,00000011), //  *
 	B32(11101000,00000000,00000011,00000010)
}};

const array<int32_t, 4> shape5 = {{
	B32(01001110,00000000,00000011,00000010), //  * 
	B32(10001100,10000000,00000010,00000011), // ***
	B32(11100100,00000000,00000011,00000010), 
 	B32(01001100,01000000,00000010,00000011)
}};

const array<int32_t, 4> shape6 = {{
	B32(11000110,00000000,00000011,00000010), // **
	B32(01001100,10000000,00000010,00000011), //  **
	B32(11000110,00000000,00000011,00000010),
 	B32(01001100,10000000,00000010,00000011)
}};

const array<int32_t, 4> shape7 = {{
	B32(01101100,00000000,00000011,00000010), //  **
	B32(10001100,01000000,00000010,00000011), // **
	B32(01101100,00000000,00000011,00000010),
 	B32(10001100,01000000,00000010,00000011)
}};

#endif
