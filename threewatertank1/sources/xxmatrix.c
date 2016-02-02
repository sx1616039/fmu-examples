/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  src\xxmatrix.c
 *  model: threetankco
 *  expmt: threetankco
 *  date:  November 6, 2015
 *  time:  2:34:26 pm
 *  user:  INTO-CPS
 *  from:  20-sim 4.5 Professional Single
 *  build: 4.5.4.6171
 **********************************************************/

/* This file implements the functions necessary for matrix
   operations
*/

/* standard include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* 20-sim include files */
#include "xxtypes.h"
#include "xxmatrix.h"

/* fill in a matrix struct with a given array, rows and columns
*/
void XXCreateMatrixStruct (XXMatrix *mat_dest, XXInteger rows, XXInteger columns, XXDouble *values)
{
	mat_dest->rows = rows;
	mat_dest->columns = columns;
	mat_dest->mat = values;
}


/* allocate a matrix struct with rows and columns
void XXAllocateMatrixStruct (XXMatrix *mat_dest, XXInteger rows, XXInteger columns)
{
	mat_dest->rows = rows;
	mat_dest->columns = columns;
	mat_dest->mat = (XXDouble*)calloc(rows * columns + 1, sizeof(XXDouble));
}
*/

/* free a matrix struct with rows and columns
void XXFreeMatrixStruct (XXMatrix *mat_dest)
{
	mat_dest->rows = 0;
	mat_dest->columns = 0;
	free(mat_dest->mat);
	mat_dest->mat = NULL;
}
*/

/* copy a matrix source to a matrix destination
*/
void XXMatrixMov (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	/* use a while loop because it is efficient! */
	XXInteger size;

	size = mat_dest->rows * mat_dest->columns;
	memcpy(mat_dest->mat, mat_source->mat, size * sizeof(XXDouble));
}


/* copy a scalar to every element in a matrix destination
*/
void XXMatrixScalarMov (XXMatrix *mat_dest, XXDouble s)
{
	XXDouble *d;
	XXInteger i;

	d = mat_dest->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = s;
		d++;
		i--;
	}
}


/* get the row(zero_based) designated by the integer
   from the source to the destination. destination is vector
*/
void XXMatrixGetRow (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger row)
{
	XXInteger size;

	size = mat_source->columns;

	/* do it with a memcpy, since it is linear memory */
	memcpy(mat_dest->mat, &mat_source->mat[size*row], size * sizeof(XXDouble));
}


/* set the row(zero_based) designated by the integer
   to the destination from the source. source is vector
*/
void XXMatrixSetRow (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger row)
{
	XXInteger size;

	size = mat_source->columns;

	/* do it with a memcpy, since it is linear memory */
	memcpy(&mat_dest->mat[size*row], mat_source->mat, size * sizeof(XXDouble));
}


/* get the column(zero_based) designated by the integer
   from the source to the destination. destination is vector
*/
void XXMatrixGetColumn (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger column)
{
	XXInteger i, rows, columns;

	rows = mat_source->rows;
	columns = mat_source->columns;

	for( i = 0; i < rows; i++)
		mat_dest->mat[i] = mat_source->mat[columns * i + column];
}


/* set the column(zero_based) designated by the integer
   to the destination from the source. source is vector
*/
void XXMatrixSetColumn (XXMatrix *mat_dest, XXMatrix *mat_source, XXInteger column)
{
	XXInteger i, rows, columns;

	rows = mat_dest->rows;
	columns = mat_dest->columns;

	for( i = 0; i < rows; i++)
		mat_dest->mat[columns * i + column] = mat_source->mat[i];
}


/* use the source vector as elements of the diagonal in the
   destination matrix
*/
void XXMatrixDiag (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXInteger i, size;

	size = mat_dest->rows;

	/* first everything zero */
	memset(mat_dest->mat, 0, size * size * sizeof(XXDouble));

	/* and loop to set the diagonal values */
	for( i = 0; i < size; i++)
	{
		/* set the diagonal value */
		mat_dest->mat[size*i+i] = mat_source->mat[i];
	}
}


