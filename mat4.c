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

float glmc_mat4f_discriminant(mat4f src_a){ //Calculates discriminant of matrix

	return src_a[0][0]*(src_a[1][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])+src_a[3][1]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3]))
		  
		  -src_a[1][0]*(src_a[0][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3]))
	      
	      +src_a[2][0]*(src_a[0][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])-src_a[1][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]))
	      
	      -src_a[3][0]*(src_a[0][1]*(src_a[1][2]*src_a[2][3]-src_a[1][3]*src_a[2][2])-src_a[1][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3])+src_a[2][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]));

}
	
inline void glmc_mat4f_inverse(mat4f dest, mat4f src_a){ //Calculates inverse of matrix
	mat4f cof;
	cof[0][0]=src_a[1][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])+src_a[3][1]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3]);
	cof[1][0]=-(src_a[0][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3]));
	cof[2][0]=src_a[0][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])-src_a[1][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]);
	cof[3][0]=-(src_a[0][1]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3])-src_a[1][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3])+src_a[2][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]));

	cof[0][1]=-(src_a[1][0]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][0]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])+src_a[3][0]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3]));
	cof[1][1]=+src_a[0][0]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][0]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][0]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3]);
	cof[2][1]=-(src_a[0][0]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])-src_a[1][0]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][0]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]));
	cof[3][1]=src_a[0][0]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3])-src_a[1][0]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3])+src_a[2][0]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]);

	
	cof[0][2]=src_a[1][0]*(src_a[2][1]*src_a[3][3]-src_a[3][1]*src_a[2][3])-src_a[2][0]*(src_a[1][1]*src_a[3][3]-src_a[3][1]*src_a[1][3])+src_a[3][0]*(src_a[1][1]*src_a[2][3]-src_a[2][1]*src_a[1][3]);
	cof[1][2]=-(src_a[0][0]*(src_a[2][1]*src_a[3][3]-src_a[3][1]*src_a[2][3])-src_a[2][0]*(src_a[0][1]*src_a[3][3]-src_a[3][1]*src_a[0][3])+src_a[3][0]*(src_a[0][1]*src_a[2][3]-src_a[2][1]*src_a[0][3]));
	cof[2][2]=src_a[0][0]*(src_a[1][1]*src_a[3][3]-src_a[3][1]*src_a[1][3])-src_a[1][0]*(src_a[0][1]*src_a[3][3]-src_a[3][1]*src_a[0][3])+src_a[3][0]*(src_a[0][1]*src_a[1][3]-src_a[1][1]*src_a[0][3]);
	cof[3][2]=-(src_a[0][0]*(src_a[1][1]*src_a[2][3]-src_a[2][1]*src_a[1][3])-src_a[1][0]*(src_a[0][1]*src_a[2][3]-src_a[2][1]*src_a[0][3])+src_a[2][0]*(src_a[0][1]*src_a[1][3]-src_a[1][1]*src_a[0][3]));

	cof[0][3]=-(src_a[1][0]*(src_a[2][1]*src_a[3][2]-src_a[3][1]*src_a[2][2])-src_a[2][0]*(src_a[1][1]*src_a[3][2]-src_a[3][1]*src_a[1][2])+src_a[3][0]*(src_a[1][1]*src_a[2][2]-src_a[2][1]*src_a[1][2]));
	cof[1][3]=src_a[0][0]*(src_a[2][1]*src_a[3][2]-src_a[3][1]*src_a[2][2])-src_a[2][0]*(src_a[0][1]*src_a[3][2]-src_a[3][1]*src_a[0][2])+src_a[3][0]*(src_a[0][1]*src_a[2][2]-src_a[2][1]*src_a[0][2]);
	cof[2][3]=-(src_a[0][0]*(src_a[1][1]*src_a[3][2]-src_a[3][1]*src_a[1][2])-src_a[1][0]*(src_a[0][1]*src_a[3][2]-src_a[3][1]*src_a[0][2])+src_a[3][0]*(src_a[0][1]*src_a[1][2]-src_a[1][1]*src_a[0][2]));
	cof[3][3]=src_a[0][0]*(src_a[1][1]*src_a[2][2]-src_a[2][1]*src_a[1][2])-src_a[1][0]*(src_a[0][1]*src_a[2][2]-src_a[2][1]*src_a[0][2])+src_a[2][0]*(src_a[0][1]*src_a[1][2]-src_a[1][1]*src_a[0][2]);

	glmc_mat4f_transpose(dest, cof);
	float discr=glmc_mat4f_discriminant(src_a);

	dest[0][0]=dest[0][0]/discr;
	dest[0][1]=dest[0][1]/discr;
	dest[0][2]=dest[0][2]/discr;
	dest[0][3]=dest[0][3]/discr;

	dest[1][0]=dest[1][0]/discr;
	dest[1][1]=dest[1][1]/discr;
	dest[1][2]=dest[1][2]/discr;
	dest[1][3]=dest[1][3]/discr;

	dest[2][0]=dest[2][0]/discr;
	dest[2][1]=dest[2][1]/discr;
	dest[2][2]=dest[2][2]/discr;
	dest[2][3]=dest[2][3]/discr;

	dest[3][0]=dest[3][0]/discr;
	dest[3][1]=dest[3][1]/discr;
	dest[3][2]=dest[3][2]/discr;
	dest[3][3]=dest[3][3]/discr;

}
inline void glmc_mat4f_transpose(mat4f dest, mat4f src_a){ //Transposes matrix
	dest[0][0]=src_a[0][0];
	dest[0][1]=src_a[1][0];
	dest[0][2]=src_a[2][0];
	dest[0][3]=src_a[3][0];

	dest[1][0]=src_a[0][1];
	dest[1][1]=src_a[1][1];
	dest[1][2]=src_a[2][1];
	dest[1][3]=src_a[3][1];

	dest[2][0]=src_a[0][2];
	dest[2][1]=src_a[1][2];
	dest[2][2]=src_a[2][2];
	dest[2][3]=src_a[3][2];

	dest[3][0]=src_a[0][3];
	dest[3][1]=src_a[1][3];
	dest[3][2]=src_a[2][3];
	dest[3][3]=src_a[3][3];
}

