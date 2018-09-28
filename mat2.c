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

inline float glmc_mat2f_discriminant(mat2f src){
	
	return src[0][0]*src[1][1]-src[1][0]*src[0][1];

}

inline void glmc_mat2f_transpose(mat2f dest, mat2f src_a){

	dest[0][0]=src_a[0][0];
	dest[1][0]=src_a[0][1];
	dest[0][1]=src_a[1][0];
	dest[1][1]=src_a[1][1];
}

inline void glmc_mat2f_transpose_dest(mat2f src_a){
	float temp=src_a[0][1];
	src_a[0][1]=src_a[1][0];
	src_a[1][0]=temp;
}

inline void glmc_mat2f_inverse(mat2f dest, mat2f src_a){

	float discr=glmc_mat2f_discriminant(src_a);
	if(discr!=0){
		dest[0][0]=src_a[1][1]/discr;
		dest[0][1]=-1*src_a[0][1]/discr;
		dest[1][0]=-1*src_a[1][0]/discr;
		dest[1][1]=src_a[0][0]/discr;
	}

}

inline int  glmc_mat2f_is_normalized(mat2f src){
	if(glmc_mat2f_discriminant(src)==1)
		return 1;
	else
		return 0;
}

inline void glmc_mat2f_normlize(mat2f dest, mat2f src){
	float discr=glmc_mat2f_discriminant(src);
	dest[0][0]=src[0][0]/discr;
	dest[0][1]=src[0][1]/discr;
	dest[1][0]=src[1][0]/discr;
	dest[1][1]=src[1][1]/discr;

}

inline void glmc_mat2f_normlize_dest(mat2f src){
	float discr=glmc_mat2f_discriminant(src);
	src[0][0]=src[0][0]/discr;
	src[0][1]=src[0][1]/discr;
	src[1][0]=src[1][0]/discr;
	src[1][1]=src[1][1]/discr;
}


inline void glmc_mat2f_add(mat2f dest, mat2f src_a, mat2f src_b){ // dest = src_a + src_b
	dest[0][0]=src_a[0][0]+src_b[0][0];
	dest[0][1]=src_a[0][1]+src_b[0][1];
	dest[1][0]=src_a[1][0]+src_b[1][0];
	dest[1][1]=src_a[1][1]+src_b[1][1];
	

}
inline void glmc_mat2f_add_dest(mat2f dest, mat2f src_b){	// dest += src_a
	
	dest[0][0]=dest[0][0]+src_b[0][0];
	dest[0][1]=dest[0][1]+src_b[0][1];
	dest[1][0]=dest[1][0]+src_b[1][0];
	dest[1][1]=dest[1][1]+src_b[1][1];
} 


inline void glmc_mat2f_sub(mat2f dest, mat2f src_a, mat2f src_b){// dest = src_a - src_b
	dest[0][0]=src_a[0][0]-src_b[0][0];
	dest[0][1]=src_a[0][1]-src_b[0][1];
	dest[1][0]=src_a[1][0]-src_b[1][0];
	dest[1][1]=src_a[1][1]-src_b[1][1];
} 
inline void glmc_mat2f_sub_dest(mat2f dest, mat2f src_b){ // dest -= src_a;
	dest[0][0]=dest[0][0]-src_b[0][0];
	dest[0][1]=dest[0][1]-src_b[0][1];
	dest[1][0]=dest[1][0]-src_b[1][0];
	dest[1][1]=dest[1][1]-src_b[1][1];
} 


inline void glmc_mat2f_mul(mat2f dest, mat2f src_a, mat2f src_b){ // dest = src_a * src_b

	dest[0][0]=src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1];
	dest[1][0]=src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[1][1];
	dest[0][1]=src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[0][1];
	dest[1][1]=src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1];
}
inline void glmc_mat2f_mul_dest(mat2f dest, mat2f src_b){// dest *= src_a

	mat2f temp_dest;
	temp_dest[0][0]=dest[0][0];
	temp_dest[0][1]=dest[0][1];
	temp_dest[1][0]=dest[1][0];
	temp_dest[1][1]=dest[1][1];

	dest[0][0]=temp_dest[0][0]*src_b[0][0]+temp_dest[1][0]*src_b[0][1];
	dest[1][0]=temp_dest[0][0]*src_b[0][0]+temp_dest[1][0]*src_b[1][1];
	dest[0][1]=temp_dest[0][1]*src_b[1][0]+temp_dest[1][1]*src_b[0][1];
	dest[1][1]=temp_dest[0][1]*src_b[1][0]+temp_dest[1][1]*src_b[1][1];
}
inline void glmc_mat2f_mul_s(mat2f dest, mat2f src_a, float src_b){// dest = src_a * scalar
	dest[0][0]=src_a[0][0]*src_b;
	dest[0][1]=src_a[0][1]*src_b;
	dest[1][0]=src_a[1][0]*src_b;
	dest[1][1]=src_a[1][1]*src_b;
}