/* add a matrix source1 to a matrix source2 to a matrix destination
*/
void XXMatrixAdd (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d;
	XXDouble *s1;
	XXDouble *s2;
	XXInteger i;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = (*s1) + (*s2);
		d++;s1++;s2++;
		i--;
	}
}


/* add a matrix source1 to a scalar source2 to a matrix destination
*/
void XXMatrixScalarAdd (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2)
{
	XXDouble *d;
	XXDouble *s1;
	XXInteger i;

	d = mat_dest->mat;
	s1 = mat_source1->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = (*s1) + s2;
		d++;s1++;
		i--;
	}
}


/* add a scalar source1 to a matrix source2 to a matrix destination
*/
void XXScalarMatrixAdd (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2)
{
	XXDouble *d;
	XXDouble *s2;
	XXInteger i;

	d = mat_dest->mat;
	s2 = mat_source2->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = s1 + (*s2);
		d++;s2++;
		i--;
	}
}


/* add a scalar source1 to a scalar source2 to a matrix destination
*/
void XXScalarScalarAdd (XXMatrix *mat_dest, XXDouble s1, XXDouble s2)
{
	XXDouble value;
	XXInteger i, size;

	value = s1 + s2;
	size = mat_dest->rows * mat_dest->columns;
	for(i = 0; i < size; i++)
		mat_dest->mat[i] = value;
}


/* subtract a matrix source2 from a matrix source1 to a matrix destination
*/
void XXMatrixSub (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d;
	XXDouble *s1;
	XXDouble *s2;
	XXInteger i;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = (*s1) - (*s2);
		d++;s1++;s2++;
		i--;
	}
}


/* subtract a scalar source2 from a matrix source1 to a matrix destination
*/
void XXMatrixScalarSub (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2)
{
	XXDouble *d;
	XXDouble *s1;
	XXInteger i;

	d = mat_dest->mat;
	s1 = mat_source1->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = (*s1) - s2;
		d++;s1++;
		i--;
	}
}


/* subtract a matrix source2 from a scalar source1 to a matrix destination
*/
void XXScalarMatrixSub (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2)
{
	XXDouble *d;
	XXDouble *s2;
	XXInteger i;

	d = mat_dest->mat;
	s2 = mat_source2->mat;

	/* use a while loop because it is efficient! */
	i = mat_dest->rows * mat_dest->columns;
	while(i)
	{
		(*d) = s1 - (*s2);
		d++;s2++;
		i--;
	}
}


/* subtract a scalar source2 from a scalar source1 to a matrix destination
*/
void XXScalarScalarSub (XXMatrix *mat_dest, XXDouble s1, XXDouble s2)
{
	XXDouble value;
	XXInteger i, size;

	value = s1 - s2;
	size = mat_dest->rows * mat_dest->columns;
	for(i = 0; i < size; i++)
		mat_dest->mat[i] = value;
}


/* multiply matrix source1 and matrix source2 to destination matrix
*/
void XXMatrixMul (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	/* do the actual multiplication (code needs no documentation, obviously) */
	XXInteger destIndex1, destIndex2, s1Index;
	XXDouble *d, *s1, *s2;
	XXDouble *d2, *s11, *s22;
	XXInteger i, j, k;
	XXInteger cMatSource1m;
	//XXInteger cMatSource1n
	XXInteger cMatSource2m;
	XXInteger cMatSource2n;
	XXInteger cMatDestn, cMatDestm;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;
	cMatSource1m = mat_source1->columns;
	//cMatSource1n = mat_source1->rows;
	cMatSource2m = mat_source2->columns;
	cMatSource2n = mat_source2->rows;
	cMatDestn = mat_dest->rows;
	cMatDestm = mat_dest->columns;

	i = 0;

	while (i < cMatDestn)
	{
		destIndex1 = cMatDestm * i;
		s1Index = i * cMatSource1m;

		j = 0;
		while (j < cMatDestm)
		{
			destIndex2 = destIndex1+j;
			d2 = d + destIndex2;
			*d2 = 0.0;
			s11 = s1 + s1Index;
			s22 = s2 + j;
			k = cMatSource2n;
			while (k)
			{
				(*d2) += (*s11) * (*s22);
				s11++;
				k--;
				s22 += cMatSource2m;
			}
			j++;
		}
		i++;
	}
}