inline void glmc_mat4f_transpose_dest(mat4f src_a){//Transposes matrix inplace
	float temp=src_a[1][0];
	src_a[1][0]=src_a[0][1];
	src_a[0][1]=temp;

	temp=src_a[2][0];
	src_a[2][0]=src_a[0][2];
	src_a[0][2]=temp;

	temp=src_a[3][0];
	src_a[3][0]=src_a[0][3];
	src_a[0][3]=temp;

	temp=src_a[1][2];
	src_a[1][2]=src_a[2][1];
	src_a[2][1]=temp;

	temp=src_a[1][3];
	src_a[1][3]=src_a[3][1];
	src_a[3][1]=temp;


	temp=src_a[2][3];
	src_a[2][3]=src_a[3][2];
	src_a[3][2]=temp;

}

inline int  glmc_mat4f_is_normalized(mat4f src){//Checks if matrix is normalized
		if(glmc_mat4f_discriminant(src)==1)
			return 1;
		else
			return 0;
}

inline void glmc_mat4f_normlize(mat4f dest, mat4f src){//Normalize matrix
	
	float discr=glmc_mat4f_discriminant(src);
	
	dest[0][0]=src[0][0]/discr;
	dest[0][1]=src[0][1]/discr;
	dest[0][2]=src[0][2]/discr;
	dest[0][3]=src[0][3]/discr;

	dest[1][0]=src[1][0]/discr;
	dest[1][1]=src[1][1]/discr;
	dest[1][2]=src[1][2]/discr;
	dest[1][3]=src[1][3]/discr;

	dest[2][0]=src[2][0]/discr;
	dest[2][1]=src[2][1]/discr;
	dest[2][2]=src[2][2]/discr;
	dest[2][3]=src[2][3]/discr;

	dest[3][0]=src[3][0]/discr;
	dest[3][1]=src[3][1]/discr;
	dest[3][2]=src[3][2]/discr;
	dest[3][3]=src[3][3]/discr;
}

inline void glmc_mat4f_normlize_dest(mat4f src){//Normalize matrix inplace

	float discr=glmc_mat4f_discriminant(src);

	src[0][0]=src[0][0]/discr;
	src[0][1]=src[0][1]/discr;
	src[0][2]=src[0][2]/discr;
	src[0][3]=src[0][3]/discr;

	src[1][0]=src[1][0]/discr;
	src[1][1]=src[1][1]/discr;
	src[1][2]=src[1][2]/discr;
	src[1][3]=src[1][3]/discr;

	src[2][0]=src[2][0]/discr;
	src[2][1]=src[2][1]/discr;
	src[2][2]=src[2][2]/discr;
	src[2][3]=src[2][3]/discr;

	src[3][0]=src[3][0]/discr;
	src[3][1]=src[3][1]/discr;
	src[3][2]=src[3][2]/discr;
	src[3][3]=src[3][3]/discr;
}

inline void glmc_mat4f_add(mat4f dest, mat4f src_a, mat4f src_b){ // dest = src_a + src_b
	dest[0][0]=src_a[0][0]+src_b[0][0];
	dest[0][1]=src_a[0][1]+src_b[0][1];
	dest[0][2]=src_a[0][2]+src_b[0][2];
	dest[0][3]=src_a[0][3]+src_b[0][3];

	dest[1][0]=src_a[1][0]+src_b[1][0];
	dest[1][1]=src_a[1][1]+src_b[1][1];
	dest[1][2]=src_a[1][2]+src_b[1][2];
	dest[1][3]=src_a[1][3]+src_b[1][3];

	dest[2][0]=src_a[2][0]+src_b[2][0];
	dest[2][1]=src_a[2][1]+src_b[2][1];
	dest[2][2]=src_a[2][2]+src_b[2][2];
	dest[2][3]=src_a[2][3]+src_b[2][3];

	dest[3][0]=src_a[3][0]+src_b[3][0];
	dest[3][1]=src_a[3][1]+src_b[3][1];
	dest[3][2]=src_a[3][2]+src_b[3][2];
	dest[3][3]=src_a[3][3]+src_b[3][3];
}

inline void glmc_mat4f_add_dest(mat4f dest, mat4f src_b){// dest += src_a
	dest[0][0]=dest[0][0]+src_b[0][0];
	dest[0][1]=dest[0][1]+src_b[0][1];
	dest[0][2]=dest[0][2]+src_b[0][2];
	dest[0][3]=dest[0][3]+src_b[0][3];

	dest[1][0]=dest[1][0]+src_b[1][0];
	dest[1][1]=dest[1][1]+src_b[1][1];
	dest[1][2]=dest[1][2]+src_b[1][2];
	dest[1][3]=dest[1][3]+src_b[1][3];

	dest[2][0]=dest[2][0]+src_b[2][0];
	dest[2][1]=dest[2][1]+src_b[2][1];
	dest[2][2]=dest[2][2]+src_b[2][2];
	dest[2][3]=dest[2][3]+src_b[2][3];

	dest[3][0]=dest[3][0]+src_b[3][0];
	dest[3][1]=dest[3][1]+src_b[3][1];
	dest[3][2]=dest[3][2]+src_b[3][2];
	dest[3][3]=dest[3][3]+src_b[3][3];
}



