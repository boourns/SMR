#ifndef WAVEFOLDER_H_
#define WAVEFOLDER_H_

#include "globals.h"

float apply_wavefolder(float channel_level, float in);
float wavefold_pos(float threshold, float in);
float wavefold_neg(float threshold, float in);

#endif /* WAVEFOLDER_H_ */
