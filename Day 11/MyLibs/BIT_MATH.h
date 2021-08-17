/*
 * BIT_MATH.h
 *
 *  Created on: Aug 15, 2021
 *      Author: a7med
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define TGL_BIT(Var,BitNo) (Var ^= ((1)<< BitNo))
#define CLR_BIT(Var,BitNo) (Var &= ~((1)<<BitNo))
#define SET_BIT(Var,BitNo) (Var |= ((1)<<BitNo))
#define GET_BIT(REG,BitNo) ((REG >> BitNo) & (1))


#endif /* BIT_MATH_H_ */