inline void glmc_mat4f_sub(mat4f dest, mat4f src_a, mat4f src_b){ // dest = src_a - src_b
	dest[0][0]=src_a[0][0]-src_b[0][0];
	dest[0][1]=src_a[0][1]-src_b[0][1];
	dest[0][2]=src_a[0][2]-src_b[0][2];
	dest[0][3]=src_a[0][3]-src_b[0][3];

	dest[1][0]=src_a[1][0]-src_b[1][0];
	dest[1][1]=src_a[1][1]-src_b[1][1];
	dest[1][2]=src_a[1][2]-src_b[1][2];
	dest[1][3]=src_a[1][3]-src_b[1][3];

	dest[2][0]=src_a[2][0]-src_b[2][0];
	dest[2][1]=src_a[2][1]-src_b[2][1];
	dest[2][2]=src_a[2][2]-src_b[2][2];
	dest[2][3]=src_a[2][3]-src_b[2][3];

	dest[3][0]=src_a[3][0]-src_b[3][0];
	dest[3][1]=src_a[3][1]-src_b[3][1];
	dest[3][2]=src_a[3][2]-src_b[3][2];
	dest[3][3]=src_a[3][3]-src_b[3][3];
}

inline void glmc_mat4f_sub_dest(mat4f dest, mat4f src_b){// dest -= src_a
	dest[0][0]=dest[0][0]-src_b[0][0];
	dest[0][1]=dest[0][1]-src_b[0][1];
	dest[0][2]=dest[0][2]-src_b[0][2];
	dest[0][3]=dest[0][3]-src_b[0][3];

	dest[1][0]=dest[1][0]-src_b[1][0];
	dest[1][1]=dest[1][1]-src_b[1][1];
	dest[1][2]=dest[1][2]-src_b[1][2];
	dest[1][3]=dest[1][3]-src_b[1][3];

	dest[2][0]=dest[2][0]-src_b[2][0];
	dest[2][1]=dest[2][1]-src_b[2][1];
	dest[2][2]=dest[2][2]-src_b[2][2];
	dest[2][3]=dest[2][3]-src_b[2][3];

	dest[3][0]=dest[3][0]-src_b[3][0];
	dest[3][1]=dest[3][1]-src_b[3][1];
	dest[3][2]=dest[3][2]-src_b[3][2];
	dest[3][3]=dest[3][3]-src_b[3][3];
}

inline void glmc_mat4f_mul(mat4f dest, mat4f src_a, mat4f src_b){// dest = src_a * src_b

	dest[0][0]=src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1]+src_a[2][0]*src_b[0][2]+src_a[3][0]*src_b[0][3];
	dest[1][0]=src_a[0][0]*src_b[1][0]+src_a[1][0]*src_b[1][1]+src_a[2][0]*src_b[1][2]+src_a[3][0]*src_b[1][3];
	dest[2][0]=src_a[0][0]*src_b[2][0]+src_a[1][0]*src_b[2][1]+src_a[2][0]*src_b[2][2]+src_a[3][0]*src_b[2][3];
	dest[3][0]=src_a[0][0]*src_b[3][0]+src_a[1][0]*src_b[3][1]+src_a[2][0]*src_b[3][2]+src_a[3][0]*src_b[3][3];

	dest[0][1]=src_a[0][1]*src_b[0][0]+src_a[1][1]*src_b[0][1]+src_a[2][1]*src_b[0][2]+src_a[3][1]*src_b[0][3];
	dest[1][1]=src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1]+src_a[2][1]*src_b[1][2]+src_a[3][1]*src_b[1][3];
	dest[2][1]=src_a[0][1]*src_b[2][0]+src_a[1][1]*src_b[2][1]+src_a[2][1]*src_b[2][2]+src_a[3][1]*src_b[2][3];
	dest[3][1]=src_a[0][1]*src_b[3][0]+src_a[1][1]*src_b[3][1]+src_a[2][1]*src_b[3][2]+src_a[3][1]*src_b[3][3];

	dest[0][2]=src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2]+src_a[3][2]*src_b[0][3];
	dest[1][2]=src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2]+src_a[3][2]*src_b[1][3];
	dest[2][2]=src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2]+src_a[3][2]*src_b[2][3];
	dest[3][2]=src_a[0][2]*src_b[3][0]+src_a[1][2]*src_b[3][1]+src_a[2][2]*src_b[3][2]+src_a[3][2]*src_b[3][3];

	dest[0][3]=src_a[0][3]*src_b[0][0]+src_a[1][3]*src_b[0][1]+src_a[2][3]*src_b[0][2]+src_a[3][3]*src_b[0][3];
	dest[1][3]=src_a[0][3]*src_b[1][0]+src_a[1][3]*src_b[1][1]+src_a[2][3]*src_b[1][2]+src_a[3][3]*src_b[1][3];
	dest[2][3]=src_a[0][3]*src_b[2][0]+src_a[1][3]*src_b[2][1]+src_a[2][3]*src_b[2][2]+src_a[3][3]*src_b[2][3];
	dest[3][3]=src_a[0][3]*src_b[3][0]+src_a[1][3]*src_b[3][1]+src_a[2][3]*src_b[3][2]+src_a[3][3]*src_b[3][3];

}

