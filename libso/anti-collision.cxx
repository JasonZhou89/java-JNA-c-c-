#include "anti-collision.h"

//����ŷ�Ͼ���
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
**        ��ȡָ����ֻ��Բָ�������ڵ����д�ֻ
** USAGE: 
** PARAMETERS:
**        INPUT:
**              source:ָ����ֻ�ľ�γ��
**              dataSet:���д�ֻ�ľ�γ��
**              safeDistance:ָ����ֻ�����ܱ߾���
**              safeDistance:ָ����ֻ�����ܱ߾���
**              ppVals:������ָ����Χ�ڵĴ�ֻ��γ����Ϣ
**              pNumvals:��ָ����Χ�ڴ�ֻ�ܸ���
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
	
	//����������ŷ�Ͼ���
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
        //��ȡָ����Χ�ڵĴ�ֻ
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
**        �ͷŶ�̬������ڴ�ռ�
** USAGE: 
** PARAMETERS:
**        INPUT:
**              source:ָ����ֻ�ľ�γ��
**              dataSet:���д�ֻ�ľ�γ��
**              safeDistance:ָ����ֻ�����ܱ߾���
**              safeDistance:ָ����ֻ�����ܱ߾���
**              ppVals:������ָ����Χ�ڵĴ�ֻ��γ����Ϣ
**              pNumvals:��ָ����Χ�ڴ�ֻ�ܸ���
**        OUTPUT 
** AUTHORS:    
** ------------------------------------------------------------------------------------------*/
EXPORT_API void cleanupStrutArray(LOCATION* pMem)
{
    printf("(C) cleaning up memory...\n");
    free(pMem);
    
    return;
}

