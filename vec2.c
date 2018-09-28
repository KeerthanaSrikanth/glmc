/* 
 * Copyright 2018 Anish Bhobe, glmc Contributors
 * 
 * Permission is hereby granted, free of charge, 
 * to any person obtaining a copy of this software 
 * and associated documentation files (the "Software"), 
 * to deal in the Software without restriction, including 
 * without limitation the rights to use, copy, modify, 
 * merge, publish, distribute, sublicense, and/or sell 
 * copies of the Software, and to permit persons to whom 
 * the Software is furnished to do so, subject to the 
 * ollowing conditions:
 * 
 * The above copyright notice and this permission notice shall be 
 * included in all copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE 
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include "glmc.h"
#include <math.h>
	
inline void glmc_vec2f_from_3f(vec2f dest, vec3f src_a){ //2d from 3d
	
	dest[0]=src_a[0];
	dest[1]=src_a[1];
}

inline void glmc_vec2f_from_4f(vec2f dest, vec4f src){ //2d from 4d
	
	dest[0]=src[0];
	dest[1]=src[1];
	
}

inline void glmc_vec2f_copy(vec2f dest, vec2f src){ //2d to 2d
	dest[0]=src[0];
	dest[1]=src[1];
}

inline float glmc_vec2f_sqrlength(vec2f vec){ //Calculates square of length of vector
	return vec[0]*vec[0]+vec[1]*vec[1];
}

inline float glmc_vec2f_length(vec2f vec){ //Calculates length of vector
	return sqrt(glmc_vec2f_sqrlength(vec));
}

inline int  glmc_vec2f_is_normalized(vec2f src){ //Checks if vector is normalized
	if(glmc_vec2f_length(src)==1)
		return 1;
	else
		return 0;
}

inline void glmc_vec2f_normlize(vec2f dest, vec2f src){//Normalizes vector
	float l=glmc_vec2f_length(src);

	dest[0]=src[0]/l;
	dest[1]=src[1]/l;
	
}

inline void glmc_vec2f_add(vec2f dest, vec2f src_a, vec2f src_b){ // dest = src_a + src_b
	
	dest[0]=src_a[0]+src_b[0];
	dest[1]=src_a[1]+src_b[1];
	
}

inline void glmc_vec2f_add_dest(vec2f src_dest, vec2f src_b){// dest += src_a
	
	src_dest[0]=src_dest[0]+src_b[0];
	src_dest[1]=src_dest[1]+src_b[1];
	
}

inline void glmc_vec2f_sub(vec2f dest, vec2f src_a, vec2f src_b){// dest = src_a - src_b
	dest[0]=src_a[0]-src_b[0];
	dest[1]=src_a[1]-src_b[1];

}

inline void glmc_vec2f_sub_dest(vec2f src_dest, vec2f src_b){ // dest -= src_a
	src_dest[0]=src_dest[0]-src_b[0];
	src_dest[1]=src_dest[1]-src_b[1];
}

inline void glmc_vec2f_mul(vec2f dest, vec2f src_a, vec2f src_b){// dest = src_a * src_b
	
	dest[0]=src_a[0]*src_b[0];
	dest[1]=src_a[1]*src_b[1];
	
}

inline void glmc_vec2f_mul_dest(vec2f src_dest, vec2f src_b){// dest *= src_a
	src_dest[0]=src_dest[0]*src_b[0];
	src_dest[1]=src_dest[1]*src_b[1];	
}

inline void glmc_vec2f_mul_s(vec2f dest, vec2f src_a, float src_b){// dest = src_a * scalar
	
	dest[0]=src_a[0]*src_b;
	dest[1]=src_a[1]*src_b;
	
}

inline void glmc_vec2f_div(vec2f dest, vec2f src_a, vec2f src_b){// dest = src_a / src_b
	dest[0]=src_a[0]/src_b[0];
	dest[1]=src_a[1]/src_b[1];

}

inline void glmc_vec2f_div_dest(vec2f src_dest, vec2f src_b){// dest /= src_a
	src_dest[0]=src_dest[0]/src_b[0];
	src_dest[1]=src_dest[1]/src_b[1];

}

inline void glmc_vec2f_div_s(vec2f dest, vec2f src_a, float src_b){// dest = src_a / scalar
	dest[0]=src_a[0]/src_b;
	dest[1]=src_a[1]/src_b;

}

inline void glmc_vec2f_addadd(vec2f dest, vec2f src_a, vec2f src_b){// dest += src_a + src_b
	
	dest[0]=dest[0]+src_a[0]+src_b[0];
	dest[1]=dest[1]+src_a[1]+src_b[1];

	
}

inline void glmc_vec2f_subadd(vec2f dest, vec2f src_a, vec2f src_b){// dest += src_a - src_b
	dest[0]=dest[0]+src_a[0]-src_b[0];
	dest[1]=dest[1]+src_a[1]-src_b[1];

}

inline void glmc_vec2f_madd(vec2f dest, vec2f src_a, vec2f src_b){// dest += src_a * src_b
	dest[0]=dest[0]+src_a[0]*src_b[0];
	dest[1]=dest[1]+src_a[1]*src_b[1];

}

inline void glmc_vec2f_msub(vec2f dest, vec2f src_a, vec2f src_b){// dest -= src_a * src_b
	dest[0]=dest[0]-src_a[0]*src_b[0];
	dest[1]=dest[1]-src_a[1]*src_b[1];

}

inline float glmc_vec2f_dot(vec2f src_a, vec2f src_b){ //Calculates dot product of vectors

	return src_a[0]*src_b[0]+src_a[1]*src_b[1];
	
}