inline void glmc_mat4f_mul_dest(mat4f dest, mat4f src_b){// dest *= src_a

	mat4f temp_dest;

	temp_dest[0][0]=dest[0][0];
	temp_dest[1][0]=dest[1][0];
	temp_dest[2][0]=dest[2][0];
	temp_dest[3][0]=dest[3][0];

	temp_dest[0][1]=dest[0][1];
	temp_dest[1][1]=dest[1][1];
	temp_dest[2][1]=dest[2][1];
	temp_dest[3][1]=dest[3][1];

	temp_dest[0][2]=dest[0][2];
	temp_dest[1][2]=dest[1][2];
	temp_dest[2][2]=dest[2][2];
	temp_dest[3][2]=dest[3][2];

	temp_dest[0][3]=dest[0][3];
	temp_dest[1][3]=dest[1][3];
	temp_dest[2][3]=dest[2][3];
	temp_dest[3][3]=dest[3][3];

	dest[0][0]=temp_dest[0][0]*src_b[0][0]+temp_dest[1][0]*src_b[0][1]+temp_dest[2][0]*src_b[0][2]+temp_dest[3][0]*src_b[0][3];
	dest[1][0]=temp_dest[0][0]*src_b[1][0]+temp_dest[1][0]*src_b[1][1]+temp_dest[2][0]*src_b[1][2]+temp_dest[3][0]*src_b[1][3];
	dest[2][0]=temp_dest[0][0]*src_b[2][0]+temp_dest[1][0]*src_b[2][1]+temp_dest[2][0]*src_b[2][2]+temp_dest[3][0]*src_b[2][3];
	dest[3][0]=temp_dest[0][0]*src_b[3][0]+temp_dest[1][0]*src_b[3][1]+temp_dest[2][0]*src_b[3][2]+temp_dest[3][0]*src_b[3][3];

	dest[0][1]=temp_dest[0][1]*src_b[0][0]+temp_dest[1][1]*src_b[0][1]+temp_dest[2][1]*src_b[0][2]+temp_dest[3][1]*src_b[0][3];
	dest[1][1]=temp_dest[0][1]*src_b[1][0]+temp_dest[1][1]*src_b[1][1]+temp_dest[2][1]*src_b[1][2]+temp_dest[3][1]*src_b[1][3];
	dest[2][1]=temp_dest[0][1]*src_b[2][0]+temp_dest[1][1]*src_b[2][1]+temp_dest[2][1]*src_b[2][2]+temp_dest[3][1]*src_b[2][3];
	dest[3][1]=temp_dest[0][1]*src_b[3][0]+temp_dest[1][1]*src_b[3][1]+temp_dest[2][1]*src_b[3][2]+temp_dest[3][1]*src_b[3][3];

	dest[0][2]=temp_dest[0][2]*src_b[0][0]+temp_dest[1][2]*src_b[0][1]+temp_dest[2][2]*src_b[0][2]+temp_dest[3][2]*src_b[0][3];
	dest[1][2]=temp_dest[0][2]*src_b[1][0]+temp_dest[1][2]*src_b[1][1]+temp_dest[2][2]*src_b[1][2]+temp_dest[3][2]*src_b[1][3];
	dest[2][2]=temp_dest[0][2]*src_b[2][0]+temp_dest[1][2]*src_b[2][1]+temp_dest[2][2]*src_b[2][2]+temp_dest[3][2]*src_b[2][3];
	dest[3][2]=temp_dest[0][2]*src_b[3][0]+temp_dest[1][2]*src_b[3][1]+temp_dest[2][2]*src_b[3][2]+temp_dest[3][2]*src_b[3][3];

	dest[0][3]=temp_dest[0][3]*src_b[0][0]+temp_dest[1][3]*src_b[0][1]+temp_dest[2][3]*src_b[0][2]+temp_dest[3][3]*src_b[0][3];
	dest[1][3]=temp_dest[0][3]*src_b[1][0]+temp_dest[1][3]*src_b[1][1]+temp_dest[2][3]*src_b[1][2]+temp_dest[3][3]*src_b[1][3];
	dest[2][3]=temp_dest[0][3]*src_b[2][0]+temp_dest[1][3]*src_b[2][1]+temp_dest[2][3]*src_b[2][2]+temp_dest[3][3]*src_b[2][3];
	dest[3][3]=temp_dest[0][3]*src_b[3][0]+temp_dest[1][3]*src_b[3][1]+temp_dest[2][3]*src_b[3][2]+temp_dest[3][3]*src_b[3][3];

}

inline void glmc_mat4f_mul_s(mat4f dest, mat4f src_a, float src_b){ // dest = src_a * scalar
	dest[0][0]=src_a[0][0]*src_b;
	dest[0][1]=src_a[0][1]*src_b;
	dest[0][2]=src_a[0][2]*src_b;
	dest[0][3]=src_a[0][3]*src_b;

	dest[1][0]=src_a[1][0]*src_b;
	dest[1][1]=src_a[1][1]*src_b;
	dest[1][2]=src_a[1][2]*src_b;
	dest[1][3]=src_a[1][3]*src_b;

	dest[2][0]=src_a[2][0]*src_b;
	dest[2][1]=src_a[2][1]*src_b;
	dest[2][2]=src_a[2][2]*src_b;
	dest[2][3]=src_a[2][3]*src_b;

	dest[3][0]=src_a[3][0]*src_b;
	dest[3][1]=src_a[3][1]*src_b;
	dest[3][2]=src_a[3][2]*src_b;
	dest[3][3]=src_a[3][3]*src_b;
}

