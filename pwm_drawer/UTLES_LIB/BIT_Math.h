#ifndef BIT_Math_h
#define BIT_Math_h

// Macro to set a bit
#define SET_BIT(REG, BIT_NUM) (REG |= (1 << (BIT_NUM)))

// Macro to clear a bit
#define CLR_BIT(REG, BIT_NUM) (REG &= ~(1 << (BIT_NUM)))

// Macro to toggle a bit
#define TOG_BIT(REG, BIT_NUM) (REG ^= (1 << (BIT_NUM)))

// Macro to get the value of a bit
#define GET_BIT(REG, BIT_NUM) (((REG) >> (BIT_NUM)) & 0x01)

#endif // BIT_Math_h