inline void glmc_mat2f_div(mat2f dest, mat2f src_a, mat2f src_b){// dest = src_a / src_b
	
	mat2f inv;
	glmc_mat2f_inverse(inv, src_b);

	dest[0][0]=src_a[0][0]*inv[0][0]+src_a[1][0]*inv[0][1];
	dest[1][0]=src_a[0][0]*inv[0][0]+src_a[1][0]*inv[1][1];
	dest[0][1]=src_a[0][1]*inv[1][0]+src_a[1][1]*inv[0][1];
	dest[1][1]=src_a[0][1]*inv[1][0]+src_a[1][1]*inv[1][1];

}
inline void glmc_mat2f_div_dest(mat2f dest, mat2f src_b){// dest /= src_a;
	mat2f inv;
	glmc_mat2f_inverse(inv, src_b);

	mat2f temp_dest;
	temp_dest[0][0]=dest[0][0];
	temp_dest[0][1]=dest[0][1];
	temp_dest[1][0]=dest[1][0];
	temp_dest[1][1]=dest[1][1];

	dest[0][0]=temp_dest[0][0]*inv[0][0]+temp_dest[1][0]*inv[0][1];
	dest[1][0]=temp_dest[0][0]*inv[0][0]+temp_dest[1][0]*inv[1][1];
	dest[0][1]=temp_dest[0][1]*inv[1][0]+temp_dest[1][1]*inv[0][1];
	dest[1][1]=temp_dest[0][1]*inv[1][0]+temp_dest[1][1]*inv[1][1];

}

inline void glmc_mat2f_div_s(mat2f dest, mat2f src_a, float src_b){// dest = src_a / scalar
	dest[0][0]=src_a[0][0]/src_b;
	dest[0][1]=src_a[0][1]/src_b;
	dest[1][0]=src_a[1][0]/src_b;
	dest[1][1]=src_a[1][1]/src_b;
}

inline void glmc_mat2f_addadd(mat2f dest, mat2f src_a, mat2f src_b){// dest += src_a + src_b
	dest[0][0]=dest[0][0]+src_a[0][0]+src_b[0][0];
	dest[0][1]=dest[0][1]+src_a[0][1]+src_b[0][1];
	dest[1][0]=dest[1][0]+src_a[1][0]+src_b[1][0];
	dest[1][1]=dest[1][1]+src_a[1][1]+src_b[1][1];
}

inline void glmc_mat2f_subadd(mat2f dest, mat2f src_a, mat2f src_b){// dest += src_a - src_b
	dest[0][0]=dest[0][0]+src_a[0][0]-src_b[0][0];
	dest[0][1]=dest[0][1]+src_a[0][1]-src_b[0][1];
	dest[1][0]=dest[1][0]+src_a[1][0]-src_b[1][0];
	dest[1][1]=dest[1][1]+src_a[1][1]-src_b[1][1];
}

inline void glmc_mat2f_madd(mat2f dest, mat2f src_a, mat2f src_b){// dest += src_a * src_b
	
	dest[0][0]=dest[0][0]+src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1];
	dest[1][0]=dest[0][1]+src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[1][1];
	dest[0][1]=dest[1][0]+src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[0][1];
	dest[1][1]=dest[1][1]+src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1];

}

inline void glmc_mat2f_msub(mat2f dest, mat2f src_a, mat2f src_b) {// dest -= src_a * src_b
	dest[0][0]=dest[0][0]-src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1];
	dest[1][0]=dest[0][1]-src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[1][1];
	dest[0][1]=dest[1][0]-src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[0][1];
	dest[1][1]=dest[1][1]-src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1];
}