inline void glmc_mat4f_div(mat4f dest, mat4f src_a, mat4f src_b){// dest = src_a / src_b
	mat4f inv;
	glmc_mat4f_inverse(inv, src_b);

	dest[0][0]=src_a[0][0]*inv[0][0]+src_a[1][0]*inv[0][1]+src_a[2][0]*inv[0][2]+src_a[3][0]*inv[0][3];
	dest[1][0]=src_a[0][0]*inv[1][0]+src_a[1][0]*inv[1][1]+src_a[2][0]*inv[1][2]+src_a[3][0]*inv[1][3];
	dest[2][0]=src_a[0][0]*inv[2][0]+src_a[1][0]*inv[2][1]+src_a[2][0]*inv[2][2]+src_a[3][0]*inv[2][3];
	dest[3][0]=src_a[0][0]*inv[3][0]+src_a[1][0]*inv[3][1]+src_a[2][0]*inv[3][2]+src_a[3][0]*inv[3][3];

	dest[0][1]=src_a[0][1]*inv[0][0]+src_a[1][1]*inv[0][1]+src_a[2][1]*inv[0][2]+src_a[3][1]*inv[0][3];
	dest[1][1]=src_a[0][1]*inv[1][0]+src_a[1][1]*inv[1][1]+src_a[2][1]*inv[1][2]+src_a[3][1]*inv[1][3];
	dest[2][1]=src_a[0][1]*inv[2][0]+src_a[1][1]*inv[2][1]+src_a[2][1]*inv[2][2]+src_a[3][1]*inv[2][3];
	dest[3][1]=src_a[0][1]*inv[3][0]+src_a[1][1]*inv[3][1]+src_a[2][1]*inv[3][2]+src_a[3][1]*inv[3][3];

	dest[0][2]=src_a[0][2]*inv[0][0]+src_a[1][2]*inv[0][1]+src_a[2][2]*inv[0][2]+src_a[3][2]*inv[0][3];
	dest[1][2]=src_a[0][2]*inv[1][0]+src_a[1][2]*inv[1][1]+src_a[2][2]*inv[1][2]+src_a[3][2]*inv[1][3];
	dest[2][2]=src_a[0][2]*inv[2][0]+src_a[1][2]*inv[2][1]+src_a[2][2]*inv[2][2]+src_a[3][2]*inv[2][3];
	dest[3][2]=src_a[0][2]*inv[3][0]+src_a[1][2]*inv[3][1]+src_a[2][2]*inv[3][2]+src_a[3][2]*inv[3][3];

	dest[0][3]=src_a[0][3]*inv[0][0]+src_a[1][3]*inv[0][1]+src_a[2][3]*inv[0][2]+src_a[3][3]*inv[0][3];
	dest[1][3]=src_a[0][3]*inv[1][0]+src_a[1][3]*inv[1][1]+src_a[2][3]*inv[1][2]+src_a[3][3]*inv[1][3];
	dest[2][3]=src_a[0][3]*inv[2][0]+src_a[1][3]*inv[2][1]+src_a[2][3]*inv[2][2]+src_a[3][3]*inv[2][3];
	dest[3][3]=src_a[0][3]*inv[3][0]+src_a[1][3]*inv[3][1]+src_a[2][3]*inv[3][2]+src_a[3][3]*inv[3][3];	
}

inline void glmc_mat4f_div_dest(mat4f dest, mat4f src_b){ // dest /= src_a
	mat4f temp_dest;
	mat4f inv;
	glmc_mat4f_inverse(inv, src_b);

	temp_dest[0][0]=dest[0][0];
	temp_dest[1][0]=dest[1][0];
	temp_dest[2][0]=dest[2][0];
	temp_dest[3][0]=dest[3][0];

	temp_dest[0][1]=dest[0][1];
	temp_dest[1][1]=dest[1][1];
	temp_dest[2][1]=dest[2][1];
	temp_dest[3][1]=dest[3][1];

	temp_dest[0][2]=dest[0][2];
	temp_dest[1][2]=dest[1][2];
	temp_dest[2][2]=dest[2][2];
	temp_dest[3][2]=dest[3][2];

	temp_dest[0][3]=dest[0][3];
	temp_dest[1][3]=dest[1][3];
	temp_dest[2][3]=dest[2][3];
	temp_dest[3][3]=dest[3][3];

	dest[0][0]=temp_dest[0][0]*inv[0][0]+temp_dest[1][0]*inv[0][1]+temp_dest[2][0]*inv[0][2]+temp_dest[3][0]*inv[0][3];
	dest[1][0]=temp_dest[0][0]*inv[1][0]+temp_dest[1][0]*inv[1][1]+temp_dest[2][0]*inv[1][2]+temp_dest[3][0]*inv[1][3];
	dest[2][0]=temp_dest[0][0]*inv[2][0]+temp_dest[1][0]*inv[2][1]+temp_dest[2][0]*inv[2][2]+temp_dest[3][0]*inv[2][3];
	dest[3][0]=temp_dest[0][0]*inv[3][0]+temp_dest[1][0]*inv[3][1]+temp_dest[2][0]*inv[3][2]+temp_dest[3][0]*inv[3][3];

	dest[0][1]=temp_dest[0][1]*inv[0][0]+temp_dest[1][1]*inv[0][1]+temp_dest[2][1]*inv[0][2]+temp_dest[3][1]*inv[0][3];
	dest[1][1]=temp_dest[0][1]*inv[1][0]+temp_dest[1][1]*inv[1][1]+temp_dest[2][1]*inv[1][2]+temp_dest[3][1]*inv[1][3];
	dest[2][1]=temp_dest[0][1]*inv[2][0]+temp_dest[1][1]*inv[2][1]+temp_dest[2][1]*inv[2][2]+temp_dest[3][1]*inv[2][3];
	dest[3][1]=temp_dest[0][1]*inv[3][0]+temp_dest[1][1]*inv[3][1]+temp_dest[2][1]*inv[3][2]+temp_dest[3][1]*inv[3][3];

	dest[0][2]=temp_dest[0][2]*inv[0][0]+temp_dest[1][2]*inv[0][1]+temp_dest[2][2]*inv[0][2]+temp_dest[3][2]*inv[0][3];
	dest[1][2]=temp_dest[0][2]*inv[1][0]+temp_dest[1][2]*inv[1][1]+temp_dest[2][2]*inv[1][2]+temp_dest[3][2]*inv[1][3];
	dest[2][2]=temp_dest[0][2]*inv[2][0]+temp_dest[1][2]*inv[2][1]+temp_dest[2][2]*inv[2][2]+temp_dest[3][2]*inv[2][3];
	dest[3][2]=temp_dest[0][2]*inv[3][0]+temp_dest[1][2]*inv[3][1]+temp_dest[2][2]*inv[3][2]+temp_dest[3][2]*inv[3][3];

	dest[0][3]=temp_dest[0][3]*inv[0][0]+temp_dest[1][3]*inv[0][1]+temp_dest[2][3]*inv[0][2]+temp_dest[3][3]*inv[0][3];
	dest[1][3]=temp_dest[0][3]*inv[1][0]+temp_dest[1][3]*inv[1][1]+temp_dest[2][3]*inv[1][2]+temp_dest[3][3]*inv[1][3];
	dest[2][3]=temp_dest[0][3]*inv[2][0]+temp_dest[1][3]*inv[2][1]+temp_dest[2][3]*inv[2][2]+temp_dest[3][3]*inv[2][3];
	dest[3][3]=temp_dest[0][3]*inv[3][0]+temp_dest[1][3]*inv[3][1]+temp_dest[2][3]*inv[3][2]+temp_dest[3][3]*inv[3][3];

}