/* multiply matrix source1 with scalar source2 to matrix destination
*/
void XXMatrixScalarMul (XXMatrix *mat_dest, XXMatrix *mat_source1, XXDouble s2)
{
	XXDouble *d, *s1;
	XXInteger i;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	i = mat_dest->rows * mat_dest->columns;

	while (i)
	{
		(*d) = (*s1) * s2;
		d++; s1++; i--;
	}
}


/* multiply scalar source1 with matrix source2 to matrix destination
*/
void XXScalarMatrixMul (XXMatrix *mat_dest, XXDouble s1, XXMatrix *mat_source2)
{
	XXDouble *d, *s2;
	XXInteger i;

	d = mat_dest->mat;
	s2 = mat_source2->mat;
	i = mat_dest->rows * mat_dest->columns;

	while (i)
	{
		(*d) = s1 * (*s2);
		d++; s2++; i--;
	}
}


/* multiply scalar source1 with scalar source2 to matrix destination
*/
void XXScalarScalarMul (XXMatrix *mat_dest, XXDouble s1, XXDouble s2)
{
	XXDouble value;
	XXInteger i, size;

	value = s1 * s2;
	size = mat_dest->rows * mat_dest->columns;
	for(i = 0; i < size; i++)
		mat_dest->mat[i] = value;
}


/* multiply matrix source1 with matrix source2 to scalar destination
   the sizes are not checked but it should be that rows of source1 == 1 and columns source2 == 1
*/
void XXScalarMatrixMatrixMul (XXDouble *dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXInteger i, size;

	*dest = 0.0;
	size = mat_source1->columns;
	for(i = 0; i < size; i++)
		*dest += mat_source1->mat[i] * mat_source2->mat[i];
}


/* divide scalar source1 with scalar source2 to matrix destination
*/
void XXScalarScalarDiv (XXMatrix *mat_dest, XXDouble s1, XXDouble s2)
{
	XXDouble value;
	XXInteger i, size;

	value = s1 / s2;
	size = mat_dest->rows * mat_dest->columns;
	for(i = 0; i < size; i++)
		mat_dest->mat[i] = value;
}


/* take the negative value of the matrix source to the the matrix destination
*/
void XXMatrixInv (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;
	XXInteger i;

	d = mat_dest->mat;
	s = mat_source->mat;
	i = mat_dest->rows * mat_dest->columns;

	while (i)
	{
		(*d) = -(*s);
		d++; s++; i--;
	}
}


/* take the transpose of the matrix source to the the matrix destination
*/
void XXMatrixTranspose (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;
	XXInteger i, j, rows, columns;

	d = mat_dest->mat;
	s = mat_source->mat;
	rows = mat_dest->rows;
	columns = mat_dest->columns;

	for(i = 0; i < rows; i++)
		for( j = 0; j < columns; j++)
			d[i * columns + j] = s[ j * rows + i];
}


/* multiply all elements element-wise to the destination
*/
void XXMatrixMulElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXInteger i;
	XXDouble *d, *s1, *s2;
	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	i = mat_source1->rows * mat_source1->columns;
	while(i)
	{
		*d = (*s1) * (*s2);
		d++; s1++; s2++; i--;
	}
}


/* divide all elements element-wise to the destination
*/
void XXMatrixDivElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXInteger i;
	XXDouble *d, *s1, *s2;
	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	i = mat_source1->rows * mat_source1->columns;
	while(i)
	{
		*d = (*s1) / (*s2);
		d++; s1++; s2++; i--;
	}
}


