#include "find_min_max.h"
#include <stddef.h>

struct MinMax GetMinMax(int *array, unsigned int begin, unsigned int end)
{
    struct MinMax result = {0, 0};
    unsigned int i;

    if (array == NULL || begin >= end) {
        return result;
    }

    result.min = array[begin];
    result.max = array[begin];

    for (i = begin + 1; i < end; ++i) {
        if (array[i] < result.min) {
            result.min = array[i];
        }
        if (array[i] > result.max) {
            result.max = array[i];
        }
    }

    return result;
}