inline void glmc_mat4f_div_s(mat4f dest, mat4f src_a, float src_b){// dest = src_a / scalar
	dest[0][0]=src_a[0][0]/src_b;
	dest[0][1]=src_a[0][1]/src_b;
	dest[0][2]=src_a[0][2]/src_b;
	dest[0][3]=src_a[0][3]/src_b;

	dest[1][0]=src_a[1][0]/src_b;
	dest[1][1]=src_a[1][1]/src_b;
	dest[1][2]=src_a[1][2]/src_b;
	dest[1][3]=src_a[1][3]/src_b;

	dest[2][0]=src_a[2][0]/src_b;
	dest[2][1]=src_a[2][1]/src_b;
	dest[2][2]=src_a[2][2]/src_b;
	dest[2][3]=src_a[2][3]/src_b;

	dest[3][0]=src_a[3][0]/src_b;
	dest[3][1]=src_a[3][1]/src_b;
	dest[3][2]=src_a[3][2]/src_b;
	dest[3][3]=src_a[3][3]/src_b;
}

inline void glmc_mat4f_addadd(mat4f dest, mat4f src_a, mat4f src_b){// dest += src_a + src_b
	dest[0][0]=dest[0][0]+src_a[0][0]+src_b[0][0];
	dest[0][1]=dest[0][1]+src_a[0][1]+src_b[0][1];
	dest[0][2]=dest[0][2]+src_a[0][2]+src_b[0][2];
	dest[0][3]=dest[0][3]+src_a[0][3]+src_b[0][3];

	dest[1][0]=dest[1][0]+src_a[1][0]+src_b[1][0];
	dest[1][1]=dest[1][1]+src_a[1][1]+src_b[1][1];
	dest[1][2]=dest[1][2]+src_a[1][2]+src_b[1][2];
	dest[1][3]=dest[1][3]+src_a[1][3]+src_b[1][3];

	dest[2][0]=dest[2][0]+src_a[2][0]+src_b[2][0];
	dest[2][1]=dest[2][1]+src_a[2][1]+src_b[2][1];
	dest[2][2]=dest[2][2]+src_a[2][2]+src_b[2][2];
	dest[2][3]=dest[2][3]+src_a[2][3]+src_b[2][3];

	dest[3][0]=dest[3][0]+src_a[3][0]+src_b[3][0];
	dest[3][1]=dest[3][1]+src_a[3][1]+src_b[3][1];
	dest[3][2]=dest[3][2]+src_a[3][2]+src_b[3][2];
	dest[3][3]=dest[3][3]+src_a[3][3]+src_b[3][3];
}

inline void glmc_mat4f_subadd(mat4f dest, mat4f src_a, mat4f src_b){ // dest += src_a - src_b
	dest[0][0]=dest[0][0]+src_a[0][0]-src_b[0][0];
	dest[0][1]=dest[0][1]+src_a[0][1]-src_b[0][1];
	dest[0][2]=dest[0][2]+src_a[0][2]-src_b[0][2];
	dest[0][3]=dest[0][3]+src_a[0][3]-src_b[0][3];

	dest[1][0]=dest[1][0]+src_a[1][0]-src_b[1][0];
	dest[1][1]=dest[1][1]+src_a[1][1]-src_b[1][1];
	dest[1][2]=dest[1][2]+src_a[1][2]-src_b[1][2];
	dest[1][3]=dest[1][3]+src_a[1][3]-src_b[1][3];

	dest[2][0]=dest[2][0]+src_a[2][0]-src_b[2][0];
	dest[2][1]=dest[2][1]+src_a[2][1]-src_b[2][1];
	dest[2][2]=dest[2][2]+src_a[2][2]-src_b[2][2];
	dest[2][3]=dest[2][3]+src_a[2][3]-src_b[2][3];

	dest[3][0]=dest[3][0]+src_a[3][0]-src_b[3][0];
	dest[3][1]=dest[3][1]+src_a[3][1]-src_b[3][1];
	dest[3][2]=dest[3][2]+src_a[3][2]-src_b[3][2];
	dest[3][3]=dest[3][3]+src_a[3][3]-src_b[3][3];
}

