/**************************************************************************
* Name : Multi-camera Multi-target Tracking in PSN
* Author : HAANJU.YOO
* Initial Date : 2013.08.29
* Last Update : 2013.08.29
* Version : 0.9
***************************************************************************
*                                            ....
*                                           W$$$$$u
*                                           $$$$F**+           .oW$$$eu
*                                           ..ueeeWeeo..      e$$$$$$$$$
*                                       .eW$$$$$$$$$$$$$$$b- d$$$$$$$$$$W
*                           ,,,,,,,uee$$$$$$$$$$$$$$$$$$$$$ H$$$$$$$$$$$~
*                        :eoC$$$$$$$$$$$C""?$$$$$$$$$$$$$$$ T$$$$$$$$$$"
*                         $$$*$$$$$$$$$$$$$e "$$$$$$$$$$$$$$i$$$$$$$$F"
*                         ?f"!?$$$$$$$$$$$$$$ud$$$$$$$$$$$$$$$$$$$$*Co
*                         $   o$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*                 !!!!m.*eeeW$$$$$$$$$$$f?$$$$$$$$$$$$$$$$$$$$$$$$$$$$$U
*                 !!!!!! !$$$$$$$$$$$$$$  T$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*                  *!!*.o$$$$$$$$$$$$$$$e,d$$$$$$$$$$$$$$$$$$$$$$$$$$$$$:
*                 "eee$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$C
*                b ?$$$$$$$$$$$$$$**$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$!
*                Tb "$$$$$$$$$$$$$$*uL"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
*                 $$o."?$$$$$$$$F" u$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*                  $$$$en ```    .e$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'
*                   $$$B*  =*"?.e$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$F
*                    $$$W"$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
*                     "$$$o#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$"
*                    R: ?$$$W$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" :!i.
*                     !!n.?$???""``.......,``````"""""""""""``   ...+!!!
*                      !* ,+::!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*`
*                      "!?!!!!!!!!!!!!!!!!!!~ !!!!!!!!!!!!!!!!!!!~`
*                      +!!!!!!!!!!!!!!!!!!!! !!!!!!!!!!!!!!!!!!?!`
*                    .!!!!!!!!!!!!!!!!!!!!!' !!!!!!!!!!!!!!!, !!!!
*                   :!!!!!!!!!!!!!!!!!!!!!!' !!!!!!!!!!!!!!!!! `!!:
*                .+!!!!!!!!!!!!!!!!!!!!!~~!! !!!!!!!!!!!!!!!!!! !!!.
*               :!!!!!!!!!!!!!!!!!!!!!!!!!.`:!!!!!!!!!!!!!!!!!:: `!!+
*               "~!!!!!!!!!!!!!!!!!!!!!!!!!!.~!!!!!!!!!!!!!!!!!!!!.`!!:
*                   ~~!!!!!!!!!!!!!!!!!!!!!!! ;!!!!~` ..eeeeeeo.`+!.!!!!.
*                 :..    `+~!!!!!!!!!!!!!!!!! :!;`.e$$$$$$$$$$$$$u .
*                 $$$$$$beeeu..  `````~+~~~~~" ` !$$$$$$$$$$$$$$$$ $b
*                 $$$$$$$$$$$$$$$$$$$$$UU$U$$$$$ ~$$$$$$$$$$$$$$$$ $$o
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$. $$$$$$$$$$$$$$$~ $$$u
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$! $$$$$$$$$$$$$$$ 8$$$$.
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$X $$$$$$$$$$$$$$`u$$$$$W
*                !$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$! $$$$$$$$$$$$$".$$$$$$$:
*                 $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$  $$$$$$$$$$$$F.$$$$$$$$$
*                 ?$$$$$$$$$$$$$$$$$$$$$$$$$$$$f $$$$$$$$$$$$' $$$$$$$$$$.
*                  $$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$  $$$$$$$$$$!
*                  "$$$$$$$$$$$$$$$$$$$$$$$$$$$ ?$$$$$$$$$$$$  $$$$$$$$$$!
*                   "$$$$$$$$$$$$$$$$$$$$$$$$Fib ?$$$$$$$$$$$b ?$$$$$$$$$
*                     "$$$$$$$$$$$$$$$$$$$$"o$$$b."$$$$$$$$$$$  $$$$$$$$'
*                    e. ?$$$$$$$$$$$$$$$$$ d$$$$$$o."?$$$$$$$$H $$$$$$$'
*                   $$$W.`?$$$$$$$$$$$$$$$ $$$$$$$$$e. "??$$$f .$$$$$$'
*                  d$$$$$$o "?$$$$$$$$$$$$ $$$$$$$$$$$$$eeeeee$$$$$$$"
*                  $$$$$$$$$bu "?$$$$$$$$$ 3$$$$$$$$$$$$$$$$$$$$*$$"
*                 d$$$$$$$$$$$$$e. "?$$$$$:`$$$$$$$$$$$$$$$$$$$$8
*         e$$e.   $$$$$$$$$$$$$$$$$$+  "??f "$$$$$$$$$$$$$$$$$$$$c
*        $$$$$$$o $$$$$$$$$$$$$$$F"          `$$$$$$$$$$$$$$$$$$$$b.0
*       M$$$$$$$$U$$$$$$$$$$$$$F"              ?$$$$$$$$$$$$$$$$$$$$$u
*       ?$$$$$$$$$$$$$$$$$$$$F                   "?$$$$$$$$$$$$$$$$$$$$u
*        "$$$$$$$$$$$$$$$$$$"                       ?$$$$$$$$$$$$$$$$$$$$o
*          "?$$$$$$$$$$$$$F                            "?$$$$$$$$$$$$$$$$$$
*             "??$$$$$$$F                                 ""?3$$$$$$$$$$$$F
*                                                       .e$$$$$$$$$$$$$$$$'
*                                                      u$$$$$$$$$$$$$$$$$
*                                                     `$$$$$$$$$$$$$$$$"
*                                                      "$$$$$$$$$$$$F"
*                                                        ""?????""
*
***************************************************************************
*
* Using DDK dataset
*
**************************************************************************/
#include "stdafx.h"
#include <iostream>
#include <omp.h>
//-------------------------------------------
#include "PSNWhere.h"
//-------------------------------------------

