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

inline float glmc_mat3f_discriminant(mat3f src_a){
	
	return src_a[0][0]*(src_a[1][1]*src_a[2][2]-src_a[1][2]*src_a[2][1])-src_a[0][1]*(src_a[1][0]*src_a[2][2]-src_a[1][2]*src_a[2][0])+src_a[0][2]*(src_a[1][0]*src_a[2][1]-src_a[1][1]*src_a[2][0]);
	
}
inline void glmc_mat3f_inverse(mat3f dest, mat3f src_a){
	mat3f cof;

	cof[0][0]=src_a[1][1]*src_a[2][2]-src_a[1][2]*src_a[2][1];
	cof[0][1]=-(src_a[1][0]*src_a[2][2]-src_a[1][2]*src_a[2][0]);
	cof[0][2]=src_a[1][0]*src_a[2][1]-src_a[1][1]*src_a[2][0];

	cof[1][0]=-(src_a[0][1]*src_a[2][2]-src_a[0][2]*src_a[2][1]);
	cof[1][1]=src_a[0][0]*src_a[2][2]-src_a[0][2]*src_a[2][0];
	cof[1][2]=-(src_a[0][0]*src_a[2][1]-src_a[0][1]*src_a[2][0]);

	cof[2][0]=src_a[0][1]*src_a[1][2]-src_a[0][2]*src_a[1][1];
	cof[2][1]=src_a[0][0]*src_a[1][2]-src_a[0][2]*src_a[1][0];
	cof[2][2]=src_a[0][0]*src_a[1][1]-src_a[0][1]*src_a[1][0];

	glmc_mat3f_transpose(dest, cof);
	float discr=glmc_mat3f_discriminant(src_a);

	dest[0][0]=dest[0][0]/discr;
	dest[0][1]=dest[0][1]/discr;
	dest[0][2]=dest[0][2]/discr;

	dest[1][0]=dest[1][0]/discr;
	dest[1][1]=dest[1][1]/discr;
	dest[1][2]=dest[1][2]/discr;

	dest[2][0]=dest[2][0]/discr;
	dest[2][1]=dest[2][1]/discr;
	dest[2][2]=dest[2][2]/discr;


}

inline void glmc_mat3f_transpose(mat3f dest, mat3f src_a){
	dest[0][0]=src_a[0][0];
	dest[1][0]=src_a[0][1];
	dest[2][0]=src_a[0][2];

	dest[0][1]=src_a[1][0];
	dest[1][1]=src_a[1][1];
	dest[2][1]=src_a[1][2];

	dest[0][2]=src_a[2][0];
	dest[1][2]=src_a[2][1];
	dest[2][2]=src_a[2][2];
}

inline void glmc_mat3f_transpose_dest(mat3f src_a){

	float temp=src_a[0][1];
	src_a[0][1]=src_a[1][0];
	src_a[1][0]=temp;

	temp=src_a[0][2];
	src_a[0][2]=src_a[2][0];
	src_a[2][0]=temp;

	temp=src_a[1][2];
	src_a[1][2]=src_a[2][1];
	src_a[2][1]=temp;

}

inline int  glmc_mat3f_is_normalized(mat3f src){
	
	if(glmc_mat3f_discriminant(src)==1)
		return 1;
	else
		return 0;
}

inline void glmc_mat3f_normlize(mat3f dest, mat3f src){
	float discr=glmc_mat3f_discriminant(src);
	dest[0][0]=src[0][0]/discr;
	dest[0][1]=src[0][1]/discr;
	dest[0][2]=src[0][2]/discr;

	dest[1][0]=src[1][0]/discr;
	dest[1][1]=src[1][1]/discr;
	dest[1][2]=src[1][2]/discr;

	dest[2][0]=src[1][0]/discr;
	dest[2][1]=src[1][1]/discr;
	dest[2][2]=src[1][2]/discr;
	
}