/* pow all elements element-wise to the destination
*/
void XXMatrixPowElement (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXInteger i;
	XXDouble *d, *s1, *s2;
	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	i = mat_source1->rows * mat_source1->columns;
	while(i)
	{
		*d = pow((*s1),(*s2));
		d++; s1++; s2++; i--;
	}
}


/* use the source1 as an integer index for the destination
   and copy the scalar value of source2 at this point
*/
void XXMatrixMovRelAbs (XXMatrix *mat_dest, XXDouble s1, XXDouble s2)
{
	/* source 1 is one based, we are zero based
	   leave some room for small variances. */
	XXInteger linIndex;

	linIndex = (XXInteger)(s1 - 0.9);

	mat_dest->mat[linIndex] = s2;
}


/* use the source2 as an integer index for the source1
   and copy this value of source1 to the scalar destination
*/
void XXMatrixMovAbsRel (XXDouble *dest, XXMatrix *mat_source1, XXDouble s2)
{
	/* source 2 is one based, we are zero based
	  leave some room for small variances. */
	XXInteger linIndex;

	linIndex = (XXInteger)(s2 - 0.9);

	*dest = mat_source1->mat[linIndex];
}


/* find the minimum value in a matrix source and place this in
   the destination
*/
void XXMatrixMinimum (XXDouble *dest, XXMatrix *mat_source)
{
	XXDouble *s;
	XXInteger i;

	s = mat_source->mat;
	*dest = (*s);

	/* go to the second element */
	s++;

	i = mat_source->rows * mat_source->columns - 1;
	while(i)
	{
		if( (*s) < (*dest) )
			*dest = (*s);
		s++;
		i--;
	}
}


/* find the maximum value in a matrix source and place this in
   the destination
*/
void XXMatrixMaximum (XXDouble *dest, XXMatrix *mat_source)
{
	XXDouble *s;
	XXInteger i;

	s = mat_source->mat;
	*dest = (*s);

	/* go to the second element */
	s++;
	i = mat_source->rows * mat_source->columns - 1;

	while(i)
	{
		if( (*s) > (*dest) )
			*dest = (*s);
		s++;
		i--;
	}
}


/* summize all the elements of the matrix and put the result in the dest
*/
void XXMatrixSum (XXDouble *dest, XXMatrix *mat_source)
{
	XXDouble *s;
	XXInteger i;

	s = mat_source->mat;
	*dest = 0;
	i = mat_source->rows * mat_source->columns;

	while(i)
	{
		*dest += (*s);
		s++;
		i--;
	}
}


/* set the destination to the eye matrix
*/
void XXMatrixEye (XXMatrix *mat_dest)
{
	XXInteger i, size, rows, columns;
	XXDouble *d;

	rows = mat_dest->rows;
	columns = mat_dest->columns;
	size = rows * columns;
	d = mat_dest->mat;

	/* first set everything to zero */
	if( size > 0 )
		memset(d, 0, size * sizeof(XXDouble));

	for(i = 0; i < rows; i++)
		d[i*(columns+1)] = 1.0;
}


/* multiply the source1 n times with itself, with n in source2
   an integer number. The result is put in the destination,
   workarray must have at least the size of the destination matrix
   plus the workarray size of an inverse matrix operation
   this makes 4 * n * n + 2 * n with n = rows/columns of source/dest.
   source and destination should be square
*/
void XXMatrixPow (XXMatrix *mat_dest, XXMatrix *mat_source1,
		  XXDouble s2, XXDouble *workarray)
{
	XXDouble abssrc2;
	XXInteger i, pow_val, offset;
	XXMatrix workMatrix;

	abssrc2 = fabs(s2);
	pow_val = (XXInteger)(abssrc2  + 0.1);

	/* map the work array on a local matrix */
	workMatrix.columns = mat_dest->columns;
	workMatrix.rows = mat_dest->rows;
	workMatrix.mat = workarray;

	/* first set the matrix to the eye value. */
	XXMatrixEye(mat_dest);

	/* keep multiplying the matrix with the source. */
	for( i = 0; i < pow_val; i++ )
	{
		/* multiply the source with the destination to the work matrix */
		XXMatrixMul(&workMatrix, mat_dest, mat_source1);

		/* and copy the workmatrix to the destination */
		XXMatrixMov(mat_dest, &workMatrix);
	}

	if( s2 < 0 )
	{
		/* take the inverse of the source if negative power */
		/* a work array is needed, but that was included in the
		   demand of this function */
		offset = workMatrix.columns * workMatrix.rows;

		/* the first part of the work array is the destination
		   the last part is work memory of the inverse */
		XXMatrixInverse(&workMatrix, mat_dest, &workarray[offset]);

		/* and copy the workmatrix to the destination */
		XXMatrixMov(mat_dest, &workMatrix);
	}
}