// DEBUG
#include "PSNWhere_SGSmooth.h"
#include "PSNWhere_Manager.h"
double tracks[51] = {-4055.830585,-3956.084419,-4175.343372,-4442.231294,-4504.186214,-4811.912024,-4832.689742,-5110.375073,-5131.233210,-5188.306980,-5539.101873,-5775.489610,-5812.707911,-5874.081062,-5848.439586,-5941.742580,-6367.347967,-6228.246239,-6268.043961,-6424.375970,-6395.807383,-6522.901084,-6614.074930,-6619.457934,-6832.562234,-6832.562234,-7136.644751,-6897.148696,-6897.148696,-7166.813152,-7107.539649,-7107.539649,-7179.874683,-7179.874683,-7179.874683,-7052.484259,-6892.820222,-7230.466158,-7220.633381,-7230.466158,-7043.776572,-7095.813581,-7012.428660,-7095.747611,-7120.330174,-7120.330174,-7120.330174,-7127.337322,-7210.509441,-7339.415910,-7573.112104};
double trackX[51] = {-4055.830585,-3956.084419,-4175.343372,-4442.231294,-4504.186214,-4811.912024,-4832.689742,-5110.375073,-5131.233210,-5188.306980,-5539.101873,-5775.489610,-5812.707911,-5874.081062,-5848.439586,-5941.742580,-6367.347967,-6228.246239,-6268.043961,-6424.375970,-6395.807383,-6522.901084,-6614.074930,-6619.457934,-6832.562234,-6832.562234,-7136.644751,-6897.148696,-6897.148696,-7166.813152,-7107.539649,-7107.539649,-7179.874683,-7179.874683,-7179.874683,-7052.484259,-6892.820222,-7230.466158,-7220.633381,-7230.466158,-7043.776572,-7095.813581,-7012.428660,-7095.747611,-7120.330174,-7120.330174,-7120.330174,-7127.337322,-7210.509441,-7339.415910,-7573.112104};
double trackY[51] = {-7436.388911,-7461.433349,-7426.147823,-7447.455326,-7286.349666,-7329.536690,-7310.234199,-7221.458559,-7425.988720,-7261.333790,-6997.345344,-7070.305669,-7038.654045,-6842.593244,-7015.311152,-6908.180437,-6665.135871,-6556.602895,-6724.242042,-6246.625352,-6187.913236,-5922.828439,-6185.148666,-5945.174353,-5750.764482,-5750.764482,-5643.779157,-5778.880391,-5778.880391,-5703.281022,-5999.121451,-5999.121451,-5731.525928,-5731.525928,-5731.525928,-5621.433579,-5711.501069,-5736.015270,-5934.836674,-5736.015270,-5602.603642,-5639.096733,-5816.955624,-5721.730039,-5666.600238,-5666.600238,-5666.600238,-5949.470955,-5758.216456,-5843.235002,-5659.652293};