inline void glmc_mat3f_normlize_dest(mat3f src){
	float discr=glmc_mat3f_discriminant(src);
	src[0][0]=src[0][0]/discr;
	src[0][1]=src[0][1]/discr;
	src[0][2]=src[0][2]/discr;

	src[1][0]=src[1][0]/discr;
	src[1][1]=src[1][1]/discr;
	src[1][2]=src[1][2]/discr;

	src[2][0]=src[1][0]/discr;
	src[2][1]=src[1][1]/discr;
	src[2][2]=src[1][2]/discr;
	
}

inline void glmc_mat3f_add(mat3f dest, mat3f src_a, mat3f src_b){// dest = src_a + src_b
	dest[0][0]=src_a[0][0]+src_b[0][0];
	dest[0][1]=src_a[0][1]+src_b[0][1];
	dest[0][2]=src_a[0][2]+src_b[0][2];

	dest[1][0]=src_a[1][0]+src_b[1][0];
	dest[1][1]=src_a[1][1]+src_b[1][1];
	dest[1][2]=src_a[1][2]+src_b[1][2];

	dest[2][0]=src_a[2][0]+src_b[2][0];
	dest[2][1]=src_a[2][1]+src_b[2][1];
	dest[2][2]=src_a[2][2]+src_b[2][2];
}

inline void glmc_mat3f_add_dest(mat3f dest, mat3f src_b){ // dest += src_a;
	dest[0][0]=dest[0][0]+src_b[0][0];
	dest[0][1]=dest[0][1]+src_b[0][1];
	dest[0][2]=dest[0][2]+src_b[0][2];

	dest[1][0]=dest[1][0]+src_b[1][0];
	dest[1][1]=dest[1][1]+src_b[1][1];
	dest[1][2]=dest[1][2]+src_b[1][2];

	dest[2][0]=dest[2][0]+src_b[2][0];
	dest[2][1]=dest[2][1]+src_b[2][1];
	dest[2][2]=dest[2][2]+src_b[2][2];
}

inline void glmc_mat3f_sub(mat3f dest, mat3f src_a, mat3f src_b){ // dest = src_a - src_b
	dest[0][0]=src_a[0][0]-src_b[0][0];
	dest[0][1]=src_a[0][1]-src_b[0][1];
	dest[0][2]=src_a[0][2]-src_b[0][2];

	dest[1][0]=src_a[1][0]-src_b[1][0];
	dest[1][1]=src_a[1][1]-src_b[1][1];
	dest[1][2]=src_a[1][2]-src_b[1][2];

	dest[2][0]=src_a[2][0]-src_b[2][0];
	dest[2][1]=src_a[2][1]-src_b[2][1];
	dest[2][2]=src_a[2][2]-src_b[2][2];
}

inline void glmc_mat3f_sub_dest(mat3f dest, mat3f src_b){// dest -= src_a
	dest[0][0]=dest[0][0]-src_b[0][0];
	dest[0][1]=dest[0][1]-src_b[0][1];
	dest[0][2]=dest[0][2]-src_b[0][2];

	dest[1][0]=dest[1][0]-src_b[1][0];
	dest[1][1]=dest[1][1]-src_b[1][1];
	dest[1][2]=dest[1][2]-src_b[1][2];

	dest[2][0]=dest[2][0]-src_b[2][0];
	dest[2][1]=dest[2][1]-src_b[2][1];
	dest[2][2]=dest[2][2]-src_b[2][2];
}

inline void glmc_mat3f_mul(mat3f dest, mat3f src_a, mat3f src_b){ // dest = src_a * src_b
	dest[0][0]=src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1]+src_a[2][0]*src_b[0][2];
	dest[0][1]=src_a[0][1]*src_b[0][0]+src_a[1][1]*src_b[0][1]+src_a[2][1]*src_b[0][2];
	dest[0][2]=src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2];

	dest[1][0]=src_a[0][0]*src_b[1][0]+src_a[1][0]*src_b[1][1]+src_a[2][0]*src_b[1][2];
	dest[1][1]=src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1]+src_a[2][1]*src_b[1][2];
	dest[1][2]=src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2];

	dest[2][0]=src_a[0][0]*src_b[2][0]+src_a[1][0]*src_b[2][1]+src_a[2][0]*src_b[2][2];
	dest[2][1]=src_a[0][1]*src_b[2][0]+src_a[1][1]*src_b[2][1]+src_a[2][1]*src_b[2][2];
	dest[2][2]=src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2];
}