/* and the scalar scalar variant
*/
void XXScalarScalarPow (XXMatrix *mat_dest, XXDouble s1, XXDouble s2)
{
	XXDouble value;
	XXInteger i, size;

	value = pow(s1, s2);
	size = mat_dest->rows * mat_dest->columns;
	for(i = 0; i < size; i++)
		mat_dest->mat[i] = value;
}


/* take the cross product of matrix source1 and matrix source2
   to a destination matrix. all matrices must be 3x1
*/
void XXMatrixCrossProduct (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d, *s1, *s2;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* just do it */
	(*d) = s1[1] * s2[2] - s1[2] * s2[1]; d++;
	(*d) = s1[2] * s2[0] - s1[0] * s2[2]; d++;
	(*d) = s1[0] * s2[1] - s1[1] * s2[0];
}


/* take the inner product of matrix source1 and matrix source2
   to a scalar destination. the source matrices must be nx1
*/
void XXMatrixInnerProduct (XXDouble *dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXInteger i;
	XXDouble *s1, *s2;

	i = mat_source1->rows;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	*dest = 0.0;
	while(i)
	{
		*dest += (*s1) * (*s2);
		s1++;s2++;
		i--;
	}
}


/* take the 2-norm of matrix source to a scalar destination
*/
void XXMatrixNorm (XXDouble *dest, XXMatrix *mat_source)
{
	/* the implementation as on page 195 of Numerical Methods. */
	XXDouble *s;
	XXInteger i;
	XXDouble t;

	s = mat_source->mat;
	i = mat_source->rows * mat_source->columns;
	t = 0.0;

	while(i)
	{
		t += (*s) * (*s);
		s++;
		i--;
	}

	/* and take the square root of the result */
	*dest = sqrt(t);
}


/* take the inf norm of matrix source to a scalar destination
*/
void XXMatrixNormInf (XXDouble *dest, XXMatrix *mat_source)
{
	/* the implementation as on page 195/196 of Numerical Methods. */
	XXDouble p;
	XXDouble *s;
	XXInteger i, j, rows, columns;

	s = mat_source->mat;
	rows = mat_source->rows;
	columns = mat_source->columns;

	*dest = 0.0;
	for( i = 0; i < rows; i++ )
	{
		p = 0;
		for( j = 0; j < columns; j++ )
			p += fabs(s[i*columns+j]);
		if( p > (*dest) )
			*dest = p;
	}
}


/* take the Trace of the matrix source to the scalar destination.
   The trace is defined as the sum of the diagonal values
*/
XXDouble XXMatrixTrace (XXMatrix *mat_source)
{
	XXDouble *s;
	XXDouble dest;
	XXInteger i, rows, columns;

	s = mat_source->mat;
	i = 0;
	rows = mat_source->rows;
	columns = mat_source->columns;

	dest = 0.0;
	while( i < rows && i < columns )
	{
		dest += s[i*(columns+1)];
		i++;
	}
	return dest;
}


/* take the symetric value of the source matrix.
   the result is placed in the destination matrix.
   the work array must have the same size as the source
*/
void XXMatrixSym (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray)
{
	/* and a work matrix */
	XXMatrix workMatrix;

	/* map the work array on a local matrix */
	workMatrix.columns = mat_dest->columns;
	workMatrix.rows = mat_dest->rows;
	workMatrix.mat = workarray;

	/* first transpose the source to the destination */
	XXMatrixTranspose(mat_dest, mat_source);

	/* add those two matrices to the work array */
	XXMatrixAdd(&workMatrix, mat_dest, mat_source);

	/* and divide by a scalar two */
	XXMatrixScalarDiv(mat_dest, &workMatrix, 2.0);
}