inline void glmc_mat4f_madd(mat4f dest, mat4f src_a, mat4f src_b){// dest += src_a * src_b
	
	dest[0][0]=dest[0][0]+src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1]+src_a[2][0]*src_b[0][2]+src_a[3][0]*src_b[0][3];
	dest[1][0]=dest[1][0]+src_a[0][0]*src_b[1][0]+src_a[1][0]*src_b[1][1]+src_a[2][0]*src_b[1][2]+src_a[3][0]*src_b[1][3];
	dest[2][0]=dest[2][0]+src_a[0][0]*src_b[2][0]+src_a[1][0]*src_b[2][1]+src_a[2][0]*src_b[2][2]+src_a[3][0]*src_b[2][3];
	dest[3][0]=dest[3][0]+src_a[0][0]*src_b[3][0]+src_a[1][0]*src_b[3][1]+src_a[2][0]*src_b[3][2]+src_a[3][0]*src_b[3][3];

	dest[0][1]=dest[0][1]+src_a[0][1]*src_b[0][0]+src_a[1][1]*src_b[0][1]+src_a[2][1]*src_b[0][2]+src_a[3][1]*src_b[0][3];
	dest[1][1]=dest[1][1]+src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1]+src_a[2][1]*src_b[1][2]+src_a[3][1]*src_b[1][3];
	dest[2][1]=dest[2][1]+src_a[0][1]*src_b[2][0]+src_a[1][1]*src_b[2][1]+src_a[2][1]*src_b[2][2]+src_a[3][1]*src_b[2][3];
	dest[3][1]=dest[3][1]+src_a[0][1]*src_b[3][0]+src_a[1][1]*src_b[3][1]+src_a[2][1]*src_b[3][2]+src_a[3][1]*src_b[3][3];

	dest[0][2]=dest[0][2]+src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2]+src_a[3][2]*src_b[0][3];
	dest[1][2]=dest[1][2]+src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2]+src_a[3][2]*src_b[1][3];
	dest[2][2]=dest[2][2]+src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2]+src_a[3][2]*src_b[2][3];
	dest[3][2]=dest[3][2]+src_a[0][2]*src_b[3][0]+src_a[1][2]*src_b[3][1]+src_a[2][2]*src_b[3][2]+src_a[3][2]*src_b[3][3];

	dest[0][3]=dest[0][3]+src_a[0][3]*src_b[0][0]+src_a[1][3]*src_b[0][1]+src_a[2][3]*src_b[0][2]+src_a[3][3]*src_b[0][3];
	dest[1][3]=dest[1][3]+src_a[0][3]*src_b[1][0]+src_a[1][3]*src_b[1][1]+src_a[2][3]*src_b[1][2]+src_a[3][3]*src_b[1][3];
	dest[2][3]=dest[2][3]+src_a[0][3]*src_b[2][0]+src_a[1][3]*src_b[2][1]+src_a[2][3]*src_b[2][2]+src_a[3][3]*src_b[2][3];
	dest[3][3]=dest[3][3]+src_a[0][3]*src_b[3][0]+src_a[1][3]*src_b[3][1]+src_a[2][3]*src_b[3][2]+src_a[3][3]*src_b[3][3];

}

inline void glmc_mat4f_msub(mat4f dest, mat4f src_a, mat4f src_b){// dest -= src_a * src_b

	dest[0][0]=dest[0][0]-src_a[0][0]*src_b[0][0]+src_a[1][0]*src_b[0][1]+src_a[2][0]*src_b[0][2]+src_a[3][0]*src_b[0][3];
	dest[1][0]=dest[1][0]-src_a[0][0]*src_b[1][0]+src_a[1][0]*src_b[1][1]+src_a[2][0]*src_b[1][2]+src_a[3][0]*src_b[1][3];
	dest[2][0]=dest[2][0]-src_a[0][0]*src_b[2][0]+src_a[1][0]*src_b[2][1]+src_a[2][0]*src_b[2][2]+src_a[3][0]*src_b[2][3];
	dest[3][0]=dest[3][0]-src_a[0][0]*src_b[3][0]+src_a[1][0]*src_b[3][1]+src_a[2][0]*src_b[3][2]+src_a[3][0]*src_b[3][3];

	dest[0][1]=dest[0][1]-src_a[0][1]*src_b[0][0]+src_a[1][1]*src_b[0][1]+src_a[2][1]*src_b[0][2]+src_a[3][1]*src_b[0][3];
	dest[1][1]=dest[1][1]-src_a[0][1]*src_b[1][0]+src_a[1][1]*src_b[1][1]+src_a[2][1]*src_b[1][2]+src_a[3][1]*src_b[1][3];
	dest[2][1]=dest[2][1]-src_a[0][1]*src_b[2][0]+src_a[1][1]*src_b[2][1]+src_a[2][1]*src_b[2][2]+src_a[3][1]*src_b[2][3];
	dest[3][1]=dest[3][1]-src_a[0][1]*src_b[3][0]+src_a[1][1]*src_b[3][1]+src_a[2][1]*src_b[3][2]+src_a[3][1]*src_b[3][3];

	dest[0][2]=dest[0][2]-src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2]+src_a[3][2]*src_b[0][3];
	dest[1][2]=dest[1][2]-src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2]+src_a[3][2]*src_b[1][3];
	dest[2][2]=dest[2][2]-src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2]+src_a[3][2]*src_b[2][3];
	dest[3][2]=dest[3][2]-src_a[0][2]*src_b[3][0]+src_a[1][2]*src_b[3][1]+src_a[2][2]*src_b[3][2]+src_a[3][2]*src_b[3][3];

	dest[0][3]=dest[0][3]-src_a[0][3]*src_b[0][0]+src_a[1][3]*src_b[0][1]+src_a[2][3]*src_b[0][2]+src_a[3][3]*src_b[0][3];
	dest[1][3]=dest[1][3]-src_a[0][3]*src_b[1][0]+src_a[1][3]*src_b[1][1]+src_a[2][3]*src_b[1][2]+src_a[3][3]*src_b[1][3];
	dest[2][3]=dest[2][3]-src_a[0][3]*src_b[2][0]+src_a[1][3]*src_b[2][1]+src_a[2][3]*src_b[2][2]+src_a[3][3]*src_b[2][3];
	dest[3][3]=dest[3][3]-src_a[0][3]*src_b[3][0]+src_a[1][3]*src_b[3][1]+src_a[2][3]*src_b[3][2]+src_a[3][3]*src_b[3][3];

}

inline void glmc_mat4f_identity(mat4f dest){ //Creates identity matrix
	dest[0][0]=1.0f;
	dest[1][0]=0.0f;
	dest[2][0]=0.0f;
	dest[3][0]=0.0f;

	dest[0][1]=0.0f;
	dest[1][1]=1.0f;
	dest[2][1]=0.0f;
	dest[3][1]=0.0f;

	dest[0][2]=0.0f;
	dest[1][2]=0.0f;
	dest[2][2]=1.0f;
	dest[3][2]=0.0f;

	dest[0][3]=0.0f;
	dest[1][3]=0.0f;
	dest[2][3]=0.0f;
	dest[3][3]=1.0f;
}

