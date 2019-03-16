#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


#define  EXPORT_API extern "C"  __attribute__ ((visibility("default"))) 

typedef struct location
{
    int longitude;
    int latitude;
}LOCATION;

EXPORT_API void getSafeDistanceShips(LOCATION *source,
					LOCATION *dataSet,
					int dataSetSize,
					int safeDistance, 
					LOCATION** ppVals,
					int* pNumvals);
EXPORT_API void cleanupStrutArray(LOCATION* pMem);