/* take the anti symetric value of the source matrix.
   the result is placed in the destination matrix.
   the work array must have the same size as the source
*/
void XXMatrixAsym (XXMatrix *mat_dest, XXMatrix *mat_source, XXDouble *workarray)
{
	/* and a work matrix */
	XXMatrix workMatrix;

	/* map the work array on a local matrix */
	workMatrix.columns = mat_dest->columns;
	workMatrix.rows = mat_dest->rows;
	workMatrix.mat = workarray;

	/* first transpose the source to the destination */
	XXMatrixTranspose(mat_dest, mat_source);

	/* subtrace those two matrices to the work array */
	XXMatrixSub(&workMatrix, mat_source, mat_dest);

	/* and divide by a scalar two */
	XXMatrixScalarDiv(mat_dest, &workMatrix, 2.0);
}


/* take the skew of the source matrix to a matrix destination
   source = 3x1, destination is 3x3
*/
void XXMatrixSkew (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;

	d = mat_dest->mat;
	s = mat_source->mat;

	/* row one */
	(*d) = 0; d++;
	(*d) = -s[2]; d++;
	(*d) = s[1]; d++;

	/* row two */
	(*d) = s[2]; d++;
	(*d) = 0; d++;
	(*d) = -s[0]; d++;

	/* row three */
	(*d) = -s[1]; d++;
	(*d) = s[0]; d++;
	(*d) = 0; d++;
}


/* take the skew of the source1 matrix and source2 matrix
   to a matrix destination.
   source1 is 3x3 and soure2 = 3x1, destination is 4x4
*/
void XXMatrixHomogeneous (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d, *s1, *s2;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* row one */
	(*d) = s1[0]; d++;
	(*d) = s1[1]; d++;
	(*d) = s1[2]; d++;
	(*d) = s2[0]; d++;

	/* row two */
	(*d) = s1[3]; d++;
	(*d) = s1[4]; d++;
	(*d) = s1[5]; d++;
	(*d) = s2[1]; d++;

	/* row three */
	(*d) = s1[6]; d++;
	(*d) = s1[7]; d++;
	(*d) = s1[8]; d++;
	(*d) = s2[2]; d++;

	/* row four */
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 1;
}


/* take the inverse of a sourceH matrix to a destination matrix
   the source is 4x4 and the destination matrix is 4x4
*/
void XXMatrixInverseH (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;

	d = mat_dest->mat;
	s = mat_source->mat;

	/* row one */
	d[0] = s[0];
	d[1] = s[4];
	d[2] = s[8];

	/* row two */
	d[4] = s[1];
	d[5] = s[5];
	d[6] = s[9];

	/* row three */
	d[8] = s[2];
	d[9] = s[6];
	d[10] = s[10];

	/* and the position */
	d[3] = -(d[0] * s[3] + d[1] * s[7] + d[2] * s[11] );
	d[7] = -(d[4] * s[3] + d[5] * s[7] + d[6] * s[11] );
	d[11] = -(d[8] * s[3] + d[9] * s[7] + d[10] * s[11] );

	/* row four */
	d[12] = 0;
	d[13] = 0;
	d[14] = 0;
	d[15] = 1;
}