int _tmain(int argc, _TCHAR* argv[])
{
	//CPSNWhere_SGSmooth smoother(9, 1);
	//int numPreData = 50;
	//std::vector<double> data(numPreData);
	//for (int pos = 0; pos < numPreData; pos++) { data[pos] = tracks[pos]; }
	//smoother.Insert(data);
	//data.resize(1, 0.0);
	//for (int pos = 0; pos < 1; pos++) { data[pos] = tracks[numPreData+pos]; }
	//smoother.Insert(data);

	CPointSmoother smoother;
	int numPreData = 51;
	std::vector<PSN_Point3D> points(numPreData);
	std::vector<PSN_Point3D> smoothedPoints, results;
	for (int pos = 0; pos < numPreData; pos++)
	{
		points[pos].x = trackX[pos];
		points[pos].y = trackY[pos];
		points[pos].z = 0.0;
	}
	smoother.Insert(points);
	smoothedPoints = smoother.GetResults(0);
	//int refreshPos = smoother.Insert(PSN_Point3D(trackX[50], trackY[50], 0.0));	
	//results = smoother.GetResults(refreshPos);
	//smoothedPoints.erase(smoothedPoints.begin() + refreshPos, smoothedPoints.end());
	//smoothedPoints.insert(smoothedPoints.end(), results.begin(), results.end());

	int a = 0;

/*
	CPSNWhere psnWhere;
	cv::Mat inputFrame[NUM_CAM];
	char inputFilePath[300];

	// argument handling
#ifdef _UNICODE
	std::wstring wstrDatasetPath(argv[1]);
	std::string strDatasetPath(wstrDatasetPath.begin(), wstrDatasetPath.end());
#else
	std::string strDatasetPath = argv[1];
#endif

	// input frame range	
	//int frameIdxStart = 0;
	//int frameIdxEnd = 300;
	
	// P6S1
	//int frameIdxStart = 100;
	//int frameIdxEnd = 430;

	// PETS2009
	int frameIdxStart = 0;
	int frameIdxEnd = 100;
	//int frameIdxEnd = 794;
	

	/////////////////////////////////////////////////////////////////
	// INITIALIZATION
	/////////////////////////////////////////////////////////////////
	psnWhere = CPSNWhere();
	psnWhere.Initialize(strDatasetPath);

	/////////////////////////////////////////////////////////////////
	// MAIN LOOP
	/////////////////////////////////////////////////////////////////
	for(int frameIdx = frameIdxStart; frameIdx <= frameIdxEnd; frameIdx++)
	{
		//---------------------------------------------------
		// FRAME GRABBING
		//---------------------------------------------------
#pragma omp parallel for
		for(int camIdx = 0; camIdx < NUM_CAM; camIdx++)
		{			
			unsigned int curCamID = CAM_ID[camIdx];
			if (PSN_INPUT_TYPE)
			{
				sprintf_s(inputFilePath, sizeof(inputFilePath), "%s\\View_%03d\\frame_%04d.jpg", strDatasetPath.c_str(), curCamID, frameIdx);						
			}
			else
			{
				sprintf_s(inputFilePath, sizeof(inputFilePath), "%s\\%d_%d.jpg", strDatasetPath.c_str(), curCamID, frameIdx);						
			}
			inputFrame[camIdx] = cv::imread(inputFilePath, cv::IMREAD_COLOR);
			if(!inputFrame[camIdx].data)
			{
				std::cout << "Can't open the input frame" << std::endl;
				inputFrame[camIdx].release();
				return -1;
			}
		}
		
		//---------------------------------------------------
		// TRACKING
		//---------------------------------------------------
		psnWhere.TrackPeople(inputFrame, frameIdx);

		//---------------------------------------------------
		// MEMORY CLEARING
		//---------------------------------------------------
		for(int camIdx = 0; camIdx < NUM_CAM; camIdx++)
		{
			inputFrame[camIdx].release();
		}
	}


	/////////////////////////////////////////////////////////////////
	// TERMINATION
	/////////////////////////////////////////////////////////////////
	psnWhere.Finalize();
 */
	return 0;
}

//()()
//('')HAANJU.YOO