inline void glmc_mat3f_mul_dest(mat3f dest, mat3f src_b){ // dest *= src_a
	mat3f temp_dest;

	temp_dest[0][0]=dest[0][0];
	temp_dest[0][1]=dest[0][1];
	temp_dest[0][2]=dest[0][2];

	temp_dest[1][0]=dest[1][0];
	temp_dest[1][1]=dest[1][1];
	temp_dest[1][2]=dest[1][2];

	temp_dest[2][0]=dest[1][0];
	temp_dest[2][1]=dest[1][1];
	temp_dest[2][2]=dest[1][2];

	dest[0][0]=temp_dest[0][0]*src_b[0][0]+temp_dest[1][0]*src_b[0][1]+temp_dest[2][0]*src_b[0][2];
	dest[0][1]=temp_dest[0][1]*src_b[0][0]+temp_dest[1][1]*src_b[0][1]+temp_dest[2][1]*src_b[0][2];
	dest[0][2]=temp_dest[0][2]*src_b[0][0]+temp_dest[1][2]*src_b[0][1]+temp_dest[2][2]*src_b[0][2];

	dest[1][0]=temp_dest[0][0]*src_b[1][0]+temp_dest[1][0]*src_b[1][1]+temp_dest[2][0]*src_b[1][2];
	dest[1][1]=temp_dest[0][1]*src_b[1][0]+temp_dest[1][1]*src_b[1][1]+temp_dest[2][1]*src_b[1][2];
	dest[1][2]=temp_dest[0][2]*src_b[1][0]+temp_dest[1][2]*src_b[1][1]+temp_dest[2][2]*src_b[1][2];

	dest[2][0]=temp_dest[0][0]*src_b[2][0]+temp_dest[1][0]*src_b[2][1]+temp_dest[2][0]*src_b[2][2];
	dest[2][1]=temp_dest[0][1]*src_b[2][0]+temp_dest[1][1]*src_b[2][1]+temp_dest[2][1]*src_b[2][2];
	dest[2][2]=temp_dest[0][2]*src_b[2][0]+temp_dest[1][2]*src_b[2][1]+temp_dest[2][2]*src_b[2][2];
}

inline void glmc_mat3f_mul_s(mat3f dest, mat3f src_a, float src_b){// dest = src_a * scalar
	dest[0][0]=dest[0][0]*src_b;
	dest[0][1]=dest[0][1]*src_b;
	dest[0][2]=dest[0][2]*src_b;

	dest[1][0]=dest[1][0]*src_b;
	dest[1][1]=dest[1][1]*src_b;
	dest[1][2]=dest[1][2]*src_b;

	dest[2][0]=dest[2][0]*src_b;
	dest[2][1]=dest[2][1]*src_b;
	dest[2][2]=dest[2][2]*src_b;
}