/* Create an Adjoint matrix.
   source matrix is 4x4, destination matrix is 6x6
*/
void XXMatrixAdjoint (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;

	d = mat_dest->mat;
	s = mat_source->mat;

	/* row one */
	(*d) = s[0]; d++;
	(*d) = s[1]; d++;
	(*d) = s[2]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row two */
	(*d) = s[4]; d++;
	(*d) = s[5]; d++;
	(*d) = s[6]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row three */
	(*d) = s[8]; d++;
	(*d) = s[9]; d++;
	(*d) = s[10]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row four */
	(*d) = -s[11] * s[4] + s[7] * s[8]; d++;
	(*d) = -s[11] * s[5] + s[7] * s[9]; d++;
	(*d) = -s[11] * s[6] + s[7] * s[10]; d++;
	(*d) = s[0]; d++;
	(*d) = s[1]; d++;
	(*d) = s[2]; d++;

	/* row five */
	(*d) = s[11] * s[0] - s[3] * s[8]; d++;
	(*d) = s[11] * s[1] - s[3] * s[9]; d++;
	(*d) = s[11] * s[2] - s[3] * s[10]; d++;
	(*d) = s[4]; d++;
	(*d) = s[5]; d++;
	(*d) = s[6]; d++;

	/* row six */
	(*d) = -s[7] * s[0] + s[3] * s[4]; d++;
	(*d) = -s[7] * s[1] + s[3] * s[5]; d++;
	(*d) = -s[7] * s[2] + s[3] * s[6]; d++;
	(*d) = s[8]; d++;
	(*d) = s[9]; d++;
	(*d) = s[10];
}


/* Create an Adjoint matrix from two source matrices
   source1 matrix is 3x3 (orientation),
   source2 matrix is 3x1 (position),
   destination matrix is 6x6
*/
void XXMatrixAdjoint1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d, *s1, *s2;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* row one */
	(*d) = s1[0]; d++;
	(*d) = s1[1]; d++;
	(*d) = s1[2]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row two */
	(*d) = s1[3]; d++;
	(*d) = s1[4]; d++;
	(*d) = s1[5]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row three */
	(*d) = s1[6]; d++;
	(*d) = s1[7]; d++;
	(*d) = s1[8]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row four */
	(*d) = -s2[2] * s1[3] + s2[1] * s1[6]; d++;
	(*d) = -s2[2] * s1[4] + s2[1] * s1[7]; d++;
	(*d) = -s2[2] * s1[5] + s2[1] * s1[8]; d++;
	(*d) = s1[0]; d++;
	(*d) = s1[1]; d++;
	(*d) = s1[2]; d++;

	/* row five */
	(*d) = s2[2] * s1[0] - s2[0] * s1[6]; d++;
	(*d) = s2[2] * s1[1] - s2[0] * s1[7]; d++;
	(*d) = s2[2] * s1[2] - s2[0] * s1[8]; d++;
	(*d) = s1[3]; d++;
	(*d) = s1[4]; d++;
	(*d) = s1[5]; d++;

	/* row six */
	(*d) = -s2[1] * s1[0] + s2[0] * s1[3]; d++;
	(*d) = -s2[1] * s1[1] + s2[0] * s1[4]; d++;
	(*d) = -s2[1] * s1[2] + s2[0] * s1[5]; d++;
	(*d) = s1[6]; d++;
	(*d) = s1[7]; d++;
	(*d) = s1[8];
}


/* Create an Adjoint matrix from a source matrix
   source1 matrix is 6x1
   destination matrix is 6x6
*/
void XXMatrixadjoint (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;

	d = mat_dest->mat;
	s = mat_source->mat;

	/* row one */
	(*d) = 0; d++;
	(*d) = -s[2]; d++;
	(*d) = s[1]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row two */
	(*d) = s[2]; d++;
	(*d) = 0; d++;
	(*d) = -s[0]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row three */
	(*d) = -s[1]; d++;
	(*d) = s[0]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row four */
	(*d) = 0; d++;
	(*d) = -s[5]; d++;
	(*d) = s[4]; d++;
	(*d) = 0; d++;
	(*d) = -s[2]; d++;
	(*d) = s[1]; d++;

	/* row two */
	(*d) = s[5]; d++;
	(*d) = 0; d++;
	(*d) = -s[3]; d++;
	(*d) = s[2]; d++;
	(*d) = 0; d++;
	(*d) = -s[0]; d++;

	/* row three */
	(*d) = -s[4]; d++;
	(*d) = s[3]; d++;
	(*d) = 0; d++;
	(*d) = -s[1]; d++;
	(*d) = s[0]; d++;
	(*d) = 0;
}


