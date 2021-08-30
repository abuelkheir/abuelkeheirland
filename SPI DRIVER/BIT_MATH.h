/*
 * BIT_MATH.h
 *
 *  Created on: Aug 21, 2021
 *      Author: Lenovo
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BitNo) (REG |= (1<<BitNo))
#define CLR_BIT(REG,BitNo) (REG &= ~(1<<BitNo))
#define TGL_BIT(REG,BitNo) (REG ^= (1<<BitNo))
#define GET_BIT(REG,BitNo) ((REG >> BitNo) & (1))

#endif /* BIT_MATH_H_ */