inline void glmc_mat3f_div(mat3f dest, mat3f src_a, mat3f src_b){ // dest = src_a / src_b
	mat3f inv;
	glmc_mat3f_inverse(inv, src_b);

	dest[0][0]=src_a[0][0]*inv[0][0]+src_a[1][0]*inv[0][1]+src_a[2][0]*inv[0][2];
	dest[0][1]=src_a[0][1]*inv[0][0]+src_a[1][1]*inv[0][1]+src_a[2][1]*inv[0][2];
	dest[0][2]=src_a[0][2]*inv[0][0]+src_a[1][2]*inv[0][1]+src_a[2][2]*inv[0][2];

	dest[1][0]=src_a[0][0]*inv[1][0]+src_a[1][0]*inv[1][1]+src_a[2][0]*inv[1][2];
	dest[1][1]=src_a[0][1]*inv[1][0]+src_a[1][1]*inv[1][1]+src_a[2][1]*inv[1][2];
	dest[1][2]=src_a[0][2]*inv[1][0]+src_a[1][2]*inv[1][1]+src_a[2][2]*inv[1][2];

	dest[2][0]=src_a[0][0]*inv[2][0]+src_a[1][0]*inv[2][1]+src_a[2][0]*inv[2][2];
	dest[2][1]=src_a[0][1]*inv[2][0]+src_a[1][1]*inv[2][1]+src_a[2][1]*inv[2][2];
	dest[2][2]=src_a[0][2]*inv[2][0]+src_a[1][2]*inv[2][1]+src_a[2][2]*inv[2][2];
}

inline void glmc_mat3f_div_dest(mat3f dest, mat3f src_b){ // dest /= src_a
	mat3f temp_dest;
	mat3f inv;
	glmc_mat3f_inverse(inv, src_b);

	temp_dest[0][0]=dest[0][0];
	temp_dest[0][1]=dest[0][1];
	temp_dest[0][2]=dest[0][2];

	temp_dest[1][0]=dest[1][0];
	temp_dest[1][1]=dest[1][1];
	temp_dest[1][2]=dest[1][2];

	temp_dest[2][0]=dest[1][0];
	temp_dest[2][1]=dest[1][1];
	temp_dest[2][2]=dest[1][2];

	dest[0][0]=temp_dest[0][0]*inv[0][0]+temp_dest[1][0]*inv[0][1]+temp_dest[2][0]*inv[0][2];
	dest[0][1]=temp_dest[0][1]*inv[0][0]+temp_dest[1][1]*inv[0][1]+temp_dest[2][1]*inv[0][2];
	dest[0][2]=temp_dest[0][2]*inv[0][0]+temp_dest[1][2]*inv[0][1]+temp_dest[2][2]*inv[0][2];

	dest[1][0]=temp_dest[0][0]*inv[1][0]+temp_dest[1][0]*inv[1][1]+temp_dest[2][0]*inv[1][2];
	dest[1][1]=temp_dest[0][1]*inv[1][0]+temp_dest[1][1]*inv[1][1]+temp_dest[2][1]*inv[1][2];
	dest[1][2]=temp_dest[0][2]*inv[1][0]+temp_dest[1][2]*inv[1][1]+temp_dest[2][2]*inv[1][2];

	dest[2][0]=temp_dest[0][0]*inv[2][0]+temp_dest[1][0]*inv[2][1]+temp_dest[2][0]*inv[2][2];
	dest[2][1]=temp_dest[0][1]*inv[2][0]+temp_dest[1][1]*inv[2][1]+temp_dest[2][1]*inv[2][2];
	dest[2][2]=temp_dest[0][2]*inv[2][0]+temp_dest[1][2]*inv[2][1]+temp_dest[2][2]*inv[2][2];
}

inline void glmc_mat3f_div_s(mat3f dest, mat3f src_a, float src_b){// dest = src_a / scalar
	dest[0][0]=dest[0][0]/src_b;
	dest[0][1]=dest[0][1]/src_b;
	dest[0][2]=dest[0][2]/src_b;

	dest[1][0]=dest[1][0]/src_b;
	dest[1][1]=dest[1][1]/src_b;
	dest[1][2]=dest[1][2]/src_b;

	dest[2][0]=dest[2][0]/src_b;
	dest[2][1]=dest[2][1]/src_b;
	dest[2][2]=dest[2][2]/src_b;
}