inline void glmc_mat4f_scale(mat4f dest, float src_x, float src_y, float src_z){ //Creates scaling matrix
	dest[0][0]=src_x;
	dest[1][0]=0.0f;
	dest[2][0]=0.0f;
	dest[3][0]=0.0f;

	dest[0][1]=0.0f;
	dest[1][1]=src_y;
	dest[2][1]=0.0f;
	dest[3][1]=0.0f;

	dest[0][2]=0.0f;
	dest[1][2]=0.0f;
	dest[2][2]=src_z;
	dest[3][2]=0.0f;

	dest[0][3]=0.0f;
	dest[1][3]=0.0f;
	dest[2][3]=0.0f;
	dest[3][3]=1.0f;
}

inline void glmc_mat4f_translate(mat4f dest, float	src_x, float src_y, float src_z){ //Creates translation matrix
	dest[0][0]=1.0f;
	dest[1][0]=0.0f;
	dest[2][0]=0.0f;
	dest[3][0]=src_x;

	dest[0][1]=0.0f;
	dest[1][1]=1.0f;
	dest[2][1]=0.0f;
	dest[3][1]=src_y;

	dest[0][2]=0.0f;
	dest[1][2]=0.0f;
	dest[2][2]=1.0f;
	dest[3][2]=src_z;

	dest[0][3]=0.0f;
	dest[1][3]=0.0f;
	dest[2][3]=0.0f;
	dest[3][3]=1.0f;
}

inline void glmc_mat4f_rotate(mat4f dest, float ux, float uy, float uz, float angle){ //Creates rotatation matrix
	float c=cos(angle);
	float s=sin(angle);

	dest[0][0]=c+ux*ux*(1-c);
	dest[1][0]=ux*uy*(1-c)-uz*s;
	dest[2][0]=ux*uz*(1-c)+uy*s;
	dest[3][0]=0.0f;

	dest[0][1]=uy*ux*(1-c)+uz*s;
	dest[1][1]=c+uy*uy*(1-c);
	dest[2][1]=uy*uz*(1-c)-ux*s;
	dest[3][1]=0.0f;

	dest[0][2]=ux*uz*(1-c)-uy*s;
	dest[1][2]=uy*uz*(1-c)+ux*s;
	dest[2][2]=c+uz*uz*(1-c);
	dest[3][2]=0.0f;

	dest[0][3]=0.0f;
	dest[1][3]=0.0f;
	dest[2][3]=0.0f;
	dest[3][3]=1.0f;
}

inline void glmc_mat4f_ortho_projection(mat4f dest, float l, float r, float t, float b){//Finds orthographic project of matrix
	dest[0][0]=2*(r-l);
	dest[1][0]=0.0f;
	dest[2][0]=0.0f;
	dest[3][0]=-((r+l)/(r-l));

	dest[0][1]=0.0f;
	dest[1][1]=2*(t-b);
	dest[2][1]=0.0f;
	dest[3][1]=-((t+b)/(t-b));

	dest[0][2]=0.0f;
	dest[1][2]=0.0f;
	dest[2][2]=0.0f;
	dest[3][2]=0.0f;

	dest[0][3]=0.0f;
	dest[1][3]=0.0f;
	dest[2][3]=0.0f;
	dest[3][3]=1.0f;
}

inline void glmc_mat4f_perspective_projection(mat4f dest,float v_angle, float aspect_ratio, float nearz, float farz){//Finds perspective project of matrix
	float t=tan(v_angle/2);
	dest[0][0]=1/(aspect_ratio*t);
	dest[1][0]=0.0f;
	dest[2][0]=0.0f;
	dest[3][0]=0.0f;

	dest[0][1]=0.0f;
	dest[1][1]=1/t;
	dest[2][1]=0.0f;
	dest[3][1]=0.0f;

	dest[0][2]=0.0f;
	dest[1][2]=0.0f;
	dest[2][2]=(farz)/(nearz-farz);
	dest[3][2]=-(farz*nearz)/(farz-nearz);

	dest[0][3]=0.0f;
	dest[1][3]=0.0f;
	dest[2][3]=1.0f;
	dest[3][3]=0.0f;
}

inline void glmc_mat4f_to_array4f(array4f dest, mat4f src){ //Converts matrix to 1D array
	dest[0]=src[0][0];
	dest[1]=src[0][1];
	dest[2]=src[0][2];
	dest[3]=src[0][3];

	dest[4]=src[1][0];
	dest[5]=src[1][1];
	dest[6]=src[1][2];
	dest[7]=src[1][3];

	dest[8]=src[2][0];
	dest[9]=src[2][1];
	dest[10]=src[2][2];
	dest[11]=src[2][3];

	dest[12]=src[3][0];
	dest[13]=src[3][1];
	dest[14]=src[3][2];
	dest[15]=src[3][3];
}

inline void glmc_mat4f_create(mat4f dest){ //Automatically normalize according to compiler flag
	scanf("%f", &dest[0][0]);
	scanf("%f", &dest[0][1]);
	scanf("%f", &dest[0][2]);
	scanf("%f", &dest[0][3]);

	scanf("%f", &dest[1][0]);
	scanf("%f", &dest[1][1]);
	scanf("%f", &dest[1][2]);
	scanf("%f", &dest[1][3]);

	scanf("%f", &dest[2][0]);
	scanf("%f", &dest[2][1]);
	scanf("%f", &dest[2][2]);
	scanf("%f", &dest[2][3]);

	scanf("%f", &dest[3][0]);
	scanf("%f", &dest[3][1]);
	scanf("%f", &dest[3][2]);
	scanf("%f", &dest[3][3]);


	#ifdef STRICT_NORMALIZE
		glmc_mat4f_normalize_dest(dest);

	#endif
}