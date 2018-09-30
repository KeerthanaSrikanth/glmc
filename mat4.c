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

float glmc_mat4f_discriminant(mat4f src_a){

	return src_a[0][0]*(src_a[1][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])+src_a[3][1]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3]))
		  
		  -src_a[1][0]*(src_a[0][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3]))
	      
	      +src_a[2][0]*(src_a[0][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])-src_a[1][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]))
	      
	      -src_a[3][0]*(src_a[0][1]*(src_a[1][2]*src_a[2][3]-src_a[1][3]*src_a[2][2])-src_a[1][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3])+src_a[2][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]));

}
	
inline void glmc_mat4f_inverse(mat4f dest, mat4f src_a){
	mat4f cof;
	cof[0][0]=src_a[1][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])+src_a[3][1]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3]);
	cof[1][0]=-src_a[0][1]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3]);
	cof[2][0]=src_a[0][1]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])-src_a[1][1]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]);
	cof[3][0]=-src_a[0][1]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3])-src_a[1][1]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3])+src_a[2][1]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]);

	cof[0][1]=src_a[1][0]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][0]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])+src_a[3][0]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3]);
	cof[1][1]=-src_a[0][0]*(src_a[2][2]*src_a[3][3]-src_a[3][2]*src_a[2][3])-src_a[2][0]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][0]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3]);
	cof[2][1]=src_a[0][0]*(src_a[1][2]*src_a[3][3]-src_a[3][2]*src_a[1][3])-src_a[1][0]*(src_a[0][2]*src_a[3][3]-src_a[3][2]*src_a[0][3])+src_a[3][0]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]);
	cof[3][1]=-src_a[0][0]*(src_a[1][2]*src_a[2][3]-src_a[2][2]*src_a[1][3])-src_a[1][0]*(src_a[0][2]*src_a[2][3]-src_a[2][2]*src_a[0][3])+src_a[2][0]*(src_a[0][2]*src_a[1][3]-src_a[1][2]*src_a[0][3]);

	
	cof[0][2]=src_a[1][0]*(src_a[2][1]*src_a[3][3]-src_a[3][1]*src_a[2][3])-src_a[2][0]*(src_a[1][1]*src_a[3][3]-src_a[3][1]*src_a[1][3])+src_a[3][0]*(src_a[1][1]*src_a[2][3]-src_a[2][1]*src_a[1][3]);
	cof[1][2]=-src_a[0][0]*(src_a[2][1]*src_a[3][3]-src_a[3][1]*src_a[2][3])-src_a[2][0]*(src_a[0][1]*src_a[3][3]-src_a[3][1]*src_a[0][3])+src_a[3][0]*(src_a[0][1]*src_a[2][3]-src_a[2][1]*src_a[0][3]);
	cof[2][2]=src_a[0][0]*(src_a[1][1]*src_a[3][3]-src_a[3][1]*src_a[1][3])-src_a[1][0]*(src_a[0][1]*src_a[3][3]-src_a[3][1]*src_a[0][3])+src_a[3][0]*(src_a[0][1]*src_a[1][3]-src_a[1][1]*src_a[0][3]);
	cof[3][2]=-src_a[0][0]*(src_a[1][1]*src_a[2][3]-src_a[2][1]*src_a[1][3])-src_a[1][0]*(src_a[0][1]*src_a[2][3]-src_a[2][1]*src_a[0][3])+src_a[2][0]*(src_a[0][1]*src_a[1][3]-src_a[1][1]*src_a[0][3]);

	cof[0][3]=src_a[1][0]*(src_a[2][1]*src_a[3][2]-src_a[3][1]*src_a[2][2])-src_a[2][0]*(src_a[1][1]*src_a[3][2]-src_a[3][1]*src_a[1][2])+src_a[3][0]*(src_a[1][1]*src_a[2][2]-src_a[2][1]*src_a[1][2]);
	cof[1][3]=-src_a[0][0]*(src_a[2][1]*src_a[3][2]-src_a[3][1]*src_a[2][2])-src_a[2][0]*(src_a[0][1]*src_a[3][2]-src_a[3][1]*src_a[0][2])+src_a[3][0]*(src_a[0][1]*src_a[2][2]-src_a[2][1]*src_a[0][2]);
	cof[2][3]=src_a[0][0]*(src_a[1][1]*src_a[3][2]-src_a[3][1]*src_a[1][2])-src_a[1][0]*(src_a[0][1]*src_a[3][2]-src_a[3][1]*src_a[0][2])+src_a[3][0]*(src_a[0][1]*src_a[1][2]-src_a[1][1]*src_a[0][2]);
	cof[3][3]=-src_a[0][0]*(src_a[1][1]*src_a[2][2]-src_a[2][1]*src_a[1][2])-src_a[1][0]*(src_a[0][1]*src_a[2][2]-src_a[2][1]*src_a[0][2])+src_a[2][0]*(src_a[0][1]*src_a[1][2]-src_a[1][1]*src_a[0][2]);

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
inline void glmc_mat4f_transpose(mat4f dest, mat4f src_a){
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

inline void glmc_mat4f_transpose_dest(mat4f src_a){
	float temp=src_a[1][0];
	src_a[1][0]=src_a[0][1];
	src_a[0][1]=temp;

	float temp=src_a[2][0];
	src_a[2][0]=src_a[0][2];
	src_a[0][2]=temp;

	float temp=src_a[3][0];
	src_a[3][0]=src_a[0][3];
	src_a[0][3]=temp;

	float temp=src_a[1][2];
	src_a[1][2]=src_a[2][1];
	src_a[2][1]=temp;

	float temp=src_a[1][3];
	src_a[1][3]=src_a[3][1];
	src_a[3][1]=temp;


	float temp=src_a[2][3];
	src_a[2][3]=src_a[3][2];
	src_a[3][2]=temp;

}

inline int  glmc_mat4f_is_normalized(mat4f src){
		if(glmc_mat4f_discriminant(src)==1)
			return 1;
		else
			return 0;
}

inline void glmc_mat4f_normlize(mat4f dest, mat4f src){
	
	float discr=glmc_mat4f_discriminant(src);
	
	dest[0][0]=src_a[0][0]/discr;
	dest[0][1]=src_a[0][1]/discr;
	dest[0][2]=src_a[0][2]/discr;
	dest[0][3]=src_a[0][3]/discr;

	dest[1][0]=src_a[1][0]/discr;
	dest[1][1]=src_a[1][1]/discr;
	dest[1][2]=src_a[1][2]/discr;
	dest[1][3]=src_a[1][3]/discr;

	dest[2][0]=src_a[2][0]/discr;
	dest[2][1]=src_a[2][1]/discr;
	dest[2][2]=src_a[2][2]/discr;
	dest[2][3]=src_a[2][3]/discr;

	dest[3][0]=src_a[3][0]/discr;
	dest[3][1]=src_a[3][1]/discr;
	dest[3][2]=src_a[3][2]/discr;
	dest[3][3]=src_a[3][3]/discr;
}

inline void glmc_mat4f_normlize_dest(mat4f src){

	float discr=glmc_mat4f_discriminant(src);

	src_a[0][0]=src_a[0][0]/discr;
	src_a[0][1]=src_a[0][1]/discr;
	src_a[0][2]=src_a[0][2]/discr;
	src_a[0][3]=src_a[0][3]/discr;

	src_a[1][0]=src_a[1][0]/discr;
	src_a[1][1]=src_a[1][1]/discr;
	src_a[1][2]=src_a[1][2]/discr;
	src_a[1][3]=src_a[1][3]/discr;

	src_a[2][0]=src_a[2][0]/discr;
	src_a[2][1]=src_a[2][1]/discr;
	src_a[2][2]=src_a[2][2]/discr;
	src_a[2][3]=src_a[2][3]/discr;

	src_a[3][0]=src_a[3][0]/discr;
	src_a[3][1]=src_a[3][1]/discr;
	src_a[3][2]=src_a[3][2]/discr;
	src_a[3][3]=src_a[3][3]/discr;
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

	dest[0][0]=src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2]+src_a[3][2]*src_b[0][3];
	dest[1][0]=src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2]+src_a[3][2]*src_b[1][3];
	dest[2][0]=src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2]+src_a[3][2]*src_b[2][3];
	dest[3][0]=src_a[0][2]*src_b[3][0]+src_a[1][2]*src_b[3][1]+src_a[2][2]*src_b[3][2]+src_a[3][2]*src_b[3][3];

	dest[0][0]=src_a[0][3]*src_b[0][0]+src_a[1][3]*src_b[0][1]+src_a[2][3]*src_b[0][2]+src_a[3][3]*src_b[0][3];
	dest[1][0]=src_a[0][3]*src_b[1][0]+src_a[1][3]*src_b[1][1]+src_a[2][3]*src_b[1][2]+src_a[3][3]*src_b[1][3];
	dest[2][0]=src_a[0][3]*src_b[2][0]+src_a[1][3]*src_b[2][1]+src_a[2][3]*src_b[2][2]+src_a[3][3]*src_b[2][3];
	dest[3][0]=src_a[0][3]*src_b[3][0]+src_a[1][3]*src_b[3][1]+src_a[2][3]*src_b[3][2]+src_a[3][3]*src_b[3][3];

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

	dest[0][0]=temp_dest[0][2]*src_b[0][0]+temp_dest[1][2]*src_b[0][1]+temp_dest[2][2]*src_b[0][2]+temp_dest[3][2]*src_b[0][3];
	dest[1][0]=temp_dest[0][2]*src_b[1][0]+temp_dest[1][2]*src_b[1][1]+temp_dest[2][2]*src_b[1][2]+temp_dest[3][2]*src_b[1][3];
	dest[2][0]=temp_dest[0][2]*src_b[2][0]+temp_dest[1][2]*src_b[2][1]+temp_dest[2][2]*src_b[2][2]+temp_dest[3][2]*src_b[2][3];
	dest[3][0]=temp_dest[0][2]*src_b[3][0]+temp_dest[1][2]*src_b[3][1]+temp_dest[2][2]*src_b[3][2]+temp_dest[3][2]*src_b[3][3];

	dest[0][0]=temp_dest[0][3]*src_b[0][0]+temp_dest[1][3]*src_b[0][1]+temp_dest[2][3]*src_b[0][2]+temp_dest[3][3]*src_b[0][3];
	dest[1][0]=temp_dest[0][3]*src_b[1][0]+temp_dest[1][3]*src_b[1][1]+temp_dest[2][3]*src_b[1][2]+temp_dest[3][3]*src_b[1][3];
	dest[2][0]=temp_dest[0][3]*src_b[2][0]+temp_dest[1][3]*src_b[2][1]+temp_dest[2][3]*src_b[2][2]+temp_dest[3][3]*src_b[2][3];
	dest[3][0]=temp_dest[0][3]*src_b[3][0]+temp_dest[1][3]*src_b[3][1]+temp_dest[2][3]*src_b[3][2]+temp_dest[3][3]*src_b[3][3];

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

	dest[0][0]=src_a[0][2]*inv[0][0]+src_a[1][2]*inv[0][1]+src_a[2][2]*inv[0][2]+src_a[3][2]*inv[0][3];
	dest[1][0]=src_a[0][2]*inv[1][0]+src_a[1][2]*inv[1][1]+src_a[2][2]*inv[1][2]+src_a[3][2]*inv[1][3];
	dest[2][0]=src_a[0][2]*inv[2][0]+src_a[1][2]*inv[2][1]+src_a[2][2]*inv[2][2]+src_a[3][2]*inv[2][3];
	dest[3][0]=src_a[0][2]*inv[3][0]+src_a[1][2]*inv[3][1]+src_a[2][2]*inv[3][2]+src_a[3][2]*inv[3][3];

	dest[0][0]=src_a[0][3]*inv[0][0]+src_a[1][3]*inv[0][1]+src_a[2][3]*inv[0][2]+src_a[3][3]*inv[0][3];
	dest[1][0]=src_a[0][3]*inv[1][0]+src_a[1][3]*inv[1][1]+src_a[2][3]*inv[1][2]+src_a[3][3]*inv[1][3];
	dest[2][0]=src_a[0][3]*inv[2][0]+src_a[1][3]*inv[2][1]+src_a[2][3]*inv[2][2]+src_a[3][3]*inv[2][3];
	dest[3][0]=src_a[0][3]*inv[3][0]+src_a[1][3]*inv[3][1]+src_a[2][3]*inv[3][2]+src_a[3][3]*inv[3][3];	
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

	dest[0][0]=temp_dest[0][2]*inv[0][0]+temp_dest[1][2]*inv[0][1]+temp_dest[2][2]*inv[0][2]+temp_dest[3][2]*inv[0][3];
	dest[1][0]=temp_dest[0][2]*inv[1][0]+temp_dest[1][2]*inv[1][1]+temp_dest[2][2]*inv[1][2]+temp_dest[3][2]*inv[1][3];
	dest[2][0]=temp_dest[0][2]*inv[2][0]+temp_dest[1][2]*inv[2][1]+temp_dest[2][2]*inv[2][2]+temp_dest[3][2]*inv[2][3];
	dest[3][0]=temp_dest[0][2]*inv[3][0]+temp_dest[1][2]*inv[3][1]+temp_dest[2][2]*inv[3][2]+temp_dest[3][2]*inv[3][3];

	dest[0][0]=temp_dest[0][3]*inv[0][0]+temp_dest[1][3]*inv[0][1]+temp_dest[2][3]*inv[0][2]+temp_dest[3][3]*inv[0][3];
	dest[1][0]=temp_dest[0][3]*inv[1][0]+temp_dest[1][3]*inv[1][1]+temp_dest[2][3]*inv[1][2]+temp_dest[3][3]*inv[1][3];
	dest[2][0]=temp_dest[0][3]*inv[2][0]+temp_dest[1][3]*inv[2][1]+temp_dest[2][3]*inv[2][2]+temp_dest[3][3]*inv[2][3];
	dest[3][0]=temp_dest[0][3]*inv[3][0]+temp_dest[1][3]*inv[3][1]+temp_dest[2][3]*inv[3][2]+temp_dest[3][3]*inv[3][3];

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

	dest[0][0]=dest[0][2]+src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2]+src_a[3][2]*src_b[0][3];
	dest[1][0]=dest[1][2]+src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2]+src_a[3][2]*src_b[1][3];
	dest[2][0]=dest[2][2]+src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2]+src_a[3][2]*src_b[2][3];
	dest[3][0]=dest[3][2]+src_a[0][2]*src_b[3][0]+src_a[1][2]*src_b[3][1]+src_a[2][2]*src_b[3][2]+src_a[3][2]*src_b[3][3];

	dest[0][0]=dest[0][3]+src_a[0][3]*src_b[0][0]+src_a[1][3]*src_b[0][1]+src_a[2][3]*src_b[0][2]+src_a[3][3]*src_b[0][3];
	dest[1][0]=dest[1][3]+src_a[0][3]*src_b[1][0]+src_a[1][3]*src_b[1][1]+src_a[2][3]*src_b[1][2]+src_a[3][3]*src_b[1][3];
	dest[2][0]=dest[2][3]+src_a[0][3]*src_b[2][0]+src_a[1][3]*src_b[2][1]+src_a[2][3]*src_b[2][2]+src_a[3][3]*src_b[2][3];
	dest[3][0]=dest[3][3]+src_a[0][3]*src_b[3][0]+src_a[1][3]*src_b[3][1]+src_a[2][3]*src_b[3][2]+src_a[3][3]*src_b[3][3];

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

	dest[0][0]=dest[0][2]-src_a[0][2]*src_b[0][0]+src_a[1][2]*src_b[0][1]+src_a[2][2]*src_b[0][2]+src_a[3][2]*src_b[0][3];
	dest[1][0]=dest[1][2]-src_a[0][2]*src_b[1][0]+src_a[1][2]*src_b[1][1]+src_a[2][2]*src_b[1][2]+src_a[3][2]*src_b[1][3];
	dest[2][0]=dest[2][2]-src_a[0][2]*src_b[2][0]+src_a[1][2]*src_b[2][1]+src_a[2][2]*src_b[2][2]+src_a[3][2]*src_b[2][3];
	dest[3][0]=dest[3][2]-src_a[0][2]*src_b[3][0]+src_a[1][2]*src_b[3][1]+src_a[2][2]*src_b[3][2]+src_a[3][2]*src_b[3][3];

	dest[0][0]=dest[0][3]-src_a[0][3]*src_b[0][0]+src_a[1][3]*src_b[0][1]+src_a[2][3]*src_b[0][2]+src_a[3][3]*src_b[0][3];
	dest[1][0]=dest[1][3]-src_a[0][3]*src_b[1][0]+src_a[1][3]*src_b[1][1]+src_a[2][3]*src_b[1][2]+src_a[3][3]*src_b[1][3];
	dest[2][0]=dest[2][3]-src_a[0][3]*src_b[2][0]+src_a[1][3]*src_b[2][1]+src_a[2][3]*src_b[2][2]+src_a[3][3]*src_b[2][3];
	dest[3][0]=dest[3][3]-src_a[0][3]*src_b[3][0]+src_a[1][3]*src_b[3][1]+src_a[2][3]*src_b[3][2]+src_a[3][3]*src_b[3][3];

}