inline void glmc_mat3f_addadd(mat3f dest, mat3f src_a, mat3f src_b){// dest += src_a + src_b
	dest[0][0]=dest[0][0]+src_a[0][0]+src_b[0][0];
	dest[0][1]=dest[0][1]+src_a[0][1]+src_b[0][1];
	dest[0][2]=dest[0][2]+src_a[0][2]+src_b[0][2];

	dest[1][0]=dest[1][0]+src_a[1][0]+src_b[1][0];
	dest[1][1]=dest[1][1]+src_a[1][1]+src_b[1][1];
	dest[1][2]=dest[1][2]+src_a[1][2]+src_b[1][2];

	dest[2][0]=dest[2][0]+src_a[2][0]+src_b[2][0];
	dest[2][1]=dest[2][1]+src_a[2][1]+src_b[2][1];
	dest[2][2]=dest[2][2]+src_a[2][2]+src_b[2][2];
}

inline void glmc_mat3f_subadd(mat3f dest, mat3f src_a, mat3f src_b){// dest += src_a - src_b
	dest[0][0]=dest[0][0]+src_a[0][0]-src_b[0][0];
	dest[0][1]=dest[0][1]+src_a[0][1]-src_b[0][1];
	dest[0][2]=dest[0][2]+src_a[0][2]-src_b[0][2];

	dest[1][0]=dest[1][0]+src_a[1][0]-src_b[1][0];
	dest[1][1]=dest[1][1]+src_a[1][1]-src_b[1][1];
	dest[1][2]=dest[1][2]+src_a[1][2]-src_b[1][2];

	dest[2][0]=dest[2][0]+src_a[2][0]-src_b[2][0];
	dest[2][1]=dest[2][1]+src_a[2][1]-src_b[2][1];
	dest[2][2]=dest[2][2]+src_a[2][2]-src_b[2][2];
}

inline void glmc_mat3f_madd(mat3f dest, mat3f src_a, mat3f src_b){ // dest += src_a * src_b
	dest[0][0]=dest[0][0]+src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1]+src_a[2][0]*src_b[0][2];
	dest[0][1]=dest[0][1]+src_a[0][1]*src_b[0][0]+src_a[1][1]*src_b[0][1]+src_a[2][1]*src_b[0][2];
	dest[0][2]=dest[0][2]+src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2];

	dest[1][0]=dest[1][0]+src_a[0][0]*src_b[1][0]+src_a[1][0]*src_b[1][1]+src_a[2][0]*src_b[1][2];
	dest[1][1]=dest[1][1]+src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1]+src_a[2][1]*src_b[1][2];
	dest[1][2]=dest[1][2]+src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2];

	dest[2][0]=dest[2][0]+src_a[0][0]*src_b[2][0]+src_a[1][0]*src_b[2][1]+src_a[2][0]*src_b[2][2];
	dest[2][1]=dest[2][1]+src_a[0][1]*src_b[2][0]+src_a[1][1]*src_b[2][1]+src_a[2][1]*src_b[2][2];
	dest[2][2]=dest[2][2]+src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2];
}

inline void glmc_mat3f_msub(mat3f dest, mat3f src_a, mat3f src_b){// dest -= src_a * src_b
	dest[0][0]=dest[0][0]-src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1]+src_a[2][0]*src_b[0][2];
	dest[0][1]=dest[0][1]-src_a[0][1]*src_b[0][0]+src_a[1][1]*src_b[0][1]+src_a[2][1]*src_b[0][2];
	dest[0][2]=dest[0][2]-src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2];

	dest[1][0]=dest[1][0]-src_a[0][0]*src_b[1][0]+src_a[1][0]*src_b[1][1]+src_a[2][0]*src_b[1][2];
	dest[1][1]=dest[1][1]-src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1]+src_a[2][1]*src_b[1][2];
	dest[1][2]=dest[1][2]-src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2];

	dest[2][0]=dest[2][0]-src_a[0][0]*src_b[2][0]+src_a[1][0]*src_b[2][1]+src_a[2][0]*src_b[2][2];
	dest[2][1]=dest[2][1]-src_a[0][1]*src_b[2][0]+src_a[1][1]*src_b[2][1]+src_a[2][1]*src_b[2][2];
	dest[2][2]=dest[2][2]-src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2];
}

