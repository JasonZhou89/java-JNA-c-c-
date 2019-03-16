#include "anti-collision.h"

//计算欧氏距离
double computeDistance(LOCATION a,LOCATION b)
{
    int i;
    double dist=0.0;

    dist+=pow(a.longitude-b.longitude,2);
    dist+=pow(a.latitude-b.latitude,2);

    return sqrt(dist);
}

/* --------------------------------------------------------------------------------------------
** FUNCTION:	getSafeDistanceShips
** --------------------------------------------------------------------------------------------
** PURPOSE:
**        获取指定船只方圆指定距离内的所有船只
** USAGE: 
** PARAMETERS:
**        INPUT:
**              source:指定船只的经纬度
**              dataSet:所有船只的经纬度
**              safeDistance:指定船只搜索周边距离
**              safeDistance:指定船只搜索周边距离
**              ppVals:所有在指定范围内的船只经纬度信息
**              pNumvals:在指定范围内船只总个数
**        OUTPUT 
** AUTHORS:    
** ------------------------------------------------------------------------------------------*/
EXPORT_API void getSafeDistanceShips(LOCATION *source,
					LOCATION *dataSet,
					int dataSetSize,
					int safeDistance, 
					LOCATION** ppVals,
					int* pNumvals)
{
	assert(source != NULL);
	assert(dataSet != NULL);
	
	//计算各个点的欧氏距离
	double diff[dataSetSize];
	int i=0;
	int count = 0;
	for (i=0;i<dataSetSize;i++)
	{
		diff[i] = computeDistance( dataSet[i], *source );
		if(diff[i] <= safeDistance)
        {
            count ++;
        }
	}

    if(count==0)
    {
        *pNumvals = 0;
        *ppVals = NULL;
    }
    else
    {
        //获取指定范围内的船只
        *pNumvals = count;
    	*ppVals = (LOCATION*)malloc(sizeof(LOCATION)*count);
    	memset(*ppVals, 0, sizeof(LOCATION)*count);
    	LOCATION* ptmp = *ppVals;
    	for (i=0;i<dataSetSize;i++)
    	{
            if(diff[i] <= safeDistance)
            {
                *ptmp = dataSet[i];
                ptmp++;
            }
    	}
    }
	
	return ;
}

/* --------------------------------------------------------------------------------------------
** FUNCTION:	cleanupStrutArray
** --------------------------------------------------------------------------------------------
** PURPOSE:
**        释放动态申请的内存空间
** USAGE: 
** PARAMETERS:
**        INPUT:
**              source:指定船只的经纬度
**              dataSet:所有船只的经纬度
**              safeDistance:指定船只搜索周边距离
**              safeDistance:指定船只搜索周边距离
**              ppVals:所有在指定范围内的船只经纬度信息
**              pNumvals:在指定范围内船只总个数
**        OUTPUT 
** AUTHORS:    
** ------------------------------------------------------------------------------------------*/
EXPORT_API void cleanupStrutArray(LOCATION* pMem)
{
    printf("(C) cleaning up memory...\n");
    free(pMem);
    
    return;
}