/* Create an adjoint matrix from two source matrices
   source1 matrix is 3x1
   source2 matrix is 3x1
   destination matrix is 6x6
*/
void XXMatrixadjoint1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d, *s1, *s2;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* row one */
	(*d) = 0; d++;
	(*d) = -s1[2]; d++;
	(*d) = s1[1]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row two */
	(*d) = s1[2]; d++;
	(*d) = 0; d++;
	(*d) = -s1[0]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row three */
	(*d) = -s1[1]; d++;
	(*d) = s1[0]; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;

	/* row four */
	(*d) = 0; d++;
	(*d) = -s2[2]; d++;
	(*d) = s2[1]; d++;
	(*d) = 0; d++;
	(*d) = -s1[2]; d++;
	(*d) = s1[1]; d++;

	/* row two */
	(*d) = s2[2]; d++;
	(*d) = 0; d++;
	(*d) = -s2[0]; d++;
	(*d) = s1[2]; d++;
	(*d) = 0; d++;
	(*d) = -s1[0]; d++;

	/* row three */
	(*d) = -s2[1]; d++;
	(*d) = s2[0]; d++;
	(*d) = 0; d++;
	(*d) = -s1[1]; d++;
	(*d) = s1[0]; d++;
	(*d) = 0;
}


/* calcalate the tilde matrix from a source matrix
   source1 matrix is 6x1
   destination matrix is 4x4
*/
void XXMatrixTilde (XXMatrix *mat_dest, XXMatrix *mat_source)
{
	XXDouble *d, *s;

	d = mat_dest->mat;
	s = mat_source->mat;

	/* row one */
	(*d) = 0; d++;
	(*d) = -s[2]; d++;
	(*d) = s[1]; d++;
	(*d) = s[3]; d++;

	/* row two */
	(*d) = s[2]; d++;
	(*d) = 0; d++;
	(*d) = -s[0]; d++;
	(*d) = s[4]; d++;

	/* row three */
	(*d) = -s[1]; d++;
	(*d) = s[0]; d++;
	(*d) = 0; d++;
	(*d) = s[5]; d++;

	/* row four */
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0;
}


/* calcalate the tilde matrix from two source matrices
   source1 matrix is 3x1
   source2 matrix is 3x1
   destination matrix is 4x4
*/
void XXMatrixTilde1 (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2)
{
	XXDouble *d, *s1, *s2;

	d = mat_dest->mat;
	s1 = mat_source1->mat;
	s2 = mat_source2->mat;

	/* row one */
	(*d) = 0; d++;
	(*d) = -s1[2]; d++;
	(*d) = s1[1]; d++;
	(*d) = s2[0]; d++;

	/* row two */
	(*d) = s1[2]; d++;
	(*d) = 0; d++;
	(*d) = -s1[0]; d++;
	(*d) = s2[1]; d++;

	/* row three */
	(*d) = -s1[1]; d++;
	(*d) = s1[0]; d++;
	(*d) = 0; d++;
	(*d) = s2[2]; d++;

	/* row four */
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0; d++;
	(*d) = 0;
}

/* calculate the solution of A x = b towards x 
   inside 20-sim this is done with an advanced linear solver
   NOTE: current code generation uses the x=inverse(A)*b approach instead */
void XXLinearSolve (XXMatrix *mat_dest, XXMatrix *mat_source1, XXMatrix *mat_source2, XXString method, XXInteger id, XXDouble *workarray)
{
	/* a work matrix */
	XXMatrix workMatrix;

	/* map the work array on a local matrix */
	workMatrix.columns = mat_source1->columns;
	workMatrix.rows = mat_source1->rows;
	workMatrix.mat = workarray;

	/* calculate the inverse */
	XXMatrixInverse (&workMatrix, mat_source1, workarray + (workMatrix.columns * workMatrix.rows));
	
	/* and multiply with b */
	XXMatrixMul (mat_dest, &workMatrix, mat_source2);
}
