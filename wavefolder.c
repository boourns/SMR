#include "arm_math.h"
#include "globals.h"
#include "filter.h"
#include "wavefolder.h"

#define NUM_WAVEFOLDS 1

// highest first
static float wavefold_thresholds_pos[NUM_WAVEFOLDS]={1.0};
static float wavefold_thresholds_neg[NUM_WAVEFOLDS]={-1.0};

// for faster math, hard-coded that wavefolder kicks in when channel_level past half
float inline apply_wavefolder(float channel_level, float in) {
  int i;
  float result = in * (channel_level*2);

  for (i = 0; i < NUM_WAVEFOLDS; i++) {
    result = wavefold_pos(wavefold_thresholds_pos[i], result);
    result = wavefold_neg(wavefold_thresholds_neg[i], result);
  }

  return result;
}

float inline wavefold_pos(float threshold, float in) {
  if (in <= threshold) {
    return threshold;
  } else {
    return threshold + (in - threshold);
  }
}

float inline wavefold_neg(float threshold, float in) {
  if (in >= threshold) {
    return threshold;
  } else {
    return threshold + (in - threshold);
  }
}
